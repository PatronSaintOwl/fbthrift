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

#pragma once

#include <cassert>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include <thrift/compiler/ast/node_list.h>
#include <thrift/compiler/ast/t_base_type.h>
#include <thrift/compiler/ast/t_const.h>
#include <thrift/compiler/ast/t_enum.h>
#include <thrift/compiler/ast/t_exception.h>
#include <thrift/compiler/ast/t_include.h>
#include <thrift/compiler/ast/t_interaction.h>
#include <thrift/compiler/ast/t_list.h>
#include <thrift/compiler/ast/t_map.h>
#include <thrift/compiler/ast/t_named.h>
#include <thrift/compiler/ast/t_package.h>
#include <thrift/compiler/ast/t_scope.h>
#include <thrift/compiler/ast/t_service.h>
#include <thrift/compiler/ast/t_set.h>
#include <thrift/compiler/ast/t_sink.h>
#include <thrift/compiler/ast/t_stream.h>
#include <thrift/compiler/ast/t_struct.h>
#include <thrift/compiler/ast/t_typedef.h>

namespace apache {
namespace thrift {
namespace compiler {

enum class t_statement_type {
  standard_header,
  program_header,
  definition,
};

enum class t_header_type {
  standard = int(t_statement_type::standard_header),
  // All annotations on headers of these types are
  // attributed to the program.
  program = int(t_statement_type::program_header),
};

/**
 * Top level class representing an entire thrift program.
 */
class t_program : public t_named {
 public:
  // The value used when an offset is not specified/unknown.
  static constexpr auto noffset = static_cast<size_t>(-1);

  /**
   * Constructor for t_program
   *
   * @param path - A *.thrift file path.
   */
  explicit t_program(std::string path)
      : t_program(std::move(path), std::make_shared<t_scope>()) {}

  void set_package(t_package package) { package_ = std::move(package); }
  const t_package package() const { return package_; }

  // Defintions, in the order they were added.
  node_list_view<t_named> definitions() { return definitions_; }
  node_list_view<const t_named> definitions() const { return definitions_; }
  void add_definition(std::unique_ptr<t_named> definition);

  // Concrete instantiation of a templated type.
  node_list_view<t_templated_type> type_instantiations() { return type_insts_; }
  node_list_view<const t_templated_type> type_instantiations() const {
    return type_insts_;
  }
  void add_type_instantiation(std::unique_ptr<t_templated_type> type_inst) {
    assert(type_inst != nullptr);
    type_insts_.emplace_back(std::move(type_inst));
  }

  void add_placeholder_typedef(std::unique_ptr<t_placeholder_typedef> ptd) {
    assert(ptd != nullptr);
    placeholder_typedefs_.push_back(ptd.get());
    nodes_.push_back(std::move(ptd));
  }

  void add_unnamed_typedef(std::unique_ptr<t_typedef> td) {
    assert(td != nullptr);
    nodes_.push_back(std::move(td));
  }

  void add_unnamed_type(std::unique_ptr<t_type> ut) {
    assert(ut != nullptr);
    // Should use add_type_instantiation
    assert(dynamic_cast<t_templated_type*>(ut.get()) == nullptr);
    // Should use add_placeholder_typedef
    assert(dynamic_cast<t_placeholder_typedef*>(ut.get()) == nullptr);
    // Should use add_unnamed_typedef
    assert(dynamic_cast<t_typedef*>(ut.get()) == nullptr);
    nodes_.push_back(std::move(ut));
  }

  /**
   * Get program elements by kind.
   */
  const std::vector<t_typedef*>& typedefs() const { return typedefs_; }
  const std::vector<t_enum*>& enums() const { return enums_; }
  const std::vector<t_const*>& consts() const { return consts_; }
  const std::vector<t_struct*>& structs() const { return structs_; }
  const std::vector<t_exception*>& exceptions() const { return exceptions_; }
  const std::vector<t_struct*>& objects() const { return objects_; }
  const std::vector<t_service*>& services() const { return services_; }
  const std::vector<t_placeholder_typedef*>& placeholder_typedefs() const {
    return placeholder_typedefs_;
  }
  const std::vector<t_interaction*>& interactions() const {
    return interactions_;
  }

  void add_cpp_include(std::string path) {
    cpp_includes_.push_back(std::move(path));
  }

  /**
   * Language neutral namespace/packaging
   *
   * @param language - The target language (i.e. py, cpp) to generate code
   * @param name_space - //TODO add definition of name_space
   */
  void set_namespace(std::string language, std::string name_space) {
    namespaces_.emplace(language, name_space);
  }

  /**
   * t_program getters
   */
  const std::string& path() const { return path_; }

  const std::string& include_prefix() const { return include_prefix_; }

  /**
   * Returns a list of includes that the program contains. Each include is of
   * type t_include*, and contains information about the program included, as
   * well as the location of the include statement.
   */
  const std::vector<t_include*>& includes() const { return includes_; }

  /**
   * Returns a list of programs that are included by this program.
   */
  std::vector<t_program*> get_included_programs() const {
    std::vector<t_program*> included_programs;
    for (auto const& include : includes_) {
      included_programs.push_back(include->get_program());
    }
    return included_programs;
  }

  t_scope* scope() const { return scope_.get(); }

  // Only used in py_frontend.tcc
  const std::map<std::string, std::string>& namespaces() const {
    return namespaces_;
  }

  // Only used in t_cpp_generator
  const std::vector<std::string>& cpp_includes() const { return cpp_includes_; }

  /**
   * Outputs a reference to the namespace corresponding to the
   * key(language) in the namespaces_ map.
   *
   * @param language - The target language (i.e. py, cpp) to generate code
   */
  const std::string& get_namespace(const std::string& language) const;

  /**
   * This creates a new program for every thrift file in an
   * include statement and sets their include_prefix by parsing
   * the directory in which they were included from
   *
   * @param path         - A full thrift file path
   * @param include_site - A full or relative thrift file path
   * @param lineno       - The line number of the include statement
   */
  std::unique_ptr<t_program> add_include(
      std::string path, std::string include_site, int lineno);

  void add_include(std::unique_ptr<t_include> include) {
    includes_.push_back(include.get());
    nodes_.push_back(std::move(include));
  }

  /**
   * This sets the directory path of the current thrift program,
   * adding checks to format it into a correct directory path
   *
   * @param include_prefix - The directory path of a thrift include statement
   */
  void set_include_prefix(std::string include_prefix);

  /**
   *  Obtains the name of a thrift file from the full file path
   *
   * @param path - A *.thrift file path
   */
  std::string compute_name_from_file_path(std::string path);

  // Add the byte offset, from the beginning of the file, for the next new line
  // ('\n').
  void add_line_offset(size_t offset) {
    assert(line_to_offset_.empty() || offset > line_to_offset_.back());
    line_to_offset_.push_back(offset);
  }
  /**
   * Computes the bytes offset for the given line, based on the offsets provied
   * via `add_line_offset`
   *
   * @param line The 1-based line number.
   * @param line_offset Optional additional 0-based byte offset to add to the
   * result, iff line offset could be determined.
   *
   * @returns The byte offset, or `noffset` if line==0 or no offset data was
   * provided for the given for line via `add_line_offset`.
   */
  size_t get_byte_offset(size_t line, size_t line_offset = 0) const noexcept;

 private:
  t_package package_;

  // All the elements owned by this program.
  node_list<t_node> nodes_;
  node_list<t_named> definitions_;
  node_list<t_templated_type> type_insts_;

  /**
   * Components to generate code for
   */
  std::vector<t_typedef*> typedefs_;
  std::vector<t_enum*> enums_;
  std::vector<t_const*> consts_;
  std::vector<t_struct*> structs_;
  std::vector<t_exception*> exceptions_;
  std::vector<t_service*> services_;
  std::vector<t_include*> includes_;
  std::vector<t_interaction*> interactions_;
  std::vector<t_placeholder_typedef*> placeholder_typedefs_;
  std::vector<t_struct*> objects_; // structs_ + exceptions_

  std::string path_; // initialized in ctor init-list
  std::string include_prefix_;
  std::map<std::string, std::string> namespaces_;
  std::vector<std::string> cpp_includes_;
  std::shared_ptr<t_scope> scope_;
  std::vector<size_t> line_to_offset_{0};

  t_program(std::string path, std::shared_ptr<t_scope> scope)
      : path_(std::move(path)), scope_(std::move(scope)) {
    set_name(compute_name_from_file_path(path_));
  }

  // TODO(afuller): Remove everything below this comment. It is only provided
  // for backwards compatibility.
 public:
  void add_typedef(std::unique_ptr<t_typedef> node) {
    add_definition(std::move(node));
  }
  void add_enum(std::unique_ptr<t_enum> node) {
    add_definition(std::move(node));
  }
  void add_const(std::unique_ptr<t_const> node) {
    add_definition(std::move(node));
  }
  void add_struct(std::unique_ptr<t_struct> node) {
    add_definition(std::move(node));
  }
  void add_exception(std::unique_ptr<t_exception> node) {
    add_definition(std::move(node));
  }
  void add_service(std::unique_ptr<t_service> node) {
    add_definition(std::move(node));
  }
  void add_interaction(std::unique_ptr<t_interaction> node) {
    add_definition(std::move(node));
  }
  void add_xception(std::unique_ptr<t_exception> tx) {
    add_exception(std::move(tx));
  }
  const std::vector<t_exception*>& xceptions() const { return exceptions(); }

  // Looks for an annotation on the given node, then if not found, and the node
  // is not generated, looks for the same annotation on the program.
  const t_const* inherit_annotation_or_null(
      const t_named& node, const char* uri) const {
    if (const t_const* annot = node.find_structured_annotation_or_null(uri)) {
      return annot;
    } else if (node.generated()) { // Generated nodes do not inherit.
      return nullptr;
    }
    return find_structured_annotation_or_null(uri);
  }
};

} // namespace compiler
} // namespace thrift
} // namespace apache
