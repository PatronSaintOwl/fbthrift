# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# pyre-unsafe

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
from __future__ import unicode_literals

import sys

from thrift.protocol import TProtocolDecorator, TMultiplexedProtocol
from thrift.Thrift import TProcessor, TMessageType, TException


class TMultiplexedProcessor(TProcessor):
    def __init__(self):
        self.services = {}

    def registerProcessor(self, serviceName, processor):
        self.services[serviceName] = processor

    def setEventHandler(self, event_handler, serviceName=None):
        """Set event handler for a service. If serviceName is None,
        set event handler for all services"""
        if serviceName is not None:
            if not serviceName in self.services:
                raise TException(
                    "Cannot set event handler for service "
                    + serviceName
                    + ": no such service"
                )
            else:
                self.services[serviceName].setEventHandler(event_handler)
        else:
            for processor in self.services.values():
                processor.setEventHandler(event_handler)

    def process(self, iprot, oprot, server_ctx=None):
        (name, type, seqid) = iprot.readMessageBegin()
        if type != TMessageType.CALL and type != TMessageType.ONEWAY:
            raise TException("TMultiplex protocol only supports CALL & ONEWAY")

        if sys.version_info[0] >= 3 and isinstance(name, bytes):
            name = name.decode("utf-8")
        index = name.find(TMultiplexedProtocol.SEPARATOR)
        if index < 0:
            raise TException(
                "Service name not found in message name: "
                + name
                + ". Did you forget to use TMultiplexProtocol "
                + "in your client?"
            )

        serviceName = name[0:index]
        call = name[index + len(TMultiplexedProtocol.SEPARATOR) :]
        if sys.version_info[0] >= 3:
            call = call.encode("utf-8")
        if not serviceName in self.services:
            raise TException(
                "Service name not found: "
                + serviceName
                + ". Did you forget to call registerProcessor()?"
            )

        standardMessage = (call, type, seqid)
        return self.services[serviceName].process(
            StoredMessageProtocol(iprot, standardMessage), oprot, server_ctx
        )


class StoredMessageProtocol(TProtocolDecorator.TProtocolDecorator):
    def __init__(self, protocol, messageBegin):
        TProtocolDecorator.TProtocolDecorator.__init__(self, protocol)
        self.messageBegin = messageBegin

    def readMessageBegin(self):
        return self.messageBegin
