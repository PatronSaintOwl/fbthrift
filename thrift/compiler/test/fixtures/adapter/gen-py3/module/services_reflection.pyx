#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from thrift.py3.reflection cimport (
  MethodSpec as __MethodSpec,
  ArgumentSpec as __ArgumentSpec,
  NumberType as __NumberType,
)

import folly.iobuf as _fbthrift_iobuf

cimport facebook.thrift.annotation.cpp.types as _facebook_thrift_annotation_cpp_types
cimport facebook.thrift.annotation.thrift.types as _facebook_thrift_annotation_thrift_types

cimport module.types as _module_types


cdef __InterfaceSpec get_reflection__Service(bint for_clients):
    cdef __InterfaceSpec spec = __InterfaceSpec._fbthrift_create(
        name="Service",
        annotations={
        },
    )
    spec.add_method(
        __MethodSpec._fbthrift_create(
            name="func",
            arguments=(
                __ArgumentSpec._fbthrift_create(
                    name="arg1",
                    type=str,
                    kind=__NumberType.NOT_A_NUMBER,
                    annotations={
                    },
                ),
                __ArgumentSpec._fbthrift_create(
                    name="arg2",
                    type=str,
                    kind=__NumberType.NOT_A_NUMBER,
                    annotations={
                    },
                ),
                __ArgumentSpec._fbthrift_create(
                    name="arg3",
                    type=_module_types.Foo,
                    kind=__NumberType.NOT_A_NUMBER,
                    annotations={
                    },
                ),
            ),
            result=int,
            result_kind=__NumberType.I32,
            exceptions=(
            ),
            annotations={
            },
        )
    )
    return spec
