#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#
import enum

import folly.iobuf as _fbthrift_iobuf
import thrift.python.types as _fbthrift_py3lite_types
import thrift.python.exceptions as _fbthrift_py3lite_exceptions


import facebook.thrift.annotation.hack.lite_types


class MyStruct(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            True,  # isUnqualified
            "MyIntField",  # name
            _fbthrift_py3lite_types.typeinfo_i64,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            2,  # id
            True,  # isUnqualified
            "MyStringField",  # name
            _fbthrift_py3lite_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            3,  # id
            True,  # isUnqualified
            "MyDataField",  # name
            lambda: _fbthrift_py3lite_types.StructTypeInfo(MyDataItem),  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            4,  # id
            True,  # isUnqualified
            "myEnum",  # name
            lambda: _fbthrift_py3lite_types.EnumTypeInfo(MyEnum),  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            5,  # id
            True,  # isUnqualified
            "oneway",  # name
            _fbthrift_py3lite_types.typeinfo_bool,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            6,  # id
            True,  # isUnqualified
            "readonly",  # name
            _fbthrift_py3lite_types.typeinfo_bool,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            7,  # id
            True,  # isUnqualified
            "idempotent",  # name
            _fbthrift_py3lite_types.typeinfo_bool,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            8,  # id
            True,  # isUnqualified
            "floatSet",  # name
            lambda: _fbthrift_py3lite_types.SetTypeInfo(_fbthrift_py3lite_types.typeinfo_float),  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.MyStruct"

    @staticmethod
    def __get_thrift_uri__():
        return "test.dev/fixtures/basic/MyStruct"

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_MyStruct()



class MyDataItem(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.MyDataItem"

    @staticmethod
    def __get_thrift_uri__():
        return "test.dev/fixtures/basic/MyDataItem"

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_MyDataItem()



class MyUnion(metaclass=_fbthrift_py3lite_types.UnionMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            True,  # isUnqualified
            "myEnum",  # name
            lambda: _fbthrift_py3lite_types.EnumTypeInfo(MyEnum),  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            2,  # id
            True,  # isUnqualified
            "myStruct",  # name
            lambda: _fbthrift_py3lite_types.StructTypeInfo(MyStruct),  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            3,  # id
            True,  # isUnqualified
            "myDataItem",  # name
            lambda: _fbthrift_py3lite_types.StructTypeInfo(MyDataItem),  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            4,  # id
            True,  # isUnqualified
            "floatSet",  # name
            lambda: _fbthrift_py3lite_types.SetTypeInfo(_fbthrift_py3lite_types.typeinfo_float),  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.MyUnion"

    @staticmethod
    def __get_thrift_uri__():
        return "test.dev/fixtures/basic/MyUnion"

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_MyUnion()


# This unfortunately has to be down here to prevent circular imports
import module.lite_metadata

class MyEnum(_fbthrift_py3lite_types.Enum, enum.Enum):
    MyValue1 = 0
    MyValue2 = 1
    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.MyEnum"

    @staticmethod
    def __get_metadata__():
        return module.lite_metadata.gen_metadata_enum_MyEnum()

def _fbthrift_metadata__struct_MyStruct():
    return module.lite_metadata.gen_metadata_struct_MyStruct()
def _fbthrift_metadata__struct_MyDataItem():
    return module.lite_metadata.gen_metadata_struct_MyDataItem()
def _fbthrift_metadata__struct_MyUnion():
    return module.lite_metadata.gen_metadata_struct_MyUnion()

_fbthrift_all_structs = [
    MyStruct,
    MyDataItem,
    MyUnion,
]
_fbthrift_py3lite_types.fill_specs(*_fbthrift_all_structs)


class _fbthrift_MyService_ping_args(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
    )

class _fbthrift_MyService_ping_result(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
    )


class _fbthrift_MyService_getRandomData_args(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
    )

class _fbthrift_MyService_getRandomData_result(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            0,  # id
            False,  # isUnqualified
            "success",  # name
            _fbthrift_py3lite_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )


class _fbthrift_MyService_sink_args(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            True,  # isUnqualified
            "sink",  # name
            _fbthrift_py3lite_types.typeinfo_i64,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

class _fbthrift_MyService_sink_result(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
    )


class _fbthrift_MyService_putDataById_args(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            True,  # isUnqualified
            "id",  # name
            _fbthrift_py3lite_types.typeinfo_i64,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            2,  # id
            True,  # isUnqualified
            "data",  # name
            _fbthrift_py3lite_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

class _fbthrift_MyService_putDataById_result(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
    )


class _fbthrift_MyService_hasDataById_args(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            True,  # isUnqualified
            "id",  # name
            _fbthrift_py3lite_types.typeinfo_i64,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

class _fbthrift_MyService_hasDataById_result(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            0,  # id
            False,  # isUnqualified
            "success",  # name
            _fbthrift_py3lite_types.typeinfo_bool,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )


class _fbthrift_MyService_getDataById_args(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            True,  # isUnqualified
            "id",  # name
            _fbthrift_py3lite_types.typeinfo_i64,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

class _fbthrift_MyService_getDataById_result(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            0,  # id
            False,  # isUnqualified
            "success",  # name
            _fbthrift_py3lite_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )


class _fbthrift_MyService_deleteDataById_args(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            True,  # isUnqualified
            "id",  # name
            _fbthrift_py3lite_types.typeinfo_i64,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

class _fbthrift_MyService_deleteDataById_result(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
    )


class _fbthrift_MyService_lobDataById_args(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            True,  # isUnqualified
            "id",  # name
            _fbthrift_py3lite_types.typeinfo_i64,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            2,  # id
            True,  # isUnqualified
            "data",  # name
            _fbthrift_py3lite_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )



class _fbthrift_MyService_invalid_return_for_hack_args(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
    )

class _fbthrift_MyService_invalid_return_for_hack_result(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            0,  # id
            False,  # isUnqualified
            "success",  # name
            lambda: _fbthrift_py3lite_types.SetTypeInfo(_fbthrift_py3lite_types.typeinfo_float),  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )


class _fbthrift_DbMixedStackArguments_getDataByKey0_args(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            True,  # isUnqualified
            "key",  # name
            _fbthrift_py3lite_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

class _fbthrift_DbMixedStackArguments_getDataByKey0_result(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            0,  # id
            False,  # isUnqualified
            "success",  # name
            _fbthrift_py3lite_types.typeinfo_binary,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )


class _fbthrift_DbMixedStackArguments_getDataByKey1_args(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            True,  # isUnqualified
            "key",  # name
            _fbthrift_py3lite_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

class _fbthrift_DbMixedStackArguments_getDataByKey1_result(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            0,  # id
            False,  # isUnqualified
            "success",  # name
            _fbthrift_py3lite_types.typeinfo_binary,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )


_fbthrift_py3lite_types.fill_specs(
    _fbthrift_MyService_ping_args,
    _fbthrift_MyService_ping_result,
    _fbthrift_MyService_getRandomData_args,
    _fbthrift_MyService_getRandomData_result,
    _fbthrift_MyService_sink_args,
    _fbthrift_MyService_sink_result,
    _fbthrift_MyService_putDataById_args,
    _fbthrift_MyService_putDataById_result,
    _fbthrift_MyService_hasDataById_args,
    _fbthrift_MyService_hasDataById_result,
    _fbthrift_MyService_getDataById_args,
    _fbthrift_MyService_getDataById_result,
    _fbthrift_MyService_deleteDataById_args,
    _fbthrift_MyService_deleteDataById_result,
    _fbthrift_MyService_lobDataById_args,
    _fbthrift_MyService_invalid_return_for_hack_args,
    _fbthrift_MyService_invalid_return_for_hack_result,
    _fbthrift_DbMixedStackArguments_getDataByKey0_args,
    _fbthrift_DbMixedStackArguments_getDataByKey0_result,
    _fbthrift_DbMixedStackArguments_getDataByKey1_args,
    _fbthrift_DbMixedStackArguments_getDataByKey1_result,
)
