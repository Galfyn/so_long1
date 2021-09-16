cmake_minimum_required(VERSION 3.20)
project(so_long C)

set(CMAKE_C_STANDARD 99)

file(GLOB SRCS *.c ./Libft/*.c)

add_executable(so_long ${SRCS})
