/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#include "thrift/compiler/test/fixtures/basic-structured-annotations/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/basic-structured-annotations/gen-cpp2/module_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/basic-structured-annotations/gen-cpp2/module_data.h"


namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::cpp2::MyEnum>::size;
folly::Range<::cpp2::MyEnum const*> const TEnumTraits<::cpp2::MyEnum>::values = folly::range(TEnumDataStorage<::cpp2::MyEnum>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::cpp2::MyEnum>::names = folly::range(TEnumDataStorage<::cpp2::MyEnum>::names);

char const* TEnumTraits<::cpp2::MyEnum>::findName(type value) noexcept {
  return ::apache::thrift::detail::st::enum_find_name(value);
}

bool TEnumTraits<::cpp2::MyEnum>::findValue(char const* name, type* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_value(name, out);
}

}} // apache::thrift

namespace cpp2 {
#ifndef ANDROID
FOLLY_PUSH_WARNING
FOLLY_GNU_DISABLE_WARNING("-Wdeprecated-declarations")
const _MyEnum_EnumMapFactory::ValuesToNamesMapType _MyEnum_VALUES_TO_NAMES = _MyEnum_EnumMapFactory::makeValuesToNamesMap();
const _MyEnum_EnumMapFactory::NamesToValuesMapType _MyEnum_NAMES_TO_VALUES = _MyEnum_EnumMapFactory::makeNamesToValuesMap();
FOLLY_POP_WARNING
#endif
} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::structured_annotation_inline>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::structured_annotation_inline>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

const char* structured_annotation_inline::__fbthrift_cpp2_gen_thrift_uri() {
  return "test.dev/fixtures/basic-structured-annotations/structured_annotation_inline";
}

structured_annotation_inline::structured_annotation_inline(const structured_annotation_inline&) = default;
structured_annotation_inline& structured_annotation_inline::operator=(const structured_annotation_inline&) = default;
structured_annotation_inline::structured_annotation_inline(structured_annotation_inline&& other) noexcept  :
    __fbthrift_field_count(std::move(other.__fbthrift_field_count)),
    __fbthrift_field_name(std::move(other.__fbthrift_field_name)),
    __isset(other.__isset) {
}

structured_annotation_inline& structured_annotation_inline::operator=(FOLLY_MAYBE_UNUSED structured_annotation_inline&& other) noexcept {
    this->__fbthrift_field_count = std::move(other.__fbthrift_field_count);
    this->__fbthrift_field_name = std::move(other.__fbthrift_field_name);
    __isset = other.__isset;
    return *this;
}


structured_annotation_inline::structured_annotation_inline(apache::thrift::FragileConstructor, ::std::int64_t count__arg, ::std::string name__arg) :
    __fbthrift_field_count(std::move(count__arg)),
    __fbthrift_field_name(std::move(name__arg)) {
  __isset.set(folly::index_constant<0>(), true);
  __isset.set(folly::index_constant<1>(), true);
}


void structured_annotation_inline::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_count = ::std::int64_t();
  this->__fbthrift_field_name = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  __isset = {};
}

bool structured_annotation_inline::__fbthrift_is_empty() const {
  return false;
}

bool structured_annotation_inline::operator==(const structured_annotation_inline& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.count_ref() == rhs.count_ref())) {
    return false;
  }
  if (!(lhs.name_ref() == rhs.name_ref())) {
    return false;
  }
  return true;
}

bool structured_annotation_inline::operator<(const structured_annotation_inline& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.count_ref() == rhs.count_ref())) {
    return lhs.count_ref() < rhs.count_ref();
  }
  if (!(lhs.name_ref() == rhs.name_ref())) {
    return lhs.name_ref() < rhs.name_ref();
  }
  return false;
}


void swap(structured_annotation_inline& a, structured_annotation_inline& b) {
  using ::std::swap;
  swap(a.count_ref().value(), b.count_ref().value());
  swap(a.name_ref().value(), b.name_ref().value());
  swap(a.__isset, b.__isset);
}

template void structured_annotation_inline::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t structured_annotation_inline::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t structured_annotation_inline::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t structured_annotation_inline::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void structured_annotation_inline::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t structured_annotation_inline::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t structured_annotation_inline::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t structured_annotation_inline::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::structured_annotation_with_default>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::structured_annotation_with_default>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

const char* structured_annotation_with_default::__fbthrift_cpp2_gen_thrift_uri() {
  return "test.dev/fixtures/basic-structured-annotations/structured_annotation_with_default";
}

structured_annotation_with_default::structured_annotation_with_default(const structured_annotation_with_default&) = default;
structured_annotation_with_default& structured_annotation_with_default::operator=(const structured_annotation_with_default&) = default;
structured_annotation_with_default::structured_annotation_with_default(structured_annotation_with_default&& other) noexcept  :
    __fbthrift_field_name(std::move(other.__fbthrift_field_name)),
    __isset(other.__isset) {
}

structured_annotation_with_default& structured_annotation_with_default::operator=(FOLLY_MAYBE_UNUSED structured_annotation_with_default&& other) noexcept {
    this->__fbthrift_field_name = std::move(other.__fbthrift_field_name);
    __isset = other.__isset;
    return *this;
}


structured_annotation_with_default::structured_annotation_with_default(apache::thrift::FragileConstructor, ::std::string name__arg) :
    __fbthrift_field_name(std::move(name__arg)) {
  __isset.set(folly::index_constant<0>(), true);
}


void structured_annotation_with_default::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_name = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  __isset = {};
}

bool structured_annotation_with_default::__fbthrift_is_empty() const {
  return false;
}

bool structured_annotation_with_default::operator==(const structured_annotation_with_default& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.name_ref() == rhs.name_ref())) {
    return false;
  }
  return true;
}

bool structured_annotation_with_default::operator<(const structured_annotation_with_default& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.name_ref() == rhs.name_ref())) {
    return lhs.name_ref() < rhs.name_ref();
  }
  return false;
}


void swap(structured_annotation_with_default& a, structured_annotation_with_default& b) {
  using ::std::swap;
  swap(a.name_ref().value(), b.name_ref().value());
  swap(a.__isset, b.__isset);
}

template void structured_annotation_with_default::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t structured_annotation_with_default::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t structured_annotation_with_default::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t structured_annotation_with_default::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void structured_annotation_with_default::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t structured_annotation_with_default::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t structured_annotation_with_default::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t structured_annotation_with_default::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::structured_annotation_forward>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::structured_annotation_forward>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

const char* structured_annotation_forward::__fbthrift_cpp2_gen_thrift_uri() {
  return "test.dev/fixtures/basic-structured-annotations/structured_annotation_forward";
}


structured_annotation_forward::structured_annotation_forward(apache::thrift::FragileConstructor, ::std::int64_t count__arg) :
    __fbthrift_field_count(std::move(count__arg)) {
  __isset.set(folly::index_constant<0>(), true);
}


void structured_annotation_forward::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_count = ::std::int64_t();
  __isset = {};
}

bool structured_annotation_forward::__fbthrift_is_empty() const {
  return false;
}

bool structured_annotation_forward::operator==(const structured_annotation_forward& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.count_ref() == rhs.count_ref())) {
    return false;
  }
  return true;
}

bool structured_annotation_forward::operator<(const structured_annotation_forward& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.count_ref() == rhs.count_ref())) {
    return lhs.count_ref() < rhs.count_ref();
  }
  return false;
}


void swap(structured_annotation_forward& a, structured_annotation_forward& b) {
  using ::std::swap;
  swap(a.count_ref().value(), b.count_ref().value());
  swap(a.__isset, b.__isset);
}

template void structured_annotation_forward::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t structured_annotation_forward::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t structured_annotation_forward::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t structured_annotation_forward::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void structured_annotation_forward::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t structured_annotation_forward::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t structured_annotation_forward::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t structured_annotation_forward::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::structured_annotation_recursive>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::structured_annotation_recursive>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

const char* structured_annotation_recursive::__fbthrift_cpp2_gen_thrift_uri() {
  return "test.dev/fixtures/basic-structured-annotations/structured_annotation_recursive";
}

structured_annotation_recursive::structured_annotation_recursive(const structured_annotation_recursive&) = default;
structured_annotation_recursive& structured_annotation_recursive::operator=(const structured_annotation_recursive&) = default;
structured_annotation_recursive::structured_annotation_recursive(structured_annotation_recursive&& other) noexcept  :
    __fbthrift_field_name(std::move(other.__fbthrift_field_name)),
    __fbthrift_field_recurse(std::move(other.__fbthrift_field_recurse)),
    __fbthrift_field_forward(std::move(other.__fbthrift_field_forward)),
    __isset(other.__isset) {
}

structured_annotation_recursive& structured_annotation_recursive::operator=(FOLLY_MAYBE_UNUSED structured_annotation_recursive&& other) noexcept {
    this->__fbthrift_field_name = std::move(other.__fbthrift_field_name);
    this->__fbthrift_field_recurse = std::move(other.__fbthrift_field_recurse);
    this->__fbthrift_field_forward = std::move(other.__fbthrift_field_forward);
    __isset = other.__isset;
    return *this;
}


structured_annotation_recursive::structured_annotation_recursive(apache::thrift::FragileConstructor, ::std::string name__arg, ::cpp2::structured_annotation_recursive recurse__arg, ::cpp2::structured_annotation_forward forward__arg) :
    __fbthrift_field_name(std::move(name__arg)),
    __fbthrift_field_recurse(std::move(recurse__arg)),
    __fbthrift_field_forward(std::move(forward__arg)) {
  __isset.set(folly::index_constant<0>(), true);
  __isset.set(folly::index_constant<1>(), true);
  __isset.set(folly::index_constant<2>(), true);
}


void structured_annotation_recursive::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_name = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
    apache::thrift::clear(this->__fbthrift_field_recurse);
    apache::thrift::clear(this->__fbthrift_field_forward);
  __isset = {};
}

bool structured_annotation_recursive::__fbthrift_is_empty() const {
  return false;
}

bool structured_annotation_recursive::operator==(const structured_annotation_recursive& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.name_ref() == rhs.name_ref())) {
    return false;
  }
  if (!(lhs.recurse_ref() == rhs.recurse_ref())) {
    return false;
  }
  if (!(lhs.forward_ref() == rhs.forward_ref())) {
    return false;
  }
  return true;
}

bool structured_annotation_recursive::operator<(const structured_annotation_recursive& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.name_ref() == rhs.name_ref())) {
    return lhs.name_ref() < rhs.name_ref();
  }
  if (!(lhs.recurse_ref() == rhs.recurse_ref())) {
    return lhs.recurse_ref() < rhs.recurse_ref();
  }
  if (!(lhs.forward_ref() == rhs.forward_ref())) {
    return lhs.forward_ref() < rhs.forward_ref();
  }
  return false;
}

const ::cpp2::structured_annotation_recursive& structured_annotation_recursive::get_recurse() const& {
  return __fbthrift_field_recurse;
}

::cpp2::structured_annotation_recursive structured_annotation_recursive::get_recurse() && {
  return std::move(__fbthrift_field_recurse);
}

const ::cpp2::structured_annotation_forward& structured_annotation_recursive::get_forward() const& {
  return __fbthrift_field_forward;
}

::cpp2::structured_annotation_forward structured_annotation_recursive::get_forward() && {
  return std::move(__fbthrift_field_forward);
}


void swap(structured_annotation_recursive& a, structured_annotation_recursive& b) {
  using ::std::swap;
  swap(a.name_ref().value(), b.name_ref().value());
  swap(a.recurse_ref().value(), b.recurse_ref().value());
  swap(a.forward_ref().value(), b.forward_ref().value());
  swap(a.__isset, b.__isset);
}

template void structured_annotation_recursive::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t structured_annotation_recursive::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t structured_annotation_recursive::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t structured_annotation_recursive::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void structured_annotation_recursive::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t structured_annotation_recursive::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t structured_annotation_recursive::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t structured_annotation_recursive::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        structured_annotation_recursive,
        ::apache::thrift::type_class::structure,
        ::cpp2::structured_annotation_recursive>,
    "inconsistent use of json option");
static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        structured_annotation_recursive,
        ::apache::thrift::type_class::structure,
        ::cpp2::structured_annotation_forward>,
    "inconsistent use of json option");

} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::structured_annotation_nested>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::structured_annotation_nested>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

const char* structured_annotation_nested::__fbthrift_cpp2_gen_thrift_uri() {
  return "test.dev/fixtures/basic-structured-annotations/structured_annotation_nested";
}

structured_annotation_nested::structured_annotation_nested(const structured_annotation_nested&) = default;
structured_annotation_nested& structured_annotation_nested::operator=(const structured_annotation_nested&) = default;
structured_annotation_nested::structured_annotation_nested(structured_annotation_nested&& other) noexcept  :
    __fbthrift_field_name(std::move(other.__fbthrift_field_name)),
    __fbthrift_field_nest(std::move(other.__fbthrift_field_nest)),
    __isset(other.__isset) {
}

structured_annotation_nested& structured_annotation_nested::operator=(FOLLY_MAYBE_UNUSED structured_annotation_nested&& other) noexcept {
    this->__fbthrift_field_name = std::move(other.__fbthrift_field_name);
    this->__fbthrift_field_nest = std::move(other.__fbthrift_field_nest);
    __isset = other.__isset;
    return *this;
}


structured_annotation_nested::structured_annotation_nested(apache::thrift::FragileConstructor, ::std::string name__arg, ::cpp2::structured_annotation_with_default nest__arg) :
    __fbthrift_field_name(std::move(name__arg)),
    __fbthrift_field_nest(std::move(nest__arg)) {
  __isset.set(folly::index_constant<0>(), true);
  __isset.set(folly::index_constant<1>(), true);
}


void structured_annotation_nested::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_name = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
    apache::thrift::clear(this->__fbthrift_field_nest);
  __isset = {};
}

bool structured_annotation_nested::__fbthrift_is_empty() const {
  return false;
}

bool structured_annotation_nested::operator==(const structured_annotation_nested& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.name_ref() == rhs.name_ref())) {
    return false;
  }
  if (!(lhs.nest_ref() == rhs.nest_ref())) {
    return false;
  }
  return true;
}

bool structured_annotation_nested::operator<(const structured_annotation_nested& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.name_ref() == rhs.name_ref())) {
    return lhs.name_ref() < rhs.name_ref();
  }
  if (!(lhs.nest_ref() == rhs.nest_ref())) {
    return lhs.nest_ref() < rhs.nest_ref();
  }
  return false;
}

const ::cpp2::structured_annotation_with_default& structured_annotation_nested::get_nest() const& {
  return __fbthrift_field_nest;
}

::cpp2::structured_annotation_with_default structured_annotation_nested::get_nest() && {
  return std::move(__fbthrift_field_nest);
}


void swap(structured_annotation_nested& a, structured_annotation_nested& b) {
  using ::std::swap;
  swap(a.name_ref().value(), b.name_ref().value());
  swap(a.nest_ref().value(), b.nest_ref().value());
  swap(a.__isset, b.__isset);
}

template void structured_annotation_nested::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t structured_annotation_nested::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t structured_annotation_nested::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t structured_annotation_nested::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void structured_annotation_nested::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t structured_annotation_nested::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t structured_annotation_nested::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t structured_annotation_nested::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        structured_annotation_nested,
        ::apache::thrift::type_class::structure,
        ::cpp2::structured_annotation_with_default>,
    "inconsistent use of json option");

} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::MyStruct>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::MyStruct>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

const char* MyStruct::__fbthrift_cpp2_gen_thrift_uri() {
  return "test.dev/fixtures/basic-structured-annotations/MyStruct";
}

MyStruct::MyStruct(const MyStruct&) = default;
MyStruct& MyStruct::operator=(const MyStruct&) = default;
MyStruct::MyStruct(MyStruct&& other) noexcept  :
    __fbthrift_field_annotated_field(std::move(other.__fbthrift_field_annotated_field)),
    __fbthrift_field_annotated_type(std::move(other.__fbthrift_field_annotated_type)),
    __fbthrift_field_annotated_recursive(std::move(other.__fbthrift_field_annotated_recursive)),
    __fbthrift_field_annotated_nested(std::move(other.__fbthrift_field_annotated_nested)),
    __isset(other.__isset) {
}

MyStruct& MyStruct::operator=(FOLLY_MAYBE_UNUSED MyStruct&& other) noexcept {
    this->__fbthrift_field_annotated_field = std::move(other.__fbthrift_field_annotated_field);
    this->__fbthrift_field_annotated_type = std::move(other.__fbthrift_field_annotated_type);
    this->__fbthrift_field_annotated_recursive = std::move(other.__fbthrift_field_annotated_recursive);
    this->__fbthrift_field_annotated_nested = std::move(other.__fbthrift_field_annotated_nested);
    __isset = other.__isset;
    return *this;
}


MyStruct::MyStruct(apache::thrift::FragileConstructor, ::std::int64_t annotated_field__arg, ::cpp2::annotated_inline_string annotated_type__arg, ::std::string annotated_recursive__arg, ::std::int64_t annotated_nested__arg) :
    __fbthrift_field_annotated_field(std::move(annotated_field__arg)),
    __fbthrift_field_annotated_type(std::move(annotated_type__arg)),
    __fbthrift_field_annotated_recursive(std::move(annotated_recursive__arg)),
    __fbthrift_field_annotated_nested(std::move(annotated_nested__arg)) {
  __isset.set(folly::index_constant<0>(), true);
  __isset.set(folly::index_constant<1>(), true);
  __isset.set(folly::index_constant<2>(), true);
  __isset.set(folly::index_constant<3>(), true);
}


void MyStruct::__fbthrift_clear() {
  // clear all fields
  this->__fbthrift_field_annotated_field = ::std::int64_t();
  this->__fbthrift_field_annotated_type = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->__fbthrift_field_annotated_recursive = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->__fbthrift_field_annotated_nested = ::std::int64_t();
  __isset = {};
}

bool MyStruct::__fbthrift_is_empty() const {
  return false;
}

bool MyStruct::operator==(const MyStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.annotated_field_ref() == rhs.annotated_field_ref())) {
    return false;
  }
  if (!(lhs.annotated_type_ref() == rhs.annotated_type_ref())) {
    return false;
  }
  if (!(lhs.annotated_recursive_ref() == rhs.annotated_recursive_ref())) {
    return false;
  }
  if (!(lhs.annotated_nested_ref() == rhs.annotated_nested_ref())) {
    return false;
  }
  return true;
}

bool MyStruct::operator<(const MyStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.annotated_field_ref() == rhs.annotated_field_ref())) {
    return lhs.annotated_field_ref() < rhs.annotated_field_ref();
  }
  if (!(lhs.annotated_type_ref() == rhs.annotated_type_ref())) {
    return lhs.annotated_type_ref() < rhs.annotated_type_ref();
  }
  if (!(lhs.annotated_recursive_ref() == rhs.annotated_recursive_ref())) {
    return lhs.annotated_recursive_ref() < rhs.annotated_recursive_ref();
  }
  if (!(lhs.annotated_nested_ref() == rhs.annotated_nested_ref())) {
    return lhs.annotated_nested_ref() < rhs.annotated_nested_ref();
  }
  return false;
}


void swap(MyStruct& a, MyStruct& b) {
  using ::std::swap;
  swap(a.annotated_field_ref().value(), b.annotated_field_ref().value());
  swap(a.annotated_type_ref().value(), b.annotated_type_ref().value());
  swap(a.annotated_recursive_ref().value(), b.annotated_recursive_ref().value());
  swap(a.annotated_nested_ref().value(), b.annotated_nested_ref().value());
  swap(a.__isset, b.__isset);
}

template void MyStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MyStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MyStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MyStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::MyException>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::MyException>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace cpp2 {

const char* MyException::__fbthrift_cpp2_gen_thrift_uri() {
  return "test.dev/fixtures/basic-structured-annotations/MyException";
}

MyException::MyException(const MyException&) = default;
MyException& MyException::operator=(const MyException&) = default;
MyException::MyException() {
}


MyException::~MyException() {}

MyException::MyException(MyException&& other) noexcept  :
    context(std::move(other.context)),
    __isset(other.__isset) {
}

MyException& MyException::operator=(FOLLY_MAYBE_UNUSED MyException&& other) noexcept {
    this->context = std::move(other.context);
    __isset = other.__isset;
    return *this;
}


MyException::MyException(apache::thrift::FragileConstructor, ::std::string context__arg) :
    context(std::move(context__arg)) {
  __isset.set(folly::index_constant<0>(), true);
}


void MyException::__fbthrift_clear() {
  // clear all fields
  this->context = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  __isset = {};
}

bool MyException::__fbthrift_is_empty() const {
  return false;
}

bool MyException::operator==(const MyException& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.context_ref() == rhs.context_ref())) {
    return false;
  }
  return true;
}

bool MyException::operator<(const MyException& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.context_ref() == rhs.context_ref())) {
    return lhs.context_ref() < rhs.context_ref();
  }
  return false;
}


void swap(MyException& a, MyException& b) {
  using ::std::swap;
  swap(a.context_ref().value(), b.context_ref().value());
  swap(a.__isset, b.__isset);
}

template void MyException::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MyException::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MyException::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MyException::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MyException::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyException::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyException::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyException::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::MyUnion>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::MyUnion>;
  static const st::translate_field_name_table table{
      data::fields_size,
      data::fields_names.data(),
      data::fields_ids.data(),
      data::fields_types.data()};
  st::translate_field_name(_fname, fid, _ftype, table);
}

} // namespace detail
} // namespace thrift
} // namespace apache

namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::cpp2::MyUnion::Type>::size;
folly::Range<::cpp2::MyUnion::Type const*> const TEnumTraits<::cpp2::MyUnion::Type>::values = folly::range(TEnumDataStorage<::cpp2::MyUnion::Type>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::cpp2::MyUnion::Type>::names = folly::range(TEnumDataStorage<::cpp2::MyUnion::Type>::names);

char const* TEnumTraits<::cpp2::MyUnion::Type>::findName(type value) noexcept {
  return ::apache::thrift::detail::st::enum_find_name(value);
}

bool TEnumTraits<::cpp2::MyUnion::Type>::findValue(char const* name, type* out) noexcept {
  return ::apache::thrift::detail::st::enum_find_value(name, out);
}
}} // apache::thrift
namespace cpp2 {

const char* MyUnion::__fbthrift_cpp2_gen_thrift_uri() {
  return "test.dev/fixtures/basic-structured-annotations/MyUnion";
}

void MyUnion::__fbthrift_clear() {
  // clear all fields
  if (type_ == Type::__EMPTY__) { return; }
  switch(type_) {
    case Type::first:
      destruct(value_.first);
      break;
    case Type::second:
      destruct(value_.second);
      break;
    default:
      assert(false);
      break;
  }
  type_ = Type::__EMPTY__;
}

bool MyUnion::__fbthrift_is_empty() const {
  return type_ == Type::__EMPTY__;
}

bool MyUnion::operator==(const MyUnion& rhs) const {
  if (type_ != rhs.type_) { return false; }
  switch(type_) {
    case Type::first:
      return value_.first == rhs.value_.first;
    case Type::second:
      return value_.second == rhs.value_.second;
    default:
      return true;
  }
}

bool MyUnion::operator<(const MyUnion& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (lhs.type_ != rhs.type_) {
    return lhs.type_ < rhs.type_;
  }
  switch (lhs.type_) {
    case Type::first:
      return lhs.value_.first < rhs.value_.first;
    case Type::second:
      return lhs.value_.second < rhs.value_.second;
    default:
      return false;
  }
}

void swap(MyUnion& a, MyUnion& b) {
  MyUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template void MyUnion::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MyUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MyUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MyUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MyUnion::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;


} // cpp2

namespace cpp2 { namespace {
FOLLY_MAYBE_UNUSED FOLLY_ERASE void validateAdapters() {
}
}} // cpp2
