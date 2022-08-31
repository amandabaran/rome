package(default_visibility = ["//rome:__subpackages__"])

cc_library(
    name = "qps_controller",
    hdrs = ["qps_controller.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//rome/testutil:fake_clock",
        "//rome/util:clocks",
        "//rome/util:duration_util",
        "@absl//absl/synchronization",
        "@absl//absl/time",
    ],
)

cc_test(
    name = "qps_controller_test",
    srcs = ["qps_controller_test.cc"],
    deps = [
        ":qps_controller",
        "//rome/util:clocks",
        "//rome/util:duration_util",
        "@absl//absl/time",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "workload_driver",
    hdrs = ["workload_driver.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//protos:colosseum_cc_proto",
        "//rome/metrics:counter",
        "//rome/metrics:stopwatch",
        "//rome/metrics:summary",
    ],
)

cc_test(
    name = "workload_driver_test",
    srcs = ["workload_driver_test.cc"],
    deps = [
        ":client_adaptor",
        ":qps_controller",
        ":workload_driver",
        "//rome/colosseum/streams",
        "//rome/testutil:status_matcher",
        "@absl//absl/status:statusor",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "client_adaptor",
    hdrs = ["client_adaptor.h"],
    visibility = ["//visibility:public"],
    deps = [
        "@absl//absl/status",
    ],
)
