##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC		=	my_hunter.c \
			utils.c \
			duck.c \
			background.c \
			destroy.c \
			draw.c

OBJ		=	$(SRC:.c=.o)

NAME	=	my_hunter

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME):
	gcc -g -o $(NAME) $(SRC) -I./include $(CSFML)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
