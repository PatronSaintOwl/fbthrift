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

#include <type_traits>
#include <vector>

#include <thrift/compiler/ast/ast_visitor.h>
#include <thrift/compiler/ast/diagnostic_context.h>
#include <thrift/compiler/ast/t_program_bundle.h>

namespace apache {
namespace thrift {
namespace compiler {

// Mutators have mutable access to the AST.
using mutator_context = visitor_context;

// An AST mutator is a ast_visitor that collects diagnostics and can
// change the ast.
class ast_mutator
    : public basic_ast_visitor<false, diagnostic_context&, mutator_context&> {
  using base = basic_ast_visitor<false, diagnostic_context&, mutator_context&>;

 public:
  using base::base;

  void mutate(diagnostic_context& ctx, t_program_bundle& bundle) {
    mutator_context mctx;
    for (auto itr = bundle.programs().rbegin(); itr != bundle.programs().rend();
         ++itr) {
      operator()(ctx, mctx, *itr);
    }
  }
};

// A thin wrapper around a vector of mutators that
// knows how to apply those mutators in order.
struct ast_mutators {
  std::vector<ast_mutator> stages;

  // Access a specific mutator stage, growing the number of stages if needed.
  template <typename T>
  ast_mutator& operator[](T&& stage) {
    static_assert(std::is_enum<T>::value, "");
    auto index = static_cast<size_t>(stage);
    if (stages.size() <= index) {
      stages.resize(index + 1);
    }
    return stages[index];
  }

  void operator()(diagnostic_context& ctx, t_program_bundle& bundle) {
    for (auto& stage : stages) {
      stage.mutate(ctx, bundle);
    }
  }
};

} // namespace compiler
} // namespace thrift
} // namespace apache
