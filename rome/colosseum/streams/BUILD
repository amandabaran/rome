package(default_visibility = ["//rome:__subpackages__"])

cc_library(
    name = "stream",
    hdrs = ["stream.h"],
    deps = ["@absl//absl/status"],
)

cc_library(
    name = "streams",
    hdrs = ["streams.h"],
    visibility = ["//visibility:public"],
    deps = [
        ":stream",
        "//rome/logging",
        "//rome/util:distribution_util",
    ],
)

cc_test(
    name = "streams_test",
    srcs = ["streams_test.cc"],
    deps = [
        ":streams",
        "//rome/testutil:status_matcher",
        "//rome/testutil:stream_matcher",
        "@absl//absl/status:statusor",
        "@gtest",
        "@gtest//:gtest_main",
    ],
)

cc_library(
    name = "ycsb",
    hdrs = ["ycsb.h"],
    visibility = ["//visibility:public"],
    deps = [
        ":streams",
        "//rome/util:status_util",
    ],
)

cc_test(
    name = "ycsb_test",
    srcs = ["ycsb_test.cc"],
    deps = [
        ":stream",
        ":ycsb",
        "@gtest//:gtest_main",
    ],
)
