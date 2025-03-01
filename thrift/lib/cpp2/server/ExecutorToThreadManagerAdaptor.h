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

#include <thrift/lib/cpp/concurrency/ThreadManager.h>

namespace apache::thrift {

// This is a thin wrapper over folly::Executor to convert
// the executor to a ThreadManager
//
// It only expose add() interface to act as an Executor
//
// This is only for the purpose of ResourcePool migration,
// This should not be used for any custom purpose
class ExecutorToThreadManagerAdaptor : concurrency::ThreadManager {
 public:
  ExecutorToThreadManagerAdaptor(folly::Executor& ex)
      : ka_(folly::getKeepAliveToken(ex)) {}

  // These are the only two interfaces that are implemented
  void add(
      std::shared_ptr<concurrency::Runnable> task,
      [[maybe_unused]] int64_t timeout = 0,
      [[maybe_unused]] int64_t expiration = 0,
      [[maybe_unused]] Source source = Source::UPSTREAM) noexcept override {
    ka_->add([task = std::move(task)]() { task->run(); });
  }

  void add(folly::Func f) override { ka_->add(std::move(f)); }

  void start() override {}

  void stop() override {}

  void join() override {}

  STATE state() const override { return concurrency::ThreadManager::STARTED; }

  std::shared_ptr<concurrency::ThreadFactory> threadFactory() const override {
    return std::shared_ptr<concurrency::ThreadFactory>(
        new concurrency::PosixThreadFactory());
  }

  void threadFactory(std::shared_ptr<concurrency::ThreadFactory>) override {}

  std::string getNamePrefix() const override {
    return "rp.executor_to_thread_manager_adaptor";
  }

  void setNamePrefix(const std::string&) override {}

  void addWorker(size_t) override {}

  void removeWorker(size_t) override {}

  size_t idleWorkerCount() const override { return 0; }

  size_t workerCount() const override { return 0; }

  size_t pendingTaskCount() const override { return 0; }

  size_t pendingUpstreamTaskCount() const override { return 0; }

  size_t totalTaskCount() const override { return 0; }

  size_t expiredTaskCount() override { return 0; }

  void remove(std::shared_ptr<concurrency::Runnable>) override {}

  std::shared_ptr<concurrency::Runnable> removeNextPending() override {
    return nullptr;
  }

  void clearPending() override {}

  void enableCodel(bool) override {}

  folly::Codel* getCodel() override { return nullptr; }

  void setExpireCallback(ExpireCallback) override {}

  void setCodelCallback(ExpireCallback) override {}

  void setThreadInitCallback(InitCallback) override {}

  void addTaskObserver(std::shared_ptr<Observer>) override {}

  std::chrono::nanoseconds getUsedCpuTime() const override {
    return std::chrono::nanoseconds();
  }

  [[nodiscard]] KeepAlive<> getKeepAlive(
      ExecutionScope, Source) const override {
    return ka_;
  }

 private:
  folly::Executor::KeepAlive<> ka_;
};

} // namespace apache::thrift
