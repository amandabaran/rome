cc_library(
    name = "memory_pool_impl",
    hdrs = ["memory_pool_impl.h"],
    deps = [],
)

cc_library(
    name = "memory_pool",
    hdrs = ["memory_pool.h"],
    visibility = ["//visibility:public"],
    deps = [
        ":memory_pool_impl",
        ":remote_ptr",
        "//rome/util:thread_util",
        "//protos:rdma_cc_proto",
        "//rome/metrics:summary",
        "//rome/rdma/connection_manager",
        "//rome/rdma/connection_manager:connection",
        "//rome/rdma/rmalloc",
        "//rome/util:memory_resource",
    ],
)

cc_test(
    name = "memory_pool_test",
    srcs = ["memory_pool_test.cc"],
    deps = [
        ":memory_pool",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "remote_ptr_impl",
    hdrs = ["remote_ptr_impl.h"],
    deps = [],
)

cc_library(
    name = "remote_ptr",
    hdrs = ["remote_ptr.h"],
    visibility = ["//visibility:public"],
    deps = [
        ":remote_ptr_impl",
        "//rome/logging",
    ],
)

cc_test(
    name = "remote_ptr_test",
    srcs = ["remote_ptr_test.cc"],
    deps = [
        ":remote_ptr",
        "//rome/logging",
        "@gtest//:gtest_main",
    ],
)
