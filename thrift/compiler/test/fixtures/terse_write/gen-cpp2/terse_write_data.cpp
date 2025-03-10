/**
 * Autogenerated by Thrift for src/terse_write.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */

#include "thrift/compiler/test/fixtures/terse_write/gen-cpp2/terse_write_data.h"

#include <thrift/lib/cpp2/gen/module_data_cpp.h>

namespace apache {
namespace thrift {

const std::array<::apache::thrift::test::MyEnum, 2> TEnumDataStorage<::apache::thrift::test::MyEnum>::values = {{
  type::ME0,
  type::ME1,
}};
const std::array<folly::StringPiece, 2> TEnumDataStorage<::apache::thrift::test::MyEnum>::names = {{
  "ME0",
  "ME1",
}};

const std::array<folly::StringPiece, 0> TStructDataStorage<::apache::thrift::test::MyStruct>::fields_names = {{
}};
const std::array<int16_t, 0> TStructDataStorage<::apache::thrift::test::MyStruct>::fields_ids = {{
}};
const std::array<protocol::TType, 0> TStructDataStorage<::apache::thrift::test::MyStruct>::fields_types = {{
}};

const std::array<folly::StringPiece, 14> TStructDataStorage<::apache::thrift::test::StructLevelTerseStruct>::fields_names = {{
  "bool_field",
  "byte_field",
  "short_field",
  "int_field",
  "long_field",
  "float_field",
  "double_field",
  "string_field",
  "binary_field",
  "enum_field",
  "list_field",
  "set_field",
  "map_field",
  "struct_field",
}};
const std::array<int16_t, 14> TStructDataStorage<::apache::thrift::test::StructLevelTerseStruct>::fields_ids = {{
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
}};
const std::array<protocol::TType, 14> TStructDataStorage<::apache::thrift::test::StructLevelTerseStruct>::fields_types = {{
  TType::T_BOOL,
  TType::T_BYTE,
  TType::T_I16,
  TType::T_I32,
  TType::T_I64,
  TType::T_FLOAT,
  TType::T_DOUBLE,
  TType::T_STRING,
  TType::T_STRING,
  TType::T_I32,
  TType::T_LIST,
  TType::T_SET,
  TType::T_MAP,
  TType::T_STRUCT,
}};

const std::array<folly::StringPiece, 28> TStructDataStorage<::apache::thrift::test::FieldLevelTerseStruct>::fields_names = {{
  "terse_bool_field",
  "terse_byte_field",
  "terse_short_field",
  "terse_int_field",
  "terse_long_field",
  "terse_float_field",
  "terse_double_field",
  "terse_string_field",
  "terse_binary_field",
  "terse_enum_field",
  "terse_list_field",
  "terse_set_field",
  "terse_map_field",
  "terse_struct_field",
  "bool_field",
  "byte_field",
  "short_field",
  "int_field",
  "long_field",
  "float_field",
  "double_field",
  "string_field",
  "binary_field",
  "enum_field",
  "list_field",
  "set_field",
  "map_field",
  "struct_field",
}};
const std::array<int16_t, 28> TStructDataStorage<::apache::thrift::test::FieldLevelTerseStruct>::fields_ids = {{
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
  22,
  23,
  24,
  25,
  26,
  27,
  28,
}};
const std::array<protocol::TType, 28> TStructDataStorage<::apache::thrift::test::FieldLevelTerseStruct>::fields_types = {{
  TType::T_BOOL,
  TType::T_BYTE,
  TType::T_I16,
  TType::T_I32,
  TType::T_I64,
  TType::T_FLOAT,
  TType::T_DOUBLE,
  TType::T_STRING,
  TType::T_STRING,
  TType::T_I32,
  TType::T_LIST,
  TType::T_SET,
  TType::T_MAP,
  TType::T_STRUCT,
  TType::T_BOOL,
  TType::T_BYTE,
  TType::T_I16,
  TType::T_I32,
  TType::T_I64,
  TType::T_FLOAT,
  TType::T_DOUBLE,
  TType::T_STRING,
  TType::T_STRING,
  TType::T_I32,
  TType::T_LIST,
  TType::T_SET,
  TType::T_MAP,
  TType::T_STRUCT,
}};

} // namespace thrift
} // namespace apache
