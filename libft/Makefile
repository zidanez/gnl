FLAGS_OBJECTS = -c -Wall -Wextra -Werror
NAME = libft.a

all: $(NAME)

$(NAME):
	gcc $(FLAGS_OBJECTS) ft_*.c -I libft.h
	ar rc libft.a ft_*.o
	ranlib libft.a

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
