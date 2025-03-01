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

#include <thrift/compiler/ast/t_type.h>

#include <array>
#include <sstream>
#include <stdexcept>
#include <string>

#include <openssl/sha.h>

#include <thrift/compiler/ast/t_program.h>
#include <thrift/compiler/ast/t_typedef.h>

namespace apache {
namespace thrift {
namespace compiler {

constexpr size_t t_type::kTypeBits;
constexpr uint64_t t_type::kTypeMask;

const std::string& t_type::type_name(type t) {
  static const auto& kTypeNames =
      *new std::array<std::string, t_type::kTypeCount>(
          {{"void",
            "string",
            "bool",
            "byte",
            "i16",
            "i32",
            "i64",
            "double",
            "enum",
            "list",
            "set",
            "map",
            "struct",
            "service",
            "program",
            "float",
            "sink",
            "stream",
            "binary"}});
  return kTypeNames.at(static_cast<size_t>(t));
}

uint64_t t_type::get_type_id() const {
  std::string name = get_full_name();
  unsigned char buf[SHA_DIGEST_LENGTH] = {};
  SHA1(reinterpret_cast<const unsigned char*>(name.data()), name.size(), buf);
  uint64_t hash = 0;
  std::memcpy(&hash, &buf, sizeof(hash));
#if !defined(_WIN32) && __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
  hash = __builtin_bswap64(hash);
#endif
  return (hash & ~t_type::kTypeMask) | static_cast<int>(get_type_value());
}

std::string t_type::get_scoped_name() const {
  std::ostringstream os;
  if (program_) {
    os << program_->name() << ".";
  }
  os << name_;
  return os.str();
}

std::string t_type::make_full_name(const char* prefix) const {
  return std::string(prefix) + " " + get_scoped_name();
}

const t_type* t_type::get_true_type() const {
  return t_typedef::find_type_if(
      this, [](const t_type* type) { return !type->is_typedef(); });
}

const t_type& t_type_ref::deref() const {
  if (type_ == nullptr) {
    throw std::runtime_error("t_type_ref has no type.");
  }
  if (auto ph = dynamic_cast<const t_placeholder_typedef*>(type_)) {
    return ph->type().deref();
  }
  return *type_;
}

} // namespace compiler
} // namespace thrift
} // namespace apache
