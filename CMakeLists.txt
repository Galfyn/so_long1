cmake_minimum_required(VERSION 3.20)
project(so_long C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-L../libft -lft -L../mlx -lmlx -framework OpenGL -framework AppKit")

file(GLOB SRCS *.c)

add_executable(so_long ${SRCS})
