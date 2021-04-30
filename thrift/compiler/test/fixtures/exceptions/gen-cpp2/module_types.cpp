/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/exceptions/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/exceptions/gen-cpp2/module_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/exceptions/gen-cpp2/module_data.h"


namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::Banal>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::Banal>;
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

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
Banal::Banal(const Banal&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
Banal::Banal(Banal&& other) noexcept { (void)other; }
Banal& Banal::operator=(FOLLY_MAYBE_UNUSED Banal&& other) noexcept {
    return *this;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END


THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
Banal::Banal(apache::thrift::FragileConstructor) {}
THRIFT_IGNORE_ISSET_USE_WARNING_END
void Banal::__clear() {
  // clear all fields
}

bool Banal::operator==(const Banal& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  return true;
}

bool Banal::operator<(const Banal& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  return false;
}


void swap(Banal& a, Banal& b) {
  using ::std::swap;
  (void)a;
  (void)b;
}

template void Banal::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t Banal::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t Banal::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Banal::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void Banal::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t Banal::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t Banal::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t Banal::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::Fiery>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::Fiery>;
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

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
Fiery::Fiery(const Fiery&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
Fiery::Fiery(Fiery&& other) noexcept  :
    message(std::move(other.message)) {}


Fiery& Fiery::operator=(FOLLY_MAYBE_UNUSED Fiery&& other) noexcept {
    this->message = std::move(other.message);
    return *this;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END


THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
Fiery::Fiery(apache::thrift::FragileConstructor, ::std::string message__arg) :
    message(std::move(message__arg)) {}
THRIFT_IGNORE_ISSET_USE_WARNING_END
void Fiery::__clear() {
  // clear all fields
  this->message = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
}

bool Fiery::operator==(const Fiery& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.message == rhs.message)) {
    return false;
  }
  return true;
}

bool Fiery::operator<(const Fiery& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.message == rhs.message)) {
    return lhs.message < rhs.message;
  }
  return false;
}


void swap(Fiery& a, Fiery& b) {
  using ::std::swap;
  swap(a.message_ref().value(), b.message_ref().value());
}

template void Fiery::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t Fiery::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t Fiery::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Fiery::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void Fiery::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t Fiery::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t Fiery::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t Fiery::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::Serious>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::Serious>;
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

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
Serious::Serious(const Serious&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
Serious::Serious(Serious&& other) noexcept  :
    sonnet(std::move(other.sonnet)),
    __isset(other.__isset) {}

Serious& Serious::operator=(FOLLY_MAYBE_UNUSED Serious&& other) noexcept {
    this->sonnet = std::move(other.sonnet);
    __isset = other.__isset;
    return *this;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END


THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
Serious::Serious(apache::thrift::FragileConstructor, ::std::string sonnet__arg) :
    sonnet(std::move(sonnet__arg)) {
  __isset.sonnet = true;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END
void Serious::__clear() {
  // clear all fields
  this->sonnet = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset = {};
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

bool Serious::operator==(const Serious& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (lhs.sonnet_ref() != rhs.sonnet_ref()) {
    return false;
  }
  return true;
}

bool Serious::operator<(const Serious& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (lhs.sonnet_ref() != rhs.sonnet_ref()) {
    return lhs.sonnet_ref() < rhs.sonnet_ref();
  }
  return false;
}


void swap(Serious& a, Serious& b) {
  using ::std::swap;
  swap(a.sonnet_ref().value_unchecked(), b.sonnet_ref().value_unchecked());
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  swap(a.__isset, b.__isset);
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

template void Serious::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t Serious::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t Serious::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Serious::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void Serious::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t Serious::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t Serious::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t Serious::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::ComplexFieldNames>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::ComplexFieldNames>;
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

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
ComplexFieldNames::ComplexFieldNames(const ComplexFieldNames&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
ComplexFieldNames::ComplexFieldNames(ComplexFieldNames&& other) noexcept  :
    error_message(std::move(other.error_message)),
    internal_error_message(std::move(other.internal_error_message)),
    __isset(other.__isset) {}

ComplexFieldNames& ComplexFieldNames::operator=(FOLLY_MAYBE_UNUSED ComplexFieldNames&& other) noexcept {
    this->error_message = std::move(other.error_message);
    this->internal_error_message = std::move(other.internal_error_message);
    __isset = other.__isset;
    return *this;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END


THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
ComplexFieldNames::ComplexFieldNames(apache::thrift::FragileConstructor, ::std::string error_message__arg, ::std::string internal_error_message__arg) :
    error_message(std::move(error_message__arg)),
    internal_error_message(std::move(internal_error_message__arg)) {
  __isset.error_message = true;
  __isset.internal_error_message = true;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END
void ComplexFieldNames::__clear() {
  // clear all fields
  this->error_message = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->internal_error_message = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset = {};
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

bool ComplexFieldNames::operator==(const ComplexFieldNames& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.error_message == rhs.error_message)) {
    return false;
  }
  if (!(lhs.internal_error_message == rhs.internal_error_message)) {
    return false;
  }
  return true;
}

bool ComplexFieldNames::operator<(const ComplexFieldNames& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.error_message == rhs.error_message)) {
    return lhs.error_message < rhs.error_message;
  }
  if (!(lhs.internal_error_message == rhs.internal_error_message)) {
    return lhs.internal_error_message < rhs.internal_error_message;
  }
  return false;
}


void swap(ComplexFieldNames& a, ComplexFieldNames& b) {
  using ::std::swap;
  swap(a.error_message_ref().value(), b.error_message_ref().value());
  swap(a.internal_error_message_ref().value(), b.internal_error_message_ref().value());
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  swap(a.__isset, b.__isset);
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

template void ComplexFieldNames::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t ComplexFieldNames::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t ComplexFieldNames::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t ComplexFieldNames::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void ComplexFieldNames::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t ComplexFieldNames::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t ComplexFieldNames::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t ComplexFieldNames::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::CustomFieldNames>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::CustomFieldNames>;
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

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
CustomFieldNames::CustomFieldNames(const CustomFieldNames&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
CustomFieldNames::CustomFieldNames(CustomFieldNames&& other) noexcept  :
    error_message(std::move(other.error_message)),
    internal_error_message(std::move(other.internal_error_message)),
    __isset(other.__isset) {}

CustomFieldNames& CustomFieldNames::operator=(FOLLY_MAYBE_UNUSED CustomFieldNames&& other) noexcept {
    this->error_message = std::move(other.error_message);
    this->internal_error_message = std::move(other.internal_error_message);
    __isset = other.__isset;
    return *this;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END


THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
CustomFieldNames::CustomFieldNames(apache::thrift::FragileConstructor, ::std::string error_message__arg, ::std::string internal_error_message__arg) :
    error_message(std::move(error_message__arg)),
    internal_error_message(std::move(internal_error_message__arg)) {
  __isset.error_message = true;
  __isset.internal_error_message = true;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END
void CustomFieldNames::__clear() {
  // clear all fields
  this->error_message = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->internal_error_message = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset = {};
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

bool CustomFieldNames::operator==(const CustomFieldNames& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.error_message == rhs.error_message)) {
    return false;
  }
  if (!(lhs.internal_error_message == rhs.internal_error_message)) {
    return false;
  }
  return true;
}

bool CustomFieldNames::operator<(const CustomFieldNames& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.error_message == rhs.error_message)) {
    return lhs.error_message < rhs.error_message;
  }
  if (!(lhs.internal_error_message == rhs.internal_error_message)) {
    return lhs.internal_error_message < rhs.internal_error_message;
  }
  return false;
}


void swap(CustomFieldNames& a, CustomFieldNames& b) {
  using ::std::swap;
  swap(a.error_message_ref().value(), b.error_message_ref().value());
  swap(a.internal_error_message_ref().value(), b.internal_error_message_ref().value());
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  swap(a.__isset, b.__isset);
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

template void CustomFieldNames::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t CustomFieldNames::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t CustomFieldNames::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t CustomFieldNames::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void CustomFieldNames::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t CustomFieldNames::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t CustomFieldNames::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t CustomFieldNames::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2
