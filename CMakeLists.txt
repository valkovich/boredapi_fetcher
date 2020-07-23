cmake_minimum_required(VERSION 3.16)
project(demonstration)

set(CMAKE_CXX_STANDARD 17)

find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(magic_enum CONFIG REQUIRED)

add_subdirectory(lib)

add_executable(test src/main.cpp)
target_include_directories(test PRIVATE lib/include)
target_link_libraries(test PUBLIC fetcher_library)