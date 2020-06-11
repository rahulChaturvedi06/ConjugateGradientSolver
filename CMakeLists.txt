cmake_minimum_required(VERSION 3.17.1)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-I ../lib/eigen-3.3.7 -pthread")

project(<OpenPhysics>)

add_executable(a.out 
               src/main.cpp
               src/solver/ConjugateGradientSolver.hpp
               src/solver/ConjugateGradientSolver.cpp
               src/utility/MatrixIO.hpp
               src/utility/MatrixIO.cpp          
              )
              
                           
                          
              





              
