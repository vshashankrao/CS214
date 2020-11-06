cmake_minimum_required(VERSION 3.17)
project(Malloc C)

set(CMAKE_C_STANDARD 99)

add_executable(Malloc mymalloc.c memgrind.c mymalloc.h)