cmake_minimum_required(VERSION 3.5.1)
project(property)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(3rdparty/Catch2)

include_directories(
  include
  3rdparty/Catch2/single_include)

set(LIBRARY_SOURCES
  src/property/raw_data.cpp
  src/property/list.cpp
  src/property/index_out_of_bounds_error.cpp
  src/property/data.cpp)

add_library(${PROJECT_NAME}
  ${LIBRARY_SOURCES})

target_link_libraries(
  ${PROJECT_NAME}
  Catch2)


### Testing
enable_testing()

macro(add_single_test testname)
  add_executable(${testname}
    test/${testname}.cpp)

  target_link_libraries(${testname}
    ${PROJECT_NAME})

  add_test(
    NAME ${testname}
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${testname})
endmacro()

add_single_test(list_test)
