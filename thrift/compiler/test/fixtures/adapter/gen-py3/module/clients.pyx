#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
from libc.stdint cimport (
    int8_t as cint8_t,
    int16_t as cint16_t,
    int32_t as cint32_t,
    int64_t as cint64_t,
)
from libcpp.memory cimport shared_ptr, make_shared, unique_ptr, make_unique
from libcpp.string cimport string
from libcpp cimport bool as cbool
from cpython cimport bool as pbool
from libcpp.vector cimport vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap
from libcpp.utility cimport move as cmove
from cython.operator cimport dereference as deref, typeid
from cpython.ref cimport PyObject
from thrift.py3.client cimport cRequestChannel_ptr, makeClientWrapper, cClientWrapper
from thrift.py3.exceptions cimport try_make_shared_exception, create_py_exception
from folly cimport cFollyTry, cFollyUnit, c_unit
from folly.cast cimport down_cast_ptr
from libcpp.typeinfo cimport type_info
import thrift.py3.types
cimport thrift.py3.types
import thrift.py3.client
cimport thrift.py3.client
from thrift.py3.common cimport (
    RpcOptions as __RpcOptions,
    cThriftServiceMetadataResponse as __fbthrift_cThriftServiceMetadataResponse,
    ServiceMetadata,
    MetadataBox as __MetadataBox,
)

from folly.futures cimport bridgeFutureWith
from folly.executor cimport get_executor
cimport folly.iobuf as _fbthrift_iobuf
import folly.iobuf as _fbthrift_iobuf
from folly.iobuf cimport move as move_iobuf
cimport cython

import sys
import types as _py_types
from asyncio import get_event_loop as asyncio_get_event_loop, shield as asyncio_shield, InvalidStateError as asyncio_InvalidStateError

cimport module.types as _module_types
import module.types as _module_types
cimport facebook.thrift.annotation.cpp.types as _facebook_thrift_annotation_cpp_types
import facebook.thrift.annotation.cpp.types as _facebook_thrift_annotation_cpp_types
cimport facebook.thrift.annotation.thrift.types as _facebook_thrift_annotation_thrift_types
import facebook.thrift.annotation.thrift.types as _facebook_thrift_annotation_thrift_types

cimport module.services_reflection as _services_reflection

from module.clients_wrapper cimport cServiceAsyncClient, cServiceClientWrapper


cdef void Service_func_callback(
    cFollyTry[cint32_t]&& result,
    PyObject* userdata
):
    client, pyfuture, options = <object> userdata  
    if result.hasException():
        pyfuture.set_exception(create_py_exception(result.exception(), <__RpcOptions>options))
    else:
        try:
            pyfuture.set_result(result.value())
        except Exception as ex:
            pyfuture.set_exception(ex.with_traceback(None))


cdef object _Service_annotations = _py_types.MappingProxyType({
})


@cython.auto_pickle(False)
cdef class Service(thrift.py3.client.Client):
    annotations = _Service_annotations

    cdef const type_info* _typeid(Service self):
        return &typeid(cServiceAsyncClient)

    cdef bind_client(Service self, cRequestChannel_ptr&& channel):
        self._client = makeClientWrapper[cServiceAsyncClient, cServiceClientWrapper](
            cmove(channel)
        )

    @cython.always_allow_keywords(True)
    def func(
            Service self,
            str arg1 not None,
            str arg2 not None,
            _module_types.Foo arg3 not None,
            __RpcOptions rpc_options=None
    ):
        if rpc_options is None:
            rpc_options = <__RpcOptions>__RpcOptions.__new__(__RpcOptions)
        self._check_connect_future()
        __loop = asyncio_get_event_loop()
        __future = __loop.create_future()
        __userdata = (self, __future, rpc_options)
        bridgeFutureWith[cint32_t](
            self._executor,
            down_cast_ptr[cServiceClientWrapper, cClientWrapper](self._client.get()).func(rpc_options._cpp_obj, 
                arg1.encode('UTF-8'),
                arg2.encode('UTF-8'),
                deref((<_module_types.Foo>arg3)._cpp_obj),
            ),
            Service_func_callback,
            <PyObject *> __userdata
        )
        return asyncio_shield(__future)


    @classmethod
    def __get_reflection__(cls):
        return _services_reflection.get_reflection__Service(for_clients=True)

    @staticmethod
    def __get_metadata__():
        cdef __fbthrift_cThriftServiceMetadataResponse response
        ServiceMetadata[_services_reflection.cServiceSvIf].gen(response)
        return __MetadataBox.box(cmove(deref(response.metadata_ref())))

    @staticmethod
    def __get_thrift_name__():
        return "module.Service"

