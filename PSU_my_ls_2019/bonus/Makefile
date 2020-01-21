##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	src/flag_l.c \
		src/main.c \
		src/flag_a.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) -L./lib/my -lmy

clean:
	make -C lib/my clean
	$(RM) $(OBJ)

fclean:	clean
	make -C lib/my fclean
	$(RM) $(NAME)

re:	fclean all
