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

package com.facebook.thrift.adapter.common;

import com.facebook.thrift.protocol.ByteBufTProtocol;
import io.netty.buffer.ByteBuf;

/**
 * Use this type adapter if you want a ByteBuf but are ok with coping the underlying data to a new
 * ByeBuf. The ByteBuf this receives will be refcnt and should be freed when no longer being used.
 */
public class CopiedPooledByteBufTypeAdapter extends AbstractByteBufTypeAdapter {
  @Override
  public ByteBuf fromThrift(ByteBufTProtocol protocol) {
    return protocol.readBinaryAsSlice().copy();
  }
}
