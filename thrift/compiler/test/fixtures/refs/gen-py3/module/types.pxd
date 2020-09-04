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
    uint32_t as cuint32_t,
)
from libcpp.string cimport string
from libcpp cimport bool as cbool, nullptr, nullptr_t
from cpython cimport bool as pbool
from libcpp.memory cimport shared_ptr, unique_ptr
from libcpp.vector cimport vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap, pair as cpair
from thrift.py3.exceptions cimport cTException
cimport folly.iobuf as __iobuf
cimport thrift.py3.exceptions
cimport thrift.py3.types
from thrift.py3.common cimport Protocol as __Protocol
from thrift.py3.types cimport bstring, move, field_ref as __FieldRef, optional_field_ref as __OptionalFieldRef
from folly.optional cimport cOptional
cdef extern from "src/gen-py3/module/types.h":
  pass


cdef extern from "src/gen-cpp2/module_types.h" namespace "::cpp2":
    cdef cppclass cTypedEnum "::cpp2::TypedEnum":
        pass





cdef class TypedEnum(thrift.py3.types.CompiledEnum):
    pass

cdef extern from "src/gen-cpp2/module_types_custom_protocol.h" namespace "::cpp2":
    cdef enum cMyUnion__type "::cpp2::MyUnion::Type":
        cMyUnion__type___EMPTY__ "::cpp2::MyUnion::Type::__EMPTY__",
        cMyUnion__type_anInteger "::cpp2::MyUnion::Type::anInteger",
        cMyUnion__type_aString "::cpp2::MyUnion::Type::aString",

    cdef cppclass cMyUnion "::cpp2::MyUnion":
        cMyUnion() except +
        cMyUnion(const cMyUnion&) except +
        bint operator==(cMyUnion&)
        bint operator!=(cMyUnion&)
        bint operator<(cMyUnion&)
        bint operator>(cMyUnion&)
        bint operator<=(cMyUnion&)
        bint operator>=(cMyUnion&)
        cMyUnion__type getType() const
        const cint32_t& get_anInteger() const
        cint32_t& set_anInteger(const cint32_t&)
        const string& get_aString() const
        string& set_aString(const string&)

    cdef cppclass cMyField__isset "::cpp2::MyField::__isset":
        bint opt_value
        bint value
        bint req_value

    cdef cppclass cMyField "::cpp2::MyField":
        cMyField() except +
        cMyField(const cMyField&) except +
        bint operator==(cMyField&)
        bint operator!=(cMyField&)
        bint operator<(cMyField&)
        bint operator>(cMyField&)
        bint operator<=(cMyField&)
        bint operator>=(cMyField&)
        __OptionalFieldRef[cint64_t] opt_value_ref()
        cint64_t opt_value
        __FieldRef[cint64_t] value_ref()
        cint64_t value
        cint64_t req_value
        cMyField__isset __isset

    cdef cppclass cMyStruct__isset "::cpp2::MyStruct::__isset":
        bint opt_ref
        bint ref
        bint req_ref

    cdef cppclass cMyStruct "::cpp2::MyStruct":
        cMyStruct() except +
        cMyStruct(const cMyStruct&) except +
        bint operator==(cMyStruct&)
        bint operator!=(cMyStruct&)
        bint operator<(cMyStruct&)
        bint operator>(cMyStruct&)
        bint operator<=(cMyStruct&)
        bint operator>=(cMyStruct&)
        unique_ptr[cMyField] opt_ref
        unique_ptr[cMyField] ref
        unique_ptr[cMyField] req_ref
        cMyStruct__isset __isset

    cdef cppclass cStructWithUnion__isset "::cpp2::StructWithUnion::__isset":
        bint u
        bint aDouble
        bint f

    cdef cppclass cStructWithUnion "::cpp2::StructWithUnion":
        cStructWithUnion() except +
        cStructWithUnion(const cStructWithUnion&) except +
        bint operator==(cStructWithUnion&)
        bint operator!=(cStructWithUnion&)
        bint operator<(cStructWithUnion&)
        bint operator>(cStructWithUnion&)
        bint operator<=(cStructWithUnion&)
        bint operator>=(cStructWithUnion&)
        unique_ptr[cMyUnion] u
        __FieldRef[double] aDouble_ref()
        double aDouble
        __FieldRef[cMyField] f_ref()
        cMyField f
        cStructWithUnion__isset __isset

    cdef cppclass cRecursiveStruct__isset "::cpp2::RecursiveStruct::__isset":
        bint mes

    cdef cppclass cRecursiveStruct "::cpp2::RecursiveStruct":
        cRecursiveStruct() except +
        cRecursiveStruct(const cRecursiveStruct&) except +
        bint operator==(cRecursiveStruct&)
        bint operator!=(cRecursiveStruct&)
        bint operator<(cRecursiveStruct&)
        bint operator>(cRecursiveStruct&)
        bint operator<=(cRecursiveStruct&)
        bint operator>=(cRecursiveStruct&)
        __OptionalFieldRef[vector[cRecursiveStruct]] mes_ref()
        vector[cRecursiveStruct] mes
        cRecursiveStruct__isset __isset

    cdef cppclass cStructWithContainers__isset "::cpp2::StructWithContainers::__isset":
        bint list_ref
        bint set_ref
        bint map_ref
        bint list_ref_unique
        bint set_ref_shared
        bint list_ref_shared_const

    cdef cppclass cStructWithContainers "::cpp2::StructWithContainers":
        cStructWithContainers() except +
        cStructWithContainers(const cStructWithContainers&) except +
        bint operator==(cStructWithContainers&)
        bint operator!=(cStructWithContainers&)
        bint operator<(cStructWithContainers&)
        bint operator>(cStructWithContainers&)
        bint operator<=(cStructWithContainers&)
        bint operator>=(cStructWithContainers&)
        unique_ptr[vector[cint32_t]] list_ref
        unique_ptr[cset[cint32_t]] set_ref
        unique_ptr[cmap[cint32_t,cint32_t]] map_ref
        unique_ptr[vector[cint32_t]] list_ref_unique
        shared_ptr[cset[cint32_t]] set_ref_shared
        shared_ptr[const vector[cint32_t]] list_ref_shared_const
        cStructWithContainers__isset __isset

    cdef cppclass cStructWithSharedConst__isset "::cpp2::StructWithSharedConst::__isset":
        bint opt_shared_const
        bint shared_const
        bint req_shared_const

    cdef cppclass cStructWithSharedConst "::cpp2::StructWithSharedConst":
        cStructWithSharedConst() except +
        cStructWithSharedConst(const cStructWithSharedConst&) except +
        bint operator==(cStructWithSharedConst&)
        bint operator!=(cStructWithSharedConst&)
        bint operator<(cStructWithSharedConst&)
        bint operator>(cStructWithSharedConst&)
        bint operator<=(cStructWithSharedConst&)
        bint operator>=(cStructWithSharedConst&)
        shared_ptr[const cMyField] opt_shared_const
        shared_ptr[const cMyField] shared_const
        shared_ptr[const cMyField] req_shared_const
        cStructWithSharedConst__isset __isset

    cdef cppclass cEmpty__isset "::cpp2::Empty::__isset":
        pass

    cdef cppclass cEmpty "::cpp2::Empty":
        cEmpty() except +
        cEmpty(const cEmpty&) except +
        bint operator==(cEmpty&)
        bint operator!=(cEmpty&)
        bint operator<(cEmpty&)
        bint operator>(cEmpty&)
        bint operator<=(cEmpty&)
        bint operator>=(cEmpty&)
        cEmpty__isset __isset

    cdef cppclass cStructWithRef__isset "::cpp2::StructWithRef::__isset":
        bint def_field
        bint opt_field
        bint req_field

    cdef cppclass cStructWithRef "::cpp2::StructWithRef":
        cStructWithRef() except +
        cStructWithRef(const cStructWithRef&) except +
        bint operator==(cStructWithRef&)
        bint operator!=(cStructWithRef&)
        bint operator<(cStructWithRef&)
        bint operator>(cStructWithRef&)
        bint operator<=(cStructWithRef&)
        bint operator>=(cStructWithRef&)
        unique_ptr[cEmpty] def_field
        unique_ptr[cEmpty] opt_field
        unique_ptr[cEmpty] req_field
        cStructWithRef__isset __isset

    cdef cppclass cStructWithRefTypeUnique__isset "::cpp2::StructWithRefTypeUnique::__isset":
        bint def_field
        bint opt_field
        bint req_field

    cdef cppclass cStructWithRefTypeUnique "::cpp2::StructWithRefTypeUnique":
        cStructWithRefTypeUnique() except +
        cStructWithRefTypeUnique(const cStructWithRefTypeUnique&) except +
        bint operator==(cStructWithRefTypeUnique&)
        bint operator!=(cStructWithRefTypeUnique&)
        bint operator<(cStructWithRefTypeUnique&)
        bint operator>(cStructWithRefTypeUnique&)
        bint operator<=(cStructWithRefTypeUnique&)
        bint operator>=(cStructWithRefTypeUnique&)
        unique_ptr[cEmpty] def_field
        unique_ptr[cEmpty] opt_field
        unique_ptr[cEmpty] req_field
        cStructWithRefTypeUnique__isset __isset

    cdef cppclass cStructWithRefTypeShared__isset "::cpp2::StructWithRefTypeShared::__isset":
        bint def_field
        bint opt_field
        bint req_field

    cdef cppclass cStructWithRefTypeShared "::cpp2::StructWithRefTypeShared":
        cStructWithRefTypeShared() except +
        cStructWithRefTypeShared(const cStructWithRefTypeShared&) except +
        bint operator==(cStructWithRefTypeShared&)
        bint operator!=(cStructWithRefTypeShared&)
        bint operator<(cStructWithRefTypeShared&)
        bint operator>(cStructWithRefTypeShared&)
        bint operator<=(cStructWithRefTypeShared&)
        bint operator>=(cStructWithRefTypeShared&)
        shared_ptr[cEmpty] def_field
        shared_ptr[cEmpty] opt_field
        shared_ptr[cEmpty] req_field
        cStructWithRefTypeShared__isset __isset

    cdef cppclass cStructWithRefTypeSharedConst__isset "::cpp2::StructWithRefTypeSharedConst::__isset":
        bint def_field
        bint opt_field
        bint req_field

    cdef cppclass cStructWithRefTypeSharedConst "::cpp2::StructWithRefTypeSharedConst":
        cStructWithRefTypeSharedConst() except +
        cStructWithRefTypeSharedConst(const cStructWithRefTypeSharedConst&) except +
        bint operator==(cStructWithRefTypeSharedConst&)
        bint operator!=(cStructWithRefTypeSharedConst&)
        bint operator<(cStructWithRefTypeSharedConst&)
        bint operator>(cStructWithRefTypeSharedConst&)
        bint operator<=(cStructWithRefTypeSharedConst&)
        bint operator>=(cStructWithRefTypeSharedConst&)
        shared_ptr[const cEmpty] def_field
        shared_ptr[const cEmpty] opt_field
        shared_ptr[const cEmpty] req_field
        cStructWithRefTypeSharedConst__isset __isset

    cdef cppclass cStructWithRefAndAnnotCppNoexceptMoveCtor__isset "::cpp2::StructWithRefAndAnnotCppNoexceptMoveCtor::__isset":
        bint def_field

    cdef cppclass cStructWithRefAndAnnotCppNoexceptMoveCtor "::cpp2::StructWithRefAndAnnotCppNoexceptMoveCtor":
        cStructWithRefAndAnnotCppNoexceptMoveCtor() except +
        cStructWithRefAndAnnotCppNoexceptMoveCtor(const cStructWithRefAndAnnotCppNoexceptMoveCtor&) except +
        bint operator==(cStructWithRefAndAnnotCppNoexceptMoveCtor&)
        bint operator!=(cStructWithRefAndAnnotCppNoexceptMoveCtor&)
        bint operator<(cStructWithRefAndAnnotCppNoexceptMoveCtor&)
        bint operator>(cStructWithRefAndAnnotCppNoexceptMoveCtor&)
        bint operator<=(cStructWithRefAndAnnotCppNoexceptMoveCtor&)
        bint operator>=(cStructWithRefAndAnnotCppNoexceptMoveCtor&)
        unique_ptr[cEmpty] def_field
        cStructWithRefAndAnnotCppNoexceptMoveCtor__isset __isset

    cdef shared_ptr[cMyField] reference_shared_ptr_opt_ref "::thrift::py3::reference_shared_ptr<::cpp2::MyField>"(shared_ptr[cMyStruct]&, cMyField&)
    cdef shared_ptr[cMyField] reference_shared_ptr_ref "::thrift::py3::reference_shared_ptr<::cpp2::MyField>"(shared_ptr[cMyStruct]&, cMyField&)
    cdef shared_ptr[cMyField] reference_shared_ptr_req_ref "::thrift::py3::reference_shared_ptr<::cpp2::MyField>"(shared_ptr[cMyStruct]&, cMyField&)
    cdef shared_ptr[cMyUnion] reference_shared_ptr_u "::thrift::py3::reference_shared_ptr<::cpp2::MyUnion>"(shared_ptr[cStructWithUnion]&, cMyUnion&)
    cdef shared_ptr[cMyField] reference_shared_ptr_f "::thrift::py3::reference_shared_ptr<::cpp2::MyField>"(shared_ptr[cStructWithUnion]&, cMyField&)
    cdef shared_ptr[vector[cRecursiveStruct]] reference_shared_ptr_mes "::thrift::py3::reference_shared_ptr<std::vector<::cpp2::RecursiveStruct>>"(shared_ptr[cRecursiveStruct]&, vector[cRecursiveStruct]&)
    cdef shared_ptr[vector[cint32_t]] reference_shared_ptr_list_ref "::thrift::py3::reference_shared_ptr<std::vector<int32_t>>"(shared_ptr[cStructWithContainers]&, vector[cint32_t]&)
    cdef shared_ptr[cset[cint32_t]] reference_shared_ptr_set_ref "::thrift::py3::reference_shared_ptr<std::set<int32_t>>"(shared_ptr[cStructWithContainers]&, cset[cint32_t]&)
    cdef shared_ptr[cmap[cint32_t,cint32_t]] reference_shared_ptr_map_ref "::thrift::py3::reference_shared_ptr<std::map<int32_t,int32_t>>"(shared_ptr[cStructWithContainers]&, cmap[cint32_t,cint32_t]&)
    cdef shared_ptr[vector[cint32_t]] reference_shared_ptr_list_ref_unique "::thrift::py3::reference_shared_ptr<std::vector<int32_t>>"(shared_ptr[cStructWithContainers]&, vector[cint32_t]&)
    cdef shared_ptr[cset[cint32_t]] reference_shared_ptr_set_ref_shared "::thrift::py3::reference_shared_ptr<std::set<int32_t>>"(shared_ptr[cStructWithContainers]&, cset[cint32_t]&)
    cdef shared_ptr[vector[cint32_t]] reference_shared_ptr_list_ref_shared_const "::thrift::py3::reference_shared_ptr<std::vector<int32_t>>"(shared_ptr[cStructWithContainers]&, vector[cint32_t]&)
    cdef shared_ptr[cMyField] reference_shared_ptr_opt_shared_const "::thrift::py3::reference_shared_ptr<::cpp2::MyField>"(shared_ptr[cStructWithSharedConst]&, cMyField&)
    cdef shared_ptr[cMyField] reference_shared_ptr_shared_const "::thrift::py3::reference_shared_ptr<::cpp2::MyField>"(shared_ptr[cStructWithSharedConst]&, cMyField&)
    cdef shared_ptr[cMyField] reference_shared_ptr_req_shared_const "::thrift::py3::reference_shared_ptr<::cpp2::MyField>"(shared_ptr[cStructWithSharedConst]&, cMyField&)
    cdef shared_ptr[cEmpty] reference_shared_ptr_def_field "::thrift::py3::reference_shared_ptr<::cpp2::Empty>"(shared_ptr[cStructWithRef]&, cEmpty&)
    cdef shared_ptr[cEmpty] reference_shared_ptr_opt_field "::thrift::py3::reference_shared_ptr<::cpp2::Empty>"(shared_ptr[cStructWithRef]&, cEmpty&)
    cdef shared_ptr[cEmpty] reference_shared_ptr_req_field "::thrift::py3::reference_shared_ptr<::cpp2::Empty>"(shared_ptr[cStructWithRef]&, cEmpty&)
    cdef shared_ptr[cEmpty] reference_shared_ptr_def_field "::thrift::py3::reference_shared_ptr<::cpp2::Empty>"(shared_ptr[cStructWithRefTypeUnique]&, cEmpty&)
    cdef shared_ptr[cEmpty] reference_shared_ptr_opt_field "::thrift::py3::reference_shared_ptr<::cpp2::Empty>"(shared_ptr[cStructWithRefTypeUnique]&, cEmpty&)
    cdef shared_ptr[cEmpty] reference_shared_ptr_req_field "::thrift::py3::reference_shared_ptr<::cpp2::Empty>"(shared_ptr[cStructWithRefTypeUnique]&, cEmpty&)
    cdef shared_ptr[cEmpty] reference_shared_ptr_def_field "::thrift::py3::reference_shared_ptr<::cpp2::Empty>"(shared_ptr[cStructWithRefTypeShared]&, cEmpty&)
    cdef shared_ptr[cEmpty] reference_shared_ptr_opt_field "::thrift::py3::reference_shared_ptr<::cpp2::Empty>"(shared_ptr[cStructWithRefTypeShared]&, cEmpty&)
    cdef shared_ptr[cEmpty] reference_shared_ptr_req_field "::thrift::py3::reference_shared_ptr<::cpp2::Empty>"(shared_ptr[cStructWithRefTypeShared]&, cEmpty&)
    cdef shared_ptr[cEmpty] reference_shared_ptr_def_field "::thrift::py3::reference_shared_ptr<::cpp2::Empty>"(shared_ptr[cStructWithRefTypeSharedConst]&, cEmpty&)
    cdef shared_ptr[cEmpty] reference_shared_ptr_opt_field "::thrift::py3::reference_shared_ptr<::cpp2::Empty>"(shared_ptr[cStructWithRefTypeSharedConst]&, cEmpty&)
    cdef shared_ptr[cEmpty] reference_shared_ptr_req_field "::thrift::py3::reference_shared_ptr<::cpp2::Empty>"(shared_ptr[cStructWithRefTypeSharedConst]&, cEmpty&)
    cdef shared_ptr[cEmpty] reference_shared_ptr_def_field "::thrift::py3::reference_shared_ptr<::cpp2::Empty>"(shared_ptr[cStructWithRefAndAnnotCppNoexceptMoveCtor]&, cEmpty&)

cdef extern from "<utility>" namespace "std" nogil:
    cdef shared_ptr[cMyUnion] __fbthrift_move "std::move"(unique_ptr[cMyUnion])
    cdef shared_ptr[cMyUnion] __fbthrift_move_shared "std::move"(shared_ptr[cMyUnion])
    cdef unique_ptr[cMyUnion] __fbthrift_move_unique "std::move"(unique_ptr[cMyUnion])
    cdef shared_ptr[cMyField] __fbthrift_move "std::move"(unique_ptr[cMyField])
    cdef shared_ptr[cMyField] __fbthrift_move_shared "std::move"(shared_ptr[cMyField])
    cdef unique_ptr[cMyField] __fbthrift_move_unique "std::move"(unique_ptr[cMyField])
    cdef shared_ptr[cMyStruct] __fbthrift_move "std::move"(unique_ptr[cMyStruct])
    cdef shared_ptr[cMyStruct] __fbthrift_move_shared "std::move"(shared_ptr[cMyStruct])
    cdef unique_ptr[cMyStruct] __fbthrift_move_unique "std::move"(unique_ptr[cMyStruct])
    cdef shared_ptr[cStructWithUnion] __fbthrift_move "std::move"(unique_ptr[cStructWithUnion])
    cdef shared_ptr[cStructWithUnion] __fbthrift_move_shared "std::move"(shared_ptr[cStructWithUnion])
    cdef unique_ptr[cStructWithUnion] __fbthrift_move_unique "std::move"(unique_ptr[cStructWithUnion])
    cdef shared_ptr[cRecursiveStruct] __fbthrift_move "std::move"(unique_ptr[cRecursiveStruct])
    cdef shared_ptr[cRecursiveStruct] __fbthrift_move_shared "std::move"(shared_ptr[cRecursiveStruct])
    cdef unique_ptr[cRecursiveStruct] __fbthrift_move_unique "std::move"(unique_ptr[cRecursiveStruct])
    cdef shared_ptr[cStructWithContainers] __fbthrift_move "std::move"(unique_ptr[cStructWithContainers])
    cdef shared_ptr[cStructWithContainers] __fbthrift_move_shared "std::move"(shared_ptr[cStructWithContainers])
    cdef unique_ptr[cStructWithContainers] __fbthrift_move_unique "std::move"(unique_ptr[cStructWithContainers])
    cdef shared_ptr[cStructWithSharedConst] __fbthrift_move "std::move"(unique_ptr[cStructWithSharedConst])
    cdef shared_ptr[cStructWithSharedConst] __fbthrift_move_shared "std::move"(shared_ptr[cStructWithSharedConst])
    cdef unique_ptr[cStructWithSharedConst] __fbthrift_move_unique "std::move"(unique_ptr[cStructWithSharedConst])
    cdef shared_ptr[cEmpty] __fbthrift_move "std::move"(unique_ptr[cEmpty])
    cdef shared_ptr[cEmpty] __fbthrift_move_shared "std::move"(shared_ptr[cEmpty])
    cdef unique_ptr[cEmpty] __fbthrift_move_unique "std::move"(unique_ptr[cEmpty])
    cdef shared_ptr[cStructWithRef] __fbthrift_move "std::move"(unique_ptr[cStructWithRef])
    cdef shared_ptr[cStructWithRef] __fbthrift_move_shared "std::move"(shared_ptr[cStructWithRef])
    cdef unique_ptr[cStructWithRef] __fbthrift_move_unique "std::move"(unique_ptr[cStructWithRef])
    cdef shared_ptr[cStructWithRefTypeUnique] __fbthrift_move "std::move"(unique_ptr[cStructWithRefTypeUnique])
    cdef shared_ptr[cStructWithRefTypeUnique] __fbthrift_move_shared "std::move"(shared_ptr[cStructWithRefTypeUnique])
    cdef unique_ptr[cStructWithRefTypeUnique] __fbthrift_move_unique "std::move"(unique_ptr[cStructWithRefTypeUnique])
    cdef shared_ptr[cStructWithRefTypeShared] __fbthrift_move "std::move"(unique_ptr[cStructWithRefTypeShared])
    cdef shared_ptr[cStructWithRefTypeShared] __fbthrift_move_shared "std::move"(shared_ptr[cStructWithRefTypeShared])
    cdef unique_ptr[cStructWithRefTypeShared] __fbthrift_move_unique "std::move"(unique_ptr[cStructWithRefTypeShared])
    cdef shared_ptr[cStructWithRefTypeSharedConst] __fbthrift_move "std::move"(unique_ptr[cStructWithRefTypeSharedConst])
    cdef shared_ptr[cStructWithRefTypeSharedConst] __fbthrift_move_shared "std::move"(shared_ptr[cStructWithRefTypeSharedConst])
    cdef unique_ptr[cStructWithRefTypeSharedConst] __fbthrift_move_unique "std::move"(unique_ptr[cStructWithRefTypeSharedConst])
    cdef shared_ptr[cStructWithRefAndAnnotCppNoexceptMoveCtor] __fbthrift_move "std::move"(unique_ptr[cStructWithRefAndAnnotCppNoexceptMoveCtor])
    cdef shared_ptr[cStructWithRefAndAnnotCppNoexceptMoveCtor] __fbthrift_move_shared "std::move"(shared_ptr[cStructWithRefAndAnnotCppNoexceptMoveCtor])
    cdef unique_ptr[cStructWithRefAndAnnotCppNoexceptMoveCtor] __fbthrift_move_unique "std::move"(unique_ptr[cStructWithRefAndAnnotCppNoexceptMoveCtor])

cdef extern from "<memory>" namespace "std" nogil:
    cdef shared_ptr[const cMyUnion] const_pointer_cast "std::const_pointer_cast<const ::cpp2::MyUnion>"(shared_ptr[cMyUnion])
    cdef shared_ptr[const cMyField] const_pointer_cast "std::const_pointer_cast<const ::cpp2::MyField>"(shared_ptr[cMyField])
    cdef shared_ptr[const cMyStruct] const_pointer_cast "std::const_pointer_cast<const ::cpp2::MyStruct>"(shared_ptr[cMyStruct])
    cdef shared_ptr[const cStructWithUnion] const_pointer_cast "std::const_pointer_cast<const ::cpp2::StructWithUnion>"(shared_ptr[cStructWithUnion])
    cdef shared_ptr[const cRecursiveStruct] const_pointer_cast "std::const_pointer_cast<const ::cpp2::RecursiveStruct>"(shared_ptr[cRecursiveStruct])
    cdef shared_ptr[const cStructWithContainers] const_pointer_cast "std::const_pointer_cast<const ::cpp2::StructWithContainers>"(shared_ptr[cStructWithContainers])
    cdef shared_ptr[const cStructWithSharedConst] const_pointer_cast "std::const_pointer_cast<const ::cpp2::StructWithSharedConst>"(shared_ptr[cStructWithSharedConst])
    cdef shared_ptr[const cEmpty] const_pointer_cast "std::const_pointer_cast<const ::cpp2::Empty>"(shared_ptr[cEmpty])
    cdef shared_ptr[const cStructWithRef] const_pointer_cast "std::const_pointer_cast<const ::cpp2::StructWithRef>"(shared_ptr[cStructWithRef])
    cdef shared_ptr[const cStructWithRefTypeUnique] const_pointer_cast "std::const_pointer_cast<const ::cpp2::StructWithRefTypeUnique>"(shared_ptr[cStructWithRefTypeUnique])
    cdef shared_ptr[const cStructWithRefTypeShared] const_pointer_cast "std::const_pointer_cast<const ::cpp2::StructWithRefTypeShared>"(shared_ptr[cStructWithRefTypeShared])
    cdef shared_ptr[const cStructWithRefTypeSharedConst] const_pointer_cast "std::const_pointer_cast<const ::cpp2::StructWithRefTypeSharedConst>"(shared_ptr[cStructWithRefTypeSharedConst])
    cdef shared_ptr[const cStructWithRefAndAnnotCppNoexceptMoveCtor] const_pointer_cast "std::const_pointer_cast<const ::cpp2::StructWithRefAndAnnotCppNoexceptMoveCtor>"(shared_ptr[cStructWithRefAndAnnotCppNoexceptMoveCtor])

cdef class __MyUnionType(thrift.py3.types.CompiledEnum):
    pass




cdef class MyUnion(thrift.py3.types.Union):
    cdef object __hash
    cdef object __weakref__
    cdef shared_ptr[cMyUnion] _cpp_obj
    cdef readonly __MyUnionType type
    cdef readonly object value
    cdef _load_cache(MyUnion self)

    @staticmethod
    cdef unique_ptr[cMyUnion] _make_instance(
        cMyUnion* base_instance,
        object anInteger,
        str aString
    ) except *

    @staticmethod
    cdef create(shared_ptr[cMyUnion])



cdef class MyField(thrift.py3.types.Struct):
    cdef object __hash
    cdef object __weakref__
    cdef shared_ptr[cMyField] _cpp_obj

    @staticmethod
    cdef unique_ptr[cMyField] _make_instance(
        cMyField* base_instance,
        bint* __isNOTSET,
        object opt_value,
        object value,
        object req_value
    ) except *

    @staticmethod
    cdef create(shared_ptr[cMyField])



cdef class MyStruct(thrift.py3.types.Struct):
    cdef object __hash
    cdef object __weakref__
    cdef shared_ptr[cMyStruct] _cpp_obj
    cdef MyField __field_opt_ref
    cdef MyField __field_ref
    cdef MyField __field_req_ref

    @staticmethod
    cdef unique_ptr[cMyStruct] _make_instance(
        cMyStruct* base_instance,
        bint* __isNOTSET,
        MyField opt_ref,
        MyField ref,
        MyField req_ref
    ) except *

    @staticmethod
    cdef create(shared_ptr[cMyStruct])



cdef class StructWithUnion(thrift.py3.types.Struct):
    cdef object __hash
    cdef object __weakref__
    cdef shared_ptr[cStructWithUnion] _cpp_obj
    cdef MyUnion __field_u
    cdef MyField __field_f

    @staticmethod
    cdef unique_ptr[cStructWithUnion] _make_instance(
        cStructWithUnion* base_instance,
        bint* __isNOTSET,
        MyUnion u,
        object aDouble,
        MyField f
    ) except *

    @staticmethod
    cdef create(shared_ptr[cStructWithUnion])



cdef class RecursiveStruct(thrift.py3.types.Struct):
    cdef object __hash
    cdef object __weakref__
    cdef shared_ptr[cRecursiveStruct] _cpp_obj
    cdef List__RecursiveStruct __field_mes

    @staticmethod
    cdef unique_ptr[cRecursiveStruct] _make_instance(
        cRecursiveStruct* base_instance,
        bint* __isNOTSET,
        object mes
    ) except *

    @staticmethod
    cdef create(shared_ptr[cRecursiveStruct])



cdef class StructWithContainers(thrift.py3.types.Struct):
    cdef object __hash
    cdef object __weakref__
    cdef shared_ptr[cStructWithContainers] _cpp_obj
    cdef List__i32 __field_list_ref
    cdef Set__i32 __field_set_ref
    cdef Map__i32_i32 __field_map_ref
    cdef List__i32 __field_list_ref_unique
    cdef Set__i32 __field_set_ref_shared
    cdef List__i32 __field_list_ref_shared_const

    @staticmethod
    cdef unique_ptr[cStructWithContainers] _make_instance(
        cStructWithContainers* base_instance,
        bint* __isNOTSET,
        object list_ref,
        object set_ref,
        object map_ref,
        object list_ref_unique,
        object set_ref_shared,
        object list_ref_shared_const
    ) except *

    @staticmethod
    cdef create(shared_ptr[cStructWithContainers])



cdef class StructWithSharedConst(thrift.py3.types.Struct):
    cdef object __hash
    cdef object __weakref__
    cdef shared_ptr[cStructWithSharedConst] _cpp_obj
    cdef MyField __field_opt_shared_const
    cdef MyField __field_shared_const
    cdef MyField __field_req_shared_const

    @staticmethod
    cdef unique_ptr[cStructWithSharedConst] _make_instance(
        cStructWithSharedConst* base_instance,
        bint* __isNOTSET,
        MyField opt_shared_const,
        MyField shared_const,
        MyField req_shared_const
    ) except *

    @staticmethod
    cdef create(shared_ptr[cStructWithSharedConst])



cdef class Empty(thrift.py3.types.Struct):
    cdef object __hash
    cdef object __weakref__
    cdef shared_ptr[cEmpty] _cpp_obj

    @staticmethod
    cdef unique_ptr[cEmpty] _make_instance(
        cEmpty* base_instance,
        bint* __isNOTSET
    ) except *

    @staticmethod
    cdef create(shared_ptr[cEmpty])



cdef class StructWithRef(thrift.py3.types.Struct):
    cdef object __hash
    cdef object __weakref__
    cdef shared_ptr[cStructWithRef] _cpp_obj
    cdef Empty __field_def_field
    cdef Empty __field_opt_field
    cdef Empty __field_req_field

    @staticmethod
    cdef unique_ptr[cStructWithRef] _make_instance(
        cStructWithRef* base_instance,
        bint* __isNOTSET,
        Empty def_field,
        Empty opt_field,
        Empty req_field
    ) except *

    @staticmethod
    cdef create(shared_ptr[cStructWithRef])



cdef class StructWithRefTypeUnique(thrift.py3.types.Struct):
    cdef object __hash
    cdef object __weakref__
    cdef shared_ptr[cStructWithRefTypeUnique] _cpp_obj
    cdef Empty __field_def_field
    cdef Empty __field_opt_field
    cdef Empty __field_req_field

    @staticmethod
    cdef unique_ptr[cStructWithRefTypeUnique] _make_instance(
        cStructWithRefTypeUnique* base_instance,
        bint* __isNOTSET,
        Empty def_field,
        Empty opt_field,
        Empty req_field
    ) except *

    @staticmethod
    cdef create(shared_ptr[cStructWithRefTypeUnique])



cdef class StructWithRefTypeShared(thrift.py3.types.Struct):
    cdef object __hash
    cdef object __weakref__
    cdef shared_ptr[cStructWithRefTypeShared] _cpp_obj
    cdef Empty __field_def_field
    cdef Empty __field_opt_field
    cdef Empty __field_req_field

    @staticmethod
    cdef unique_ptr[cStructWithRefTypeShared] _make_instance(
        cStructWithRefTypeShared* base_instance,
        bint* __isNOTSET,
        Empty def_field,
        Empty opt_field,
        Empty req_field
    ) except *

    @staticmethod
    cdef create(shared_ptr[cStructWithRefTypeShared])



cdef class StructWithRefTypeSharedConst(thrift.py3.types.Struct):
    cdef object __hash
    cdef object __weakref__
    cdef shared_ptr[cStructWithRefTypeSharedConst] _cpp_obj
    cdef Empty __field_def_field
    cdef Empty __field_opt_field
    cdef Empty __field_req_field

    @staticmethod
    cdef unique_ptr[cStructWithRefTypeSharedConst] _make_instance(
        cStructWithRefTypeSharedConst* base_instance,
        bint* __isNOTSET,
        Empty def_field,
        Empty opt_field,
        Empty req_field
    ) except *

    @staticmethod
    cdef create(shared_ptr[cStructWithRefTypeSharedConst])



cdef class StructWithRefAndAnnotCppNoexceptMoveCtor(thrift.py3.types.Struct):
    cdef object __hash
    cdef object __weakref__
    cdef shared_ptr[cStructWithRefAndAnnotCppNoexceptMoveCtor] _cpp_obj
    cdef Empty __field_def_field

    @staticmethod
    cdef unique_ptr[cStructWithRefAndAnnotCppNoexceptMoveCtor] _make_instance(
        cStructWithRefAndAnnotCppNoexceptMoveCtor* base_instance,
        bint* __isNOTSET,
        Empty def_field
    ) except *

    @staticmethod
    cdef create(shared_ptr[cStructWithRefAndAnnotCppNoexceptMoveCtor])


cdef class List__RecursiveStruct(thrift.py3.types.List):
    cdef shared_ptr[vector[cRecursiveStruct]] _cpp_obj
    @staticmethod
    cdef create(shared_ptr[vector[cRecursiveStruct]])
    @staticmethod
    cdef shared_ptr[vector[cRecursiveStruct]] _make_instance(object items) except *

cdef class List__i32(thrift.py3.types.List):
    cdef shared_ptr[vector[cint32_t]] _cpp_obj
    @staticmethod
    cdef create(shared_ptr[vector[cint32_t]])
    @staticmethod
    cdef shared_ptr[vector[cint32_t]] _make_instance(object items) except *

cdef class Set__i32(thrift.py3.types.Set):
    cdef shared_ptr[cset[cint32_t]] _cpp_obj
    @staticmethod
    cdef create(shared_ptr[cset[cint32_t]])
    @staticmethod
    cdef shared_ptr[cset[cint32_t]] _make_instance(object items) except *

cdef class Map__i32_i32(thrift.py3.types.Map):
    cdef shared_ptr[cmap[cint32_t,cint32_t]] _cpp_obj
    @staticmethod
    cdef create(shared_ptr[cmap[cint32_t,cint32_t]])
    @staticmethod
    cdef shared_ptr[cmap[cint32_t,cint32_t]] _make_instance(object items) except *

cdef extern from "<utility>" namespace "std" nogil:
    cdef shared_ptr[vector[cRecursiveStruct]] __fbthrift_move "std::move"(unique_ptr[vector[cRecursiveStruct]])
    cdef shared_ptr[vector[cRecursiveStruct]] __fbthrift_move_shared "std::move"(shared_ptr[vector[cRecursiveStruct]])
    cdef shared_ptr[vector[cint32_t]] __fbthrift_move "std::move"(unique_ptr[vector[cint32_t]])
    cdef shared_ptr[vector[cint32_t]] __fbthrift_move_shared "std::move"(shared_ptr[vector[cint32_t]])
    cdef shared_ptr[cmap[cint32_t,cint32_t]] __fbthrift_move "std::move"(unique_ptr[cmap[cint32_t,cint32_t]])
    cdef shared_ptr[cmap[cint32_t,cint32_t]] __fbthrift_move_shared "std::move"(shared_ptr[cmap[cint32_t,cint32_t]])
    cdef shared_ptr[cset[cint32_t]] __fbthrift_move "std::move"(unique_ptr[cset[cint32_t]])
    cdef shared_ptr[cset[cint32_t]] __fbthrift_move_shared "std::move"(shared_ptr[cset[cint32_t]])
cdef extern from "<utility>" nogil:
    pass  
    shared_ptr[cRecursiveStruct] reference_shared_ptr_List__RecursiveStruct "::thrift::py3::reference_shared_ptr<::cpp2::RecursiveStruct>"(...)
cdef extern from "<memory>" namespace "std" nogil:
    cdef shared_ptr[const vector[cRecursiveStruct]] const_pointer_cast "std::const_pointer_cast<const std::vector<::cpp2::RecursiveStruct>>"(shared_ptr[vector[cRecursiveStruct]])
    cdef shared_ptr[const vector[cint32_t]] const_pointer_cast "std::const_pointer_cast<const std::vector<int32_t>>"(shared_ptr[vector[cint32_t]])
    cdef shared_ptr[const cmap[cint32_t,cint32_t]] const_pointer_cast "std::const_pointer_cast<const std::map<int32_t,int32_t>>"(shared_ptr[cmap[cint32_t,cint32_t]])
    cdef shared_ptr[const cset[cint32_t]] const_pointer_cast "std::const_pointer_cast<const std::set<int32_t>>"(shared_ptr[cset[cint32_t]])

cdef extern from "src/gen-cpp2/module_constants.h" namespace "::cpp2":
    cdef cStructWithRef ckStructWithRef "::cpp2::module_constants::kStructWithRef"()
    cdef cStructWithRefTypeUnique ckStructWithRefTypeUnique "::cpp2::module_constants::kStructWithRefTypeUnique"()
    cdef cStructWithRefTypeShared ckStructWithRefTypeShared "::cpp2::module_constants::kStructWithRefTypeShared"()
    cdef cStructWithRefTypeSharedConst ckStructWithRefTypeSharedConst "::cpp2::module_constants::kStructWithRefTypeSharedConst"()
