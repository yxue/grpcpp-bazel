load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_proto",
    sha256 = "602e7161d9195e50246177e7c55b2f39950a9cf7366f74ed5f22fd45750cd208",
    strip_prefix = "rules_proto-97d8af4dc474595af3900dd85cb3a29ad28cc313",
    urls = [
        "https://github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
        ],
    )

http_archive(
    name = "com_github_grpc_grpc",
    sha256 = "6aa269f238d7d9f4cd484c22f7d89c03b8a688c79e985bb35980f6a46a36f3a0",
    strip_prefix = "grpc-4caedbca11261d403c2ef97e54d7d7449bb47871",
    urls = [
        "https://github.com/grpc/grpc/archive/4caedbca11261d403c2ef97e54d7d7449bb47871.tar.gz",
        ],
    )

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_extra_deps()
