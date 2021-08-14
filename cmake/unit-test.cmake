set(TEST_SOURCE_DIR ${PROJECT_HOME_DIR}/test-dir)
set(TEST_SOURCES    ${TEST_SOURCE_DIR}/main.cc
                    ${TEST_SOURCE_DIR}/fls.cc)



#
add_executable(unit_test ${TEST_SOURCES})
target_link_libraries(unit_test fls gtest_main)
target_include_directories(unit_test PRIVATE ${PROJECT_HEADER_DIR})



#
enable_testing()
include(GoogleTest)
gtest_discover_tests(unit_test)
