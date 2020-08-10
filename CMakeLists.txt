cmake_minimum_required(VERSION 3.17)
project(first_neuro C)

set(CMAKE_C_STANDARD 99)

add_executable(first_neuro main.c header.h neuro.c)