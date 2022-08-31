package(default_visibility = ["//visibility:public"])

cc_library(
    name = "rmalloc",
    hdrs = ["rmalloc.h"],
    deps = ["//rome/rdma:rdma_memory"],
)

cc_test(
    name = "rmalloc_test",
    srcs = ["rmalloc_test.cc"],
    deps = [
        ":rmalloc",
        "//rome/rdma:rdma_device",
        "//rome/rdma:rdma_util",
        "//rome/util:memory_resource",
        "//rome/rdma/connection_manager",
        "@gtest//:gtest_main",
    ],
)
