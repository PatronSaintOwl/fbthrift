/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <folly/portability/GTest.h>
#include <thrift/compiler/codemod/file_manager.h>
#include <thrift/compiler/test/parser_test_helpers.h>
#include <thrift/compiler/util.h>

namespace apache::thrift::compiler {

std::string read_file(const std::string& path) {
  std::string content;
  EXPECT_TRUE(folly::readFile(path.c_str(), content));
  return content;
}

// Testing overloading of < operator in replacement struct.
TEST(FileManagerTest, replacement_less_than) {
  codemod::replacement a{2, 4, ""};
  codemod::replacement b{2, 5, ""};
  codemod::replacement c{3, 5, ""};
  codemod::replacement d{5, 7, ""};

  EXPECT_TRUE(a < b); // Same begin, different end
  EXPECT_TRUE(b < c); // Same end, different begin
  EXPECT_TRUE(a < c); // Overlapping
  EXPECT_TRUE(a < d); // Non-overlapping
}

// Basic test of apply_replacements functionality, without traversing AST.
TEST(FileManagerTest, apply_replacements_test) {
  auto program = dedent_and_parse_to_program(R"(
    struct A {
      1: optional A a (cpp.ref);
    } (cpp.noexcept_move)
  )");

  codemod::file_manager fm(*program);

  fm.add(
      {program->get_byte_offset(2, 2),
       program->get_byte_offset(2, 28),
       "@cpp.Ref{cpp.RefType.Unique}\n  1: optional string a;"});
  fm.add({program->get_byte_offset(3, 1), program->get_byte_offset(3, 21), ""});

  fm.apply_replacements();

  EXPECT_EQ(read_file(program->path()), strip_left_margin(R"(
    struct A {
      @cpp.Ref{cpp.RefType.Unique}
      1: optional string a;
    }
  )"));
}

// Testing correct line and column after including another thrift file.
TEST(FileManagerTest, correct_location_after_include_test) {
  auto include = dedent_and_parse_to_program(R"(
    struct A {
      1: string a;
    }
  )");

  auto program = dedent_and_parse_to_program(R"(
    include ")" + include->path() + R"("
    struct B {
      1: string b;
    }
  )");

  const auto struct_src_range = program->structs()[0]->src_range();
  const auto field_src_range = program->structs()[0]->fields()[0].src_range();

  EXPECT_EQ(struct_src_range.begin().line(), 2);
  EXPECT_EQ(struct_src_range.begin().column(), 1);
  EXPECT_EQ(struct_src_range.end().line(), 4);
  EXPECT_EQ(struct_src_range.end().column(), 2);

  EXPECT_EQ(field_src_range.begin().line(), 3);
  EXPECT_EQ(field_src_range.begin().column(), 3);
  EXPECT_EQ(field_src_range.end().line(), 3);
  EXPECT_EQ(field_src_range.end().column(), 14);
}

TEST(FileManagerTest, location_range) {
  auto program = dedent_and_parse_to_program(R"(
    service EchoService {
      /// Returns msg
      string echo(1: string msg
      ); /// Returns msg
    }

    struct Foo {
      /// This is a field
      i32 foo; /// This is a field
    }
  )");

  auto& func = program->services()[0]->functions()[0];
  EXPECT_EQ(func.name(), "echo");
  EXPECT_EQ(func.src_range().begin().line(), 3);
  EXPECT_EQ(func.src_range().begin().column(), 3);
  EXPECT_EQ(func.src_range().end().line(), 4);
  EXPECT_EQ(func.src_range().end().column(), 4);

  auto& field = program->structs()[0]->fields()[0];
  EXPECT_EQ(field.name(), "foo");
  EXPECT_EQ(field.src_range().begin().line(), 9);
  EXPECT_EQ(field.src_range().begin().column(), 3);
  EXPECT_EQ(field.src_range().end().line(), 9);
  EXPECT_EQ(field.src_range().end().column(), 10);
}

} // namespace apache::thrift::compiler
