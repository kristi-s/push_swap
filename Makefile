# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: droslyn <droslyn@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 14:48:13 by droslyn           #+#    #+#              #
#    Updated: 2021/07/02 20:07:51 by droslyn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = ./libft
HEADER = push_swap.h
SRCS = main.c ft_check_arg.c ft_main_body.c ft_error.c \
        ft_find_mid.c op_few_cmd.c op_rotate.c operations.c \
        utility.c ft_create_stack.c ft_analise_op.c \
		utility_cmd.c
OBJ = ${SRCS:.c=.o}
INC = ${SRCS:.c=.d}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -MD

.c.o:
		${CC} ${CFLAGS} -I ${HEADER} -c $< -o $@

${NAME}: ${OBJ}
	make -C ${LIBFT}
	${CC} ${OBJ} ${CFLAGS} -I ${HEADER} ./libft/libft.a -o ${NAME}
include ${wildcard ${INC}}

all: ${NAME}

clean:
	make -C ${LIBFT} clean
	${RM} ${OBJ} ${INC}

fclean: clean
	make -C ${LIBFT} fclean
	${RM} ${NAME}

re: fclean all

bonus:
	make -C ./src_checker
	cp ./src_checker/checker .

bclean: clean
	make -C ./src_checker clean
	${RM} checker

.PHONY: all clean fclean re bonus
