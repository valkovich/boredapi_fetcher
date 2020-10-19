#include <activity.h>

namespace Fetcher {
void from_json(const json &j, Activity &p) {
  j.at("activity").get_to(p.name);
  j.at("accessibility").get_to(p.accessibility);
  j.at("type").get_to(p.type);
  j.at("price").get_to(p.price);
  j.at("key").get_to(p.key);
}

void to_json(json &j, const Activity &p) {
  j = json{{"activity", p.name}, {"accessibility", p.accessibility},
           {"type", p.type},     {"participants", p.participants},
           {"price", p.price},   {"key", p.key}};
}

std::string to_string(const Activity &temp) {
  json temp_obj;
  to_json(temp_obj, temp);
  return temp_obj.dump();

  /// TODO change to more optimized version
}
}  // namespace Fetcher
