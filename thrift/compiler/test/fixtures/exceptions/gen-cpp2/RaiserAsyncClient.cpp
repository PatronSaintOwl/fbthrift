/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#include "thrift/compiler/test/fixtures/exceptions/gen-cpp2/RaiserAsyncClient.h"

#include <thrift/lib/cpp2/gen/client_cpp.h>

namespace cpp2 {
typedef apache::thrift::ThriftPresult<false> Raiser_doBland_pargs;
typedef apache::thrift::ThriftPresult<true> Raiser_doBland_presult;
typedef apache::thrift::ThriftPresult<false> Raiser_doRaise_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::cpp2::Banal>, apache::thrift::FieldData<2, apache::thrift::protocol::T_STRUCT,  ::cpp2::Fiery>, apache::thrift::FieldData<3, apache::thrift::protocol::T_STRUCT,  ::cpp2::Serious>> Raiser_doRaise_presult;
typedef apache::thrift::ThriftPresult<false> Raiser_get200_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_STRING, ::std::string*>> Raiser_get200_presult;
typedef apache::thrift::ThriftPresult<false> Raiser_get500_pargs;
typedef apache::thrift::ThriftPresult<true, apache::thrift::FieldData<0, apache::thrift::protocol::T_STRING, ::std::string*>, apache::thrift::FieldData<1, apache::thrift::protocol::T_STRUCT,  ::cpp2::Fiery>, apache::thrift::FieldData<2, apache::thrift::protocol::T_STRUCT,  ::cpp2::Banal>, apache::thrift::FieldData<3, apache::thrift::protocol::T_STRUCT,  ::cpp2::Serious>> Raiser_get500_presult;

template <typename Protocol_>
void RaiserAsyncClient::doBlandT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback) {
  std::shared_ptr<apache::thrift::transport::THeader> header(ctx, &ctx->header);
  Raiser_doBland_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, Protocol_>(prot, rpcOptions, std::move(callback), ctx->ctx, std::move(header), channel_.get(), "doBland", writer, sizer);
  ctx->reqContext.setRequestHeader(nullptr);
}

template <typename Protocol_>
void RaiserAsyncClient::doRaiseT(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback) {
  std::shared_ptr<apache::thrift::transport::THeader> header(ctx, &ctx->header);
  Raiser_doRaise_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, Protocol_>(prot, rpcOptions, std::move(callback), ctx->ctx, std::move(header), channel_.get(), "doRaise", writer, sizer);
  ctx->reqContext.setRequestHeader(nullptr);
}

template <typename Protocol_>
void RaiserAsyncClient::get200T(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback) {
  std::shared_ptr<apache::thrift::transport::THeader> header(ctx, &ctx->header);
  Raiser_get200_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, Protocol_>(prot, rpcOptions, std::move(callback), ctx->ctx, std::move(header), channel_.get(), "get200", writer, sizer);
  ctx->reqContext.setRequestHeader(nullptr);
}

template <typename Protocol_>
void RaiserAsyncClient::get500T(Protocol_* prot, apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback) {
  std::shared_ptr<apache::thrift::transport::THeader> header(ctx, &ctx->header);
  Raiser_get500_pargs args;
  auto sizer = [&](Protocol_* p) { return args.serializedSizeZC(p); };
  auto writer = [&](Protocol_* p) { args.write(p); };
  apache::thrift::clientSendT<apache::thrift::RpcKind::SINGLE_REQUEST_SINGLE_RESPONSE, Protocol_>(prot, rpcOptions, std::move(callback), ctx->ctx, std::move(header), channel_.get(), "get500", writer, sizer);
  ctx->reqContext.setRequestHeader(nullptr);
}



void RaiserAsyncClient::doBland(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  doBland(rpcOptions, std::move(callback));
}

void RaiserAsyncClient::doBland(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto ctx = std::make_shared<apache::thrift::detail::ac::ClientRequestContext>(
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId(),
      rpcOptions.releaseWriteHeaders(),
      this->handlers_,
      this->getServiceName(),
      "Raiser.doBland");
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  callbackContext.ctx = std::shared_ptr<apache::thrift::ContextStack>(ctx, &ctx->ctx);
  auto wrappedCallback = apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext));
  doBlandImpl(rpcOptions, std::move(ctx), std::move(wrappedCallback));
}

void RaiserAsyncClient::doBlandImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      doBlandT(&writer, rpcOptions, std::move(ctx), std::move(callback));
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      doBlandT(&writer, rpcOptions, std::move(ctx), std::move(callback));
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

void RaiserAsyncClient::sync_doBland() {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_doBland(rpcOptions);
}

void RaiserAsyncClient::sync_doBland(apache::thrift::RpcOptions& rpcOptions) {
  apache::thrift::ClientReceiveState _returnState;
  apache::thrift::ClientSyncCallback<false> callback(&_returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctx = std::make_shared<apache::thrift::detail::ac::ClientRequestContext>(
      protocolId,
      rpcOptions.releaseWriteHeaders(),
      this->handlers_,
      this->getServiceName(),
      "Raiser.doBland");
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  doBlandImpl(rpcOptions, ctx, std::move(wrappedCallback));
  callback.waitUntilDone(evb);
  _returnState.resetProtocolId(protocolId);
  _returnState.resetCtx(std::shared_ptr<apache::thrift::ContextStack>(ctx, &ctx->ctx));
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(!!_returnState.exception());
    _returnState.exception().throw_exception();
  }
  return folly::fibers::runInMainContext([&] {
      recv_doBland(_returnState);
  });
}


folly::Future<folly::Unit> RaiserAsyncClient::future_doBland() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_doBland(rpcOptions);
}

folly::SemiFuture<folly::Unit> RaiserAsyncClient::semifuture_doBland() {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_doBland(rpcOptions);
}

folly::Future<folly::Unit> RaiserAsyncClient::future_doBland(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<folly::Unit>>(std::move(_promise), recv_wrapped_doBland, channel_);
  doBland(rpcOptions, std::move(callback));
  return _future;
}

folly::SemiFuture<folly::Unit> RaiserAsyncClient::semifuture_doBland(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_doBland, channel_);
  auto callback = std::move(callbackAndFuture.first);
  doBland(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> RaiserAsyncClient::header_future_doBland(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<folly::Unit>>(std::move(_promise), recv_wrapped_doBland, channel_);
  doBland(rpcOptions, std::move(callback));
  return _future;
}

folly::SemiFuture<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> RaiserAsyncClient::header_semifuture_doBland(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_doBland, channel_);
  auto callback = std::move(callbackAndFuture.first);
  doBland(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

void RaiserAsyncClient::doBland(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  doBland(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper RaiserAsyncClient::recv_wrapped_doBland(::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = Raiser_doBland_presult;
  constexpr auto const fname = "doBland";
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void RaiserAsyncClient::recv_doBland(::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_doBland(state);
  if (ew) {
    ew.throw_exception();
  }
}

void RaiserAsyncClient::recv_instance_doBland(::apache::thrift::ClientReceiveState& state) {
  recv_doBland(state);
}

folly::exception_wrapper RaiserAsyncClient::recv_instance_wrapped_doBland(::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_doBland(state);
}

void RaiserAsyncClient::doRaise(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  doRaise(rpcOptions, std::move(callback));
}

void RaiserAsyncClient::doRaise(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto ctx = std::make_shared<apache::thrift::detail::ac::ClientRequestContext>(
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId(),
      rpcOptions.releaseWriteHeaders(),
      this->handlers_,
      this->getServiceName(),
      "Raiser.doRaise");
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  callbackContext.ctx = std::shared_ptr<apache::thrift::ContextStack>(ctx, &ctx->ctx);
  auto wrappedCallback = apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext));
  doRaiseImpl(rpcOptions, std::move(ctx), std::move(wrappedCallback));
}

void RaiserAsyncClient::doRaiseImpl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      doRaiseT(&writer, rpcOptions, std::move(ctx), std::move(callback));
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      doRaiseT(&writer, rpcOptions, std::move(ctx), std::move(callback));
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

void RaiserAsyncClient::sync_doRaise() {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_doRaise(rpcOptions);
}

void RaiserAsyncClient::sync_doRaise(apache::thrift::RpcOptions& rpcOptions) {
  apache::thrift::ClientReceiveState _returnState;
  apache::thrift::ClientSyncCallback<false> callback(&_returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctx = std::make_shared<apache::thrift::detail::ac::ClientRequestContext>(
      protocolId,
      rpcOptions.releaseWriteHeaders(),
      this->handlers_,
      this->getServiceName(),
      "Raiser.doRaise");
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  doRaiseImpl(rpcOptions, ctx, std::move(wrappedCallback));
  callback.waitUntilDone(evb);
  _returnState.resetProtocolId(protocolId);
  _returnState.resetCtx(std::shared_ptr<apache::thrift::ContextStack>(ctx, &ctx->ctx));
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(!!_returnState.exception());
    _returnState.exception().throw_exception();
  }
  return folly::fibers::runInMainContext([&] {
      recv_doRaise(_returnState);
  });
}


folly::Future<folly::Unit> RaiserAsyncClient::future_doRaise() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_doRaise(rpcOptions);
}

folly::SemiFuture<folly::Unit> RaiserAsyncClient::semifuture_doRaise() {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_doRaise(rpcOptions);
}

folly::Future<folly::Unit> RaiserAsyncClient::future_doRaise(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<folly::Unit> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<folly::Unit>>(std::move(_promise), recv_wrapped_doRaise, channel_);
  doRaise(rpcOptions, std::move(callback));
  return _future;
}

folly::SemiFuture<folly::Unit> RaiserAsyncClient::semifuture_doRaise(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_doRaise, channel_);
  auto callback = std::move(callbackAndFuture.first);
  doRaise(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> RaiserAsyncClient::header_future_doRaise(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<folly::Unit>>(std::move(_promise), recv_wrapped_doRaise, channel_);
  doRaise(rpcOptions, std::move(callback));
  return _future;
}

folly::SemiFuture<std::pair<folly::Unit, std::unique_ptr<apache::thrift::transport::THeader>>> RaiserAsyncClient::header_semifuture_doRaise(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_doRaise, channel_);
  auto callback = std::move(callbackAndFuture.first);
  doRaise(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

void RaiserAsyncClient::doRaise(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  doRaise(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper RaiserAsyncClient::recv_wrapped_doRaise(::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = Raiser_doRaise_presult;
  constexpr auto const fname = "doRaise";
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void RaiserAsyncClient::recv_doRaise(::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_doRaise(state);
  if (ew) {
    ew.throw_exception();
  }
}

void RaiserAsyncClient::recv_instance_doRaise(::apache::thrift::ClientReceiveState& state) {
  recv_doRaise(state);
}

folly::exception_wrapper RaiserAsyncClient::recv_instance_wrapped_doRaise(::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_doRaise(state);
}

void RaiserAsyncClient::get200(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  get200(rpcOptions, std::move(callback));
}

void RaiserAsyncClient::get200(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto ctx = std::make_shared<apache::thrift::detail::ac::ClientRequestContext>(
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId(),
      rpcOptions.releaseWriteHeaders(),
      this->handlers_,
      this->getServiceName(),
      "Raiser.get200");
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  callbackContext.ctx = std::shared_ptr<apache::thrift::ContextStack>(ctx, &ctx->ctx);
  auto wrappedCallback = apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext));
  get200Impl(rpcOptions, std::move(ctx), std::move(wrappedCallback));
}

void RaiserAsyncClient::get200Impl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      get200T(&writer, rpcOptions, std::move(ctx), std::move(callback));
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      get200T(&writer, rpcOptions, std::move(ctx), std::move(callback));
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

void RaiserAsyncClient::sync_get200(::std::string& _return) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_get200(rpcOptions, _return);
}

void RaiserAsyncClient::sync_get200(apache::thrift::RpcOptions& rpcOptions, ::std::string& _return) {
  apache::thrift::ClientReceiveState _returnState;
  apache::thrift::ClientSyncCallback<false> callback(&_returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctx = std::make_shared<apache::thrift::detail::ac::ClientRequestContext>(
      protocolId,
      rpcOptions.releaseWriteHeaders(),
      this->handlers_,
      this->getServiceName(),
      "Raiser.get200");
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  get200Impl(rpcOptions, ctx, std::move(wrappedCallback));
  callback.waitUntilDone(evb);
  _returnState.resetProtocolId(protocolId);
  _returnState.resetCtx(std::shared_ptr<apache::thrift::ContextStack>(ctx, &ctx->ctx));
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(!!_returnState.exception());
    _returnState.exception().throw_exception();
  }
  return folly::fibers::runInMainContext([&] {
      recv_get200(_return, _returnState);
  });
}


folly::Future<::std::string> RaiserAsyncClient::future_get200() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_get200(rpcOptions);
}

folly::SemiFuture<::std::string> RaiserAsyncClient::semifuture_get200() {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_get200(rpcOptions);
}

folly::Future<::std::string> RaiserAsyncClient::future_get200(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<::std::string> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<::std::string>>(std::move(_promise), recv_wrapped_get200, channel_);
  get200(rpcOptions, std::move(callback));
  return _future;
}

folly::SemiFuture<::std::string> RaiserAsyncClient::semifuture_get200(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_get200, channel_);
  auto callback = std::move(callbackAndFuture.first);
  get200(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> RaiserAsyncClient::header_future_get200(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<::std::string>>(std::move(_promise), recv_wrapped_get200, channel_);
  get200(rpcOptions, std::move(callback));
  return _future;
}

folly::SemiFuture<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> RaiserAsyncClient::header_semifuture_get200(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_get200, channel_);
  auto callback = std::move(callbackAndFuture.first);
  get200(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

void RaiserAsyncClient::get200(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  get200(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper RaiserAsyncClient::recv_wrapped_get200(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = Raiser_get200_presult;
  constexpr auto const fname = "get200";
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state, _return);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state, _return);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void RaiserAsyncClient::recv_get200(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_get200(_return, state);
  if (ew) {
    ew.throw_exception();
  }
}

void RaiserAsyncClient::recv_instance_get200(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_get200(_return, state);
}

folly::exception_wrapper RaiserAsyncClient::recv_instance_wrapped_get200(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_get200(_return, state);
}

void RaiserAsyncClient::get500(std::unique_ptr<apache::thrift::RequestCallback> callback) {
  ::apache::thrift::RpcOptions rpcOptions;
  get500(rpcOptions, std::move(callback));
}

void RaiserAsyncClient::get500(apache::thrift::RpcOptions& rpcOptions, std::unique_ptr<apache::thrift::RequestCallback> callback) {
  auto ctx = std::make_shared<apache::thrift::detail::ac::ClientRequestContext>(
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId(),
      rpcOptions.releaseWriteHeaders(),
      this->handlers_,
      this->getServiceName(),
      "Raiser.get500");
  apache::thrift::RequestCallback::Context callbackContext;
  callbackContext.protocolId =
      apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  callbackContext.ctx = std::shared_ptr<apache::thrift::ContextStack>(ctx, &ctx->ctx);
  auto wrappedCallback = apache::thrift::toRequestClientCallbackPtr(std::move(callback), std::move(callbackContext));
  get500Impl(rpcOptions, std::move(ctx), std::move(wrappedCallback));
}

void RaiserAsyncClient::get500Impl(apache::thrift::RpcOptions& rpcOptions, std::shared_ptr<apache::thrift::detail::ac::ClientRequestContext> ctx, apache::thrift::RequestClientCallback::Ptr callback) {
  switch (apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolWriter writer;
      get500T(&writer, rpcOptions, std::move(ctx), std::move(callback));
      break;
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolWriter writer;
      get500T(&writer, rpcOptions, std::move(ctx), std::move(callback));
      break;
    }
    default:
    {
      apache::thrift::detail::ac::throw_app_exn("Could not find Protocol");
    }
  }
}

void RaiserAsyncClient::sync_get500(::std::string& _return) {
  ::apache::thrift::RpcOptions rpcOptions;
  sync_get500(rpcOptions, _return);
}

void RaiserAsyncClient::sync_get500(apache::thrift::RpcOptions& rpcOptions, ::std::string& _return) {
  apache::thrift::ClientReceiveState _returnState;
  apache::thrift::ClientSyncCallback<false> callback(&_returnState);
  auto protocolId = apache::thrift::GeneratedAsyncClient::getChannel()->getProtocolId();
  auto evb = apache::thrift::GeneratedAsyncClient::getChannel()->getEventBase();
  auto ctx = std::make_shared<apache::thrift::detail::ac::ClientRequestContext>(
      protocolId,
      rpcOptions.releaseWriteHeaders(),
      this->handlers_,
      this->getServiceName(),
      "Raiser.get500");
  auto wrappedCallback = apache::thrift::RequestClientCallback::Ptr(&callback);
  get500Impl(rpcOptions, ctx, std::move(wrappedCallback));
  callback.waitUntilDone(evb);
  _returnState.resetProtocolId(protocolId);
  _returnState.resetCtx(std::shared_ptr<apache::thrift::ContextStack>(ctx, &ctx->ctx));
  SCOPE_EXIT {
    if (_returnState.header() && !_returnState.header()->getHeaders().empty()) {
      rpcOptions.setReadHeaders(_returnState.header()->releaseHeaders());
    }
  };
  if (!_returnState.buf()) {
    assert(!!_returnState.exception());
    _returnState.exception().throw_exception();
  }
  return folly::fibers::runInMainContext([&] {
      recv_get500(_return, _returnState);
  });
}


folly::Future<::std::string> RaiserAsyncClient::future_get500() {
  ::apache::thrift::RpcOptions rpcOptions;
  return future_get500(rpcOptions);
}

folly::SemiFuture<::std::string> RaiserAsyncClient::semifuture_get500() {
  ::apache::thrift::RpcOptions rpcOptions;
  return semifuture_get500(rpcOptions);
}

folly::Future<::std::string> RaiserAsyncClient::future_get500(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<::std::string> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::FutureCallback<::std::string>>(std::move(_promise), recv_wrapped_get500, channel_);
  get500(rpcOptions, std::move(callback));
  return _future;
}

folly::SemiFuture<::std::string> RaiserAsyncClient::semifuture_get500(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeSemiFutureCallback(recv_wrapped_get500, channel_);
  auto callback = std::move(callbackAndFuture.first);
  get500(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

folly::Future<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> RaiserAsyncClient::header_future_get500(apache::thrift::RpcOptions& rpcOptions) {
  folly::Promise<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> _promise;
  auto _future = _promise.getFuture();
  auto callback = std::make_unique<apache::thrift::HeaderFutureCallback<::std::string>>(std::move(_promise), recv_wrapped_get500, channel_);
  get500(rpcOptions, std::move(callback));
  return _future;
}

folly::SemiFuture<std::pair<::std::string, std::unique_ptr<apache::thrift::transport::THeader>>> RaiserAsyncClient::header_semifuture_get500(apache::thrift::RpcOptions& rpcOptions) {
  auto callbackAndFuture = makeHeaderSemiFutureCallback(recv_wrapped_get500, channel_);
  auto callback = std::move(callbackAndFuture.first);
  get500(rpcOptions, std::move(callback));
  return std::move(callbackAndFuture.second);
}

void RaiserAsyncClient::get500(folly::Function<void (::apache::thrift::ClientReceiveState&&)> callback) {
  get500(std::make_unique<apache::thrift::FunctionReplyCallback>(std::move(callback)));
}

#if FOLLY_HAS_COROUTINES
#endif // FOLLY_HAS_COROUTINES
folly::exception_wrapper RaiserAsyncClient::recv_wrapped_get500(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  if (state.isException()) {
    return std::move(state.exception());
  }
  if (!state.buf()) {
    return folly::make_exception_wrapper<apache::thrift::TApplicationException>("recv_ called without result");
  }

  using result = Raiser_get500_presult;
  constexpr auto const fname = "get500";
  switch (state.protocolId()) {
    case apache::thrift::protocol::T_BINARY_PROTOCOL:
    {
      apache::thrift::BinaryProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state, _return);
    }
    case apache::thrift::protocol::T_COMPACT_PROTOCOL:
    {
      apache::thrift::CompactProtocolReader reader;
      return apache::thrift::detail::ac::recv_wrapped<result>(
          fname, &reader, state, _return);
    }
    default:
    {
    }
  }
  return folly::make_exception_wrapper<apache::thrift::TApplicationException>("Could not find Protocol");
}

void RaiserAsyncClient::recv_get500(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  auto ew = recv_wrapped_get500(_return, state);
  if (ew) {
    ew.throw_exception();
  }
}

void RaiserAsyncClient::recv_instance_get500(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_get500(_return, state);
}

folly::exception_wrapper RaiserAsyncClient::recv_instance_wrapped_get500(::std::string& _return, ::apache::thrift::ClientReceiveState& state) {
  return recv_wrapped_get500(_return, state);
}


} // cpp2
