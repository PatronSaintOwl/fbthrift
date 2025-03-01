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

#include <folly/FileUtil.h>

#include <thrift/compiler/codemod/file_manager.h>

namespace apache {
namespace thrift {
namespace compiler {
namespace codemod {

void file_manager::apply_replacements() {
  size_t prev_end = 0;
  std::string new_content;

  // Perform the replacements.
  for (const auto& r : replacements_) {
    // Only apply replacements that are not overlapped with previous one.
    if (prev_end <= r.begin_pos) {
      new_content.append(old_content_, prev_end, r.begin_pos - prev_end);
      new_content += r.new_content;
      prev_end = r.end_pos;
    }
  }

  // Get the last part of the file.
  new_content += old_content_.substr(prev_end);

  // No need for catching nor throwing here since if file doesn't exist
  // the constructor itself will throw an exception.
  folly::writeFile(new_content, program_->path().c_str());
}

// NOTE: Rely on automated formatting to fix formatting issues.
void file_manager::remove(const t_annotation& annotation) {
  auto begin_offset = annotation.second.src_range.begin().offset();
  auto end_offset = annotation.second.src_range.end().offset();

  expand_over_whitespaces(begin_offset, end_offset);

  if (end_offset < old_content_.length() && old_content_[end_offset] == ',') {
    end_offset++;
  } else if (
      begin_offset >= 1 && end_offset < old_content_.length() &&
      old_content_[begin_offset - 1] == '(' &&
      old_content_[end_offset] == ')') {
    --begin_offset;
    ++end_offset;
  }

  add({begin_offset, end_offset, ""});
}

size_t file_manager::get_last_include_offset() const {
  int lineno = 0;

  for (const auto* include : program_->includes()) {
    lineno = std::max(lineno, include->lineno());
  }

  return program_->get_byte_offset(lineno + 1);
}

void file_manager::expand_over_whitespaces(
    size_t& begin_offset, size_t& end_offset) const noexcept {
  while (begin_offset >= 1 && std::isspace(old_content_[begin_offset - 1])) {
    begin_offset--;
  }

  while (end_offset < old_content_.length() &&
         std::isspace(old_content_[end_offset])) {
    end_offset++;
  }
}

void file_manager::add_include(std::string include) {
  if (includes_.find(include) == includes_.end()) {
    std::string curr_include = "include \"" + include + "\"\n";
    includes_.insert(std::move(include));
    auto offset = get_last_include_offset();
    replacements_.insert({offset, offset, curr_include});
  }
}

void file_manager::remove_all_annotations(const t_node& node) {
  size_t begin_offset = SIZE_MAX;
  size_t end_offset = 0;

  for (const auto& annotation : node.annotations()) {
    begin_offset =
        std::min(begin_offset, annotation.second.src_range.begin().offset());
    end_offset =
        std::max(end_offset, annotation.second.src_range.end().offset());
  }

  expand_over_whitespaces(begin_offset, end_offset);

  if (begin_offset >= 1 && end_offset < old_content_.length() &&
      old_content_[begin_offset - 1] == '(' &&
      old_content_[end_offset] == ')') {
    --begin_offset;
    ++end_offset;
  }

  replacements_.insert({begin_offset, end_offset, ""});
}

} // namespace codemod
} // namespace compiler
} // namespace thrift
} // namespace apache
