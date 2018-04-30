#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
from libcpp.memory cimport shared_ptr, make_shared, unique_ptr, make_unique
from libcpp.string cimport string
from libcpp cimport bool as cbool
from cpython cimport bool as pbool
from libc.stdint cimport int8_t, int16_t, int32_t, int64_t
from libcpp.vector cimport vector as vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap
from cython.operator cimport dereference as deref, typeid
from cpython.ref cimport PyObject
from thrift.py3.client cimport cRequestChannel_ptr, makeClientWrapper
from thrift.py3.exceptions cimport try_make_shared_exception, create_py_exception
from folly cimport cFollyTry, cFollyUnit, c_unit
from libcpp.typeinfo cimport type_info
import thrift.py3.types
cimport thrift.py3.types
import thrift.py3.client
cimport thrift.py3.client
from thrift.py3.common cimport RpcOptions as __RpcOptions
from thrift.py3.common import RpcOptions as __RpcOptions

from folly.futures cimport bridgeFutureWith
from folly.executor cimport get_executor
cimport cython

import sys
import types as _py_types
from asyncio import get_event_loop as asyncio_get_event_loop, shield as asyncio_shield, InvalidStateError as asyncio_InvalidStateError

cimport module.types as _module_types
import module.types as _module_types

from module.clients_wrapper cimport cMyRootAsyncClient, cMyRootClientWrapper
from module.clients_wrapper cimport cMyNodeAsyncClient, cMyNodeClientWrapper
from module.clients_wrapper cimport cMyLeafAsyncClient, cMyLeafClientWrapper


cdef void MyRoot_do_root_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* userdata
):
    client, pyfuture, options = <object> userdata  
    if result.hasException():
        pyfuture.set_exception(create_py_exception(result.exception(), <__RpcOptions>options))
    else:
        try:
            pyfuture.set_result(None)
        except Exception as ex:
            pyfuture.set_exception(ex.with_traceback(None))

cdef void MyNode_do_mid_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* userdata
):
    client, pyfuture, options = <object> userdata  
    if result.hasException():
        pyfuture.set_exception(create_py_exception(result.exception(), <__RpcOptions>options))
    else:
        try:
            pyfuture.set_result(None)
        except Exception as ex:
            pyfuture.set_exception(ex.with_traceback(None))

cdef void MyLeaf_do_leaf_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* userdata
):
    client, pyfuture, options = <object> userdata  
    if result.hasException():
        pyfuture.set_exception(create_py_exception(result.exception(), <__RpcOptions>options))
    else:
        try:
            pyfuture.set_result(None)
        except Exception as ex:
            pyfuture.set_exception(ex.with_traceback(None))


cdef object _MyRoot_annotations = _py_types.MappingProxyType({
})


cdef class MyRoot(thrift.py3.client.Client):
    annotations = _MyRoot_annotations

    def __cinit__(MyRoot self):
        loop = asyncio_get_event_loop()
        self._connect_future = loop.create_future()
        self._deferred_headers = {}

    cdef const type_info* _typeid(MyRoot self):
        return &typeid(cMyRootAsyncClient)

    @staticmethod
    cdef _module_MyRoot_set_client(MyRoot inst, shared_ptr[cMyRootClientWrapper] c_obj):
        """So the class hierarchy talks to the correct pointer type"""
        inst._module_MyRoot_client = c_obj

    cdef _module_MyRoot_reset_client(MyRoot self):
        """So the class hierarchy resets the shared pointer up the chain"""
        self._module_MyRoot_client.reset()

    def __dealloc__(MyRoot self):
        if self._connect_future.done() and not self._connect_future.exception():
            print(f'thrift-py3 client: {self!r} was not cleaned up, use the async context manager', file=sys.stderr)
            if self._module_MyRoot_client:
                deref(self._module_MyRoot_client).disconnect().get()
        self._module_MyRoot_reset_client()

    cdef bind_client(MyRoot self, cRequestChannel_ptr&& channel):
        MyRoot._module_MyRoot_set_client(
            self,
            makeClientWrapper[cMyRootAsyncClient, cMyRootClientWrapper](
                thrift.py3.client.move(channel)
            ),
        )

    async def __aenter__(MyRoot self):
        await asyncio_shield(self._connect_future)
        if self._context_entered:
            raise asyncio_InvalidStateError('Client context has been used already')
        self._context_entered = True
        for key, value in self._deferred_headers.items():
            self.set_persistent_header(key, value)
        self._deferred_headers = None
        return self

    def __aexit__(MyRoot self, *exc):
        self._check_connect_future()
        loop = asyncio_get_event_loop()
        future = loop.create_future()
        userdata = (self, future)
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._module_MyRoot_client).disconnect(),
            closed_MyRoot_py3_client_callback,
            <PyObject *>userdata  # So we keep client alive until disconnect
        )
        # To break any future usage of this client
        # Also to prevent dealloc from trying to disconnect in a blocking way.
        badfuture = loop.create_future()
        badfuture.set_exception(asyncio_InvalidStateError('Client Out of Context'))
        badfuture.exception()
        self._connect_future = badfuture
        return asyncio_shield(future)

    def set_persistent_header(MyRoot self, str key, str value):
        if not self._module_MyRoot_client:
            self._deferred_headers[key] = value
            return

        cdef string ckey = <bytes> key.encode('utf-8')
        cdef string cvalue = <bytes> value.encode('utf-8')
        deref(self._module_MyRoot_client).setPersistentHeader(ckey, cvalue)

    @cython.always_allow_keywords(True)
    def do_root(
            MyRoot self,
            __RpcOptions rpc_options=None
    ):
        if rpc_options is None:
            rpc_options = <__RpcOptions>__RpcOptions.__new__(__RpcOptions)
        self._check_connect_future()
        __loop = asyncio_get_event_loop()
        __future = __loop.create_future()
        __userdata = (self, __future, rpc_options)
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._module_MyRoot_client).do_root(rpc_options._cpp_obj, 
            ),
            MyRoot_do_root_callback,
            <PyObject *> __userdata
        )
        return asyncio_shield(__future)



cdef void closed_MyRoot_py3_client_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* userdata,
):
    client, pyfuture = <object> userdata 
    pyfuture.set_result(None)
cdef object _MyNode_annotations = _py_types.MappingProxyType({
})


cdef class MyNode(MyRoot):
    annotations = _MyNode_annotations

    def __cinit__(MyNode self):
        loop = asyncio_get_event_loop()
        self._connect_future = loop.create_future()
        self._deferred_headers = {}

    cdef const type_info* _typeid(MyNode self):
        return &typeid(cMyNodeAsyncClient)

    @staticmethod
    cdef _module_MyNode_set_client(MyNode inst, shared_ptr[cMyNodeClientWrapper] c_obj):
        """So the class hierarchy talks to the correct pointer type"""
        inst._module_MyNode_client = c_obj
        MyRoot._module_MyRoot_set_client(inst, <shared_ptr[cMyRootClientWrapper]>c_obj)

    cdef _module_MyNode_reset_client(MyNode self):
        """So the class hierarchy resets the shared pointer up the chain"""
        self._module_MyNode_client.reset()
        MyRoot._module_MyRoot_reset_client(self)

    def __dealloc__(MyNode self):
        if self._connect_future.done() and not self._connect_future.exception():
            print(f'thrift-py3 client: {self!r} was not cleaned up, use the async context manager', file=sys.stderr)
            if self._module_MyNode_client:
                deref(self._module_MyNode_client).disconnect().get()
        self._module_MyNode_reset_client()

    cdef bind_client(MyNode self, cRequestChannel_ptr&& channel):
        MyNode._module_MyNode_set_client(
            self,
            makeClientWrapper[cMyNodeAsyncClient, cMyNodeClientWrapper](
                thrift.py3.client.move(channel)
            ),
        )

    async def __aenter__(MyNode self):
        await asyncio_shield(self._connect_future)
        if self._context_entered:
            raise asyncio_InvalidStateError('Client context has been used already')
        self._context_entered = True
        for key, value in self._deferred_headers.items():
            self.set_persistent_header(key, value)
        self._deferred_headers = None
        return self

    def __aexit__(MyNode self, *exc):
        self._check_connect_future()
        loop = asyncio_get_event_loop()
        future = loop.create_future()
        userdata = (self, future)
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._module_MyNode_client).disconnect(),
            closed_MyNode_py3_client_callback,
            <PyObject *>userdata  # So we keep client alive until disconnect
        )
        # To break any future usage of this client
        # Also to prevent dealloc from trying to disconnect in a blocking way.
        badfuture = loop.create_future()
        badfuture.set_exception(asyncio_InvalidStateError('Client Out of Context'))
        badfuture.exception()
        self._connect_future = badfuture
        return asyncio_shield(future)

    def set_persistent_header(MyNode self, str key, str value):
        if not self._module_MyNode_client:
            self._deferred_headers[key] = value
            return

        cdef string ckey = <bytes> key.encode('utf-8')
        cdef string cvalue = <bytes> value.encode('utf-8')
        deref(self._module_MyNode_client).setPersistentHeader(ckey, cvalue)

    @cython.always_allow_keywords(True)
    def do_mid(
            MyNode self,
            __RpcOptions rpc_options=None
    ):
        if rpc_options is None:
            rpc_options = <__RpcOptions>__RpcOptions.__new__(__RpcOptions)
        self._check_connect_future()
        __loop = asyncio_get_event_loop()
        __future = __loop.create_future()
        __userdata = (self, __future, rpc_options)
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._module_MyNode_client).do_mid(rpc_options._cpp_obj, 
            ),
            MyNode_do_mid_callback,
            <PyObject *> __userdata
        )
        return asyncio_shield(__future)



cdef void closed_MyNode_py3_client_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* userdata,
):
    client, pyfuture = <object> userdata 
    pyfuture.set_result(None)
cdef object _MyLeaf_annotations = _py_types.MappingProxyType({
})


cdef class MyLeaf(MyNode):
    annotations = _MyLeaf_annotations

    def __cinit__(MyLeaf self):
        loop = asyncio_get_event_loop()
        self._connect_future = loop.create_future()
        self._deferred_headers = {}

    cdef const type_info* _typeid(MyLeaf self):
        return &typeid(cMyLeafAsyncClient)

    @staticmethod
    cdef _module_MyLeaf_set_client(MyLeaf inst, shared_ptr[cMyLeafClientWrapper] c_obj):
        """So the class hierarchy talks to the correct pointer type"""
        inst._module_MyLeaf_client = c_obj
        MyNode._module_MyNode_set_client(inst, <shared_ptr[cMyNodeClientWrapper]>c_obj)

    cdef _module_MyLeaf_reset_client(MyLeaf self):
        """So the class hierarchy resets the shared pointer up the chain"""
        self._module_MyLeaf_client.reset()
        MyNode._module_MyNode_reset_client(self)

    def __dealloc__(MyLeaf self):
        if self._connect_future.done() and not self._connect_future.exception():
            print(f'thrift-py3 client: {self!r} was not cleaned up, use the async context manager', file=sys.stderr)
            if self._module_MyLeaf_client:
                deref(self._module_MyLeaf_client).disconnect().get()
        self._module_MyLeaf_reset_client()

    cdef bind_client(MyLeaf self, cRequestChannel_ptr&& channel):
        MyLeaf._module_MyLeaf_set_client(
            self,
            makeClientWrapper[cMyLeafAsyncClient, cMyLeafClientWrapper](
                thrift.py3.client.move(channel)
            ),
        )

    async def __aenter__(MyLeaf self):
        await asyncio_shield(self._connect_future)
        if self._context_entered:
            raise asyncio_InvalidStateError('Client context has been used already')
        self._context_entered = True
        for key, value in self._deferred_headers.items():
            self.set_persistent_header(key, value)
        self._deferred_headers = None
        return self

    def __aexit__(MyLeaf self, *exc):
        self._check_connect_future()
        loop = asyncio_get_event_loop()
        future = loop.create_future()
        userdata = (self, future)
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._module_MyLeaf_client).disconnect(),
            closed_MyLeaf_py3_client_callback,
            <PyObject *>userdata  # So we keep client alive until disconnect
        )
        # To break any future usage of this client
        # Also to prevent dealloc from trying to disconnect in a blocking way.
        badfuture = loop.create_future()
        badfuture.set_exception(asyncio_InvalidStateError('Client Out of Context'))
        badfuture.exception()
        self._connect_future = badfuture
        return asyncio_shield(future)

    def set_persistent_header(MyLeaf self, str key, str value):
        if not self._module_MyLeaf_client:
            self._deferred_headers[key] = value
            return

        cdef string ckey = <bytes> key.encode('utf-8')
        cdef string cvalue = <bytes> value.encode('utf-8')
        deref(self._module_MyLeaf_client).setPersistentHeader(ckey, cvalue)

    @cython.always_allow_keywords(True)
    def do_leaf(
            MyLeaf self,
            __RpcOptions rpc_options=None
    ):
        if rpc_options is None:
            rpc_options = <__RpcOptions>__RpcOptions.__new__(__RpcOptions)
        self._check_connect_future()
        __loop = asyncio_get_event_loop()
        __future = __loop.create_future()
        __userdata = (self, __future, rpc_options)
        bridgeFutureWith[cFollyUnit](
            self._executor,
            deref(self._module_MyLeaf_client).do_leaf(rpc_options._cpp_obj, 
            ),
            MyLeaf_do_leaf_callback,
            <PyObject *> __userdata
        )
        return asyncio_shield(__future)



cdef void closed_MyLeaf_py3_client_callback(
    cFollyTry[cFollyUnit]&& result,
    PyObject* userdata,
):
    client, pyfuture = <object> userdata 
    pyfuture.set_result(None)
