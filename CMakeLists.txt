cmake_minimum_required(VERSION 3.27)
project(SO_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(SO_1 main.c
        somma.h
        somma.c
        prodotto.h
        prodotto.c)