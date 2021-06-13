cmake_minimum_required(VERSION 3.19)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(libft)

file(GLOB
        LIBFT "libft/*.c")

add_executable(push_swap
        ${LIBFT}
        ft_check_arg.c
        ft_create_stack.c
        ft_error.c
        utility.c
        operations.c
        for_debug.c
        ft_find_mid.c
        ft_sort_stack.c
        main.c
        push_swap.h)
