cmake_minimum_required(VERSION 3.17)
project(gemini C)

set(CMAKE_C_STANDARD 11)

add_executable(gemini main.c board.c board.h)