cmake_minimum_required(VERSION 3.23.1)

project(helloWorld VERSION 1.0.0  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the TCL package
find_package(Qt6 COMPONENTS REQUIRED Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

qt_add_executable(helloworld
    main.cpp
)
target_compile_options(${PROJECT_NAME} PRIVATE -c -g -std=c++17 -Wall -W -Werror -pedantic)
target_include_directories(${PROJECT_NAME} PUBLIC . ../)

target_link_libraries(helloworld PRIVATE Qt6::Core)
target_link_libraries(helloworld PRIVATE Qt6::Widgets)
