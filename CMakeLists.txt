cmake_minimum_required(VERSION 3.16.3)
project(Projekt)

set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
find_package(OpenGL REQUIRED)


add_executable(
    Projekt
    main.cpp
)
target_link_libraries(
    Projekt
    sfml-graphics
    sfml-window
    sfml-audio
    OpenGL
)


