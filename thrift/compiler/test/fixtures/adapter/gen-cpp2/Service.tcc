/**
 * Autogenerated by Thrift for src/module.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/compiler/test/fixtures/adapter/gen-cpp2/Service.h"

#include <thrift/lib/cpp2/gen/service_tcc.h>

namespace cpp2 {
typedef apache::thrift::ThriftPresult<false, apache::thrift::FieldData<1, ::apache::thrift::type_class::string, ::apache::thrift::adapt_detail::adapted_t<my::Adapter2, ::std::string>*>, apache::thrift::FieldData<2, ::apache::thrift::type_class::string, ::std::string*>, apache::thrift::FieldData<3, ::apache::thrift::type_class::structure, ::cpp2::Foo*>> Service_func_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, ::apache::thrift::type_class::integral, ::apache::thrift::adapt_detail::adapted_t<my::Adapter1, ::std::int32_t>*>> Service_func_presult;
template <typename ProtocolIn_, typename ProtocolOut_>
void ServiceAsyncProcessor::setUpAndProcess_func(apache::thrift::ResponseChannelRequest::UniquePtr req, apache::thrift::SerializedCompressedRequest&& serializedRequest, apache::thrift::Cpp2RequestContext* ctx, folly::EventBase* eb, apache::thrift::concurrency::ThreadManager* tm) {
  if (!setUpRequestProcessing(req, ctx, eb, tm, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, iface_)) {
    return;
  }
  auto scope = iface_->getRequestExecutionScope(ctx, apache::thrift::concurrency::NORMAL);
  ctx->setRequestExecutionScope(std::move(scope));
  processInThread(std::move(req), std::move(serializedRequest), ctx, eb, tm, apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, &ServiceAsyncProcessor::executeRequest_func<ProtocolIn_, ProtocolOut_>, this);
}

template <typename ProtocolIn_, typename ProtocolOut_>
void ServiceAsyncProcessor::executeRequest_func(apache::thrift::ServerRequest&& serverRequest) {
  // make sure getRequestContext is null
  // so async calls don't accidentally use it
  iface_->setRequestContext(nullptr);
  ::cpp2::Service_func_pargs args;
  auto uarg_arg1 = std::make_unique<::apache::thrift::adapt_detail::adapted_t<my::Adapter2, ::std::string>>();
  args.get<0>().value = uarg_arg1.get();
  auto uarg_arg2 = std::make_unique<::std::string>();
  args.get<1>().value = uarg_arg2.get();
  auto uarg_arg3 = std::make_unique<::cpp2::Foo>();
  args.get<2>().value = uarg_arg3.get();
  std::unique_ptr<apache::thrift::ContextStack> ctxStack(this->getContextStack(this->getServiceName(), "Service.func", serverRequest.requestContext()));
  try {
    deserializeRequest<ProtocolIn_>(args, "func", apache::thrift::detail::ServerRequestHelper::compressedRequest(std::move(serverRequest)).uncompress(), ctxStack.get());
  }
  catch (const std::exception& ex) {
    folly::exception_wrapper ew(std::current_exception(), ex);
    apache::thrift::detail::ap::process_handle_exn_deserialization<ProtocolOut_>(
        ew
        , apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
        , serverRequest.requestContext()
        , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
        , "func");
    return;
  }
  auto requestPileNotification = apache::thrift::detail::ServerRequestHelper::requestPileNotification(serverRequest);
  auto concurrencyControllerNotification = apache::thrift::detail::ServerRequestHelper::concurrencyControllerNotification(serverRequest);
  auto callback = std::make_unique<apache::thrift::HandlerCallback<::apache::thrift::adapt_detail::adapted_t<my::Adapter1, ::std::int32_t>>>(
    apache::thrift::detail::ServerRequestHelper::request(std::move(serverRequest))
    , std::move(ctxStack)
    , return_func<ProtocolIn_,ProtocolOut_>
    , throw_wrapped_func<ProtocolIn_, ProtocolOut_>
    , serverRequest.requestContext()->getProtoSeqId()
    , apache::thrift::detail::ServerRequestHelper::eventBase(serverRequest)
    , apache::thrift::detail::ServerRequestHelper::executor(serverRequest)
    , serverRequest.requestContext()
    , requestPileNotification.first, requestPileNotification.second
    , concurrencyControllerNotification.first, concurrencyControllerNotification.second
    );
  iface_->async_tm_func(std::move(callback), std::move(uarg_arg1), std::move(uarg_arg2), std::move(uarg_arg3));
}

template <class ProtocolIn_, class ProtocolOut_>
apache::thrift::SerializedResponse ServiceAsyncProcessor::return_func(apache::thrift::ContextStack* ctx, ::apache::thrift::adapt_detail::adapted_t<my::Adapter1, ::std::int32_t> const& _return) {
  ProtocolOut_ prot;
  ::cpp2::Service_func_presult result;
  result.get<0>().value = const_cast<::apache::thrift::adapt_detail::adapted_t<my::Adapter1, ::std::int32_t>*>(&_return);
  result.setIsSet(0, true);
  return serializeResponse(&prot, ctx, result);
}

template <class ProtocolIn_, class ProtocolOut_>
void ServiceAsyncProcessor::throw_wrapped_func(apache::thrift::ResponseChannelRequest::UniquePtr req,int32_t protoSeqId,apache::thrift::ContextStack* ctx,folly::exception_wrapper ew,apache::thrift::Cpp2RequestContext* reqCtx) {
  if (!ew) {
    return;
  }
  {
    (void)protoSeqId;
    apache::thrift::detail::ap::process_throw_wrapped_handler_error<ProtocolOut_>(
        ew, std::move(req), reqCtx, ctx, "func");
    return;
  }
}


} // cpp2
