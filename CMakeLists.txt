cmake_minimum_required(VERSION 3.15)
project(FiscalFragment-SelicIndex LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

#----------
#   Dependencies
#----------

#   gtest
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/heads/main.zip)
FetchContent_MakeAvailable(googletest)

#   JSON
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)


#   CPR(libcurl)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 1.10.x)
FetchContent_MakeAvailable(cpr)


#   Sol2(lua)
FetchContent_Declare(sol2 GIT_REPOSITORY https://github.com/ThePhD/sol2.git GIT_TAG v3.3.0)
FetchContent_MakeAvailable(sol2)

#--------------------
#   Executable Config
#--------------------
find_package(Lua REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

#   lib links
target_link_libraries(${PROJECT_NAME} PRIVATE
    cpr::cpr
    nlohmann_json::nlohmann_json
    sol2
    ${LUA_LIBRARIES}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${LUA_INCLUDE_DIR})

#   cp lua script to build dir
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/scripts ${CMAKE_BINARY_DIR}/scripts
)

#   unit tests

enable_testing()
add_executable(unit_tests tests/test_main.cpp)

target_link_libraries(unit_tests PRIVATE 
    GTest::gtest
    cpr::cpr
    nlohmann_json::nlohmann_json
)

add_test(NAME Alltests COMMAND unit_tests)