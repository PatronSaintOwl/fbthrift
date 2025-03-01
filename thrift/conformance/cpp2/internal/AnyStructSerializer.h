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

#pragma once

#include <thrift/conformance/if/gen-cpp2/protocol_types.h>
#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>
#include <thrift/lib/cpp2/protocol/JSONProtocol.h>
#include <thrift/lib/cpp2/protocol/SimpleJSONProtocol.h>

namespace apache::thrift::conformance::detail {

template <StandardProtocol protocol>
struct ProtocolHelper;

template <>
struct ProtocolHelper<StandardProtocol::Binary> {
  using reader = BinaryProtocolReader;
  using writer = BinaryProtocolWriter;
};

template <>
struct ProtocolHelper<StandardProtocol::Compact> {
  using reader = CompactProtocolReader;
  using writer = CompactProtocolWriter;
};

template <>
struct ProtocolHelper<StandardProtocol::Json> {
  using reader = JSONProtocolReader;
  using writer = JSONProtocolWriter;
};

template <>
struct ProtocolHelper<StandardProtocol::SimpleJson> {
  using reader = SimpleJSONProtocolReader;
  using writer = SimpleJSONProtocolWriter;
};

template <StandardProtocol protocol>
using protocol_reader_t = typename ProtocolHelper<protocol>::reader;

template <StandardProtocol protocol>
using protocol_writer_t = typename ProtocolHelper<protocol>::writer;

} // namespace apache::thrift::conformance::detail
