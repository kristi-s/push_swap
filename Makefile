NAME = push_swap
LIBFT = ./libft
HEADER = push_swap.h
SRCS = main.c ft_check_arg.c ft_create_stack_2.c ft_error.c \
        ft_find_mid.c op_few_cmd.c op_rotate.c operations.c \
        utility.c ft_create_stack.c
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
	${RM} ${OBJ}

fclean: clean
	make -C ${LIBFT} fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
