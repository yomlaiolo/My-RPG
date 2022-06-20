##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compile the library
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../.
	cp my.h ../../include

clean:
	rm -f $(OBJ)

fclean:
	rm -f ../$(NAME)
	rm -f $(NAME)

re:	fclean all
