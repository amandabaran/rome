#include "coroutine.h"

#include <chrono>
#include <experimental/coroutine>
#include <thread>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "rome/logging/logging.h"

namespace {
using namespace ::rome::coroutine;

struct next {
  bool await_ready() { return false; }
  bool await_suspend(Task::handler_type h) { return true; }
  void await_resume() {}
};

constexpr int kNumTasks = 4;

// A task adds the value associated with its `task_num` and iteration count.
// This way, we can check after the run that all expected values corresponding
// to a round-robin execution are present.
Task task(int task_num, std::vector<int>* out) {
  for (int i = 0; i < kNumTasks; ++i) {
    out->push_back(task_num + (i * kNumTasks));
    co_await suspend_always{};
  }
}

Task cancellable_task(const Cancelation& canceled) {
  while (!canceled) {
    co_await suspend_always{};
  }
}

TEST(RoundRobinSchedulerTest, RunsTasks) {
  // Test plan: Create a round-robin scheduler then schedule a number of tasks.
  // Each task will push a value onto a shared vector. After the coroutines
  // complete, check that the vector contains the expected values.
  ROME_INIT_LOG();
  RoundRobinScheduler scheduler;

  std::vector<int> values;
  for (int i = 0; i < kNumTasks; ++i) {
    scheduler.Schedule(task(i, &values));
  }
  scheduler.Run();

  for (int i = 0; i < values.size(); ++i) {
    EXPECT_EQ(values[i], i);
  }
}

TEST(RoundRobinSchedulerTest, CancelsTasks) {
  // Test plan: Create a round-robin scheduler then schedule a number of tasks.
  // Each task will push a value onto a shared vector. After the coroutines
  // complete, check that the vector contains the expected values.
  RoundRobinScheduler scheduler;

  std::vector<int> values;
  scheduler.Schedule(cancellable_task(scheduler.Cancelation()));
  std::thread t([&]() { scheduler.Run(); });

  std::this_thread::sleep_for(std::chrono::microseconds(100));
  scheduler.Cancel();
  t.join();
}

}  // namespace