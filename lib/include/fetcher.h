#pragma once

#include <activity.h>
#include <cpr/cpr.h>

#include <iostream>
#include <magic_enum.hpp>
#include <nlohmann/json.hpp>
#include <optional>
#include <string_view>

using nlohmann::json;
using Response = cpr::Response;

namespace Fetcher {

class DataFetcher {
  static std::optional<Response> MakeRequest(std::string_view key_name,
                                             std::string_view value);
  static std::optional<Response> MakeRequest(std::string_view first_name,
                                             std::string_view first_value,
                                             std::string_view second_name,
                                             std::string_view second_value);

  static json MakeJson(cpr::Response response);

  void CleanSetup();

  nlohmann::json json_response;
  cpr::Response response;

  std::optional<ActivityType> type;

  std::optional<float> price, min_price, max_price;

  std::optional<int> key, participants, accessibility, min_accessibility,
      max_accessibility;

 public:
  void SetKey(int temp_key);
  [[nodiscard]] int GetKey() const;

  void SetType(ActivityType temp_activity_type);
  [[nodiscard]] ActivityType GetType() const;

  void SetParticipants(int temp_participants);
  [[nodiscard]] int GetParticipant() const;

  void SetPrice(float temp_price);
  [[nodiscard]] float GetPrice() const;

  void SetMaxPrice(float temp_max_price);
  [[nodiscard]] float GetMaxPrice() const;

  void SetMinPrice(float temp_min_price);
  [[nodiscard]] float GetMinPrice() const;

  void SetAccessibility(float temp_accessibility);
  [[nodiscard]] float GetAccessibility() const;

  void SetMaxAccessibility(float temp_max_accessibility);
  [[nodiscard]] float GetMaxAccessibility() const;

  void SetMinAccessibility(float temp_min_accessibility);
  [[nodiscard]] float GetMinAccessibility() const;

  nlohmann::json Fetch();

  static std::optional<json> GetRandomActivity();
  static std::optional<json> GetActivityByKey(int key);
  static std::optional<json> GetActivityByType(ActivityType req_type);
  static std::optional<json> GetActivityByParticipants(int req_participants);
  static std::optional<json> GetActivityByPrice(float req_price);
  static std::optional<json> GetActivityByPriceRange(float min_price,
                                                     float max_price);
  static std::optional<json> GetActivityByAccessibility(
      float req_accessibility);
  static std::optional<json> GetActivityByAccessibilityRange(
      float min_accessibility, float max_accessibility);
};

}  // namespace Fetcher
