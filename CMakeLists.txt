cmake_minimum_required(VERSION 2.8)
project(project4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -o2")

add_executable(project4 main.cpp WeightedGraph.cpp WeightedGraph.h)