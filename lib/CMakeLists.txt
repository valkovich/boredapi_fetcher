cmake_minimum_required(VERSION 3.16)
project(library)

set(CMAKE_CXX_STANDARD 17)

set(FETCHER_INCLUDE_FILES include)

find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(magic_enum CONFIG REQUIRED)

add_library(fetcher_library STATIC src/fetcher.cpp src/activity.cpp src/activities.cpp)
target_include_directories(fetcher_library PUBLIC include)
target_link_libraries(fetcher_library PUBLIC cpr nlohmann_json nlohmann_json::nlohmann_json magic_enum::magic_enum)