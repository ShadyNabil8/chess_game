cmake_minimum_required(VERSION 3.27)
project(chess LANGUAGES CXX)
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")  # Collect all .cpp files in the src directory
add_executable(${PROJECT_NAME} ${SOURCES})  # Add the collected source files to the executable
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
