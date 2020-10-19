#pragma once

#include <activity.h>

#include <vector>

namespace Fetcher {

class Activities {
  std::vector<Activity> m_storage;

 public:
  void AddActivity(const json& temp_activity);
  void AddActivity(const Activity& temp);

  void DeleteActivity(size_t index);

  std::string dump();
};

}  // namespace Fetcher
