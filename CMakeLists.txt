cmake_minimum_required(VERSION 3.16)
project(currencytests)

set(CMAKE_CXX_STANDARD 17)

add_executable(currencytests main.cpp directed_graph.h directed_graph.cc)
