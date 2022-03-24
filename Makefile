
cflags = -Wall -Werror -Wextra

rm = rm -rf

NAME = push_swap

src = libft/ft_*.c params.c parse.c init_array.c init_stack.c \
		push_swap_utils.c sort_three.c sort_five.c sort.c main.c operations/*.c

all: $(NAME)

$(NAME) : $(src) push_swap.h
			$(MAKE) -C libft/
			$(CC) $(cflags) $(src) -o $(NAME)
clean:
	$(MAKE) clean -C libft/

fclean: clean
	$(MAKE) fclean -C libft/
	$(rm) $(NAME)

re: fclean all

.PHONY: all clean fclean re