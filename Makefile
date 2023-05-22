##
## EPITECH PROJECT, 2022
## CPool_10
## File description:
## Makefile
##

NAME = my_rpg

T_SRC	= 	main.c						\
			events.c					\
			buttons/buttons.c			\
			buttons/create_button.c		\
			buttons/handle.c			\
			display.c					\
			buttons/handle_2.c			\
			menu.c						\
			buttons/fps.c				\
			character/character_init.c 	\
			character/character_parse.c \
			create_sprite.c				\
			handle_fncs.c				\
			buttons/new_game_handle.c	\
			inventory/handle_inv.c		\
			buttons/handle_volume.c		\
			init_map.c					\
			load_map.c					\
			movement.c					\
			display_fncs.c				\
			resource_init.c 			\
			parse_tools.c 				\
			data_destroys.c 			\
			inventory/handle_stats.c	\
			move_map.c					\

PREFIX = src/

SRC = $(addprefix $(PREFIX), $(T_SRC))

OBJ	=	$(SRC:.c=.o)

CFLAGS = -g3 -W -Wall -Wextra -Werror -I include/ -L lib/ -lmy

CSFML =  -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm

all: 	$(NAME)

$(NAME): dolib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CSFML)

dolib:
	cd lib; make

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *.gcda
	rm -f *.gcno
	cd lib; make clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(T_NAME)
	cd lib; make fclean

re:	fclean all
	make clean
