cmake_minimum_required(VERSION 4.1)
project(console-manager)

include_directories(${CMAKE_SOURCE_DIR}/lib/PDCurses)

add_executable(console-manager src/main.cpp)

target_link_libraries(console-manager
    ${CMAKE_SOURCE_DIR}/lib/PDCurses/wincon/pdcurses.lib
)
