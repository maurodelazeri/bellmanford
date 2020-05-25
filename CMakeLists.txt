cmake_minimum_required(VERSION 3.16)
project(currencytests)

set(CMAKE_CXX_STANDARD 17)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(currencytests main.cpp incl/bellman_ford.h incl/bellman_ford_test.h incl/graph_creator.h incl/graph_printer.h src/graph_creator.cpp src/graph_printer.cpp src/bellman_ford.cpp src/bellman_ford_test.cpp)

TARGET_LINK_LIBRARIES( currencytests LINK_PUBLIC ${Boost_LIBRARIES} )
