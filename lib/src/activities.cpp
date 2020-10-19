#include <activities.h>

namespace Fetcher {

void Activities::AddActivity(const json& temp_activity) {
  Activity temp;
  from_json(temp_activity, temp);
  this->AddActivity(temp);
}

void Activities::AddActivity(const Activity& temp) {
  /// TODO Add data validation

  m_storage.push_back(temp);
}

void Activities::DeleteActivity(size_t index) {
  if (index >= 0 && index <= this->m_storage.size()) {
    this->m_storage.erase(this->m_storage.begin() + index);
  }
}

std::string Activities::dump() {
  std::string answer;

  for (auto& element : this->m_storage) {
    answer += to_string(element) + '\n';
  }

  return answer;
}

/// TODO Add overloaded version of DeleteActivity with search
}  // namespace Fetcher
