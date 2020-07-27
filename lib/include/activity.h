#pragma once

#include <nlohmann/json.hpp>

#include <string>

using nlohmann::json;

namespace Fetcher {
enum class ActivityType {
  education,
  recreational,
  social,
  diy,
  charity,
  cooking,
  relaxation,
  music,
  busywork,
  none
};

struct Activity {
 public:
  std::string name;
  float accesibility;
  std::string type;
  int participants;
  float price;
  std::string key;
};

void from_json(const json &j, Activity &p);
void to_json(json &j, const Activity &p);
std::string to_string(const Activity &temp);
}  // namespace Fetcher
