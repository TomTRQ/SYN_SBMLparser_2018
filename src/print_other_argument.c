/*
** EPITECH PROJECT, 2019
** file that prints if -i is invalid
** File description:
** SBML Parser
*/

#include <stdlib.h>
#include <stdio.h>
#include "sbml.h"
#include "const.h"

static const char *parts_name[5] = {"listOfCompartments", "listOfSpecies", \
"listOfReactions", "listOfReactants", "listOfProducts"};

int print_compartment(parse_t *parse, char *name)
{
    list_t *temp = parse->list;

    while (temp != NULL && my_strcmp(temp->name, parts_name[1]) != 0)
        temp = temp->next;
    printf("List of species in compartment %s\n", name);
    if (temp != NULL && temp->elems != NULL)
    sort_string_alphabetic_order(temp->elems, name);
    return (SUCCESS);
}

int print_other_argument(parse_t *parse)
{
    list_t *temp = parse->list;

    while (temp != NULL && my_strcmp(temp->name, parts_name[1]) != 0)
        temp = temp->next;
    printf("List of species\n");
    if (temp == NULL || temp->elems == NULL)
        return (SUCCESS);
    sort_string_alphabetic_order(temp->elems, NULL);
    return (SUCCESS);
}