##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	lib/my/my_getnbr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putnbr.c	\
		lib/my/my_putstr.c	\
		lib/my/my_revnbr.c	\
		lib/my/my_strcpy.c	\
		lib/my/my_strlen.c	\
		lib/my/my_strncpy.c	\

SRC2	=	src/main.c	\
		src/manage_map.c	\
		src/get_input.c	\
		src/ia_input.c	\
		src/error_input.c	\

OBJ	=	$(SRC:.c=.o)

NAME =	libmy.a

NAME2 = matchstick

all:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -o $(NAME2) $(SRC2) -L. libmy.a -g

tests_run:
	gcc -o unit_tests $(SRC3) $(SRCT) -L. libmy.a --coverage
	./unit_tests

clean:
	rm $(OBJ)

fclean:
	rm -f $(NAME)
	rm -f $(NAME2)
	rm $(OBJ)

re:	fclean all
