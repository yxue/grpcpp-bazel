load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_proto",
    sha256 = "d8992e6eeec276d49f1d4e63cfa05bbed6d4a26cfe6ca63c972827a0d141ea3b",
    strip_prefix = "rules_proto-cfdc2fa31879c0aebe31ce7702b1a9c8a4be02d2",
    urls = [
        "https://github.com/bazelbuild/rules_proto/archive/cfdc2fa31879c0aebe31ce7702b1a9c8a4be02d2.tar.gz",
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

http_archive(
    name = "com_google_googleapis",
    sha256 = "2368a76f8f39582b45d119579f4c8674ddb119cd764f91b87383dac376087694",
    strip_prefix = "googleapis-369e0cd05493fc5fdd7be96c6dc3b141e9dd0c16",
    url = "https://github.com/googleapis/googleapis/archive/369e0cd05493fc5fdd7be96c6dc3b141e9dd0c16.tar.gz",
)

load("@com_google_googleapis//:repository_rules.bzl", "switched_rules_by_language")

switched_rules_by_language(
    name = "com_google_googleapis_imports",
    cc = True,
    grpc = True,
)

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")

grpc_extra_deps()

http_archive(
    name = "com_google_absl",
    strip_prefix = "abseil-cpp-98eb410c93ad059f9bba1bf43f5bb916fc92a5ea",
    urls = ["https://github.com/abseil/abseil-cpp/archive/98eb410c93ad059f9bba1bf43f5bb916fc92a5ea.zip"],
)

http_archive(
    name = "rules_cc",
    strip_prefix = "rules_cc-262ebec3c2296296526740db4aefce68c80de7fa",
    urls = ["https://github.com/bazelbuild/rules_cc/archive/262ebec3c2296296526740db4aefce68c80de7fa.zip"],
)

http_archive(
    name = "com_google_googletest",
    strip_prefix = "googletest-011959aafddcd30611003de96cfd8d7a7685c700",
    urls = ["https://github.com/google/googletest/archive/011959aafddcd30611003de96cfd8d7a7685c700.zip"],
)
