##
## EPITECH PROJECT, 2018
## PSU_42sh_2018
## File description:
## Makefile for the tests
##

LIB             =       ../lib/
SRC_PATH       =       ../src/

SRC	=       $(LIB)clean_str.c   \
            $(LIB)clean_parts.c \
            $(LIB)get_word.c    \
            $(LIB)my_strcat.c   \
            $(LIB)my_strcmp.c   \
            $(LIB)my_strcpy.c   \
            $(LIB)prints.c      \
            $(LIB)my_strncpy.c  \

SRC_TESTS	=   test_clean_str.c  \
                test_lib.c          \
                test_sbml.c         \

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-fno-builtin -W -Wall -Wextra -I./../include --coverage -lgcov

LDFLAGS = -L../lib -lmy -lcriterion

NAME	=	unit_tests

all:	$(NAME)

$(NAME):
	@gcc -c $(SRC) $(CFLAGS) $(LDFLAGS)
	@gcc -c $(SRC_TESTS) -I../include
	@gcc -o $(NAME) *.o $(CFLAGS) $(LDFLAGS)
	@./$(NAME)
	@cp $(NAME) ../

clean:
	@rm -f *.o *.gcno *.gcda

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

re:	fclean all

.PHONY:	all, clean, fclean, re, $(NAME)