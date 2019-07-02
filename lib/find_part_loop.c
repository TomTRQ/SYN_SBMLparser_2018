/*
** EPITECH PROJECT, 2019
** File that finds if create a new part
** File description:
** SBML Parser
*/

#include "sbml.h"

static const char *parts_name[5] = {"listOfCompartments", "listOfSpecies", \
"listOfReactions", "listOfReactants", "listOfProducts"};

int find_part_loop(int *parts, char *str)
{
    int i = *parts;

    while (i <= 4) {
        if (my_strcmp(str, parts_name[i]) == 0) {
            *parts = i + 1;
            return (1);
        }
        i += 1;
    }
    return (0);
}