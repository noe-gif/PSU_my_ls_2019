##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	my_putstr.c \
		my_strlen.c \
		my_getnbr.c \
		my_strncpy.c \
		my_strcmp.c \
		my_putchar.c \
		my_put_nbr.c \
		my_printf.c \
		my_put_unsigned_int.c \
		my_putnbr_base.c \
		my_puthexa.c \
		my_rev_str.c \
		my_strcpy.c \
		my_strcat.c \
		my_strdup.c

OBJ	=	$(SRC:.c=.o)

NAME    =       libmy.a

CC	=	ar rc

RM	=	rm -f

all:    $(NAME)

$(NAME): $(OBJ)
	gcc -c $(SRC)
	$(CC) $(NAME) *.o

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all













