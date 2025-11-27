cmake_minimum_required(VERSION 3.10)
project(LogAnalyzer VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_policy(SET CMP0079 NEW) 


find_package(GTest QUIET)
if(NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG v1.14.0
    )
    
    FetchContent_MakeAvailable(googletest)
endif()


add_subdirectory(core)
add_subdirectory(cli)
add_subdirectory(tests)
