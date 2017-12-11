aux_source_directory(. DIR_LIB_SRCS)

include_directories(..)

add_definitions("-std=c++11 -Wall")

add_library(GPIO ${DIR_LIB_SRCS})
