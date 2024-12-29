cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME ProjectName)
string(REPLACE " " "_" ProjectId ${ProjectName})
project(${ProjectName})

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest GTest::gtest_main)

enable_testing()

gtest_discover_tests(${PROJECT_NAME})
