include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(tests
        recycling_check.cpp
        bin_checks.cpp
        garbage_check.cpp extra_checks.cpp)

target_link_libraries(tests gtest gtest_main)
target_link_libraries(tests waste_recycling)
