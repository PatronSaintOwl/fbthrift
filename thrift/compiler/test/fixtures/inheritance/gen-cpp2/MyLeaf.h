/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include <thrift/lib/cpp2/gen/service_h.h>

#include "thrift/compiler/test/fixtures/inheritance/gen-cpp2/MyLeafAsyncClient.h"
#include "thrift/compiler/test/fixtures/inheritance/gen-cpp2/module_types.h"
#include "thrift/compiler/test/fixtures/inheritance/gen-cpp2/MyNode.h"

namespace folly {
  class IOBuf;
  class IOBufQueue;
}
namespace apache { namespace thrift {
  class Cpp2RequestContext;
  class BinaryProtocolReader;
  class CompactProtocolReader;
  namespace transport { class THeader; }
}}

namespace cpp2 {
class MyLeaf;
class MyLeafAsyncProcessor;

class MyLeafServiceInfoHolder : public apache::thrift::ServiceInfoHolder {
  public:
   apache::thrift::ServiceRequestInfoMap const& requestInfoMap() const override;
   static apache::thrift::ServiceRequestInfoMap staticRequestInfoMap();
};
} // cpp2

namespace apache::thrift {
template <>
class ServiceHandler<::cpp2::MyLeaf> : virtual public ::cpp2::MyNodeSvIf {
 public:
  std::string_view getGeneratedName() const override { return "MyLeaf"; }

  typedef ::cpp2::MyLeafAsyncProcessor ProcessorType;
  std::unique_ptr<apache::thrift::AsyncProcessor> getProcessor() override;
  CreateMethodMetadataResult createMethodMetadata() override;
 private:
  std::optional<std::reference_wrapper<apache::thrift::ServiceRequestInfoMap const>> getServiceRequestInfoMap() const;
 public:

  virtual void do_leaf();
  virtual folly::Future<folly::Unit> future_do_leaf();
  virtual folly::SemiFuture<folly::Unit> semifuture_do_leaf();
  virtual void async_tm_do_leaf(std::unique_ptr<apache::thrift::HandlerCallback<void>> callback);
 private:
  static ::cpp2::MyLeafServiceInfoHolder __fbthrift_serviceInfoHolder;
  std::atomic<apache::thrift::detail::si::InvocationType> __fbthrift_invocation_do_leaf{apache::thrift::detail::si::InvocationType::AsyncTm};
};

} // namespace apache::thrift

namespace cpp2 {
using MyLeafSvIf = ::apache::thrift::ServiceHandler<MyLeaf>;
} // cpp2
namespace cpp2 {
class MyLeafSvNull : public MyLeafSvIf, virtual public ::cpp2::MyNodeSvIf {
 public:
  void do_leaf() override;
};

class MyLeafAsyncProcessor : public ::cpp2::MyNodeAsyncProcessor {
 public:
  const char* getServiceName() override;
  void getServiceMetadata(apache::thrift::metadata::ThriftServiceMetadataResponse& response) override;
  using BaseAsyncProcessor = ::cpp2::MyNodeAsyncProcessor;
 protected:
  ::apache::thrift::ServiceHandler<::cpp2::MyLeaf>* iface_;
 public:
  // This is implemented in case the corresponding AsyncProcessorFactory did not implement createMethodMetadata.
  // This can happen if the service is using a custom AsyncProcessorFactory but re-using the same AsyncProcessor.
  void processSerializedCompressedRequest(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  // By default, this overload will be called for generated services
  void processSerializedCompressedRequestWithMetadata(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata, apache::thrift::protocol::PROTOCOL_TYPES protType, apache::thrift::Cpp2RequestContext* context, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) override;
  void executeRequest(apache::thrift::ServerRequest&& serverRequest, const apache::thrift::AsyncProcessorFactory::MethodMetadata& methodMetadata) override;
 public:
  using ProcessFuncs = GeneratedAsyncProcessor::ProcessFuncs<MyLeafAsyncProcessor>;
  using ProcessMap = GeneratedAsyncProcessor::ProcessMap<ProcessFuncs>;
  static const MyLeafAsyncProcessor::ProcessMap& getOwnProcessMap();
 private:
  static const MyLeafAsyncProcessor::ProcessMap kOwnProcessMap_;
 private:
  template <typename ProtocolIn_, typename ProtocolOut_>
  void setUpAndProcess_do_leaf(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm);
  template <typename ProtocolIn_, typename ProtocolOut_>
  void executeRequest_do_leaf(apache::thrift::ServerRequest&& serverRequest);
  template <class ProtocolIn_, class ProtocolOut_>
  static apache::thrift::SerializedResponse return_do_leaf(apache::thrift::ContextStack* ctx);
  template <class ProtocolIn_, class ProtocolOut_>
  static void throw_wrapped_do_leaf(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx);
 public:
  MyLeafAsyncProcessor(::apache::thrift::ServiceHandler<::cpp2::MyLeaf>* iface) :
      ::cpp2::MyNodeAsyncProcessor(iface),
      iface_(iface) {}
  ~MyLeafAsyncProcessor() override {}
};

} // cpp2
