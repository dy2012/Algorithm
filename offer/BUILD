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
    name = "jz22",
    srcs = [ "jz22.cpp"],
    deps = [
    ],
    linkopts = LINKOPTS
)
