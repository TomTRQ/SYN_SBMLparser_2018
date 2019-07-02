/*
** EPITECH PROJECT, 2019
** File that prints the -i
** File description:
** SBML Parser
*/

#include <stdio.h>
#include <stdlib.h>
#include "sbml.h"
#include "const.h"

static const char *parts_name[5] = {"listOfCompartments", "listOfSpecies", \
"listOfReactions", "listOfReactants", "listOfProducts"};

int print_species(parse_t *parse, char *name)
{
    char *to_print = NULL;
    int stoichiometry = 1;

    printf("List of reactions consuming species %s (quantities)\n", name);
    to_print = get_part_strings("id", parts_name[2], parse);
    if (to_print != NULL) {
        printf("--->%s (%d)\n", to_print, stoichiometry);
    }
    return (SUCCESS);
}

char **fill_tab_strings(parse_t *parse, const char *part)
{
    list_t *temp = parse->list;
    int count = 0;
    char **tab = NULL;
    int i = 0;

    while (temp != NULL && my_strcmp(temp->name, part) != 0)
        temp = temp->next;
    while (temp != NULL && temp->elems != NULL && temp->elems[count] != NULL)
        count += 1;
    tab = malloc(sizeof(char *) * (count + 1));
    while (i < count) {
        tab[i] = my_strcpy(tab[i], get_string_from_elem\
        (temp->elems[i], "species"));
        i += 1;
    }
    tab[i] = NULL;
    if (tab == NULL)
        return (NULL);
    return (tab);
}

int print_reaction(parse_t *parse, char *name)
{
    char **reactants = fill_tab_strings(parse, parts_name[3]);
    char **reactions = fill_tab_strings(parse, parts_name[4]);

    if (reactants == NULL || reactions == NULL)
        return (ERROR);
    reactants = sort_alphabetic_order(reactants);
    reactions = sort_alphabetic_order(reactions);
    printf("List of reactants of reaction %s\n", name);
    for (int i = 0; reactants[i] != NULL; i++)
        printf("--->%s\n", reactants[i]);
    printf("List of products of reaction %s\n", name);
    for (int i = 0; reactions[i] != NULL; i++)
        printf("--->%s\n", reactions[i]);
    free_tab(reactants);
    free_tab(reactions);
    return (SUCCESS);
}

int print_i_without_extra(parse_t *parse, char *name)
{
    if (find_element_list("id", name, parts_name[0], parse) == 1)
        return (print_compartment(parse, name));
    for (int i = 0; i < 5; i++) {
        if (i == 1 && find_element_list("id", name, parts_name[i], parse) == 1)
            return (print_species(parse, name));
        else if (i >= 2 && find_element_list\
        ("id", name, parts_name[i], parse) == 1)
            return (print_reaction(parse, name));
    }
    return (print_other_argument(parse));
}