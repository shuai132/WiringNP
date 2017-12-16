add_subdirectory(../gpio gpio)

aux_source_directory(. DIR_LIB_SRCS)

include_directories(.. ../gpio)

add_definitions("-std=c++11 -Wall")

add_library(PWM ${DIR_LIB_SRCS})

target_link_libraries(PWM GPIO)
