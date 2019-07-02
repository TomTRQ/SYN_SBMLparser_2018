/*
** EPITECH PROJECT, 2019
** test sbml
** File description:
** SBML parser
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sbml.h"
#include "const.h"
#include "my.h"

Test(file_name, right_file_name)
{
    char file[10] = "file.sbml\0";

    cr_assert(right_file_name(file) == SUCCESS);
}

Test(file_name, too_small_name)
{
    char file[4] = "hey\0";

    cr_assert(right_file_name(file) == ERROR);
}

Test(file_name, not_sbml_file)
{
    char file[9] = "file.sbm\0";

    cr_assert(right_file_name(file) == ERROR);
}

Test(get_file, invalid_open)
{
    char file[10] = "hey.sbml\0";

    cr_assert(get_file_content(file) == NULL);
}

Test(get_flags, invalid_flag)
{
    int argc = 3;
    char *argv[4] = {"./SBMLparser", "file.sbml", "hey", NULL};
    parse_t *parse = malloc(sizeof(parse_t));

    cr_assert(get_flags(argc, argv, parse) == ERROR);
}

Test(get_flags, valid_e_flag)
{
    int argc = 5;
    char *argv[6] = {"./SBMLparser", "file.sbml", "-i", \
    "Cytosol", "-e", NULL};
    parse_t *parse = malloc(sizeof(parse_t));

    cr_assert(get_flags(argc, argv, parse) == SUCCESS);
}

Test(get_flags, valid_json_flag)
{
    int argc = 5;
    char *argv[6] = {"./SBMLparser", "file.sbml", "-i", \
    "Cytosol", "-json", NULL};
    parse_t *parse = malloc(sizeof(parse_t));

    cr_assert(get_flags(argc, argv, parse) == SUCCESS);
}

Test(get_flags, incomplete_i_option)
{
    int argc = 3;
    char *argv[4] = {"./SBMLparser", "file.sbml", "-i", NULL};
    parse_t *parse = malloc(sizeof(parse_t));

    cr_assert(get_flags(argc, argv, parse) == SUCCESS);
}

Test(get_flags, no_flag)
{
    int argc = 2;
    char *argv[3] = {"./SBMLparser", "file.sbml", NULL};
    parse_t *parse = malloc(sizeof(parse_t));

    cr_assert(get_flags(argc, argv, parse) == SUCCESS);
}

Test(test_exec, not_enough_arguments)
{
    char *argv[2] = {"./SBMLparser", NULL};
    int argc = 1;

    cr_assert(start_program(argc, argv) == ERROR);
}

Test(test_exec, wrong_argument_first)
{
    char *argv[4] = {"./SBMLparser", "file.sbml", "hey", NULL};
    int argc = 3;

    cr_assert(start_program(argc, argv) == ERROR);
}

Test(test_exec, wrong_file_name)
{
    char *argv[3] = {"./SBMLparser", "hey", NULL};
    int argc = 2;

    cr_assert(start_program(argc, argv) == ERROR);
}

Test(test_exec, e_option_invalid)
{
    char *argv[6] = {"./SBMLparser", "file.sbml", "-i", "hey", "-e", NULL};
    int argc = 5;

    cr_assert(start_program(argc, argv) == ERROR);
}

Test(test_exec, print_h)
{
    char *argv[3] = {"./SBMLparser", "-h", NULL};
    int argc = 2;

    cr_redirect_stdout();
    cr_redirect_stderr();
    cr_assert(start_program(argc, argv) == SUCCESS);
}