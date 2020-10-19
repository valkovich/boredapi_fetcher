#pragma once

#include <nlohmann/json.hpp>
#include <string>

using nlohmann::json;

namespace Fetcher {

enum class ActivityType : size_t {
  education = 0,
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
  std::string name, type, key;
  float accessibility, price;
  int participants;
};

void from_json(const json &j, Activity &p);
void to_json(json &j, const Activity &p);
std::string to_string(const Activity &temp);

}  // namespace Fetcher
