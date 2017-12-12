cmake_minimum_required (VERSION 2.8)

add_subdirectory(../base/gpio gpio)

aux_source_directory(. DIR_SRCS)

include_directories(. ../base ../base/gpio)

add_definitions("-std=c++11 -Wall")

link_libraries(wiringPi pthread)

add_executable(blink ${DIR_SRCS})

target_link_libraries(blink GPIO)
