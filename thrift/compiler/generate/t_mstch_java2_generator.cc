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

#include <cctype>
#include <set>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <thrift/compiler/lib/java/util.h>

#include <thrift/compiler/ast/t_typedef.h>
#include <thrift/compiler/gen/cpp/type_resolver.h>
#include <thrift/compiler/generate/t_mstch_generator.h>
#include <thrift/compiler/generate/t_mstch_objects.h>

using namespace std;

namespace apache {
namespace thrift {
namespace compiler {

namespace {
/**
 * Gets the java namespace, throws a runtime error if not found.
 */
std::string get_namespace_or_default(const t_program& prog) {
  const auto& prog_namespace = prog.get_namespace("java2");
  if (prog_namespace != "") {
    return prog_namespace;
  } else {
    throw std::runtime_error{"No namespace 'java2' in " + prog.name()};
  }
}

std::string get_constants_class_name(const t_program& prog) {
  const auto& constant_name = prog.get_namespace("java2.constants");
  if (constant_name == "") {
    return "Constants";
  } else {
    auto java_name_space = get_namespace_or_default(prog);
    std::string java_class_name;
    if (constant_name.rfind(java_name_space) == 0) {
      java_class_name = constant_name.substr(java_name_space.length() + 1);
    } else {
      java_class_name = constant_name;
    }

    if (java_class_name == "" ||
        java_class_name.find('.') != std::string::npos) {
      throw std::runtime_error{
          "Java Constants Class Name `" + java_class_name +
          "` is not well formatted."};
    }

    return java_class_name;
  }
}

template <typename Node>
std::string get_java2_swift_name(const Node* node) {
  return node->get_annotation(
      "java.swift.name", java::mangle_java_name(node->get_name(), false));
}

} // namespace

class t_mstch_java2_generator : public t_mstch_generator {
 public:
  t_mstch_java2_generator(
      t_program* program,
      t_generation_context context,
      const std::map<std::string, std::string>& parsed_options,
      const std::string& /* option_string */)
      : t_mstch_generator(
            program, std::move(context), "java2", parsed_options) {
    out_dir_base_ = "gen-java2";
  }

  void generate_program() override;

 private:
  void set_mstch_generators();

  /*
   * Generate multiple Java items according to the given template. Writes
   * output to package_dir underneath the global output directory.
   */
  template <typename T, typename Generator, typename Cache>
  void generate_rpc_interfaces(
      Generator const* generator,
      Cache& c,
      const t_program* program,
      const std::vector<T*>& items) {
    const auto& id = program->path();
    if (!cache_->programs_.count(id)) {
      cache_->programs_[id] = generators_->program_generator_->generate(
          program, generators_, cache_);
    }
    auto package_dir = boost::filesystem::path{
        java::package_to_path(get_namespace_or_default(*program))};

    for (const T* item : items) {
      auto filename = java::mangle_java_name(item->get_name(), true) + ".java";
      const auto& item_id = id + item->get_name();
      if (!c.count(item_id)) {
        c[item_id] = generator->generate(item, generators_, cache_);
      }

      render_to_file(
          c[item_id], "Service", "services" / package_dir / filename);
    }
  }

  template <typename T, typename Generator, typename Cache>
  void generate_items(
      Generator const* generator,
      Cache& c,
      const t_program* program,
      const std::vector<T*>& items,
      const std::string& tpl_path) {
    const auto& id = program->path();
    if (!cache_->programs_.count(id)) {
      cache_->programs_[id] = generators_->program_generator_->generate(
          program, generators_, cache_);
    }
    auto package_dir = boost::filesystem::path{
        java::package_to_path(get_namespace_or_default(*program))};

    for (const T* item : items) {
      auto filename = java::mangle_java_name(item->get_name(), true) + ".java";
      const auto& item_id = id + item->get_name();
      if (!c.count(item_id)) {
        c[item_id] = generator->generate(item, generators_, cache_);
      }

      render_to_file(
          c[item_id], tpl_path, "data-type" / package_dir / filename);
    }
  }

  /*
   * Generate Service Client implementation - Sync & Async. Writes
   * output to package_dir
   */
  template <typename T, typename Generator, typename Cache>
  void generate_services(
      Generator const* generator,
      Cache& c,
      const t_program* program,
      const std::vector<T*>& services) {
    const auto& id = program->path();
    if (!cache_->programs_.count(id)) {
      cache_->programs_[id] = generators_->program_generator_->generate(
          program, generators_, cache_);
    }
    auto package_dir = boost::filesystem::path{
        java::package_to_path(get_namespace_or_default(*program))};

    // Iterate through services
    for (const T* service : services) {
      auto service_name = java::mangle_java_name(service->get_name(), true);

      // Generate Async to Reactive Wrapper
      auto async_reactive_wrapper_filename =
          service_name + "AsyncReactiveWrapper.java";
      const auto& async_reactive_wrapper_id =
          id + service->get_name() + "AsyncReactiveWrapper";
      if (!c.count(async_reactive_wrapper_id)) {
        c[async_reactive_wrapper_id] =
            generator->generate(service, generators_, cache_);
      }

      render_to_file(
          c[async_reactive_wrapper_id],
          "AsyncReactiveWrapper",
          "services" / package_dir / async_reactive_wrapper_filename);

      // Generate Blocking to Reactive Wrapper
      auto blocking_reactive_wrapper_filename =
          service_name + "BlockingReactiveWrapper.java";
      const auto& blocking_reactive_wrapper_id =
          id + service->get_name() + "BlockingReactiveWrapper";
      if (!c.count(blocking_reactive_wrapper_id)) {
        c[blocking_reactive_wrapper_id] =
            generator->generate(service, generators_, cache_);
      }

      render_to_file(
          c[blocking_reactive_wrapper_id],
          "BlockingReactiveWrapper",
          "services" / package_dir / blocking_reactive_wrapper_filename);

      // Generate Reactive to Async Wrapper
      auto reactive_async_wrapper_filename =
          service_name + "ReactiveAsyncWrapper.java";
      const auto& reactive_async_wrapper_id =
          id + service->get_name() + "ReactiveAsyncWrapper";
      if (!c.count(reactive_async_wrapper_id)) {
        c[reactive_async_wrapper_id] =
            generator->generate(service, generators_, cache_);
      }

      render_to_file(
          c[reactive_async_wrapper_id],
          "ReactiveAsyncWrapper",
          "services" / package_dir / reactive_async_wrapper_filename);

      // Generate Reactive to Blocking Wrapper
      auto reactive_blocking_wrapper_filename =
          service_name + "ReactiveBlockingWrapper.java";
      const auto& reactive_blocking_wrapper_id =
          id + service->get_name() + "ReactiveBlockingWrapper";
      if (!c.count(reactive_blocking_wrapper_id)) {
        c[reactive_blocking_wrapper_id] =
            generator->generate(service, generators_, cache_);
      }

      render_to_file(
          c[reactive_blocking_wrapper_id],
          "ReactiveBlockingWrapper",
          "services" / package_dir / reactive_blocking_wrapper_filename);

      // Generate Reactive Client
      auto reactive_client_filename = service_name + "ReactiveClient.java";
      const auto& reactive_client_wrapper_id =
          id + service->get_name() + "ReactiveClient";
      if (!c.count(reactive_client_wrapper_id)) {
        c[reactive_client_wrapper_id] =
            generator->generate(service, generators_, cache_);
      }

      render_to_file(
          c[reactive_client_wrapper_id],
          "ReactiveClient",
          "services" / package_dir / reactive_client_filename);

      // Generate RpcServerHandler
      auto rpc_server_handler_filename = service_name + "RpcServerHandler.java";
      const auto& rpc_server_handler_id =
          id + service->get_name() + "RpcServerHandler";
      if (!c.count(rpc_server_handler_id)) {
        c[rpc_server_handler_id] =
            generator->generate(service, generators_, cache_);
      }

      render_to_file(
          c[rpc_server_handler_id],
          "RpcServerHandler",
          "services" / package_dir / rpc_server_handler_filename);
    }
  }

  void generate_constants(const t_program* program) {
    if (program->consts().empty()) {
      // Only generate Constants.java if we actually have constants
      return;
    }
    auto name = program->name();
    const auto& prog = cached_program(program);

    auto package_dir = boost::filesystem::path{
        java::package_to_path(get_namespace_or_default(*program))};
    auto constant_file_name = get_constants_class_name(*program) + ".java";
    render_to_file(
        prog, "Constants", "data-type" / package_dir / constant_file_name);
  }

  void generate_placeholder(const t_program* program) {
    auto package_dir = boost::filesystem::path{
        java::package_to_path(get_namespace_or_default(*program))};
    auto placeholder_file_name = ".generated_" + program->name();
    write_output("data-type" / package_dir / placeholder_file_name, "");
    write_output("services" / package_dir / placeholder_file_name, "");
  }
};

class mstch_java2_program : public mstch_program {
 public:
  mstch_java2_program(
      t_program const* program,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION const pos)
      : mstch_program(program, generators, cache, pos) {
    register_methods(
        this,
        {
            {"program:javaPackage", &mstch_java2_program::java_package},
            {"program:constantClassName",
             &mstch_java2_program::constant_class_name},
        });
  }
  mstch::node java_package() { return get_namespace_or_default(*program_); }
  mstch::node constant_class_name() {
    return get_constants_class_name(*program_);
  }
};

class mstch_java2_struct : public mstch_struct {
  // A struct is a "big struct" if it contains > 127 members. The reason for
  // this limit is that we generate exhaustive constructor for Thrift struct
  // but Java methods are limited to 255 arguments (and since long/double
  // types count twice, 127 is a safe threshold).
  static constexpr uint64_t bigStructThreshold = 127;

 public:
  mstch_java2_struct(
      t_struct const* strct,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION const pos)
      : mstch_struct(strct, generators, cache, pos) {
    register_methods(
        this,
        {
            {"struct:javaPackage", &mstch_java2_struct::java_package},
            {"struct:unionFieldTypeUnique?",
             &mstch_java2_struct::is_union_field_type_unique},
            {"struct:asBean?", &mstch_java2_struct::is_as_bean},
            {"struct:isBigStruct?", &mstch_java2_struct::is_BigStruct},
            {"struct:javaCapitalName", &mstch_java2_struct::java_capital_name},
            {"struct:javaAnnotations?",
             &mstch_java2_struct::has_java_annotations},
            {"struct:isUnion?", &mstch_java2_struct::is_struct_union},
            {"struct:javaAnnotations", &mstch_java2_struct::java_annotations},
            {"struct:exceptionMessage", &mstch_java2_struct::exception_message},
            {"struct:needsExceptionMessage?",
             &mstch_java2_struct::needs_exception_message},
            {"struct:enableIsSet?", &mstch_java2_struct::enable_is_set},
        });
  }
  mstch::node java_package() {
    return get_namespace_or_default(*(strct_->program()));
  }
  mstch::node is_struct_union() { return strct_->is_union(); }
  mstch::node is_union_field_type_unique() {
    std::set<std::string> field_types;
    for (const auto& field : strct_->fields()) {
      auto type_name = field.type()->get_full_name();
      std::string type_with_erasure = type_name.substr(0, type_name.find('<'));
      if (field_types.find(type_with_erasure) != field_types.end()) {
        return false;
      } else {
        field_types.insert(type_with_erasure);
      }
    }
    return true;
  }
  mstch::node is_as_bean() {
    if (!strct_->is_xception() && !strct_->is_union()) {
      return strct_->get_annotation("java.swift.mutable") == "true";
    } else {
      return false;
    }
  }

  mstch::node is_BigStruct() {
    return (
        strct_->is_struct() && strct_->fields().size() > bigStructThreshold);
  }

  mstch::node java_capital_name() {
    return java::mangle_java_name(strct_->get_name(), true);
  }
  mstch::node has_java_annotations() {
    return strct_->has_annotation("java.swift.annotations");
  }
  mstch::node java_annotations() {
    return strct_->get_annotation("java.swift.annotations");
  }
  mstch::node exception_message() {
    const auto& field_name_to_use = strct_->get_annotation("message");
    if (const auto* field = strct_->get_field_by_name(field_name_to_use)) {
      return get_java2_swift_name(field);
    }

    throw std::runtime_error{
        "The exception message field '" + field_name_to_use +
        "' is not found in " + strct_->get_name() + "!"};
  }
  // we can only override Throwable's getMessage() if:
  //  1 - there is provided 'message' annotation
  //  2 - there is no struct field named 'message'
  //      (since it will generate getMessage() as well)
  mstch::node needs_exception_message() {
    return strct_->is_xception() && strct_->has_annotation("message") &&
        strct_->get_field_by_name("message") == nullptr;
  }
  mstch::node enable_is_set() {
    return strct_->has_annotation("java.swift.enable_is_set");
  }
};

class mstch_java2_service : public mstch_service {
 public:
  mstch_java2_service(
      t_service const* service,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION const pos)
      : mstch_service(service, generators, cache, pos) {
    register_methods(
        this,
        {
            {"service:javaPackage", &mstch_java2_service::java_package},
            {"service:javaCapitalName",
             &mstch_java2_service::java_capital_name},
            {"service:onewayFunctions",
             &mstch_java2_service::get_oneway_functions},
            {"service:requestResponseFunctions",
             &mstch_java2_service::get_request_response_functions},
            {"service:singleRequestFunctions",
             &mstch_java2_service::get_single_request_functions},
            {"service:streamingFunctions",
             &mstch_java2_service::get_streaming_functions},
            {"service:sinkFunctions", &mstch_java2_service::get_sink_functions},
        });
  }
  mstch::node java_package() {
    return get_namespace_or_default(*(service_->program()));
  }
  mstch::node java_capital_name() {
    return java::mangle_java_name(service_->get_name(), true);
  }
  mstch::node get_oneway_functions() {
    std::vector<t_function*> funcs;
    for (auto func : service_->get_functions()) {
      if (func->is_oneway()) {
        funcs.push_back(func);
      }
    }
    return generate_functions(funcs);
  }
  mstch::node get_request_response_functions() {
    std::vector<t_function*> funcs;
    for (auto func : service_->get_functions()) {
      if (!func->returns_stream() && !func->returns_sink() &&
          !func->get_returntype()->is_service() && !func->is_oneway()) {
        funcs.push_back(func);
      }
    }
    return generate_functions(funcs);
  }
  mstch::node get_single_request_functions() {
    std::vector<t_function*> funcs;
    for (auto func : service_->get_functions()) {
      if (!func->returns_stream() && !func->returns_sink() &&
          !func->get_returntype()->is_service()) {
        funcs.push_back(func);
      }
    }
    return generate_functions(funcs);
  }

  mstch::node get_streaming_functions() {
    std::vector<t_function*> funcs;
    for (auto func : service_->get_functions()) {
      if (func->returns_stream()) {
        funcs.push_back(func);
      }
    }
    return generate_functions(funcs);
  }

  mstch::node get_sink_functions() {
    std::vector<t_function*> funcs;
    for (auto func : service_->get_functions()) {
      if (func->returns_sink()) {
        funcs.push_back(func);
      }
    }
    return generate_functions(funcs);
  }
};

class mstch_java2_function : public mstch_function {
 public:
  mstch_java2_function(
      t_function const* function,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION const pos)
      : mstch_function(function, generators, cache, pos) {
    register_methods(
        this,
        {
            {"function:javaName", &mstch_java2_function::java_name},
            {"function:voidType", &mstch_java2_function::is_void_type},
            {"function:nestedDepth", &mstch_java2_function::get_nested_depth},
            {"function:nestedDepth++",
             &mstch_java2_function::increment_nested_depth},
            {"function:nestedDepth--",
             &mstch_java2_function::decrement_nested_depth},
            {"function:isFirstDepth?", &mstch_java2_function::is_first_depth},
            {"function:prevNestedDepth",
             &mstch_java2_function::preceding_nested_depth},
            {"function:isNested?",
             &mstch_java2_function::get_nested_container_flag},
            {"function:setIsNested",
             &mstch_java2_function::set_nested_container_flag},
            {"function:unsetIsNested",
             &mstch_java2_function::unset_nested_container_flag},
        });
  }

  int32_t nestedDepth = 0;
  bool isNestedContainerFlag = false;

  mstch::node get_nested_depth() { return nestedDepth; }
  mstch::node preceding_nested_depth() { return (nestedDepth - 1); }
  mstch::node is_first_depth() { return (nestedDepth == 1); }
  mstch::node get_nested_container_flag() { return isNestedContainerFlag; }
  mstch::node set_nested_container_flag() {
    isNestedContainerFlag = true;
    return mstch::node();
  }
  mstch::node unset_nested_container_flag() {
    isNestedContainerFlag = false;
    return mstch::node();
  }
  mstch::node increment_nested_depth() {
    nestedDepth++;
    return mstch::node();
  }
  mstch::node decrement_nested_depth() {
    nestedDepth--;
    return mstch::node();
  }

  mstch::node java_name() {
    return java::mangle_java_name(function_->get_name(), false);
  }

  mstch::node is_void_type() { return function_->get_returntype()->is_void(); }
};

class mstch_java2_field : public mstch_field {
 public:
  mstch_java2_field(
      t_field const* field,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION const pos,
      int32_t index,
      field_generator_context const* field_context)
      : mstch_field(field, generators, cache, pos, index, field_context) {
    register_methods(
        this,
        {{"field:javaName", &mstch_java2_field::java_name},
         {"field:javaCapitalName", &mstch_java2_field::java_capital_name},
         {"field:javaDefaultValue", &mstch_java2_field::java_default_value},
         {"field:javaAllCapsName", &mstch_java2_field::java_all_caps_name},
         {"field:recursive?", &mstch_java2_field::is_recursive_reference},
         {"field:negativeId?", &mstch_java2_field::is_negative_id},
         {"field:javaAnnotations?", &mstch_java2_field::has_java_annotations},
         {"field:javaAnnotations", &mstch_java2_field::java_annotations},
         {"field:javaTFieldName", &mstch_java2_field::java_tfield_name},
         {"field:isNullableOrOptionalNotEnum?",
          &mstch_java2_field::is_nullable_or_optional_not_enum},
         {"field:nestedDepth", &mstch_java2_field::get_nested_depth},
         {"field:nestedDepth++", &mstch_java2_field::increment_nested_depth},
         {"field:nestedDepth--", &mstch_java2_field::decrement_nested_depth},
         {"field:isFirstDepth?", &mstch_java2_field::is_first_depth},
         {"field:prevNestedDepth", &mstch_java2_field::preceding_nested_depth},
         {"field:isContainer?", &mstch_java2_field::is_container},
         {"field:isNested?", &mstch_java2_field::get_nested_container_flag},
         {"field:setIsNested", &mstch_java2_field::set_nested_container_flag},
         {"field:typeFieldName", &mstch_java2_field::type_field_name},
         {"field:isSensitive?", &mstch_java2_field::is_sensitive},
         {"field:hasInitialValue?", &mstch_java2_field::has_initial_value},
         {"field:isPrimitive?", &mstch_java2_field::is_primitive},
         {"field:adapterClassName",
          &mstch_java2_field::get_structured_adapter_class_name},
         {"field:typeClassName",
          &mstch_java2_field::get_structured_type_class_name},
         {"field:terse_write?", &mstch_java2_field::terse_write},
         {"field:hasAdapter?", &mstch_java2_field::is_typedef_adapter}});
  }

  int32_t nestedDepth = 0;
  bool isNestedContainerFlag = false;

  mstch::node terse_write() {
    return field_->get_req() == t_field::e_req::terse;
  }

  mstch::node is_typedef_adapter() {
    auto type = field_->get_type();
    if (type->is_typedef()) {
      auto has_annotation = type->find_structured_annotation_or_null(
          "facebook.com/thrift/annotation/java/Adapter");
      return has_annotation != nullptr;
    } else {
      return false;
    }
  }

  mstch::node get_structured_adapter_class_name() {
    return get_structed_annotation_attribute("adapterClassName");
  }

  mstch::node get_structured_type_class_name() {
    return get_structed_annotation_attribute("typeClassName");
  }

  mstch::node get_structed_annotation_attribute(const std::string& field) {
    auto type = field_->get_type();
    if (auto annotation = type->find_structured_annotation_or_null(
            "facebook.com/thrift/annotation/java/Adapter")) {
      for (const auto& item : annotation->value()->get_map()) {
        if (item.first->get_string() == field) {
          return item.second->get_string();
        }
      }
    }

    return nullptr;
  }

  mstch::node has_initial_value() {
    if (field_->get_req() == t_field::e_req::optional) {
      // default values are ignored for optional fields
      return false;
    }
    return field_->get_value();
  }
  mstch::node get_nested_depth() { return nestedDepth; }
  mstch::node preceding_nested_depth() { return (nestedDepth - 1); }
  mstch::node is_first_depth() { return (nestedDepth == 1); }
  mstch::node get_nested_container_flag() { return isNestedContainerFlag; }
  mstch::node set_nested_container_flag() {
    isNestedContainerFlag = true;
    return mstch::node();
  }
  mstch::node increment_nested_depth() {
    nestedDepth++;
    return mstch::node();
  }
  mstch::node decrement_nested_depth() {
    nestedDepth--;
    return mstch::node();
  }
  mstch::node is_primitive() {
    auto type = field_->get_type()->get_true_type();
    return type->is_void() || type->is_bool() || type->is_byte() ||
        type->is_i16() || type->is_i32() || type->is_i64() ||
        type->is_double() || type->is_float();
  }

  mstch::node is_nullable_or_optional_not_enum() {
    if (field_->get_req() == t_field::e_req::optional) {
      return true;
    }
    const t_type* field_type = field_->get_type()->get_true_type();
    return !(
        field_type->is_bool() || field_type->is_byte() ||
        field_type->is_float() || field_type->is_i16() ||
        field_type->is_i32() || field_type->is_i64() ||
        field_type->is_double() || field_type->is_enum());
  }

  mstch::node is_container() {
    return field_->get_type()->get_true_type()->is_container();
  }
  mstch::node java_name() { return get_java2_swift_name(field_); }

  mstch::node type_field_name() {
    auto type_name = field_->get_type()->get_full_name();
    return java::mangle_java_name(type_name, true);
  }

  mstch::node java_tfield_name() {
    return constant_name(field_->get_name()) + "_FIELD_DESC";
  }
  mstch::node java_capital_name() {
    return java::mangle_java_name(
        field_->get_annotation("java.swift.name", &field_->get_name()), true);
  }
  mstch::node java_all_caps_name() {
    auto field_name = field_->get_name();
    boost::to_upper(field_name);
    return field_name;
  }
  mstch::node java_default_value() { return default_value_for_field(field_); }
  mstch::node is_recursive_reference() {
    return field_->get_annotation("swift.recursive_reference") == "true";
  }
  mstch::node is_negative_id() { return field_->get_key() < 0; }
  std::string default_value_for_field(const t_field* field) {
    if (field_->get_req() == t_field::e_req::optional) {
      return "null";
    }
    return default_value_for_type(field->get_type());
  }
  std::string default_value_for_type(const t_type* type) {
    if (type->is_typedef()) {
      auto typedef_type = dynamic_cast<const t_typedef*>(type)->get_type();
      return default_value_for_type(typedef_type);
    } else {
      if (type->is_byte() || type->is_i16() || type->is_i32()) {
        return "0";
      } else if (type->is_i64()) {
        return "0L";
      } else if (type->is_float()) {
        return "0.f";
      } else if (type->is_double()) {
        return "0.";
      } else if (type->is_bool()) {
        return "false";
      } else if (type->is_enum()) {
        // we use fromInteger(0) as default value as it may be null or the enum
        // entry for 0.
        auto javaNamespace = get_namespace_or_default(*(type->program()));
        auto enumType = java::mangle_java_name(type->get_name(), true);
        return javaNamespace + "." + enumType + ".fromInteger(0)";
      }
      return "null";
    }
  }
  mstch::node has_java_annotations() {
    return field_->has_annotation("java.swift.annotations");
  }
  mstch::node is_sensitive() {
    return field_->has_annotation("java.sensitive");
  }
  std::string constant_name(string name) {
    string constant_str;

    bool is_first = true;
    bool was_previous_char_upper = false;
    for (string::iterator iter = name.begin(); iter != name.end(); ++iter) {
      string::value_type character = (*iter);
      bool is_upper = isupper(character);
      if (is_upper && !is_first && !was_previous_char_upper) {
        constant_str += '_';
      }
      constant_str += toupper(character);
      is_first = false;
      was_previous_char_upper = is_upper;
    }
    return constant_str;
  }
  mstch::node java_annotations() {
    return field_->get_annotation("java.swift.annotations");
  }
};

class mstch_java2_enum : public mstch_enum {
 public:
  mstch_java2_enum(
      t_enum const* enm,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION const pos)
      : mstch_enum(enm, generators, cache, pos) {
    register_methods(
        this,
        {
            {"enum:javaPackage", &mstch_java2_enum::java_package},
            {"enum:javaCapitalName", &mstch_java2_enum::java_capital_name},
            {"enum:skipEnumNameMap?",
             &mstch_java2_enum::java_skip_enum_name_map},
        });
  }
  mstch::node java_package() {
    return get_namespace_or_default(*(enm_->program()));
  }
  mstch::node java_capital_name() {
    return java::mangle_java_name(enm_->get_name(), true);
  }
  mstch::node java_skip_enum_name_map() {
    return enm_->has_annotation("java.swift.skip_enum_name_map");
  }
};

class mstch_java2_enum_value : public mstch_enum_value {
 public:
  mstch_java2_enum_value(
      t_enum_value const* enm_value,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION const pos)
      : mstch_enum_value(enm_value, generators, cache, pos) {
    register_methods(
        this,
        {
            {"enum_value:javaConstantName",
             &mstch_java2_enum_value::java_constant_name},
        });
  }
  mstch::node java_constant_name() {
    return java::mangle_java_constant_name(enm_value_->get_name());
  }
};

class mstch_java2_const : public mstch_const {
 public:
  mstch_java2_const(
      t_const const* cnst,
      t_const const* current_const,
      t_type const* expected_type,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION const pos,
      int32_t index,
      t_field const* field)
      : mstch_const(
            cnst,
            current_const,
            expected_type,
            generators,
            cache,
            pos,
            index,
            field) {
    register_methods(
        this,
        {
            {"constant:javaCapitalName", &mstch_java2_const::java_capital_name},
            {"constant:javaFieldName", &mstch_java2_const::java_field_name},
            {"constant:javaIgnoreConstant?",
             &mstch_java2_const::java_ignore_constant},
        });
  }
  mstch::node java_capital_name() {
    return java::mangle_java_constant_name(cnst_->get_name());
  }
  mstch::node java_field_name() {
    return java::mangle_java_name(field_->get_name(), true);
  }
  mstch::node java_ignore_constant() {
    // we have to ignore constants if they are enums that we handled as ints, as
    // we don't have the constant values to work with.
    if (cnst_->get_type()->is_map()) {
      t_map* map = (t_map*)cnst_->get_type();
      if (map->get_key_type()->is_enum()) {
        return map->get_key_type()->has_annotation(
            "java.swift.skip_enum_name_map");
      }
    }
    if (cnst_->get_type()->is_list()) {
      t_list* list = (t_list*)cnst_->get_type();
      if (list->get_elem_type()->is_enum()) {
        return list->get_elem_type()->has_annotation(
            "java.swift.skip_enum_name_map");
      }
    }
    if (cnst_->get_type()->is_set()) {
      t_set* set = (t_set*)cnst_->get_type();
      if (set->get_elem_type()->is_enum()) {
        return set->get_elem_type()->has_annotation(
            "java.swift.skip_enum_name_map");
      }
    }
    return mstch::node();
  }
};

class mstch_java2_const_value : public mstch_const_value {
 public:
  mstch_java2_const_value(
      t_const_value const* const_value,
      t_const const* current_const,
      t_type const* expected_type,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t index)
      : mstch_const_value(
            const_value,
            current_const,
            expected_type,
            generators,
            cache,
            pos,
            index) {
    register_methods(
        this,
        {
            {"value:quotedString", &mstch_java2_const_value::quote_java_string},
            {"value:javaEnumValueName",
             &mstch_java2_const_value::java_enum_value_name},
        });
  }
  mstch::node quote_java_string() {
    return java::quote_java_string(const_value_->get_string());
  }
  mstch::node java_enum_value_name() {
    if (type_ == cv::CV_INTEGER && const_value_->is_enum()) {
      const t_enum_value* enum_value = const_value_->get_enum_value();
      if (enum_value != nullptr) {
        return java::mangle_java_constant_name(enum_value->get_name());
      }
      return "fromInteger(" + std::to_string(const_value_->get_integer()) + ")";
    }
    return mstch::node();
  }
  bool same_type_as_expected() const override { return true; }
};

class mstch_java2_type : public mstch_type {
 public:
  mstch_java2_type(
      t_type const* type,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION const pos)
      : mstch_type(type, generators, cache, pos) {
    register_methods(
        this,
        {
            {"type:primitive?", &mstch_java2_type::is_primitive},
            {"type:isContainer?", &mstch_java2_type::is_container_type},
            {"type:javaType", &mstch_java2_type::java_type},
            {"type:setIsMapKey", &mstch_java2_type::set_is_map_key},
            {"type:isMapKey?", &mstch_java2_type::get_map_key_flag},
            {"type:setIsMapValue", &mstch_java2_type::set_is_map_value},
            {"type:isMapValue?", &mstch_java2_type::get_map_value_flag},
            {"type:isBinaryString?", &mstch_java2_type::is_binary_string},
            {"type:setIsNotMap", &mstch_java2_type::set_is_not_map},
        });
  }
  bool isMapValueFlag = false;
  bool isMapKeyFlag = false;

  mstch::node set_is_not_map() {
    isMapValueFlag = false;
    isMapKeyFlag = false;
    return mstch::node();
  }
  mstch::node get_map_value_flag() { return isMapValueFlag; }
  mstch::node get_map_key_flag() { return isMapKeyFlag; }
  mstch::node set_is_map_value() {
    isMapValueFlag = true;
    return mstch::node();
  }
  mstch::node set_is_map_key() {
    isMapKeyFlag = true;
    return mstch::node();
  }

  mstch::node is_container_type() {
    return type_->get_true_type()->is_container();
  }

  mstch::node is_primitive() {
    return type_->is_void() || type_->is_bool() || type_->is_byte() ||
        type_->is_i16() || type_->is_i32() || type_->is_i64() ||
        type_->is_double() || type_->is_float();
  }
  mstch::node java_type() {
    return type_->get_true_type()->get_annotation("java.swift.type");
  }
  mstch::node is_binary_string() {
    return type_->get_true_type()->get_annotation("java.swift.binary_string");
  }
};

class program_java2_generator : public program_generator {
 public:
  program_java2_generator() = default;
  ~program_java2_generator() override = default;
  std::shared_ptr<mstch_base> generate(
      t_program const* program,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t /*index*/) const override {
    return std::make_shared<mstch_java2_program>(
        program, generators, cache, pos);
  }
};

class struct_java2_generator : public struct_generator {
 public:
  explicit struct_java2_generator() = default;
  ~struct_java2_generator() override = default;
  std::shared_ptr<mstch_base> generate(
      t_struct const* strct,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t /*index*/) const override {
    return std::make_shared<mstch_java2_struct>(strct, generators, cache, pos);
  }
};

class service_java2_generator : public service_generator {
 public:
  explicit service_java2_generator() = default;
  ~service_java2_generator() override = default;
  std::shared_ptr<mstch_base> generate(
      t_service const* service,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t /*index*/) const override {
    return std::make_shared<mstch_java2_service>(
        service, generators, cache, pos);
  }
};

class function_java2_generator : public function_generator {
 public:
  function_java2_generator() = default;
  ~function_java2_generator() override = default;
  std::shared_ptr<mstch_base> generate(
      t_function const* function,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t /*index*/) const override {
    return std::make_shared<mstch_java2_function>(
        function, generators, cache, pos);
  }
};

class field_java2_generator : public field_generator {
 public:
  field_java2_generator() = default;
  ~field_java2_generator() override = default;
  std::shared_ptr<mstch_base> generate(
      t_field const* field,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t index,
      field_generator_context const* field_context) const override {
    return std::make_shared<mstch_java2_field>(
        field, generators, cache, pos, index, field_context);
  }
};

class enum_java2_generator : public enum_generator {
 public:
  explicit enum_java2_generator() = default;
  ~enum_java2_generator() override = default;
  std::shared_ptr<mstch_base> generate(
      t_enum const* enm,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t /*index*/) const override {
    return std::make_shared<mstch_java2_enum>(enm, generators, cache, pos);
  }
};

class enum_value_java2_generator : public enum_value_generator {
 public:
  enum_value_java2_generator() = default;
  ~enum_value_java2_generator() override = default;
  std::shared_ptr<mstch_base> generate(
      t_enum_value const* enm_value,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t /*index*/) const override {
    return std::make_shared<mstch_java2_enum_value>(
        enm_value, generators, cache, pos);
  }
};

class type_java2_generator : public type_generator {
 public:
  type_java2_generator() = default;
  ~type_java2_generator() override = default;
  std::shared_ptr<mstch_base> generate(
      t_type const* type,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t /*index*/) const override {
    return std::make_shared<mstch_java2_type>(type, generators, cache, pos);
  }
};

class const_java2_generator : public const_generator {
 public:
  const_java2_generator() = default;
  ~const_java2_generator() override = default;
  std::shared_ptr<mstch_base> generate(
      t_const const* cnst,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t index,
      t_const const* current_const,
      t_type const* expected_type,
      t_field const* field) const override {
    return std::make_shared<mstch_java2_const>(
        cnst,
        current_const,
        expected_type,
        generators,
        cache,
        pos,
        index,
        field);
  }
};

class const_value_java2_generator : public const_value_generator {
 public:
  const_value_java2_generator() = default;
  ~const_value_java2_generator() override = default;
  std::shared_ptr<mstch_base> generate(
      t_const_value const* const_value,
      std::shared_ptr<mstch_generators const> generators,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t index,
      t_const const* current_const,
      t_type const* expected_type) const override {
    return std::make_shared<mstch_java2_const_value>(
        const_value,
        current_const,
        expected_type,
        generators,
        cache,
        pos,
        index);
  }
};

void t_mstch_java2_generator::generate_program() {
  set_mstch_generators();

  auto name = get_program()->name();
  const auto& id = get_program()->path();
  if (!cache_->programs_.count(id)) {
    cache_->programs_[id] = generators_->program_generator_->generate(
        get_program(), generators_, cache_);
  }

  generate_items(
      generators_->struct_generator_.get(),
      cache_->structs_,
      get_program(),
      get_program()->objects(),
      "Object");
  generate_rpc_interfaces(
      generators_->service_generator_.get(),
      cache_->services_,
      get_program(),
      get_program()->services());
  generate_services(
      generators_->service_generator_.get(),
      cache_->services_,
      get_program(),
      get_program()->services());
  generate_items(
      generators_->enum_generator_.get(),
      cache_->enums_,
      get_program(),
      get_program()->enums(),
      "Enum");
  generate_constants(get_program());
  generate_placeholder(get_program());
}

void t_mstch_java2_generator::set_mstch_generators() {
  generators_->set_program_generator(
      std::make_unique<program_java2_generator>());
  generators_->set_struct_generator(std::make_unique<struct_java2_generator>());
  generators_->set_service_generator(
      std::make_unique<service_java2_generator>());
  generators_->set_function_generator(
      std::make_unique<function_java2_generator>());
  generators_->set_field_generator(std::make_unique<field_java2_generator>());
  generators_->set_enum_generator(std::make_unique<enum_java2_generator>());
  generators_->set_enum_value_generator(
      std::make_unique<enum_value_java2_generator>());
  generators_->set_type_generator(std::make_unique<type_java2_generator>());
  generators_->set_const_generator(std::make_unique<const_java2_generator>());
  generators_->set_const_value_generator(
      std::make_unique<const_value_java2_generator>());
}

THRIFT_REGISTER_GENERATOR(mstch_java2, "Java", "");

} // namespace compiler
} // namespace thrift
} // namespace apache
