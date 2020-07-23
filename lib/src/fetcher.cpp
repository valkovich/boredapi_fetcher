#include <fetcher.h>

namespace Fetcher {
void DataFetcher::SetKey(int temp_key) {
  if (temp_key >= 1000000 && temp_key <= 9999999) {
    this->key = temp_key;
    return;
  }

  this->key = std::nullopt;
}

int DataFetcher::GetKey() const { return *this->key; }

void DataFetcher::SetType(ActivityType temp_activity_type) {
  if (temp_activity_type != ActivityType::none) {
    this->type = temp_activity_type;
    return;
  }

  this->type = std::nullopt;
}

ActivityType DataFetcher::GetType() const { return *this->type; }

void DataFetcher::SetParticipants(int temp_participants) {
  if (temp_participants > 0) {
    this->participants = temp_participants;
    return;
  }

  this->participants = std::nullopt;
}

int DataFetcher::GetParticipant() const { return *this->participants; }

void DataFetcher::SetPrice(float temp_price) {
  if (temp_price >= 0.0f && temp_price <= 1.0f) {
    this->price = temp_price;
    return;
  }

  this->price = std::nullopt;
}

float DataFetcher::GetPrice() const { return *this->price; }

void DataFetcher::SetMaxPrice(float temp_max_price) {
  if (temp_max_price <= 1.0f) {
    this->max_price = temp_max_price;
    return;
  }

  this->max_price = std::nullopt;
}

float DataFetcher::GetMaxPrice() const { return *this->max_price; }

void DataFetcher::SetMinPrice(float temp_min_price) {
  if (temp_min_price <= 1.0f) {
    this->min_price = temp_min_price;
    return;
  }

  this->min_price = std::nullopt;
}

float DataFetcher::GetMinPrice() const { return *this->min_price; }

void DataFetcher::SetAccessibility(float temp_accessibility) {
  if (temp_accessibility >= 0.0f && temp_accessibility <= 1.0f) {
    this->accessibility = temp_accessibility;
    return;
  }

  this->accessibility = std::nullopt;
}

float DataFetcher::GetAccessibility() const { return *this->accessibility; }

void DataFetcher::SetMaxAccessibility(float temp_max_accessibility) {
  if (temp_max_accessibility <= 1.0f) {
    this->max_accessibility = temp_max_accessibility;
    return;
  }

  this->max_accessibility = std::nullopt;
}

float DataFetcher::GetMaxAccessibility() const {
  return *this->max_accessibility;
}

void DataFetcher::SetMinAccessibility(float temp_min_accessibility) {
  if (temp_min_accessibility <= 1.0f) {
    this->min_accessibility = temp_min_accessibility;
    return;
  }

  this->min_accessibility = std::nullopt;
}

float DataFetcher::GetMinAccessibility() const {
  return *this->min_accessibility;
}

nlohmann::json DataFetcher::Fetch() {
  cpr::Parameters fetch_params;

  if (this->key) {
    fetch_params.AddParameter({"key", std::to_string(*this->key)});
  }

  if (this->type) {
    fetch_params.AddParameter({"type", magic_enum::enum_name(*this->type)});
  }

  if (this->participants) {
    fetch_params.AddParameter(
        {"participants", std::to_string(*this->participants)});
  }

  if (this->price) {
    fetch_params.AddParameter({"price", std::to_string(*this->price)});
  }

  if (this->min_price) {
    fetch_params.AddParameter({"minprice", std::to_string(*this->min_price)});
  }

  if (this->max_price) {
    fetch_params.AddParameter({"maxprice", std::to_string(*this->max_price)});
  }

  if (this->accessibility) {
    fetch_params.AddParameter(
        {"accessibility", std::to_string(*this->accessibility)});
  }

  if (this->min_accessibility) {
    fetch_params.AddParameter(
        {"minaccessibility", std::to_string(*this->min_accessibility)});
  }

  if (this->max_accessibility) {
    fetch_params.AddParameter(
        {"maxaccessibility", std::to_string(*this->max_accessibility)});
  }

  auto resp =
      cpr::Get(cpr::Url("http://www.boredapi.com/api/activity"), fetch_params);

  auto result = DataFetcher::MakeJson(resp);

  this->CleanSetup();

  return result;
}

std::optional<json> DataFetcher::GetRandomActivity() {
  auto response = DataFetcher::MakeRequest("", "");

  if (response) {
    if (response->status_code == 200) {
      return DataFetcher::MakeJson(*response);
    }
  }

  return std::nullopt;
}

std::optional<json> DataFetcher::GetActivityByKey(int key) {
  auto response = DataFetcher::MakeRequest("key", std::to_string(key));

  if (response) {
    if (response->status_code == 200) {
      return DataFetcher::MakeJson(*response);
    }
  }

  return std::nullopt;
}

std::optional<json> DataFetcher::GetActivityByType(ActivityType req_type) {
  auto response =
      DataFetcher::MakeRequest("type", magic_enum::enum_name(req_type));

  if (response) {
    if (response->status_code == 200) {
      return DataFetcher::MakeJson(*response);
    }
  }

  return std::nullopt;
}

std::optional<json> DataFetcher::GetActivityByParticipants(
    int req_participants) {
  auto response = DataFetcher::MakeRequest("participants",
                                           std::to_string(req_participants));

  if (response) {
    if (response->status_code == 200) {
      return DataFetcher::MakeJson(*response);
    }
  }

  return std::nullopt;
}

std::optional<json> DataFetcher::GetActivityByPrice(float req_price) {
  auto response = DataFetcher::MakeRequest("price", std::to_string(req_price));

  if (response) {
    if (response->status_code == 200) {
      return DataFetcher::MakeJson(*response);
    }
  }

  return std::nullopt;
}

std::optional<json> DataFetcher::GetActivityByPriceRange(float minprice,
                                                         float maxprice) {
  auto response =
      DataFetcher::MakeRequest("minprice", std::to_string(minprice), "maxprice",
                               std::to_string(maxprice));

  if (response) {
    if (response->status_code == 200) {
      return DataFetcher::MakeJson(*response);
    }
  }

  return std::nullopt;
}

std::optional<json> DataFetcher::GetActivityByAccessibility(
    float req_accessibility) {
  auto response = DataFetcher::MakeRequest("req_accessibility",
                                           std::to_string(req_accessibility));

  if (response) {
    if (response->status_code == 200) {
      return DataFetcher::MakeJson(*response);
    }
  }

  return std::nullopt;
}

std::optional<json> DataFetcher::GetActivityByAccessibilityRange(
    float min_accessibility, float max_accessibility) {
  auto response = DataFetcher::MakeRequest(
      "minaccessibility", std::to_string(min_accessibility), "maxaccessibility",
      std::to_string(max_accessibility));

  if (response) {
    if (response->status_code == 200) {
      return DataFetcher::MakeJson(*response);
    }
  }

  return std::nullopt;
}

std::optional<Response> DataFetcher::MakeRequest(std::string_view key_name,
                                                 std::string_view value) {
  Response response;

  if (!key_name.empty()) {
    response = cpr::Get(cpr::Url("http://www.boredapi.com/api/activity"),
                        cpr::Parameters{{key_name, value}});
  } else {
    response = cpr::Get(cpr::Url("http://www.boredapi.com/api/activity"));
  }

  if (response.status_code == 200) {
    return response;
  }

  return std::nullopt;
}

std::optional<Response> DataFetcher::MakeRequest(
    std::string_view first_name, std::string_view first_value,
    std::string_view second_name, std::string_view second_value) {
  auto response = cpr::Get(
      cpr::Url("http://www.boredapi.com/api/activity"),
      cpr::Parameters{{first_name, first_value}, {second_name, second_value}});

  if (response.status_code == 200) {
    return response;
  }

  return std::nullopt;
}

json DataFetcher::MakeJson(cpr::Response response) {
  auto json_response = json::object();
  json_response = json::parse(response.text);
  return json_response;
}

void DataFetcher::CleanSetup() {
  this->json_response = nlohmann::json::object();
  response = cpr::Response();

  type.reset();

  price.reset();
  min_price.reset();
  max_price.reset();

  key.reset();
  participants.reset();
  accessibility.reset();
  min_accessibility.reset();
  max_accessibility.reset();
}
}  // namespace Fetcher
