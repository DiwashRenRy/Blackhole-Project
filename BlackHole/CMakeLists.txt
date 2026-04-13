cmake_minimum_required(VERSION 3.15)
project(BlackHoleSim)

# Use modern C++17
set(CMAKE_CXX_STANDARD 17)

# Tell CMake to find the Raylib library we installed
find_package(raylib REQUIRED)

# Tell CMake our main executable comes from src/main.cpp
add_executable(BlackHoleSim src/main.cpp src/Particle.cpp)
target_include_directories(BlackHoleSim PRIVATE include)

# Link Raylib to our project
target_link_libraries(BlackHoleSim PRIVATE raylib)