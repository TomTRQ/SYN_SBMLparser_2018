/*
** EPITECH PROJECT, 2019
** File that prints the content
** File description:
** SBML Parser
*/

#include <stdio.h>
#include <stdlib.h>
#include "sbml.h"
#include "const.h"

static const char *parts_name[5] = {"listOfCompartments", "listOfSpecies", \
"listOfReactions", "listOfReactants", "listOfProducts"};

int print_e_option(parse_t *parse, char *name)
{
    char *first_part = NULL;
    char *second_part = NULL;

    if (find_element_list("id", name, parts_name[2], parse) == 0)
        return (ERROR);
    first_part = get_part_strings("species", parts_name[3], parse);
    if (order_string(first_part) == ERROR)
        return (ERROR);
    if (find_element_list("reversible", "false", parts_name[2], parse) == 1)
        printf(" -> ");
    else if (find_element_list("reversible", "true", parts_name[2], parse) == 1)
        printf(" <-> ");
    second_part = get_part_strings("species", parts_name[4], parse);
    if (order_string(second_part) == ERROR)
        return (ERROR);
    printf("\n");
    return (SUCCESS);
}

int print_i_option(parse_t *parse, int e_option, char *name)
{
    if (parse->json_option == 1)
        return (print_json_option());
    if (e_option == 0)
        return (print_i_without_extra(parse, name));
    else
        return (print_e_option(parse, name));
}

int print_content(parse_t *parse)
{
    if (parse->e_option == 1 && parse->i_option == NULL)
        return (ERROR);
    else if (parse->i_option != NULL)
        return (print_i_option(parse, parse->e_option, parse->i_option));
    if (parse->i_option == NULL && parse->json_option == 0)
        return (print_without_option(parse));
    return (SUCCESS);
}