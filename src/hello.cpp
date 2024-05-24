#include "hello.hpp"

#include <iostream>
#include <fmt/format.h>

#include <userver/server/handlers/http_handler_base.hpp>

//#include <nlohmann/json.hpp>

namespace service_template {

namespace {

class Hello final : public userver::server::handlers::HttpHandlerBase {
public:
  static constexpr std::string_view kName = "handler-hello";

  using HttpHandlerBase::HttpHandlerBase;

  std::string HandleRequestThrow(
      const userver::server::http::HttpRequest &request,
      userver::server::request::RequestContext &) const override {
    return service_template::SayHelloTo(request.GetArg("name"));
  }
};

} // namespace

std::string SayHelloTo(std::string_view name) {
  if (name.empty()) {
    name = "unknown user";
  }

    // nlohmann::json j = {
    //     {"name", "John Doe"},
    //     {"age", 30},
    //     {"email", "john@example.com"},
    //     {"isStudent", false},
    //     {"scores", {85, 92, 77}}
    // };

    // // Получение значений
    // std::cout << "Name: " << j["name"] << std::endl;
    // std::cout << "Age: " << j["age"] << std::endl;
    // std::cout << "Email: " << j.value("email", "N/A") << std::endl;

  //return fmt::format("Hello, {}!\n", name);
  return fmt::format("Hello, {}!\n", name);
}

void AppendHello(userver::components::ComponentList &component_list) {
  component_list.Append<Hello>();
}

} // namespace service_template
