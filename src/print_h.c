/*
** EPITECH PROJECT, 2019
** File that prints the -h option
** File description:
** SBML Parser
*/

#include "sbml.h"
#include "const.h"

int print_h(int argc, char **argv)
{
    if (argc == 2 && my_strcmp("-h", argv[1]) == 0) {
        my_putstr("USAGE\n"
        "     ./SBMLparser SBMLfile [-i ID [-e]] [-json]\n\n"
        "DESCRIPTION\n"
        "      SBMLfile   SBML file\n"
        "      -i ID      id of the compartment, "
        "reaction or product to be extracted\n"
        "                 (ignored if uncorrect)\n"
        "      -e         print the equation "
        "if a reaction ID is given as argument\n"
        "                 (ignored otherwise)\n"
        "      -json      transform the file into a JSON file\n");
        return (1);
    }
    return (SUCCESS);
}
