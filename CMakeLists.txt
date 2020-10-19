cmake_minimum_required(VERSION 3.16)
project(demonstration)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/include)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC fetcher_library)