##
## EPITECH PROJECT, 2018
## PSU_42sh_2018
## File description:
## Makefile for the all project
##

NAME	=	SBMLparser

SRC_PATH       =       ./src/

SRC	=   $(SRC_PATH)main.c                   \
        $(SRC_PATH)initiate_structs.c       \
        $(SRC_PATH)print_h.c                \
        $(SRC_PATH)get_content.c            \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-fno-builtin -W -Wall -Wextra -I./include

LDFLAGS = -L./lib -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C lib all
	@gcc $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c
	@echo "Compiling $@..."
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "Removing files ..."
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	cd tests && make fclean
	cd lib && make fclean

tests_run:
	@make -C lib all
	@make -C tests all

debug: CFLAGS += -g3
debug: re

re:	fclean all

.PHONY:	all, clean, fclean, tests_run, re