#include <grpcpp/grpcpp.h>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "grpc/helloworld.grpc.pb.h"

ABSL_FLAG(bool, streaming, true, "Use streaming receive.");

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::Greeter;
using helloworld::HelloRequest;
using helloworld::HelloResponse;

class GreeterClient {
 public:
  GreeterClient(std::shared_ptr<Channel> channel)
      : stub_(Greeter::NewStub(channel)) {}

  void UnaryHello(const std::string& user) {
    HelloRequest request;
    request.set_name(user);
    HelloResponse reply;
    ClientContext context;
    Status status = stub_->UnaryHello(&context, request, &reply);
    if (status.ok()) {
      std::cout << reply.message() << "\n";
    } else {
      std::cout << "RPC failed\n" << status.error_message();
    }
  }

  void StreamingHello(const std::string& user) {
    HelloRequest request;
    request.set_name(user);
    ClientContext context;
    auto reader = stub_->StreamingHello(&context, request);
    HelloResponse reply;
    while (reader->Read(&reply)) {
      std::cout << reply.message() << "\n";
    }
  }

 private:
  std::unique_ptr<Greeter::Stub> stub_;
};

int main() {
  GreeterClient greeter(grpc::CreateChannel(
      "localhost:50051", grpc::InsecureChannelCredentials()));
  std::string user("world");
  if (absl::GetFlag(FLAGS_streaming)) {
    std::cout << "Streaming ...\n";
    greeter.StreamingHello(user);
  } else {
    greeter.UnaryHello(user);
  }
  return 0;
}
