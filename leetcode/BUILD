#load('@rules_cc//cc:defs.bzl', "cc_binary")

config_setting (
    name = "linux",
    values = {"cpu" : "linux"},
    visibility = ["//visibility:public"]
)

LINKOPTS = [
    "-lpthread",
    "-ldl"
]

cc_binary(
    name = "invert_binary_tree",
    srcs = [ "invert_binary_tree.cpp"],
    deps = [
    ],
    linkopts = LINKOPTS
)

cc_binary(
    name = "symmetric_tree",
    srcs = [ "symmetric_tree.cpp"],
    deps = [
    ],
    linkopts = LINKOPTS
)

cc_binary(
    name = "maximum_depth_of_binary_tree",
    srcs = [ "maximum_depth_of_binary_tree.cpp" ],
    deps = [
    ],
    linkopts = LINKOPTS
)

cc_test(
    name = "leetcode_test",
    srcs = [ "leetcode_test.cpp" ],
    deps = ["@com_google_googletest//:gtest_main"],
)
