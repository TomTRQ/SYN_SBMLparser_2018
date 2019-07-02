/*
** EPITECH PROJECT, 2019
** test functions that print
** File description:
** SBML Parser
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sbml.h"
#include "const.h"

Test(test_exec, exec_without_arguments)
{
    char *argv[3] = {"./SBMLparser", "file.sbml", NULL};
    int argc = 2;

    cr_redirect_stdout();
    cr_redirect_stderr();
    cr_assert(start_program(argc, argv) == SUCCESS);
}

Test(test_exec, exec_invalid_i)
{
    char *argv[4] = {"./SBMLparser", "file.sbml", "-i", NULL};
    int argc = 3;

    cr_redirect_stdout();
    cr_redirect_stderr();
    cr_assert(start_program(argc, argv) == SUCCESS);
}

Test(test_exec, exec_species)
{
    char *argv[5] = {"./SBMLparser", "file.sbml", "-i", \
    "Compound414", NULL};
    int argc = 4;

    cr_redirect_stdout();
    cr_redirect_stderr();
    cr_assert(start_program(argc, argv) == SUCCESS);
}

Test(test_exec, exec_reaction)
{
    char *argv[5] = {"./SBMLparser", "file.sbml", "-i", \
    "Reaction1232", NULL};
    int argc = 4;

    cr_redirect_stdout();
    cr_redirect_stderr();
    cr_assert(start_program(argc, argv) == SUCCESS);
}

Test(test_exec, exec_compartment)
{
    char *argv[5] = {"./SBMLparser", "file.sbml", "-i", \
    "Cytosol", NULL};
    int argc = 4;

    cr_redirect_stdout();
    cr_redirect_stderr();
    cr_assert(start_program(argc, argv) == SUCCESS);
}

Test(test_exec, exec_second_invalid_i)
{
    char *argv[5] = {"./SBMLparser", "file.sbml", "-i", \
    "ChuckNorris", NULL};
    int argc = 4;

    cr_redirect_stdout();
    cr_redirect_stderr();
    cr_assert(start_program(argc, argv) == SUCCESS);
}

Test(test_exec, exec_e_option)
{
    char *argv[6] = {"./SBMLparser", "file.sbml", "-i", \
    "Reaction1232", "-e", NULL};
    int argc = 5;

    cr_redirect_stdout();
    cr_redirect_stderr();
    cr_assert(start_program(argc, argv) == SUCCESS);
}

Test(test_exec, exec_json)
{
    char *argv[6] = {"./SBMLparser", "file.sbml", "-i", \
    "Reaction1232", "-json", NULL};
    int argc = 5;

    cr_redirect_stdout();
    cr_redirect_stderr();
    cr_assert(start_program(argc, argv) == SUCCESS);
}