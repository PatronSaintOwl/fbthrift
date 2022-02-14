// @generated by Thrift for src/module.thrift
// This file is probably not the place you want to edit!

#![recursion_limit = "100000000"]
#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals, unused_crate_dependencies)]

pub use self::errors::*;
pub use self::types::*;

/// Thrift type definitions for `module`.
pub mod types {
    #![allow(clippy::redundant_closure)]


    pub type containerTypedef = ::std::collections::BTreeMap<::std::primitive::i16, ::std::string::String>;

    #[derive(Clone, PartialEq, Debug)]
    pub enum ComplexUnion {
        intValue(::std::primitive::i64),
        stringValue(::std::string::String),
        intListValue(::std::vec::Vec<::std::primitive::i64>),
        stringListValue(::std::vec::Vec<::std::string::String>),
        typedefValue(crate::types::containerTypedef),
        stringRef(::std::string::String),
        UnknownField(::std::primitive::i32),
    }

    #[derive(Clone, PartialEq, Eq, PartialOrd, Ord, Hash, Debug)]
    pub enum ListUnion {
        intListValue(::std::vec::Vec<::std::primitive::i64>),
        stringListValue(::std::vec::Vec<::std::string::String>),
        UnknownField(::std::primitive::i32),
    }

    #[derive(Clone, PartialEq, Eq, PartialOrd, Ord, Hash, Debug)]
    pub enum DataUnion {
        binaryData(::std::vec::Vec<::std::primitive::u8>),
        stringData(::std::string::String),
        UnknownField(::std::primitive::i32),
    }

    #[derive(Clone, PartialEq)]
    pub struct Val {
        pub strVal: ::std::string::String,
        pub intVal: ::std::primitive::i32,
        pub typedefValue: crate::types::containerTypedef,
        // This field forces `..Default::default()` when instantiating this
        // struct, to make code future-proof against new fields added later to
        // the definition in Thrift. If you don't want this, add the annotation
        // `(rust.exhaustive)` to the Thrift struct to eliminate this field.
        #[doc(hidden)]
        pub _dot_dot_Default_default: self::dot_dot::OtherFields,
    }

    #[derive(Clone, PartialEq, Debug)]
    pub enum ValUnion {
        v1(crate::types::Val),
        v2(crate::types::Val),
        UnknownField(::std::primitive::i32),
    }

    #[derive(Clone, PartialEq, Eq, PartialOrd, Ord, Hash, Debug)]
    pub enum VirtualComplexUnion {
        thingOne(::std::string::String),
        thingTwo(::std::string::String),
        UnknownField(::std::primitive::i32),
    }

    #[derive(Clone, PartialEq, Eq, PartialOrd, Ord, Hash)]
    pub struct NonCopyableStruct {
        pub num: ::std::primitive::i64,
        // This field forces `..Default::default()` when instantiating this
        // struct, to make code future-proof against new fields added later to
        // the definition in Thrift. If you don't want this, add the annotation
        // `(rust.exhaustive)` to the Thrift struct to eliminate this field.
        #[doc(hidden)]
        pub _dot_dot_Default_default: self::dot_dot::OtherFields,
    }

    #[derive(Clone, PartialEq, Debug)]
    pub enum NonCopyableUnion {
        s(crate::types::NonCopyableStruct),
        UnknownField(::std::primitive::i32),
    }



    impl ::std::default::Default for ComplexUnion {
        fn default() -> Self {
            Self::UnknownField(-1)
        }
    }

    impl ::fbthrift::GetTType for ComplexUnion {
        const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
    }

    impl<P> ::fbthrift::Serialize<P> for ComplexUnion
    where
        P: ::fbthrift::ProtocolWriter,
    {
        fn write(&self, p: &mut P) {
            p.write_struct_begin("ComplexUnion");
            match self {
                ComplexUnion::intValue(inner) => {
                    p.write_field_begin("intValue", ::fbthrift::TType::I64, 1);
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                ComplexUnion::stringValue(inner) => {
                    p.write_field_begin("stringValue", ::fbthrift::TType::String, 5);
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                ComplexUnion::intListValue(inner) => {
                    p.write_field_begin("intListValue", ::fbthrift::TType::List, 2);
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                ComplexUnion::stringListValue(inner) => {
                    p.write_field_begin("stringListValue", ::fbthrift::TType::List, 3);
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                ComplexUnion::typedefValue(inner) => {
                    p.write_field_begin("typedefValue", ::fbthrift::TType::Map, 9);
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                ComplexUnion::stringRef(inner) => {
                    p.write_field_begin("stringRef", ::fbthrift::TType::String, 14);
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                ComplexUnion::UnknownField(_) => {}
            }
            p.write_field_stop();
            p.write_struct_end();
        }
    }

    impl<P> ::fbthrift::Deserialize<P> for ComplexUnion
    where
        P: ::fbthrift::ProtocolReader,
    {
        fn read(p: &mut P) -> ::anyhow::Result<Self> {
            static FIELDS: &[::fbthrift::Field] = &[
                ::fbthrift::Field::new("intListValue", ::fbthrift::TType::List, 2),
                ::fbthrift::Field::new("intValue", ::fbthrift::TType::I64, 1),
                ::fbthrift::Field::new("stringListValue", ::fbthrift::TType::List, 3),
                ::fbthrift::Field::new("stringRef", ::fbthrift::TType::String, 14),
                ::fbthrift::Field::new("stringValue", ::fbthrift::TType::String, 5),
                ::fbthrift::Field::new("typedefValue", ::fbthrift::TType::Map, 9),
            ];
            let _ = p.read_struct_begin(|_| ())?;
            let mut once = false;
            let mut alt = ::std::option::Option::None;
            loop {
                let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
                match (fty, fid as ::std::primitive::i32, once) {
                    (::fbthrift::TType::Stop, _, _) => break,
                    (::fbthrift::TType::I64, 1, false) => {
                        once = true;
                        alt = ::std::option::Option::Some(ComplexUnion::intValue(::fbthrift::Deserialize::read(p)?));
                    }
                    (::fbthrift::TType::String, 5, false) => {
                        once = true;
                        alt = ::std::option::Option::Some(ComplexUnion::stringValue(::fbthrift::Deserialize::read(p)?));
                    }
                    (::fbthrift::TType::List, 2, false) => {
                        once = true;
                        alt = ::std::option::Option::Some(ComplexUnion::intListValue(::fbthrift::Deserialize::read(p)?));
                    }
                    (::fbthrift::TType::List, 3, false) => {
                        once = true;
                        alt = ::std::option::Option::Some(ComplexUnion::stringListValue(::fbthrift::Deserialize::read(p)?));
                    }
                    (::fbthrift::TType::Map, 9, false) => {
                        once = true;
                        alt = ::std::option::Option::Some(ComplexUnion::typedefValue(::fbthrift::Deserialize::read(p)?));
                    }
                    (::fbthrift::TType::String, 14, false) => {
                        once = true;
                        alt = ::std::option::Option::Some(ComplexUnion::stringRef(::fbthrift::Deserialize::read(p)?));
                    }
                    (fty, _, false) => p.skip(fty)?,
                    (badty, badid, true) => return ::std::result::Result::Err(::std::convert::From::from(::fbthrift::ApplicationException::new(
                        ::fbthrift::ApplicationExceptionErrorCode::ProtocolError,
                        format!(
                            "unwanted extra union {} field ty {:?} id {}",
                            "ComplexUnion",
                            badty,
                            badid,
                        ),
                    ))),
                }
                p.read_field_end()?;
            }
            p.read_struct_end()?;
            ::std::result::Result::Ok(alt.unwrap_or_default())
        }
    }


    impl ::std::default::Default for ListUnion {
        fn default() -> Self {
            Self::UnknownField(-1)
        }
    }

    impl ::fbthrift::GetTType for ListUnion {
        const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
    }

    impl<P> ::fbthrift::Serialize<P> for ListUnion
    where
        P: ::fbthrift::ProtocolWriter,
    {
        fn write(&self, p: &mut P) {
            p.write_struct_begin("ListUnion");
            match self {
                ListUnion::intListValue(inner) => {
                    p.write_field_begin("intListValue", ::fbthrift::TType::List, 2);
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                ListUnion::stringListValue(inner) => {
                    p.write_field_begin("stringListValue", ::fbthrift::TType::List, 3);
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                ListUnion::UnknownField(_) => {}
            }
            p.write_field_stop();
            p.write_struct_end();
        }
    }

    impl<P> ::fbthrift::Deserialize<P> for ListUnion
    where
        P: ::fbthrift::ProtocolReader,
    {
        fn read(p: &mut P) -> ::anyhow::Result<Self> {
            static FIELDS: &[::fbthrift::Field] = &[
                ::fbthrift::Field::new("intListValue", ::fbthrift::TType::List, 2),
                ::fbthrift::Field::new("stringListValue", ::fbthrift::TType::List, 3),
            ];
            let _ = p.read_struct_begin(|_| ())?;
            let mut once = false;
            let mut alt = ::std::option::Option::None;
            loop {
                let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
                match (fty, fid as ::std::primitive::i32, once) {
                    (::fbthrift::TType::Stop, _, _) => break,
                    (::fbthrift::TType::List, 2, false) => {
                        once = true;
                        alt = ::std::option::Option::Some(ListUnion::intListValue(::fbthrift::Deserialize::read(p)?));
                    }
                    (::fbthrift::TType::List, 3, false) => {
                        once = true;
                        alt = ::std::option::Option::Some(ListUnion::stringListValue(::fbthrift::Deserialize::read(p)?));
                    }
                    (fty, _, false) => p.skip(fty)?,
                    (badty, badid, true) => return ::std::result::Result::Err(::std::convert::From::from(::fbthrift::ApplicationException::new(
                        ::fbthrift::ApplicationExceptionErrorCode::ProtocolError,
                        format!(
                            "unwanted extra union {} field ty {:?} id {}",
                            "ListUnion",
                            badty,
                            badid,
                        ),
                    ))),
                }
                p.read_field_end()?;
            }
            p.read_struct_end()?;
            ::std::result::Result::Ok(alt.unwrap_or_default())
        }
    }


    impl ::std::default::Default for DataUnion {
        fn default() -> Self {
            Self::UnknownField(-1)
        }
    }

    impl ::fbthrift::GetTType for DataUnion {
        const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
    }

    impl<P> ::fbthrift::Serialize<P> for DataUnion
    where
        P: ::fbthrift::ProtocolWriter,
    {
        fn write(&self, p: &mut P) {
            p.write_struct_begin("DataUnion");
            match self {
                DataUnion::binaryData(inner) => {
                    p.write_field_begin("binaryData", ::fbthrift::TType::String, 1);
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                DataUnion::stringData(inner) => {
                    p.write_field_begin("stringData", ::fbthrift::TType::String, 2);
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                DataUnion::UnknownField(_) => {}
            }
            p.write_field_stop();
            p.write_struct_end();
        }
    }

    impl<P> ::fbthrift::Deserialize<P> for DataUnion
    where
        P: ::fbthrift::ProtocolReader,
    {
        fn read(p: &mut P) -> ::anyhow::Result<Self> {
            static FIELDS: &[::fbthrift::Field] = &[
                ::fbthrift::Field::new("binaryData", ::fbthrift::TType::String, 1),
                ::fbthrift::Field::new("stringData", ::fbthrift::TType::String, 2),
            ];
            let _ = p.read_struct_begin(|_| ())?;
            let mut once = false;
            let mut alt = ::std::option::Option::None;
            loop {
                let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
                match (fty, fid as ::std::primitive::i32, once) {
                    (::fbthrift::TType::Stop, _, _) => break,
                    (::fbthrift::TType::String, 1, false) => {
                        once = true;
                        alt = ::std::option::Option::Some(DataUnion::binaryData(::fbthrift::Deserialize::read(p)?));
                    }
                    (::fbthrift::TType::String, 2, false) => {
                        once = true;
                        alt = ::std::option::Option::Some(DataUnion::stringData(::fbthrift::Deserialize::read(p)?));
                    }
                    (fty, _, false) => p.skip(fty)?,
                    (badty, badid, true) => return ::std::result::Result::Err(::std::convert::From::from(::fbthrift::ApplicationException::new(
                        ::fbthrift::ApplicationExceptionErrorCode::ProtocolError,
                        format!(
                            "unwanted extra union {} field ty {:?} id {}",
                            "DataUnion",
                            badty,
                            badid,
                        ),
                    ))),
                }
                p.read_field_end()?;
            }
            p.read_struct_end()?;
            ::std::result::Result::Ok(alt.unwrap_or_default())
        }
    }

    impl ::std::default::Default for self::Val {
        fn default() -> Self {
            Self {
                strVal: ::std::default::Default::default(),
                intVal: ::std::default::Default::default(),
                typedefValue: ::std::default::Default::default(),
                _dot_dot_Default_default: self::dot_dot::OtherFields(()),
            }
        }
    }

    impl ::std::fmt::Debug for self::Val {
        fn fmt(&self, formatter: &mut ::std::fmt::Formatter) -> ::std::fmt::Result {
            formatter
                .debug_struct("Val")
                .field("strVal", &self.strVal)
                .field("intVal", &self.intVal)
                .field("typedefValue", &self.typedefValue)
                .finish()
        }
    }

    unsafe impl ::std::marker::Send for self::Val {}
    unsafe impl ::std::marker::Sync for self::Val {}

    impl ::fbthrift::GetTType for self::Val {
        const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
    }

    impl<P> ::fbthrift::Serialize<P> for self::Val
    where
        P: ::fbthrift::ProtocolWriter,
    {
        fn write(&self, p: &mut P) {
            p.write_struct_begin("Val");
            p.write_field_begin("strVal", ::fbthrift::TType::String, 1);
            ::fbthrift::Serialize::write(&self.strVal, p);
            p.write_field_end();
            p.write_field_begin("intVal", ::fbthrift::TType::I32, 2);
            ::fbthrift::Serialize::write(&self.intVal, p);
            p.write_field_end();
            p.write_field_begin("typedefValue", ::fbthrift::TType::Map, 9);
            ::fbthrift::Serialize::write(&self.typedefValue, p);
            p.write_field_end();
            p.write_field_stop();
            p.write_struct_end();
        }
    }

    impl<P> ::fbthrift::Deserialize<P> for self::Val
    where
        P: ::fbthrift::ProtocolReader,
    {
        fn read(p: &mut P) -> ::anyhow::Result<Self> {
            static FIELDS: &[::fbthrift::Field] = &[
                ::fbthrift::Field::new("intVal", ::fbthrift::TType::I32, 2),
                ::fbthrift::Field::new("strVal", ::fbthrift::TType::String, 1),
                ::fbthrift::Field::new("typedefValue", ::fbthrift::TType::Map, 9),
            ];
            let mut field_strVal = ::std::option::Option::None;
            let mut field_intVal = ::std::option::Option::None;
            let mut field_typedefValue = ::std::option::Option::None;
            let _ = p.read_struct_begin(|_| ())?;
            loop {
                let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
                match (fty, fid as ::std::primitive::i32) {
                    (::fbthrift::TType::Stop, _) => break,
                    (::fbthrift::TType::String, 1) => field_strVal = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                    (::fbthrift::TType::I32, 2) => field_intVal = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                    (::fbthrift::TType::Map, 9) => field_typedefValue = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                    (fty, _) => p.skip(fty)?,
                }
                p.read_field_end()?;
            }
            p.read_struct_end()?;
            ::std::result::Result::Ok(Self {
                strVal: field_strVal.unwrap_or_default(),
                intVal: field_intVal.unwrap_or_default(),
                typedefValue: field_typedefValue.unwrap_or_default(),
                _dot_dot_Default_default: self::dot_dot::OtherFields(()),
            })
        }
    }



    impl ::std::default::Default for ValUnion {
        fn default() -> Self {
            Self::UnknownField(-1)
        }
    }

    impl ::fbthrift::GetTType for ValUnion {
        const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
    }

    impl<P> ::fbthrift::Serialize<P> for ValUnion
    where
        P: ::fbthrift::ProtocolWriter,
    {
        fn write(&self, p: &mut P) {
            p.write_struct_begin("ValUnion");
            match self {
                ValUnion::v1(inner) => {
                    p.write_field_begin("v1", ::fbthrift::TType::Struct, 1);
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                ValUnion::v2(inner) => {
                    p.write_field_begin("v2", ::fbthrift::TType::Struct, 2);
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                ValUnion::UnknownField(_) => {}
            }
            p.write_field_stop();
            p.write_struct_end();
        }
    }

    impl<P> ::fbthrift::Deserialize<P> for ValUnion
    where
        P: ::fbthrift::ProtocolReader,
    {
        fn read(p: &mut P) -> ::anyhow::Result<Self> {
            static FIELDS: &[::fbthrift::Field] = &[
                ::fbthrift::Field::new("v1", ::fbthrift::TType::Struct, 1),
                ::fbthrift::Field::new("v2", ::fbthrift::TType::Struct, 2),
            ];
            let _ = p.read_struct_begin(|_| ())?;
            let mut once = false;
            let mut alt = ::std::option::Option::None;
            loop {
                let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
                match (fty, fid as ::std::primitive::i32, once) {
                    (::fbthrift::TType::Stop, _, _) => break,
                    (::fbthrift::TType::Struct, 1, false) => {
                        once = true;
                        alt = ::std::option::Option::Some(ValUnion::v1(::fbthrift::Deserialize::read(p)?));
                    }
                    (::fbthrift::TType::Struct, 2, false) => {
                        once = true;
                        alt = ::std::option::Option::Some(ValUnion::v2(::fbthrift::Deserialize::read(p)?));
                    }
                    (fty, _, false) => p.skip(fty)?,
                    (badty, badid, true) => return ::std::result::Result::Err(::std::convert::From::from(::fbthrift::ApplicationException::new(
                        ::fbthrift::ApplicationExceptionErrorCode::ProtocolError,
                        format!(
                            "unwanted extra union {} field ty {:?} id {}",
                            "ValUnion",
                            badty,
                            badid,
                        ),
                    ))),
                }
                p.read_field_end()?;
            }
            p.read_struct_end()?;
            ::std::result::Result::Ok(alt.unwrap_or_default())
        }
    }


    impl ::std::default::Default for VirtualComplexUnion {
        fn default() -> Self {
            Self::UnknownField(-1)
        }
    }

    impl ::fbthrift::GetTType for VirtualComplexUnion {
        const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
    }

    impl<P> ::fbthrift::Serialize<P> for VirtualComplexUnion
    where
        P: ::fbthrift::ProtocolWriter,
    {
        fn write(&self, p: &mut P) {
            p.write_struct_begin("VirtualComplexUnion");
            match self {
                VirtualComplexUnion::thingOne(inner) => {
                    p.write_field_begin("thingOne", ::fbthrift::TType::String, 1);
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                VirtualComplexUnion::thingTwo(inner) => {
                    p.write_field_begin("thingTwo", ::fbthrift::TType::String, 2);
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                VirtualComplexUnion::UnknownField(_) => {}
            }
            p.write_field_stop();
            p.write_struct_end();
        }
    }

    impl<P> ::fbthrift::Deserialize<P> for VirtualComplexUnion
    where
        P: ::fbthrift::ProtocolReader,
    {
        fn read(p: &mut P) -> ::anyhow::Result<Self> {
            static FIELDS: &[::fbthrift::Field] = &[
                ::fbthrift::Field::new("thingOne", ::fbthrift::TType::String, 1),
                ::fbthrift::Field::new("thingTwo", ::fbthrift::TType::String, 2),
            ];
            let _ = p.read_struct_begin(|_| ())?;
            let mut once = false;
            let mut alt = ::std::option::Option::None;
            loop {
                let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
                match (fty, fid as ::std::primitive::i32, once) {
                    (::fbthrift::TType::Stop, _, _) => break,
                    (::fbthrift::TType::String, 1, false) => {
                        once = true;
                        alt = ::std::option::Option::Some(VirtualComplexUnion::thingOne(::fbthrift::Deserialize::read(p)?));
                    }
                    (::fbthrift::TType::String, 2, false) => {
                        once = true;
                        alt = ::std::option::Option::Some(VirtualComplexUnion::thingTwo(::fbthrift::Deserialize::read(p)?));
                    }
                    (fty, _, false) => p.skip(fty)?,
                    (badty, badid, true) => return ::std::result::Result::Err(::std::convert::From::from(::fbthrift::ApplicationException::new(
                        ::fbthrift::ApplicationExceptionErrorCode::ProtocolError,
                        format!(
                            "unwanted extra union {} field ty {:?} id {}",
                            "VirtualComplexUnion",
                            badty,
                            badid,
                        ),
                    ))),
                }
                p.read_field_end()?;
            }
            p.read_struct_end()?;
            ::std::result::Result::Ok(alt.unwrap_or_default())
        }
    }

    impl ::std::default::Default for self::NonCopyableStruct {
        fn default() -> Self {
            Self {
                num: ::std::default::Default::default(),
                _dot_dot_Default_default: self::dot_dot::OtherFields(()),
            }
        }
    }

    impl ::std::fmt::Debug for self::NonCopyableStruct {
        fn fmt(&self, formatter: &mut ::std::fmt::Formatter) -> ::std::fmt::Result {
            formatter
                .debug_struct("NonCopyableStruct")
                .field("num", &self.num)
                .finish()
        }
    }

    unsafe impl ::std::marker::Send for self::NonCopyableStruct {}
    unsafe impl ::std::marker::Sync for self::NonCopyableStruct {}

    impl ::fbthrift::GetTType for self::NonCopyableStruct {
        const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
    }

    impl<P> ::fbthrift::Serialize<P> for self::NonCopyableStruct
    where
        P: ::fbthrift::ProtocolWriter,
    {
        fn write(&self, p: &mut P) {
            p.write_struct_begin("NonCopyableStruct");
            p.write_field_begin("num", ::fbthrift::TType::I64, 1);
            ::fbthrift::Serialize::write(&self.num, p);
            p.write_field_end();
            p.write_field_stop();
            p.write_struct_end();
        }
    }

    impl<P> ::fbthrift::Deserialize<P> for self::NonCopyableStruct
    where
        P: ::fbthrift::ProtocolReader,
    {
        fn read(p: &mut P) -> ::anyhow::Result<Self> {
            static FIELDS: &[::fbthrift::Field] = &[
                ::fbthrift::Field::new("num", ::fbthrift::TType::I64, 1),
            ];
            let mut field_num = ::std::option::Option::None;
            let _ = p.read_struct_begin(|_| ())?;
            loop {
                let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
                match (fty, fid as ::std::primitive::i32) {
                    (::fbthrift::TType::Stop, _) => break,
                    (::fbthrift::TType::I64, 1) => field_num = ::std::option::Option::Some(::fbthrift::Deserialize::read(p)?),
                    (fty, _) => p.skip(fty)?,
                }
                p.read_field_end()?;
            }
            p.read_struct_end()?;
            ::std::result::Result::Ok(Self {
                num: field_num.unwrap_or_default(),
                _dot_dot_Default_default: self::dot_dot::OtherFields(()),
            })
        }
    }



    impl ::std::default::Default for NonCopyableUnion {
        fn default() -> Self {
            Self::UnknownField(-1)
        }
    }

    impl ::fbthrift::GetTType for NonCopyableUnion {
        const TTYPE: ::fbthrift::TType = ::fbthrift::TType::Struct;
    }

    impl<P> ::fbthrift::Serialize<P> for NonCopyableUnion
    where
        P: ::fbthrift::ProtocolWriter,
    {
        fn write(&self, p: &mut P) {
            p.write_struct_begin("NonCopyableUnion");
            match self {
                NonCopyableUnion::s(inner) => {
                    p.write_field_begin("s", ::fbthrift::TType::Struct, 1);
                    ::fbthrift::Serialize::write(inner, p);
                    p.write_field_end();
                }
                NonCopyableUnion::UnknownField(_) => {}
            }
            p.write_field_stop();
            p.write_struct_end();
        }
    }

    impl<P> ::fbthrift::Deserialize<P> for NonCopyableUnion
    where
        P: ::fbthrift::ProtocolReader,
    {
        fn read(p: &mut P) -> ::anyhow::Result<Self> {
            static FIELDS: &[::fbthrift::Field] = &[
                ::fbthrift::Field::new("s", ::fbthrift::TType::Struct, 1),
            ];
            let _ = p.read_struct_begin(|_| ())?;
            let mut once = false;
            let mut alt = ::std::option::Option::None;
            loop {
                let (_, fty, fid) = p.read_field_begin(|_| (), FIELDS)?;
                match (fty, fid as ::std::primitive::i32, once) {
                    (::fbthrift::TType::Stop, _, _) => break,
                    (::fbthrift::TType::Struct, 1, false) => {
                        once = true;
                        alt = ::std::option::Option::Some(NonCopyableUnion::s(::fbthrift::Deserialize::read(p)?));
                    }
                    (fty, _, false) => p.skip(fty)?,
                    (badty, badid, true) => return ::std::result::Result::Err(::std::convert::From::from(::fbthrift::ApplicationException::new(
                        ::fbthrift::ApplicationExceptionErrorCode::ProtocolError,
                        format!(
                            "unwanted extra union {} field ty {:?} id {}",
                            "NonCopyableUnion",
                            badty,
                            badid,
                        ),
                    ))),
                }
                p.read_field_end()?;
            }
            p.read_struct_end()?;
            ::std::result::Result::Ok(alt.unwrap_or_default())
        }
    }

    mod dot_dot {
        #[derive(Copy, Clone, PartialEq, Eq, PartialOrd, Ord, Hash)]
        pub struct OtherFields(pub(crate) ());

        #[allow(dead_code)] // if serde isn't being used
        pub(super) fn default_for_serde_deserialize() -> OtherFields {
            OtherFields(())
        }
    }
}

/// Error return types.
pub mod errors {
}
