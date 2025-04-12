cmake_minimum_required(VERSION 3.14)
project(project_template CXX)

set(CMAKE_CXX_STANDARD 20)


find_package(OpenSSL REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/main.cpp)

target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto)
