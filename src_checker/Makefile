# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 14:47:37 by droslyn           #+#    #+#              #
#    Updated: 2021/07/02 14:47:40 by droslyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
LIBFT = ../libft
HEADER = ../push_swap.h

SRCS = main.c gnl.c ft_do_cmd.c ft_do_cmd_a.c ft_do_cmd_b.c ft_return.c\
        ../operations.c \
        ../ft_create_stack.c \
        ../ft_error.c \
		../ft_find_mid.c \
		../op_rotate.c \
		../ft_check_arg.c \
		../utility.c \
		../op_few_cmd.c


OBJ = ${SRCS:.c=.o}
INC = ${SRCS:.c=.d}
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -MD

.c.o:
		${CC} ${CFLAGS} -I ${HEADER} -c $< -o $@



${NAME}: ${OBJ}
	make -C ${LIBFT}
	${CC} ${OBJ} ${CFLAGS} -I ${HEADER} ../libft/libft.a -o ${NAME}
include ${wildcard ${INC}}

all: ${NAME}

clean:
	make -C ${LIBFT} clean
	${RM} ${OBJ}

fclean: clean
	make -C ${LIBFT} fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
