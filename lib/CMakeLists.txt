cmake_minimum_required(VERSION 3.16)
project(library)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        cmodule
        URL "https://github.com/scapix-com/cmodule/archive/v1.0.18.tar.gz"
        URL_HASH SHA256=26a4f5967eb8b4b33bf54283eb2aa8833a6b17ad50bc4d78163bd9c7af532304
)
FetchContent_MakeAvailable(cmodule)

set(FETCHER_INCLUDE_FILES include)

find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(magic_enum CONFIG REQUIRED)
find_package(Scapix REQUIRED)

add_library(fetcher_library STATIC src/fetcher.cpp src/activity.cpp src/activities.cpp)
target_include_directories(fetcher_library PUBLIC include)
target_link_libraries(fetcher_library PUBLIC cpr nlohmann_json nlohmann_json::nlohmann_json magic_enum::magic_enum scapix)