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

#include <memory>
#include <string>
#include <vector>

#include <folly/portability/GMock.h>
#include <folly/portability/GTest.h>

#include <thrift/compiler/ast/t_exception.h>
#include <thrift/compiler/ast/t_function.h>
#include <thrift/compiler/ast/t_interaction.h>
#include <thrift/compiler/ast/t_service.h>
#include <thrift/compiler/ast/t_struct.h>
#include <thrift/compiler/ast/t_union.h>
#include <thrift/compiler/test/parser_test_helpers.h>
#include <thrift/compiler/validator/validator.h>

namespace {

class ValidatorTest : public testing::Test {};

} // namespace

TEST_F(ValidatorTest, run_validator) {
  class fake_validator : public validator {
   public:
    using visitor::visit;
    bool visit(t_program* const program) final {
      EXPECT_TRUE(validator::visit(program));
      add_error(50, "sadface");
      return true;
    }
  };

  t_program program("/path/to/file.thrift");
  auto errors = run_validator<fake_validator>(&program);
  EXPECT_EQ(1, errors.size());
  EXPECT_EQ("[FAILURE:/path/to/file.thrift:50] sadface", errors.front().str());
}

TEST_F(ValidatorTest, DuplicatedStructNames) {
  t_program program("/path/to/file.thrift");

  program.add_struct(std::make_unique<t_struct>(&program, "Foo"));
  program.add_struct(std::make_unique<t_struct>(&program, "Bar"));
  auto ex = std::make_unique<t_exception>(&program, "Foo");
  ex->set_lineno(42);
  program.add_xception(std::move(ex));

  auto errors = run_validator<struct_names_uniqueness_validator>(&program);
  EXPECT_EQ(1, errors.size());
  EXPECT_EQ(
      "[FAILURE:/path/to/file.thrift:42] Redefinition of type `Foo`.",
      errors.front().str());
}

TEST_F(ValidatorTest, NestedInteractions) {
  t_program program("/path/to/file.thrift");

  auto interaction = std::make_unique<t_interaction>(&program, "foo");
  auto func = std::make_unique<t_function>(
      interaction.get(), "frobnicate", std::make_unique<t_paramlist>(&program));
  func->set_lineno(42);
  interaction->add_function(std::move(func));
  program.add_interaction(std::move(interaction));

  auto errors = run_validator<interactions_validator>(&program);
  EXPECT_EQ(1, errors.size());
  EXPECT_EQ(
      "[FAILURE:/path/to/file.thrift:42] Nested interactions are forbidden.",
      errors.front().str());
}

TEST_F(ValidatorTest, DuplicateInteractions) {
  t_program program("/path/to/file.thrift");

  auto interaction = std::make_unique<t_interaction>(&program, "Clyde");
  auto service = create_fake_service("foo");
  auto func = std::make_unique<t_function>(
      service.get(), "frobnicate", std::make_unique<t_paramlist>(&program));
  func->set_lineno(1);
  func->set_is_interaction_constructor();
  service->add_function(std::move(func));

  func = std::make_unique<t_function>(
      interaction.get(), "interact", std::make_unique<t_paramlist>(&program));
  func->set_lineno(2);
  func->set_is_interaction_constructor();
  service->add_function(std::move(func));

  auto args = std::make_unique<t_paramlist>(&program);
  auto type = std::make_unique<t_base_type>(t_base_type::t_i32());
  args->append(std::make_unique<t_field>(type.get(), "arg"));
  func = std::make_unique<t_function>(
      interaction.get(), "reinteract", std::move(args));
  func->set_lineno(3);
  func->set_is_interaction_constructor();
  service->add_function(std::move(func));

  program.add_service(std::move(service));

  program.add_interaction(std::move(interaction));

  auto errors = run_validator<interactions_validator>(&program);
  EXPECT_EQ(2, errors.size());
  EXPECT_EQ(
      "[FAILURE:/path/to/file.thrift:1] Only interactions can be performed.",
      errors.front().str());
  EXPECT_EQ(
      "[FAILURE:/path/to/file.thrift:3] Service `foo` has multiple methods for creating interaction `Clyde`.",
      errors.at(1).str());
}
