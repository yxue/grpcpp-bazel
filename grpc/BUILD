load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")

proto_library(
    name = "helloworld_proto",
    srcs = ["helloworld.proto"],
    )

cc_proto_library(
    name = "helloworld_cc_proto",
    deps = [":helloworld_proto"],
    )

cc_grpc_library(
    name = "helloworld_cc_grpc",
    srcs = [":helloworld_proto"],
    grpc_only = True,
    deps = [":helloworld_cc_proto"],
    )

cc_binary(
    name = "greeter_client",
    srcs = ["greeter_client.cc"],
    deps = [
        ":helloworld_cc_grpc",
        "@com_github_grpc_grpc//:grpc++",
        ]
    )

cc_binary(
    name = "greeter_server",
    srcs = ["greeter_server.cc"],
    deps = [
        ":helloworld_cc_grpc",
        "@com_github_grpc_grpc//:grpc++",
        ]
    )