##
## EPITECH PROJECT, 2018
## task01
## File description:
## task01
##

SRC	=	infinadd.c	\

LIB	=	-L./lib/my/ -lmy

NAME	=	infin_add

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(LIB)

clean:
	rm -f $(NAME)

fclean:	clean

re:	fclean all
