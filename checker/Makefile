NAME = checker

HEADER = ../push_swap.h

SRC = main.c gnl.c \
        ../operations.c \
        ../ft_create_stack_2.c \
        ../ft_error.c

OBJ = $(SRC:.c=.o)
COMPILER = gcc
FLAGS = -ferror-limit=2 -Wall -Wextra -Werror -g
all: $(NAME)

$(NAME): $(OBJ)
	make -C ../libft
	mv ../libft/libft.a .
	$(COMPILER) $(FLAGS) -I $(HEADER) -o $(NAME) $(OBJ) libft.a

%.o: %.c $(HEADER)
	$(COMPILER) $(FLAGS) -I $(HEADER) -c $< -o $@

clean:
	make -C ../libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C ../libft clean
	rm -rf $(NAME)
	rm -rf libft.a
#	rm -rf checker.dSYM/

re: fclean all

.PHONY: all clean fclean re