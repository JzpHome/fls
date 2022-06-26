set(FLS_TEST_SOURCES    test-dir/main.cc
                        test-dir/fls.cc)



#
add_executable(fls_test ${FLS_TEST_SOURCES})
target_link_libraries(fls_test fls gtest_main)
target_include_directories(fls_test PRIVATE include)
set_target_properties(fls_test
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")



#
enable_testing()
include(GoogleTest)
gtest_discover_tests(fls_test)
