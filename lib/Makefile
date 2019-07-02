##
## EPITECH PROJECT, 2018
## PSU_42sh_2018
## File description:
## Makefile for the lib
##

SRC	=	my_strcat.c     \
        my_strcmp.c     \
        prints.c        \
        get_word.c      \
        clean_parts.c   \
        clean_str.c     \
        my_strcpy.c     \
        my_strncpy.c    \
        find_char_number.c  \
        get_string_from_elem.c   \
        find_part_loop.c        \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-c -fno-builtin -W -Wall -Wextra -I../include

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@echo "Compiling $@..."
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all, clean, fclean, re
