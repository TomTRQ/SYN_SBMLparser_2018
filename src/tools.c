/*
** EPITECH PROJECT, 2019
** file containing tools for parsing, printing ...
** File description:
** SBML Parser
*/

#include <stdlib.h>
#include "sbml.h"
#include "const.h"

int find_content_number(elements_t **elements, char *name, char *param)
{
    int i = 0;
    int count = 0;

    while (param != NULL && elements != NULL && elements[i] != NULL) {
        if (get_string_from_elem(elements[i], name) != NULL && \
        my_strcmp(get_string_from_elem\
        (elements[i], "compartment"), param) == 0)
            count += 1;
        i = i + 1;
    }
    while (param == NULL && elements != NULL && elements[i] != NULL) {
        if (get_string_from_elem(elements[i], name) != NULL)
            count += 1;
        i = i + 1;
    }
    return (count);
}

char *modif_return_value(list_t *temp, char *category, int *tab, \
char *return_string)
{
    while (temp->elems[tab[0]]->category[tab[1]] != NULL) {
        if (my_strcmp(temp->elems[tab[0]]->category[tab[1]], category) == 0) {
            return_string = my_strcat(return_string, \
            get_string_from_elem(temp->elems[tab[0]], "stoichiometry"));
            return_string = my_strcat\
            (return_string, temp->elems[tab[0]]->content[tab[1]]);
        }
        tab[1] = tab[1] + 1;
    }
    tab[1] = 0;
    tab[0] = tab[0] + 1;
    return (return_string);
}

char *get_part_strings(char *category, char const *parts, parse_t *parse)
{
    list_t *temp = parse->list;
    int tab[2] = {0, 0};
    char *return_string = NULL;

    while (temp->next != NULL && my_strcmp(parts, temp->name) != 0)
        temp = temp->next;
    while (temp->elems[tab[0]] != NULL)
        return_string = modif_return_value(temp, category, tab, return_string);
    return (return_string);
}

int existing_element(list_t *temp, char *cat_to_find, \
char *name_to_find, int *tab)
{
    while (temp->elems[tab[0]]->category[tab[1]] != NULL) {
        if (my_strcmp(temp->elems[tab[0]]->category\
        [tab[1]], cat_to_find) == 0 && my_strcmp\
        (temp->elems[tab[0]]->content[tab[1]], name_to_find) == 0)
            return (1);
        tab[1] = tab[1] + 1;
    }
    tab[1] = 0;
    tab[0] = tab[0] + 1;
    return (0);
}

int find_element_list(char *cat_to_find, \
char *name_to_find, char const *parts, parse_t *parse)
{
    list_t *temp = parse->list;
    int tab[2] = {0, 0};

    while (temp != NULL && temp->next != NULL && \
    my_strcmp(parts, temp->name) != 0)
        temp = temp->next;
    while (temp != NULL && temp->elems != NULL && temp->elems[tab[0]] != NULL)
        if (existing_element(temp, cat_to_find, name_to_find, tab) == 1)
            return (1);
    return (0);
}