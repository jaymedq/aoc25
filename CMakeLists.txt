cmake_minimum_required(VERSION 3.23)

project(aoc25)
add_compile_options(-g -O0)
add_library(common)
target_sources(common
    PRIVATE
    src/common/common.cpp
    PUBLIC
    FILE_SET commonheaders
    TYPE HEADERS
    BASE_DIRS
    include
    FILES
    include/common.hpp
)
add_executable(day2)
target_sources(day2
    PRIVATE
    src/day2/day2.cpp
)
target_include_directories(
    day2
    PRIVATE
    include/
)

add_executable(day3)
target_sources(day3
    PRIVATE
    src/day3/day3.cpp
)
target_include_directories(
    day3
    PRIVATE
    include/
)

add_executable(day4)
target_sources(day4
    PRIVATE
    src/day4/day4.cpp
)
target_include_directories(
    day4
    PRIVATE
    include/
)

add_executable(day5)
target_sources(day5
    PRIVATE
    src/day5/day5.cpp
)
target_include_directories(
    day5
    PRIVATE
    include/
)

add_executable(day6)
target_sources(day6
    PRIVATE
    src/day6/day6.cpp
)
target_include_directories(
    day6
    PRIVATE
    include/
)

add_executable(day7)
target_sources(day7
    PRIVATE
    src/day7/day7.cpp
)
target_include_directories(
    day7
    PRIVATE
    include/
)

