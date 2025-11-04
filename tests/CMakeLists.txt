add_executable(test-runner
    test_reader.cpp
    test_parser.cpp
    test_statistics.cpp
    test_reporter.cpp
    test_analyzer.cpp
)

file(COPY ${CMAKE_SOURCE_DIR}/tests/test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(test-runner core_lib GTest::GTest GTest::Main)

add_custom_target(test COMMAND ./test-runner DEPENDS test-runner)