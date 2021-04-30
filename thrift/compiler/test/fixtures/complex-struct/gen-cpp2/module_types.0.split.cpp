/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/complex-struct/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/complex-struct/gen-cpp2/module_types.tcc"

#include <thrift/lib/cpp2/gen/module_types_cpp.h>

#include "thrift/compiler/test/fixtures/complex-struct/gen-cpp2/module_data.h"


namespace apache { namespace thrift {

constexpr std::size_t const TEnumTraits<::cpp2::MyEnum>::size;
folly::Range<::cpp2::MyEnum const*> const TEnumTraits<::cpp2::MyEnum>::values = folly::range(TEnumDataStorage<::cpp2::MyEnum>::values);
folly::Range<folly::StringPiece const*> const TEnumTraits<::cpp2::MyEnum>::names = folly::range(TEnumDataStorage<::cpp2::MyEnum>::names);

char const* TEnumTraits<::cpp2::MyEnum>::findName(type value) {
  using factory = ::cpp2::_MyEnum_EnumMapFactory;
  static folly::Indestructible<factory::ValuesToNamesMapType> const map{
      factory::makeValuesToNamesMap()};
  auto found = map->find(value);
  return found == map->end() ? nullptr : found->second;
}

bool TEnumTraits<::cpp2::MyEnum>::findValue(char const* name, type* out) {
  using factory = ::cpp2::_MyEnum_EnumMapFactory;
  static folly::Indestructible<factory::NamesToValuesMapType> const map{
      factory::makeNamesToValuesMap()};
  auto found = map->find(name);
  return found == map->end() ? false : (*out = found->second, true);
}

}} // apache::thrift

namespace cpp2 {
FOLLY_PUSH_WARNING
FOLLY_GNU_DISABLE_WARNING("-Wdeprecated-declarations")
const _MyEnum_EnumMapFactory::ValuesToNamesMapType _MyEnum_VALUES_TO_NAMES = _MyEnum_EnumMapFactory::makeValuesToNamesMap();
const _MyEnum_EnumMapFactory::NamesToValuesMapType _MyEnum_NAMES_TO_VALUES = _MyEnum_EnumMapFactory::makeNamesToValuesMap();
FOLLY_POP_WARNING

} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::MyStructFloatFieldThrowExp>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::MyStructFloatFieldThrowExp>;
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
MyStructFloatFieldThrowExp::MyStructFloatFieldThrowExp(const MyStructFloatFieldThrowExp&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
MyStructFloatFieldThrowExp::MyStructFloatFieldThrowExp(MyStructFloatFieldThrowExp&& other) noexcept  :
    myLongField(std::move(other.myLongField)),
    MyByteField(std::move(other.MyByteField)),
    myStringField(std::move(other.myStringField)),
    myFloatField(std::move(other.myFloatField)),
    __isset(other.__isset) {}

MyStructFloatFieldThrowExp& MyStructFloatFieldThrowExp::operator=(FOLLY_MAYBE_UNUSED MyStructFloatFieldThrowExp&& other) noexcept {
    this->myLongField = std::move(other.myLongField);
    this->MyByteField = std::move(other.MyByteField);
    this->myStringField = std::move(other.myStringField);
    this->myFloatField = std::move(other.myFloatField);
    __isset = other.__isset;
    return *this;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END


THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
MyStructFloatFieldThrowExp::MyStructFloatFieldThrowExp(apache::thrift::FragileConstructor, ::std::int64_t myLongField__arg, ::std::int8_t MyByteField__arg, ::std::string myStringField__arg, float myFloatField__arg) :
    myLongField(std::move(myLongField__arg)),
    MyByteField(std::move(MyByteField__arg)),
    myStringField(std::move(myStringField__arg)),
    myFloatField(std::move(myFloatField__arg)) {
  __isset.myLongField = true;
  __isset.MyByteField = true;
  __isset.myStringField = true;
  __isset.myFloatField = true;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END
void MyStructFloatFieldThrowExp::__clear() {
  // clear all fields
  this->myLongField = 0;
  this->MyByteField = 0;
  this->myStringField = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->myFloatField = 0;
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset = {};
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

bool MyStructFloatFieldThrowExp::operator==(const MyStructFloatFieldThrowExp& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.myLongField == rhs.myLongField)) {
    return false;
  }
  if (!(lhs.MyByteField == rhs.MyByteField)) {
    return false;
  }
  if (!(lhs.myStringField == rhs.myStringField)) {
    return false;
  }
  if (!(lhs.myFloatField == rhs.myFloatField)) {
    return false;
  }
  return true;
}

bool MyStructFloatFieldThrowExp::operator<(const MyStructFloatFieldThrowExp& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.myLongField == rhs.myLongField)) {
    return lhs.myLongField < rhs.myLongField;
  }
  if (!(lhs.MyByteField == rhs.MyByteField)) {
    return lhs.MyByteField < rhs.MyByteField;
  }
  if (!(lhs.myStringField == rhs.myStringField)) {
    return lhs.myStringField < rhs.myStringField;
  }
  if (!(lhs.myFloatField == rhs.myFloatField)) {
    return lhs.myFloatField < rhs.myFloatField;
  }
  return false;
}


void swap(MyStructFloatFieldThrowExp& a, MyStructFloatFieldThrowExp& b) {
  using ::std::swap;
  swap(a.myLongField_ref().value(), b.myLongField_ref().value());
  swap(a.MyByteField_ref().value(), b.MyByteField_ref().value());
  swap(a.myStringField_ref().value(), b.myStringField_ref().value());
  swap(a.myFloatField_ref().value(), b.myFloatField_ref().value());
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  swap(a.__isset, b.__isset);
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

template void MyStructFloatFieldThrowExp::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MyStructFloatFieldThrowExp::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MyStructFloatFieldThrowExp::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MyStructFloatFieldThrowExp::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MyStructFloatFieldThrowExp::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyStructFloatFieldThrowExp::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyStructFloatFieldThrowExp::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyStructFloatFieldThrowExp::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::SimpleStruct>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::SimpleStruct>;
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
SimpleStruct::SimpleStruct(const SimpleStruct&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
SimpleStruct::SimpleStruct(SimpleStruct&& other) noexcept  :
    age(std::move(other.age)),
    name(std::move(other.name)),
    __isset(other.__isset) {}

SimpleStruct& SimpleStruct::operator=(FOLLY_MAYBE_UNUSED SimpleStruct&& other) noexcept {
    this->age = std::move(other.age);
    this->name = std::move(other.name);
    __isset = other.__isset;
    return *this;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END


THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
SimpleStruct::SimpleStruct(apache::thrift::FragileConstructor, ::std::int64_t age__arg, ::std::string name__arg) :
    age(std::move(age__arg)),
    name(std::move(name__arg)) {
  __isset.age = true;
  __isset.name = true;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END
void SimpleStruct::__clear() {
  // clear all fields
  this->age = 60LL;
  this->name = apache::thrift::StringTraits<std::string>::fromStringLiteral("Batman");
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset = {};
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

bool SimpleStruct::operator==(const SimpleStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.age == rhs.age)) {
    return false;
  }
  if (!(lhs.name == rhs.name)) {
    return false;
  }
  return true;
}

bool SimpleStruct::operator<(const SimpleStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.age == rhs.age)) {
    return lhs.age < rhs.age;
  }
  if (!(lhs.name == rhs.name)) {
    return lhs.name < rhs.name;
  }
  return false;
}


void swap(SimpleStruct& a, SimpleStruct& b) {
  using ::std::swap;
  swap(a.age_ref().value(), b.age_ref().value());
  swap(a.name_ref().value(), b.name_ref().value());
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  swap(a.__isset, b.__isset);
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

template void SimpleStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t SimpleStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t SimpleStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t SimpleStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void SimpleStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t SimpleStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t SimpleStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t SimpleStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::MyDataItem>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::MyDataItem>;
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
MyDataItem::MyDataItem(apache::thrift::FragileConstructor) {}
THRIFT_IGNORE_ISSET_USE_WARNING_END
void MyDataItem::__clear() {
  // clear all fields
}

bool MyDataItem::operator==(const MyDataItem& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  return true;
}

bool MyDataItem::operator<(const MyDataItem& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  return false;
}


void swap(MyDataItem& a, MyDataItem& b) {
  using ::std::swap;
  (void)a;
  (void)b;
}

template void MyDataItem::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t MyDataItem::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t MyDataItem::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t MyDataItem::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void MyDataItem::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t MyDataItem::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t MyDataItem::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t MyDataItem::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::ComplexNestedStruct>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::ComplexNestedStruct>;
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
ComplexNestedStruct::ComplexNestedStruct(const ComplexNestedStruct&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
ComplexNestedStruct::ComplexNestedStruct() {}

THRIFT_IGNORE_ISSET_USE_WARNING_END

ComplexNestedStruct::~ComplexNestedStruct() {}

THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
ComplexNestedStruct::ComplexNestedStruct(ComplexNestedStruct&& other) noexcept  :
    setOfSetOfInt(std::move(other.setOfSetOfInt)),
    listofListOfListOfListOfEnum(std::move(other.listofListOfListOfListOfEnum)),
    listOfListOfMyStruct(std::move(other.listOfListOfMyStruct)),
    setOfListOfListOfLong(std::move(other.setOfListOfListOfLong)),
    setOfSetOfsetOfLong(std::move(other.setOfSetOfsetOfLong)),
    mapStructListOfListOfLong(std::move(other.mapStructListOfListOfLong)),
    mKeyStructValInt(std::move(other.mKeyStructValInt)),
    listOfMapKeyIntValInt(std::move(other.listOfMapKeyIntValInt)),
    listOfMapKeyStrValList(std::move(other.listOfMapKeyStrValList)),
    mapKeySetValLong(std::move(other.mapKeySetValLong)),
    mapKeyListValLong(std::move(other.mapKeyListValLong)),
    mapKeyMapValMap(std::move(other.mapKeyMapValMap)),
    mapKeySetValMap(std::move(other.mapKeySetValMap)),
    NestedMaps(std::move(other.NestedMaps)),
    mapKeyIntValList(std::move(other.mapKeyIntValList)),
    mapKeyIntValSet(std::move(other.mapKeyIntValSet)),
    mapKeySetValInt(std::move(other.mapKeySetValInt)),
    mapKeyListValSet(std::move(other.mapKeyListValSet)),
    __isset(other.__isset) {}

ComplexNestedStruct& ComplexNestedStruct::operator=(FOLLY_MAYBE_UNUSED ComplexNestedStruct&& other) noexcept {
    this->setOfSetOfInt = std::move(other.setOfSetOfInt);
    this->listofListOfListOfListOfEnum = std::move(other.listofListOfListOfListOfEnum);
    this->listOfListOfMyStruct = std::move(other.listOfListOfMyStruct);
    this->setOfListOfListOfLong = std::move(other.setOfListOfListOfLong);
    this->setOfSetOfsetOfLong = std::move(other.setOfSetOfsetOfLong);
    this->mapStructListOfListOfLong = std::move(other.mapStructListOfListOfLong);
    this->mKeyStructValInt = std::move(other.mKeyStructValInt);
    this->listOfMapKeyIntValInt = std::move(other.listOfMapKeyIntValInt);
    this->listOfMapKeyStrValList = std::move(other.listOfMapKeyStrValList);
    this->mapKeySetValLong = std::move(other.mapKeySetValLong);
    this->mapKeyListValLong = std::move(other.mapKeyListValLong);
    this->mapKeyMapValMap = std::move(other.mapKeyMapValMap);
    this->mapKeySetValMap = std::move(other.mapKeySetValMap);
    this->NestedMaps = std::move(other.NestedMaps);
    this->mapKeyIntValList = std::move(other.mapKeyIntValList);
    this->mapKeyIntValSet = std::move(other.mapKeyIntValSet);
    this->mapKeySetValInt = std::move(other.mapKeySetValInt);
    this->mapKeyListValSet = std::move(other.mapKeyListValSet);
    __isset = other.__isset;
    return *this;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END


THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
ComplexNestedStruct::ComplexNestedStruct(apache::thrift::FragileConstructor, ::std::set<::std::set<::std::int32_t>> setOfSetOfInt__arg, ::std::vector<::std::vector<::std::vector<::std::vector<::cpp2::MyEnum>>>> listofListOfListOfListOfEnum__arg, ::std::vector<::std::vector<::cpp2::MyStruct>> listOfListOfMyStruct__arg, ::std::set<::std::vector<::std::vector<::std::int64_t>>> setOfListOfListOfLong__arg, ::std::set<::std::set<::std::set<::std::int64_t>>> setOfSetOfsetOfLong__arg, ::std::map<::std::int32_t, ::std::vector<::std::vector<::cpp2::MyStruct>>> mapStructListOfListOfLong__arg, ::std::map<::cpp2::MyStruct, ::std::int32_t> mKeyStructValInt__arg, ::std::vector<::std::map<::std::int32_t, ::std::int32_t>> listOfMapKeyIntValInt__arg, ::std::vector<::std::map<::std::string, ::std::vector<::cpp2::MyStruct>>> listOfMapKeyStrValList__arg, ::std::map<::std::set<::std::int32_t>, ::std::int64_t> mapKeySetValLong__arg, ::std::map<::std::vector<::std::string>, ::std::int32_t> mapKeyListValLong__arg, ::std::map<::std::map<::std::int32_t, ::std::string>, ::std::map<::std::int32_t, ::std::string>> mapKeyMapValMap__arg, ::std::map<::std::set<::std::vector<::std::int32_t>>, ::std::map<::std::vector<::std::set<::std::string>>, ::std::string>> mapKeySetValMap__arg, ::std::map<::std::map<::std::map<::std::int32_t, ::std::string>, ::std::string>, ::std::map<::std::int32_t, ::std::string>> NestedMaps__arg, ::std::map<::std::int32_t, ::std::vector<::cpp2::MyStruct>> mapKeyIntValList__arg, ::std::map<::std::int32_t, ::std::set<bool>> mapKeyIntValSet__arg, ::std::map<::std::set<bool>, ::cpp2::MyEnum> mapKeySetValInt__arg, ::std::map<::std::vector<::std::int32_t>, ::std::set<::std::map<double, ::std::string>>> mapKeyListValSet__arg) :
    setOfSetOfInt(std::move(setOfSetOfInt__arg)),
    listofListOfListOfListOfEnum(std::move(listofListOfListOfListOfEnum__arg)),
    listOfListOfMyStruct(std::move(listOfListOfMyStruct__arg)),
    setOfListOfListOfLong(std::move(setOfListOfListOfLong__arg)),
    setOfSetOfsetOfLong(std::move(setOfSetOfsetOfLong__arg)),
    mapStructListOfListOfLong(std::move(mapStructListOfListOfLong__arg)),
    mKeyStructValInt(std::move(mKeyStructValInt__arg)),
    listOfMapKeyIntValInt(std::move(listOfMapKeyIntValInt__arg)),
    listOfMapKeyStrValList(std::move(listOfMapKeyStrValList__arg)),
    mapKeySetValLong(std::move(mapKeySetValLong__arg)),
    mapKeyListValLong(std::move(mapKeyListValLong__arg)),
    mapKeyMapValMap(std::move(mapKeyMapValMap__arg)),
    mapKeySetValMap(std::move(mapKeySetValMap__arg)),
    NestedMaps(std::move(NestedMaps__arg)),
    mapKeyIntValList(std::move(mapKeyIntValList__arg)),
    mapKeyIntValSet(std::move(mapKeyIntValSet__arg)),
    mapKeySetValInt(std::move(mapKeySetValInt__arg)),
    mapKeyListValSet(std::move(mapKeyListValSet__arg)) {
  __isset.setOfSetOfInt = true;
  __isset.listofListOfListOfListOfEnum = true;
  __isset.listOfListOfMyStruct = true;
  __isset.setOfListOfListOfLong = true;
  __isset.setOfSetOfsetOfLong = true;
  __isset.mapStructListOfListOfLong = true;
  __isset.mKeyStructValInt = true;
  __isset.listOfMapKeyIntValInt = true;
  __isset.listOfMapKeyStrValList = true;
  __isset.mapKeySetValLong = true;
  __isset.mapKeyListValLong = true;
  __isset.mapKeyMapValMap = true;
  __isset.mapKeySetValMap = true;
  __isset.NestedMaps = true;
  __isset.mapKeyIntValList = true;
  __isset.mapKeyIntValSet = true;
  __isset.mapKeySetValInt = true;
  __isset.mapKeyListValSet = true;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END
void ComplexNestedStruct::__clear() {
  // clear all fields
  this->setOfSetOfInt.clear();
  this->listofListOfListOfListOfEnum.clear();
  this->listOfListOfMyStruct.clear();
  this->setOfListOfListOfLong.clear();
  this->setOfSetOfsetOfLong.clear();
  this->mapStructListOfListOfLong.clear();
  this->mKeyStructValInt.clear();
  this->listOfMapKeyIntValInt.clear();
  this->listOfMapKeyStrValList.clear();
  this->mapKeySetValLong.clear();
  this->mapKeyListValLong.clear();
  this->mapKeyMapValMap.clear();
  this->mapKeySetValMap.clear();
  this->NestedMaps.clear();
  this->mapKeyIntValList.clear();
  this->mapKeyIntValSet.clear();
  this->mapKeySetValInt.clear();
  this->mapKeyListValSet.clear();
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  __isset = {};
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

bool ComplexNestedStruct::operator==(const ComplexNestedStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.setOfSetOfInt == rhs.setOfSetOfInt)) {
    return false;
  }
  if (!(lhs.listofListOfListOfListOfEnum == rhs.listofListOfListOfListOfEnum)) {
    return false;
  }
  if (!(lhs.listOfListOfMyStruct == rhs.listOfListOfMyStruct)) {
    return false;
  }
  if (!(lhs.setOfListOfListOfLong == rhs.setOfListOfListOfLong)) {
    return false;
  }
  if (!(lhs.setOfSetOfsetOfLong == rhs.setOfSetOfsetOfLong)) {
    return false;
  }
  if (!(lhs.mapStructListOfListOfLong == rhs.mapStructListOfListOfLong)) {
    return false;
  }
  if (!(lhs.mKeyStructValInt == rhs.mKeyStructValInt)) {
    return false;
  }
  if (!(lhs.listOfMapKeyIntValInt == rhs.listOfMapKeyIntValInt)) {
    return false;
  }
  if (!(lhs.listOfMapKeyStrValList == rhs.listOfMapKeyStrValList)) {
    return false;
  }
  if (!(lhs.mapKeySetValLong == rhs.mapKeySetValLong)) {
    return false;
  }
  if (!(lhs.mapKeyListValLong == rhs.mapKeyListValLong)) {
    return false;
  }
  if (!(lhs.mapKeyMapValMap == rhs.mapKeyMapValMap)) {
    return false;
  }
  if (!(lhs.mapKeySetValMap == rhs.mapKeySetValMap)) {
    return false;
  }
  if (!(lhs.NestedMaps == rhs.NestedMaps)) {
    return false;
  }
  if (!(lhs.mapKeyIntValList == rhs.mapKeyIntValList)) {
    return false;
  }
  if (!(lhs.mapKeyIntValSet == rhs.mapKeyIntValSet)) {
    return false;
  }
  if (!(lhs.mapKeySetValInt == rhs.mapKeySetValInt)) {
    return false;
  }
  if (!(lhs.mapKeyListValSet == rhs.mapKeyListValSet)) {
    return false;
  }
  return true;
}

bool ComplexNestedStruct::operator<(const ComplexNestedStruct& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.setOfSetOfInt == rhs.setOfSetOfInt)) {
    return lhs.setOfSetOfInt < rhs.setOfSetOfInt;
  }
  if (!(lhs.listofListOfListOfListOfEnum == rhs.listofListOfListOfListOfEnum)) {
    return lhs.listofListOfListOfListOfEnum < rhs.listofListOfListOfListOfEnum;
  }
  if (!(lhs.listOfListOfMyStruct == rhs.listOfListOfMyStruct)) {
    return lhs.listOfListOfMyStruct < rhs.listOfListOfMyStruct;
  }
  if (!(lhs.setOfListOfListOfLong == rhs.setOfListOfListOfLong)) {
    return lhs.setOfListOfListOfLong < rhs.setOfListOfListOfLong;
  }
  if (!(lhs.setOfSetOfsetOfLong == rhs.setOfSetOfsetOfLong)) {
    return lhs.setOfSetOfsetOfLong < rhs.setOfSetOfsetOfLong;
  }
  if (!(lhs.mapStructListOfListOfLong == rhs.mapStructListOfListOfLong)) {
    return lhs.mapStructListOfListOfLong < rhs.mapStructListOfListOfLong;
  }
  if (!(lhs.mKeyStructValInt == rhs.mKeyStructValInt)) {
    return lhs.mKeyStructValInt < rhs.mKeyStructValInt;
  }
  if (!(lhs.listOfMapKeyIntValInt == rhs.listOfMapKeyIntValInt)) {
    return lhs.listOfMapKeyIntValInt < rhs.listOfMapKeyIntValInt;
  }
  if (!(lhs.listOfMapKeyStrValList == rhs.listOfMapKeyStrValList)) {
    return lhs.listOfMapKeyStrValList < rhs.listOfMapKeyStrValList;
  }
  if (!(lhs.mapKeySetValLong == rhs.mapKeySetValLong)) {
    return lhs.mapKeySetValLong < rhs.mapKeySetValLong;
  }
  if (!(lhs.mapKeyListValLong == rhs.mapKeyListValLong)) {
    return lhs.mapKeyListValLong < rhs.mapKeyListValLong;
  }
  if (!(lhs.mapKeyMapValMap == rhs.mapKeyMapValMap)) {
    return lhs.mapKeyMapValMap < rhs.mapKeyMapValMap;
  }
  if (!(lhs.mapKeySetValMap == rhs.mapKeySetValMap)) {
    return lhs.mapKeySetValMap < rhs.mapKeySetValMap;
  }
  if (!(lhs.NestedMaps == rhs.NestedMaps)) {
    return lhs.NestedMaps < rhs.NestedMaps;
  }
  if (!(lhs.mapKeyIntValList == rhs.mapKeyIntValList)) {
    return lhs.mapKeyIntValList < rhs.mapKeyIntValList;
  }
  if (!(lhs.mapKeyIntValSet == rhs.mapKeyIntValSet)) {
    return lhs.mapKeyIntValSet < rhs.mapKeyIntValSet;
  }
  if (!(lhs.mapKeySetValInt == rhs.mapKeySetValInt)) {
    return lhs.mapKeySetValInt < rhs.mapKeySetValInt;
  }
  if (!(lhs.mapKeyListValSet == rhs.mapKeyListValSet)) {
    return lhs.mapKeyListValSet < rhs.mapKeyListValSet;
  }
  return false;
}

const ::std::set<::std::set<::std::int32_t>>& ComplexNestedStruct::get_setOfSetOfInt() const& {
  return setOfSetOfInt;
}

::std::set<::std::set<::std::int32_t>> ComplexNestedStruct::get_setOfSetOfInt() && {
  return std::move(setOfSetOfInt);
}

const ::std::vector<::std::vector<::std::vector<::std::vector<::cpp2::MyEnum>>>>& ComplexNestedStruct::get_listofListOfListOfListOfEnum() const& {
  return listofListOfListOfListOfEnum;
}

::std::vector<::std::vector<::std::vector<::std::vector<::cpp2::MyEnum>>>> ComplexNestedStruct::get_listofListOfListOfListOfEnum() && {
  return std::move(listofListOfListOfListOfEnum);
}

const ::std::vector<::std::vector<::cpp2::MyStruct>>& ComplexNestedStruct::get_listOfListOfMyStruct() const& {
  return listOfListOfMyStruct;
}

::std::vector<::std::vector<::cpp2::MyStruct>> ComplexNestedStruct::get_listOfListOfMyStruct() && {
  return std::move(listOfListOfMyStruct);
}

const ::std::set<::std::vector<::std::vector<::std::int64_t>>>& ComplexNestedStruct::get_setOfListOfListOfLong() const& {
  return setOfListOfListOfLong;
}

::std::set<::std::vector<::std::vector<::std::int64_t>>> ComplexNestedStruct::get_setOfListOfListOfLong() && {
  return std::move(setOfListOfListOfLong);
}

const ::std::set<::std::set<::std::set<::std::int64_t>>>& ComplexNestedStruct::get_setOfSetOfsetOfLong() const& {
  return setOfSetOfsetOfLong;
}

::std::set<::std::set<::std::set<::std::int64_t>>> ComplexNestedStruct::get_setOfSetOfsetOfLong() && {
  return std::move(setOfSetOfsetOfLong);
}

const ::std::map<::std::int32_t, ::std::vector<::std::vector<::cpp2::MyStruct>>>& ComplexNestedStruct::get_mapStructListOfListOfLong() const& {
  return mapStructListOfListOfLong;
}

::std::map<::std::int32_t, ::std::vector<::std::vector<::cpp2::MyStruct>>> ComplexNestedStruct::get_mapStructListOfListOfLong() && {
  return std::move(mapStructListOfListOfLong);
}

const ::std::map<::cpp2::MyStruct, ::std::int32_t>& ComplexNestedStruct::get_mKeyStructValInt() const& {
  return mKeyStructValInt;
}

::std::map<::cpp2::MyStruct, ::std::int32_t> ComplexNestedStruct::get_mKeyStructValInt() && {
  return std::move(mKeyStructValInt);
}

const ::std::vector<::std::map<::std::int32_t, ::std::int32_t>>& ComplexNestedStruct::get_listOfMapKeyIntValInt() const& {
  return listOfMapKeyIntValInt;
}

::std::vector<::std::map<::std::int32_t, ::std::int32_t>> ComplexNestedStruct::get_listOfMapKeyIntValInt() && {
  return std::move(listOfMapKeyIntValInt);
}

const ::std::vector<::std::map<::std::string, ::std::vector<::cpp2::MyStruct>>>& ComplexNestedStruct::get_listOfMapKeyStrValList() const& {
  return listOfMapKeyStrValList;
}

::std::vector<::std::map<::std::string, ::std::vector<::cpp2::MyStruct>>> ComplexNestedStruct::get_listOfMapKeyStrValList() && {
  return std::move(listOfMapKeyStrValList);
}

const ::std::map<::std::set<::std::int32_t>, ::std::int64_t>& ComplexNestedStruct::get_mapKeySetValLong() const& {
  return mapKeySetValLong;
}

::std::map<::std::set<::std::int32_t>, ::std::int64_t> ComplexNestedStruct::get_mapKeySetValLong() && {
  return std::move(mapKeySetValLong);
}

const ::std::map<::std::vector<::std::string>, ::std::int32_t>& ComplexNestedStruct::get_mapKeyListValLong() const& {
  return mapKeyListValLong;
}

::std::map<::std::vector<::std::string>, ::std::int32_t> ComplexNestedStruct::get_mapKeyListValLong() && {
  return std::move(mapKeyListValLong);
}

const ::std::map<::std::map<::std::int32_t, ::std::string>, ::std::map<::std::int32_t, ::std::string>>& ComplexNestedStruct::get_mapKeyMapValMap() const& {
  return mapKeyMapValMap;
}

::std::map<::std::map<::std::int32_t, ::std::string>, ::std::map<::std::int32_t, ::std::string>> ComplexNestedStruct::get_mapKeyMapValMap() && {
  return std::move(mapKeyMapValMap);
}

const ::std::map<::std::set<::std::vector<::std::int32_t>>, ::std::map<::std::vector<::std::set<::std::string>>, ::std::string>>& ComplexNestedStruct::get_mapKeySetValMap() const& {
  return mapKeySetValMap;
}

::std::map<::std::set<::std::vector<::std::int32_t>>, ::std::map<::std::vector<::std::set<::std::string>>, ::std::string>> ComplexNestedStruct::get_mapKeySetValMap() && {
  return std::move(mapKeySetValMap);
}

const ::std::map<::std::map<::std::map<::std::int32_t, ::std::string>, ::std::string>, ::std::map<::std::int32_t, ::std::string>>& ComplexNestedStruct::get_NestedMaps() const& {
  return NestedMaps;
}

::std::map<::std::map<::std::map<::std::int32_t, ::std::string>, ::std::string>, ::std::map<::std::int32_t, ::std::string>> ComplexNestedStruct::get_NestedMaps() && {
  return std::move(NestedMaps);
}

const ::std::map<::std::int32_t, ::std::vector<::cpp2::MyStruct>>& ComplexNestedStruct::get_mapKeyIntValList() const& {
  return mapKeyIntValList;
}

::std::map<::std::int32_t, ::std::vector<::cpp2::MyStruct>> ComplexNestedStruct::get_mapKeyIntValList() && {
  return std::move(mapKeyIntValList);
}

const ::std::map<::std::int32_t, ::std::set<bool>>& ComplexNestedStruct::get_mapKeyIntValSet() const& {
  return mapKeyIntValSet;
}

::std::map<::std::int32_t, ::std::set<bool>> ComplexNestedStruct::get_mapKeyIntValSet() && {
  return std::move(mapKeyIntValSet);
}

const ::std::map<::std::set<bool>, ::cpp2::MyEnum>& ComplexNestedStruct::get_mapKeySetValInt() const& {
  return mapKeySetValInt;
}

::std::map<::std::set<bool>, ::cpp2::MyEnum> ComplexNestedStruct::get_mapKeySetValInt() && {
  return std::move(mapKeySetValInt);
}

const ::std::map<::std::vector<::std::int32_t>, ::std::set<::std::map<double, ::std::string>>>& ComplexNestedStruct::get_mapKeyListValSet() const& {
  return mapKeyListValSet;
}

::std::map<::std::vector<::std::int32_t>, ::std::set<::std::map<double, ::std::string>>> ComplexNestedStruct::get_mapKeyListValSet() && {
  return std::move(mapKeyListValSet);
}


void swap(ComplexNestedStruct& a, ComplexNestedStruct& b) {
  using ::std::swap;
  swap(a.setOfSetOfInt_ref().value(), b.setOfSetOfInt_ref().value());
  swap(a.listofListOfListOfListOfEnum_ref().value(), b.listofListOfListOfListOfEnum_ref().value());
  swap(a.listOfListOfMyStruct_ref().value(), b.listOfListOfMyStruct_ref().value());
  swap(a.setOfListOfListOfLong_ref().value(), b.setOfListOfListOfLong_ref().value());
  swap(a.setOfSetOfsetOfLong_ref().value(), b.setOfSetOfsetOfLong_ref().value());
  swap(a.mapStructListOfListOfLong_ref().value(), b.mapStructListOfListOfLong_ref().value());
  swap(a.mKeyStructValInt_ref().value(), b.mKeyStructValInt_ref().value());
  swap(a.listOfMapKeyIntValInt_ref().value(), b.listOfMapKeyIntValInt_ref().value());
  swap(a.listOfMapKeyStrValList_ref().value(), b.listOfMapKeyStrValList_ref().value());
  swap(a.mapKeySetValLong_ref().value(), b.mapKeySetValLong_ref().value());
  swap(a.mapKeyListValLong_ref().value(), b.mapKeyListValLong_ref().value());
  swap(a.mapKeyMapValMap_ref().value(), b.mapKeyMapValMap_ref().value());
  swap(a.mapKeySetValMap_ref().value(), b.mapKeySetValMap_ref().value());
  swap(a.NestedMaps_ref().value(), b.NestedMaps_ref().value());
  swap(a.mapKeyIntValList_ref().value(), b.mapKeyIntValList_ref().value());
  swap(a.mapKeyIntValSet_ref().value(), b.mapKeyIntValSet_ref().value());
  swap(a.mapKeySetValInt_ref().value(), b.mapKeySetValInt_ref().value());
  swap(a.mapKeyListValSet_ref().value(), b.mapKeyListValSet_ref().value());
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
  swap(a.__isset, b.__isset);
THRIFT_IGNORE_ISSET_USE_WARNING_END
}

template void ComplexNestedStruct::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t ComplexNestedStruct::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t ComplexNestedStruct::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t ComplexNestedStruct::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void ComplexNestedStruct::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t ComplexNestedStruct::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t ComplexNestedStruct::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t ComplexNestedStruct::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        ComplexNestedStruct,
        ::apache::thrift::type_class::list<::apache::thrift::type_class::list<::apache::thrift::type_class::structure>>,
        ::std::vector<::std::vector<::cpp2::MyStruct>>>,
    "inconsistent use of json option");
static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        ComplexNestedStruct,
        ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::list<::apache::thrift::type_class::list<::apache::thrift::type_class::structure>>>,
        ::std::map<::std::int32_t, ::std::vector<::std::vector<::cpp2::MyStruct>>>>,
    "inconsistent use of json option");
static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        ComplexNestedStruct,
        ::apache::thrift::type_class::map<::apache::thrift::type_class::structure, ::apache::thrift::type_class::integral>,
        ::std::map<::cpp2::MyStruct, ::std::int32_t>>,
    "inconsistent use of json option");
static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        ComplexNestedStruct,
        ::apache::thrift::type_class::list<::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::list<::apache::thrift::type_class::structure>>>,
        ::std::vector<::std::map<::std::string, ::std::vector<::cpp2::MyStruct>>>>,
    "inconsistent use of json option");
static_assert(
    ::apache::thrift::detail::st::gen_check_json<
        ComplexNestedStruct,
        ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::list<::apache::thrift::type_class::structure>>,
        ::std::map<::std::int32_t, ::std::vector<::cpp2::MyStruct>>>,
    "inconsistent use of json option");

static_assert(
    ::apache::thrift::detail::st::gen_check_nimble<
        ComplexNestedStruct,
        ::apache::thrift::type_class::list<::apache::thrift::type_class::list<::apache::thrift::type_class::structure>>,
        ::std::vector<::std::vector<::cpp2::MyStruct>>>,
    "inconsistent use of nimble option");
static_assert(
    ::apache::thrift::detail::st::gen_check_nimble<
        ComplexNestedStruct,
        ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::list<::apache::thrift::type_class::list<::apache::thrift::type_class::structure>>>,
        ::std::map<::std::int32_t, ::std::vector<::std::vector<::cpp2::MyStruct>>>>,
    "inconsistent use of nimble option");
static_assert(
    ::apache::thrift::detail::st::gen_check_nimble<
        ComplexNestedStruct,
        ::apache::thrift::type_class::map<::apache::thrift::type_class::structure, ::apache::thrift::type_class::integral>,
        ::std::map<::cpp2::MyStruct, ::std::int32_t>>,
    "inconsistent use of nimble option");
static_assert(
    ::apache::thrift::detail::st::gen_check_nimble<
        ComplexNestedStruct,
        ::apache::thrift::type_class::list<::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::list<::apache::thrift::type_class::structure>>>,
        ::std::vector<::std::map<::std::string, ::std::vector<::cpp2::MyStruct>>>>,
    "inconsistent use of nimble option");
static_assert(
    ::apache::thrift::detail::st::gen_check_nimble<
        ComplexNestedStruct,
        ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::list<::apache::thrift::type_class::structure>>,
        ::std::map<::std::int32_t, ::std::vector<::cpp2::MyStruct>>>,
    "inconsistent use of nimble option");

} // cpp2

namespace apache {
namespace thrift {
namespace detail {

void TccStructTraits<::cpp2::reqXcep>::translateFieldName(
    folly::StringPiece _fname,
    int16_t& fid,
    apache::thrift::protocol::TType& _ftype) noexcept {
  using data = apache::thrift::TStructDataStorage<::cpp2::reqXcep>;
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
reqXcep::reqXcep(const reqXcep&) = default;
THRIFT_IGNORE_ISSET_USE_WARNING_END
THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
reqXcep::reqXcep(reqXcep&& other) noexcept  :
    message(std::move(other.message)),
    errorCode(std::move(other.errorCode)) {}


reqXcep& reqXcep::operator=(FOLLY_MAYBE_UNUSED reqXcep&& other) noexcept {
    this->message = std::move(other.message);
    this->errorCode = std::move(other.errorCode);
    return *this;
}
THRIFT_IGNORE_ISSET_USE_WARNING_END


THRIFT_IGNORE_ISSET_USE_WARNING_BEGIN
reqXcep::reqXcep(apache::thrift::FragileConstructor, ::std::string message__arg, ::std::int32_t errorCode__arg) :
    message(std::move(message__arg)),
    errorCode(std::move(errorCode__arg)) {}
THRIFT_IGNORE_ISSET_USE_WARNING_END
void reqXcep::__clear() {
  // clear all fields
  this->message = apache::thrift::StringTraits<std::string>::fromStringLiteral("");
  this->errorCode = 0;
}

bool reqXcep::operator==(const reqXcep& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.message == rhs.message)) {
    return false;
  }
  if (!(lhs.errorCode == rhs.errorCode)) {
    return false;
  }
  return true;
}

bool reqXcep::operator<(const reqXcep& rhs) const {
  (void)rhs;
  auto& lhs = *this;
  (void)lhs;
  if (!(lhs.message == rhs.message)) {
    return lhs.message < rhs.message;
  }
  if (!(lhs.errorCode == rhs.errorCode)) {
    return lhs.errorCode < rhs.errorCode;
  }
  return false;
}


void swap(reqXcep& a, reqXcep& b) {
  using ::std::swap;
  swap(a.message_ref().value(), b.message_ref().value());
  swap(a.errorCode_ref().value(), b.errorCode_ref().value());
}

template void reqXcep::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
template uint32_t reqXcep::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t reqXcep::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t reqXcep::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template void reqXcep::readNoXfer<>(apache::thrift::CompactProtocolReader*);
template uint32_t reqXcep::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t reqXcep::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t reqXcep::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;



} // cpp2
