##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC	=	src/flags/flag_d.c \
		src/flags/flag_l.c \
		src/main.c \
		src/l_s.c \
		src/flags/flag_a.c \
		src/flags/flag_r.c \
		src/flags/flag_t.c \
		src/time_sorting/sorting.c \
		src/time_sorting/utils.c \
		src/helper.c \
		src/final_parsing.c

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
