NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c print_char_str.c utoa.c
AR = ar -rcs

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	Make -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	make fclean -C ./libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re