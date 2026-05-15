cmake_minimum_required(VERSION 3.10)
project(pso_convergence)

set(CMAKE_CXX_STANDARD 14)

add_executable(pso_convergence
        src/main.cpp
        src/Particle.cpp
        src/Swarm.cpp
        src/Functions.cpp
        src/Particle.h
        src/Functions.h
        src/Swarm.h
)