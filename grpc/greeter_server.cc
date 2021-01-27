#include <grpcpp/grpcpp.h>

#include <chrono>
#include <string>
#include <thread>

#include "absl/strings/str_format.h"
#include "absl/time/clock.h"
#include "absl/time/time.h"
#include "grpc/helloworld.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerWriter;
using grpc::Status;
using helloworld::Greeter;
using helloworld::HelloRequest;
using helloworld::HelloResponse;

class GreeterServiceImpl final : public Greeter::Service {
  Status UnaryHello(ServerContext* context, const HelloRequest* request,
                    HelloResponse* reply) override {
    std::string prefix("Hello ");
    reply->set_message(prefix + request->name());
    return Status::OK;
  }

  Status StreamingHello(ServerContext* context, const HelloRequest* request,
                        ServerWriter<HelloResponse>* writer) override {
    while (true) {
      HelloResponse response;
      response.set_message(absl::StrFormat("Hello %s, %s", request->name(),
                                           absl::FormatTime(absl::Now())));
      writer->Write(response);
      absl::SleepFor(absl::Seconds(3));
    }
    return Status::OK;
  }
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  GreeterServiceImpl service;

  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  server->Wait();
}

int main() {
  RunServer();
  return 0;
}
