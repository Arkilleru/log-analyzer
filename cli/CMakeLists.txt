add_executable(log-analyzer-cli main.cpp)
target_link_libraries(log-analyzer-cli core_lib)

set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY EP_PREFIX ${CMAKE_BINARY_DIR})