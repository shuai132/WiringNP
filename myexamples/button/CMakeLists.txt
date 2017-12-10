cmake_minimum_required(VERSION 2.6)

PROJECT (BUTTON)

SET(BASE_SRC_LIST   ../base/gpio/gpio.cpp
)
SET(MY_SRC_LIST     ./button.cpp
)
INCLUDE_DIRECTORIES(. ../base ../base/gpio)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
LINK_LIBRARIES(wiringPi pthread)
ADD_EXECUTABLE(button ${BASE_SRC_LIST} ${MY_SRC_LIST})
