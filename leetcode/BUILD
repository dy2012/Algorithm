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

cc_binary(
    name = "binary_tree_inorder_traversal",
    srcs = [ "binary_tree_inorder_traversal.cpp" ],
    deps = [
    ],
    linkopts = LINKOPTS
)

cc_binary(
    name = "validate_binary_search_tree",
    srcs = [ "validate_binary_search_tree.cpp" ],
    deps = [
    ],
    linkopts = LINKOPTS
)

cc_binary(
    name = "binary_tree_level_order_traversal",
    srcs = [ "binary_tree_level_order_traversal.cpp" ],
    deps = [
    ],
    linkopts = LINKOPTS
)
