/*
** EPITECH PROJECT, 2019
** Main file for the project
** File description:
** SBML Parser
*/

#include <stdlib.h>
#include "sbml.h"
#include "const.h"

int main(int argc, char **argv)
{
    if (argc == 1 || argc > 6)
        return (ERROR);
    return (start_program(argc, argv));
}