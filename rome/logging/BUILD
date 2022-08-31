load("@bazel_skylib//rules:common_settings.bzl", "string_flag")

levels = [
    "auto",
    "off",
    "critical",
    "error",
    "warn",
    "info",
    "debug",
    "trace",
]

string_flag(
    name = "log_level",
    build_setting_default = "auto",
    values = levels,
)

config_setting(
    name = "auto",
    flag_values = {
        ":log_level": "auto",
    },
)

config_setting(
    name = "trace",
    flag_values = {
        ":log_level": "trace",
    },
)

config_setting(
    name = "debug",
    flag_values = {
        ":log_level": "debug",
    },
)

config_setting(
    name = "info",
    flag_values = {
        ":log_level": "info",
    },
)

config_setting(
    name = "warn",
    flag_values = {
        ":log_level": "warn",
    },
)

config_setting(
    name = "error",
    flag_values = {
        ":log_level": "error",
    },
)

config_setting(
    name = "critical",
    flag_values = {
        ":log_level": "critical",
    },
)

config_setting(
    name = "off",
    flag_values = {
        ":log_level": "off",
    },
)

config_setting(
    name = "dbg",
    flag_values = {
        ":log_level": "auto",
    },
    values = {
        "compilation_mode": "dbg",
    },
)

config_setting(
    name = "fastbuild",
    flag_values = {
        ":log_level": "auto",
    },
    values = {
        "compilation_mode": "fastbuild",
    },
)

config_setting(
    name = "opt",
    flag_values = {
        ":log_level": "auto",
    },
    values = {
        "compilation_mode": "opt",
    },
)

cc_library(
    name = "logging",
    hdrs = ["logging.h"],
    defines = select({
        ":off": ["ROME_LOG_LEVEL=OFF"],
        ":trace": ["ROME_LOG_LEVEL=TRACE"],
        ":debug": ["ROME_LOG_LEVEL=DEBUG"],
        ":info": ["ROME_LOG_LEVEL=INFO"],
        ":warn": ["ROME_LOG_LEVEL=WARN"],
        ":error": ["ROME_LOG_LEVEL=ERROR"],
        ":critical": ["ROME_LOG_LEVEL=CRITICAL"],
        ":dbg": ["ROME_LOG_LEVEL=DEBUG"],
        ":fastbuild": ["ROME_LOG_LEVEL=INFO"],
        ":opt": ["ROME_LOG_LEVEL=INFO"],
        "//conditions:default": ["ROME_LOG_LEVEL=INFO"],
    }),
    visibility = ["//visibility:public"],
    deps = [
        "//rome/testutil:status_matcher",
        "@spdlog",
    ],
)

cc_test(
    name = "logging_test",
    srcs = ["logging_test.cc"],
    deps = [
        ":logging",
        "@gtest//:gtest_main",
    ],
)
