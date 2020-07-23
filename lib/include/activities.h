#pragma once

#include <activity.h>

#include <vector>

namespace Fetcher {
class Activities {
 public:
  void AddActivity(const json& temp_activity);
  void AddActivity(const Activity& temp);

  void DeleteActivity(size_t index);

  std::string dump();

 private:
  std::vector<Activity> storage;
};
}  // namespace Fetcher
