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

#include <thrift/compiler/ast/t_program.h>

#include <cctype>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace apache {
namespace thrift {
namespace compiler {

void t_program::add_definition(std::unique_ptr<t_named> definition) {
  assert(definition != nullptr);

  // Resolve Thrift URI if need be.
  if (definition->uri().empty()) { // Inherit from package.
    definition->set_uri(package_.get_uri(definition->name()));
    if (auto* uri = definition->find_annotation_or_null("thrift.uri")) {
      definition->set_uri(*uri); // Manual override.
    }
  }

  // Index the node.
  if (auto* node = dynamic_cast<t_exception*>(definition.get())) {
    objects_.push_back(node);
    exceptions_.push_back(node);
  } else if (auto* node = dynamic_cast<t_struct*>(definition.get())) {
    objects_.push_back(node);
    structs_.push_back(node);
  } else if (auto* node = dynamic_cast<t_interaction*>(definition.get())) {
    interactions_.push_back(node);
  } else if (auto* node = dynamic_cast<t_service*>(definition.get())) {
    services_.push_back(node);
  } else if (auto* node = dynamic_cast<t_enum*>(definition.get())) {
    enums_.push_back(node);
  } else if (auto* node = dynamic_cast<t_typedef*>(definition.get())) {
    typedefs_.push_back(node);
  } else if (auto* node = dynamic_cast<t_const*>(definition.get())) {
    consts_.push_back(node);
  }

  // Transfer ownership of the definition.
  definitions_.push_back(std::move(definition));
}

const std::string& t_program::get_namespace(const std::string& language) const {
  auto pos = namespaces_.find(language);
  static const auto& kEmpty = *new std::string();
  return (pos != namespaces_.end() ? pos->second : kEmpty);
}

std::unique_ptr<t_program> t_program::add_include(
    std::string path, std::string include_site, int lineno) {
  auto program = std::unique_ptr<t_program>(new t_program(path, scope_));

  std::string include_prefix;
  const auto last_slash = include_site.find_last_of("/\\");
  if (last_slash != std::string::npos) {
    include_prefix = include_site.substr(0, last_slash);
  }

  program->set_include_prefix(include_prefix);

  auto include = std::make_unique<t_include>(program.get());
  include->set_lineno(lineno);

  add_include(std::move(include));

  return program;
}

void t_program::set_include_prefix(std::string include_prefix) {
  include_prefix_ = std::move(include_prefix);

  int len = include_prefix_.size();
  if (len > 0 && include_prefix_[len - 1] != '/') {
    include_prefix_ += '/';
  }
}

std::string t_program::compute_name_from_file_path(std::string path) {
  std::string::size_type slash = path.find_last_of("/\\");
  if (slash != std::string::npos) {
    path = path.substr(slash + 1);
  }
  std::string::size_type dot = path.rfind('.');
  if (dot != std::string::npos) {
    path = path.substr(0, dot);
  }
  return path;
}

size_t t_program::get_byte_offset(
    size_t line, size_t line_offset) const noexcept {
  if (line == 0) {
    return noffset; // Not specified.
  }
  if (line > line_to_offset_.size()) {
    return noffset; // No offset data provided.
  }
  return line_to_offset_[line - 1] + line_offset;
}

} // namespace compiler
} // namespace thrift
} // namespace apache
