cmake_minimum_required(VERSION 3.21)
project(class_animal)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 14)
include_directories(${PROJECT_SOURCE_DIR}/include)
set(SRC_FILES ${PROJECT_SOURCE_DIR}/src/animal.cpp
        src/animal.cpp
        include/animal.h)
add_library(prime_lib ${SRC_FILES})
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

add_executable(class_animal ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(class_animal prime_lib)
