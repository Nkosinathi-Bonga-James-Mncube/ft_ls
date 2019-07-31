NAME = ls.a

SRC = ft_ls.c

OBJ =ft_ls.o

all: $(NAME)

$(NAME):
		gcc -c -Wall -Wextra -Werror $(SRC) $(LIB)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all

