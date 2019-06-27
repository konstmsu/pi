cmake_minimum_required(VERSION 3.7)
project(app)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)

add_executable(app main.cpp actions/Blinker.cpp actions/Blinker.h)

find_library(WIRINGPI_LIBRARIES NAMES wiringPi)
target_link_libraries(app ${WIRINGPI_LIBRARIES})