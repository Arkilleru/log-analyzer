add_executable(test-runner
    test_reader.cpp
    test_parser.cpp
    test_statistics.cpp
    test_reporter.cpp
    test_analyzer.cpp
    tests.h
)

target_link_libraries(test-runner
    core_lib
    GTest::gtest
    GTest::gtest_main
)

add_custom_target(run-tests
    COMMAND test-runner
    DEPENDS test-runner
)
