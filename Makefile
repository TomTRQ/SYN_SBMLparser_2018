##
## EPITECH PROJECT, 2018
## SBML Parser
## File description:
## Makefile for the all project
##

NAME	=	SBMLparser

SRC_PATH       =       ./src/
TEST_PATH       =       ./tests/

SRC_MAIN    =   $(SRC_PATH)main.c           \

SRC	=   $(SRC_PATH)initiate_structs.c       \
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


SRC_TESTS	=	$(TEST_PATH)test_clean_str.c                    \
                $(TEST_PATH)test_get_word.c                     \
                $(TEST_PATH)test_handle_structs.c               \
                $(TEST_PATH)test_lib.c                          \
                $(TEST_PATH)test_print.c                        \
                $(TEST_PATH)test_sbml.c                         \

OBJ	=	$(SRC:.c=.o)

OBJ_MAIN    =   $(SRC_MAIN:.c=.o)

CFLAGS	=	-fno-builtin -W -Wall -Wextra -I./include

TEST_CFLAGS	=	-fno-builtin -W -Wall -Wextra -I./include --coverage -lgcov

LDFLAGS = -L./lib -lmy

TEST_LDFLAGS    =   -L./lib -lmy -lcriterion

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ_MAIN)
	@make -C lib all
	@gcc $(OBJ_MAIN) $(OBJ) -o $(NAME) $(LDFLAGS)

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
	@rm -f *.gcno
	@rm -f *.o
	@rm -f *.gcda

tests_run:	fclean
	@make -C lib all
	@gcc -c $(SRC) $(TEST_CFLAGS) $(TEST_LDFLAGS)
	@gcc -c $(SRC_TESTS) -I./include
	@gcc -o $(NAME) *.o $(TEST_CFLAGS) $(TEST_LDFLAGS)
	@./$(NAME)

debug: CFLAGS += -g3
debug: re

re:	fclean all

.PHONY:	all, clean, fclean, tests_run, re