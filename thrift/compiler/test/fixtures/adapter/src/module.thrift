/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

namespace android test.fixtures.adapter
namespace java test.fixtures.adapter
namespace java2 test.fixtures.adapter
namespace java.swift test.fixtures.adapter

include "thrift/annotation/cpp.thrift"
include "thrift/annotation/python.thrift"
include "thrift/annotation/thrift.thrift"

typedef set<string> (
  hack.adapter = '\Adapter2',
  cpp.adapter = 'my::Adapter2',
  py.adapter = 'my.Adapter2',
) SetWithAdapter
typedef list<
  string (
    hack.adapter = '\Adapter1',
    cpp.adapter = 'my::Adapter1',
    py.adapter = 'my.Adapter1',
  )
> ListWithElemAdapter

@cpp.Adapter{name = "my::Adapter1"}
typedef i64 MyI64

struct Foo {
  1: i32 (
    hack.adapter = '\Adapter1',
    cpp.adapter = 'my::Adapter1',
    py.adapter = 'my.Adapter1',
  ) intField;
  2: optional i32 (
    hack.adapter = '\Adapter1',
    cpp.adapter = 'my::Adapter1',
    py.adapter = 'my.Adapter1',
  ) optionalIntField;
  3: i32 (
    hack.adapter = '\Adapter1',
    cpp.adapter = 'my::Adapter1',
    py.adapter = 'my.Adapter1',
  ) intFieldWithDefault = 13;
  4: SetWithAdapter setField;
  5: optional SetWithAdapter optionalSetField;
  6: map<
    string,
    ListWithElemAdapter (
      hack.adapter = '\Adapter2',
      cpp.adapter = 'my::Adapter2',
      py.adapter = 'my.Adapter2',
    )
  > (
    hack.adapter = '\Adapter3',
    cpp.adapter = 'my::Adapter3',
    py.adapter = 'my.Adapter3',
  ) mapField;
  7: optional map<
    string,
    ListWithElemAdapter (
      hack.adapter = '\Adapter2',
      cpp.adapter = 'my::Adapter2',
      py.adapter = 'my.Adapter2',
    )
  > (
    hack.adapter = '\Adapter3',
    cpp.adapter = 'my::Adapter3',
    py.adapter = 'my.Adapter3',
  ) optionalMapField;
  8: binary (
    hack.adapter = '\Adapter1',
    cpp.adapter = 'my::Adapter1',
    py.adapter = 'my.Adapter1',
  ) binaryField;
  9: MyI64 longField;
  @cpp.Adapter{name = "my::Adapter2"}
  10: MyI64 adaptedLongField;
} (
  thrift.uri = "facebook.com/thrift/compiler/test/fixtures/adapter/src/module/Foo",
)

union Baz {
  1: i32 (
    hack.adapter = '\Adapter1',
    cpp.adapter = 'my::Adapter1',
    py.adapter = 'my.Adapter1',
  ) intField;
  4: SetWithAdapter setField;
  6: map<
    string,
    ListWithElemAdapter (
      hack.adapter = '\Adapter2',
      cpp.adapter = 'my::Adapter2',
      py.adapter = 'my.Adapter2',
    )
  > (
    hack.adapter = '\Adapter3',
    cpp.adapter = 'my::Adapter3',
    py.adapter = 'my.Adapter3',
  ) mapField;
  8: binary (
    hack.adapter = '\Adapter1',
    cpp.adapter = 'my::Adapter1',
    py.adapter = 'my.Adapter1',
  ) binaryField;
  9: MyI64 longField;
}

struct Bar {
  1: Foo (
    hack.adapter = '\Adapter1',
    cpp.adapter = 'my::Adapter1',
    py.adapter = 'my.Adapter1',
  ) structField;
  2: optional Foo (
    hack.adapter = '\Adapter1',
    cpp.adapter = 'my::Adapter1',
    py.adapter = 'my.Adapter1',
  ) optionalStructField;
  3: list<
    Foo (
      hack.adapter = '\Adapter1',
      cpp.adapter = 'my::Adapter1',
      py.adapter = 'my.Adapter1',
    )
  > structListField;
  4: optional list<
    Foo (
      hack.adapter = '\Adapter1',
      cpp.adapter = 'my::Adapter1',
      py.adapter = 'my.Adapter1',
    )
  > optionalStructListField;
  5: Baz (
    hack.adapter = '\Adapter1',
    cpp.adapter = 'my::Adapter1',
    py.adapter = 'my.Adapter1',
  ) unionField;
  6: optional Baz (
    hack.adapter = '\Adapter1',
    cpp.adapter = 'my::Adapter1',
    py.adapter = 'my.Adapter1',
  ) optionalUnionField;
}

struct StructWithFieldAdapter {
  @cpp.Adapter{name = "my::Adapter1"}
  @python.Adapter{name = "my.Adapter1", typeHint = "my.AdaptedType1"}
  1: i32 field;
  @cpp.Adapter{name = "my::Adapter1"}
  @cpp.Ref{type = cpp.RefType.Shared}
  2: i32 shared_field;
  @cpp.Adapter{name = "my::Adapter1"}
  @cpp.Ref{type = cpp.RefType.Shared}
  3: optional i32 opt_shared_field;
  @cpp.Adapter{name = "my::Adapter1"}
  @thrift.Box
  4: optional i32 opt_boxed_field;
}

typedef Bar (
  hack.adapter = '\Adapter2',
  cpp.adapter = 'my::Adapter2',
  py.adapter = 'my.Adapter2',
) StructWithAdapter

typedef Baz (
  hack.adapter = '\Adapter2',
  cpp.adapter = 'my::Adapter2',
  py.adapter = 'my.Adapter2',
) UnionWithAdapter

service Service {
  i32 (
    hack.adapter = '\Adapter1',
    cpp.adapter = 'my::Adapter1',
    py.adapter = 'my.Adapter1',
  ) func(
    1: string (
      hack.adapter = '\Adapter2',
      cpp.adapter = 'my::Adapter2',
      py.adapter = 'my.Adapter2',
    ) arg1,
    @cpp.Adapter{name = "my::Adapter2"}
    2: string arg2,
    3: Foo arg3,
  );
}
