cc_library(
    name = "connection",
    hdrs = ["connection.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//rome/rdma/channel:rdma_channel",
        "//rome/rdma/channel:twosided_messenger",
    ],
)

cc_library(
    name = "connection_manager_impl",
    hdrs = ["connection_manager_impl.h"],
    deps = [],
)

cc_library(
    name = "connection_manager",
    hdrs = ["connection_manager.h"],
    visibility = ["//visibility:public"],
    deps = [
        ":connection",
        ":connection_manager_impl",
        "//protos:rdma_cc_proto",
        "//protos:testutil_cc_proto",
        "//rome/rdma:rdma_broker",
        "//rome/rdma:rdma_device",
        "//rome/rdma:rdma_receiver",
        "//rome/rdma:rdma_util",
        "//rome/rdma/channel:rdma_accessor",
        "//rome/rdma/channel:rdma_channel",
        "//rome/util:coroutine",
        "//rome/util:status_util",
        "@absl//absl/status",
        "@absl//absl/status:statusor",
    ],
)

cc_test(
    name = "connection_manager_test",
    srcs = ["connection_manager_test.cc"],
    deps = [
        ":connection_manager",
        "//rome/testutil:status_matcher",
        "//rome/util:clocks",
        "@gtest//:gtest_main",
    ],
)
