cmake_minimum_required(VERSION 3.16)
project(library)

set(SCAPIX_BRIDGE java)

set(CMAKE_CXX_STANDARD 17)

set(FETCHER_INCLUDE_FILES include/activities.h include/activity.h include/fetcher.h)

find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(magic_enum CONFIG REQUIRED)

add_library(fetcher_library STATIC src/fetcher.cpp src/activity.cpp src/activities.cpp)
target_include_directories(fetcher_library PUBLIC include)
target_link_libraries(fetcher_library PUBLIC cpr nlohmann_json nlohmann_json::nlohmann_json magic_enum::magic_enum)

include(FetchContent)
FetchContent_Declare(
        cmodule
        URL "https://github.com/scapix-com/cmodule/archive/v1.0.19.tar.gz"
        URL_HASH SHA256=755bf9846b0626b4038e01e9ad413e27358f48ce9dbcfdee43917d21e6ee8fd9
)
FetchContent_MakeAvailable(cmodule)

find_package(Scapix REQUIRED)

scapix_bridge_headers(fetcher_library com.example.fetcher ${FETCHER_INCLUDE_FILES})