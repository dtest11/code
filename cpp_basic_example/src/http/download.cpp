#include <cpr/cpr.h>

#include <iostream>

void download_example() {
  cpr::Response r = cpr::Get(
      cpr::Url{"https://api.github.com/repos/whoshuu/cpr/contributors"},
      cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
      cpr::Parameters{{"anon", "true"}, {"key", "value"}});
  std::cout << r.status_code << std::endl;  // 200
  // std::cout << r.header << std::endl;
  std::cout << r.text << std::endl;
}