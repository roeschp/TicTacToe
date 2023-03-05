cmake_minimum_required(VERSION 3.24)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

add_executable(TicTacToe main.cpp Console/Console.cpp Console/Console.h MiniMax/MiniMax.cpp MiniMax/MiniMax.h Playground/Playground.cpp Playground/Playground.h Util/Util.cpp Util/Util.h TicTacToe/TicTacToe.cpp TicTacToe/TicTacToe.h)
