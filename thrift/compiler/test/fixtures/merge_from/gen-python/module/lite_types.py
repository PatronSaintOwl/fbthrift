#
# Autogenerated by Thrift
#
# DO NOT EDIT
#  @generated
#
import folly.iobuf as _fbthrift_iobuf
import thrift.python.types as _fbthrift_py3lite_types
import thrift.python.exceptions as _fbthrift_py3lite_exceptions


import facebook.thrift.annotation.meta.lite_types

import foo.lite_types


class Fields(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            100,  # id
            True,  # isUnqualified
            "injected_field",  # name
            _fbthrift_py3lite_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.Fields"

    @staticmethod
    def __get_thrift_uri__():
        return None

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_Fields()



class FieldsInjectedToEmptyStruct(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            100,  # id
            True,  # isUnqualified
            "injected_field",  # name
            _fbthrift_py3lite_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.FieldsInjectedToEmptyStruct"

    @staticmethod
    def __get_thrift_uri__():
        return None

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_FieldsInjectedToEmptyStruct()



class FieldsInjectedToStruct(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            True,  # isUnqualified
            "string_field",  # name
            _fbthrift_py3lite_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            100,  # id
            True,  # isUnqualified
            "injected_field",  # name
            _fbthrift_py3lite_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.FieldsInjectedToStruct"

    @staticmethod
    def __get_thrift_uri__():
        return None

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_FieldsInjectedToStruct()



class FieldsInjectedWithIncludedStruct(metaclass=_fbthrift_py3lite_types.StructMeta):
    _fbthrift_SPEC = (
        (
            1,  # id
            True,  # isUnqualified
            "string_field",  # name
            _fbthrift_py3lite_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            100,  # id
            True,  # isUnqualified
            "injected_field",  # name
            _fbthrift_py3lite_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            101,  # id
            False,  # isUnqualified
            "injected_structured_annotation_field",  # name
            _fbthrift_py3lite_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
        (
            102,  # id
            False,  # isUnqualified
            "injected_unstructured_annotation_field",  # name
            _fbthrift_py3lite_types.typeinfo_string,  # typeinfo
            None,  # default value
            None,  # adapter class
        ),
    )

    @staticmethod
    def __get_thrift_name__() -> str:
        return "module.FieldsInjectedWithIncludedStruct"

    @staticmethod
    def __get_thrift_uri__():
        return None

    @staticmethod
    def __get_metadata__():
        return _fbthrift_metadata__struct_FieldsInjectedWithIncludedStruct()


# This unfortunately has to be down here to prevent circular imports
import module.lite_metadata


def _fbthrift_metadata__struct_Fields():
    return module.lite_metadata.gen_metadata_struct_Fields()
def _fbthrift_metadata__struct_FieldsInjectedToEmptyStruct():
    return module.lite_metadata.gen_metadata_struct_FieldsInjectedToEmptyStruct()
def _fbthrift_metadata__struct_FieldsInjectedToStruct():
    return module.lite_metadata.gen_metadata_struct_FieldsInjectedToStruct()
def _fbthrift_metadata__struct_FieldsInjectedWithIncludedStruct():
    return module.lite_metadata.gen_metadata_struct_FieldsInjectedWithIncludedStruct()

_fbthrift_all_structs = [
    Fields,
    FieldsInjectedToEmptyStruct,
    FieldsInjectedToStruct,
    FieldsInjectedWithIncludedStruct,
]
_fbthrift_py3lite_types.fill_specs(*_fbthrift_all_structs)
