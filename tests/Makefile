##
## EPITECH PROJECT, 2018
## PSU_42sh_2018
## File description:
## Makefile for the tests
##

LIB             =       ../lib/
SRC_PATH        =       ../src/

SRC	=       $(LIB_PATH)my_strcat.c     \
            $(LIB_PATH)my_strcmp.c     \
            $(LIB_PATH)prints.c        \
            $(LIB_PATH)get_word.c      \
            $(LIB_PATH)clean_parts.c   \
            $(LIB_PATH)clean_str.c     \
            $(LIB_PATH)my_strcpy.c     \
            $(LIB_PATH)my_strncpy.c    \
            $(LIB_PATH)find_char_number.c  \
            $(LIB_PATH)get_string_from_elem.c   \
            $(SRC_PATH)initiate_structs.c       \
            $(SRC_PATH)print_h.c                \
            $(SRC_PATH)get_content.c            \
            $(SRC_PATH)parsing.c                \
            $(SRC_PATH)print_content.c          \
            $(SRC_PATH)free_structs.c           \
            $(SRC_PATH)sort_alphabetic_order.c  \
            $(SRC_PATH)print_without_options.c  \
            $(SRC_PATH)add_elements_print_list.c    \
            $(SRC_PATH)tools.c                      \
            $(SRC_PATH)print_other_argument.c       \
            $(SRC_PATH)print_json.c                 \
            $(SRC_PATH)print_i.c                    \
            $(SRC_PATH)sort_and_print_tab.c         \
            $(SRC_PATH)order_string.c               \
            $(SRC_PATH)start_program.c              \

SRC_TESTS	=	test_clean_str.c                    \
                test_get_word.c                     \
                test_handle_structs.c               \
                test_lib.c                          \
                test_print.c                        \
                test_sbml.c                         \

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

clean:
	@rm -f *.o *.gcno *.gcda

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

re:	fclean all

.PHONY:	all, clean, fclean, re, $(NAME)