/*
** EPITECH PROJECT, 2019
** File that frees at the end
** File description:
** SBML Parser
*/

#include <stdlib.h>
#include "sbml.h"
#include "const.h"

void free_tab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void free_string(char *str)
{
    if (str != NULL)
        free(str);
}

void free_linked_list(parse_t *parse)
{
    int i = 0;

    while (parse->list != NULL && parse->list->next != NULL) {
        while (parse->list->elems != NULL && parse->list->elems[i] != NULL) {
            free_tab(parse->list->elems[i]->category);
            free_tab(parse->list->elems[i]->content);
            free_string(parse->list->elems[i]->name);
            free(parse->list->elems[i]);
            i = i + 1;
        }
        i = 0;
        if (parse->list->name != NULL)
            free_string(parse->list->name);
        if (parse->list->elems != NULL)
            free(parse->list->elems);
        parse->list = parse->list->next;
    }
}

void free_print_list(parse_t *parse)
{
    while (parse->print != NULL && parse->print->next != NULL) {
        free_string(parse->print->name);
        free_tab(parse->print->content);
        parse->print = parse->print->next;
    }
    free(parse->print);
}

int free_structs(parse_t *parse, char *file)
{
    free_string(file);
    if (parse->i_option != NULL)
        free_string(parse->i_option);
    free_tab(parse->model->elems->category);
    free_tab(parse->model->elems->content);
    free_string(parse->model->elems->name);
    free(parse->model->elems);
    free(parse->model);
    free_tab(parse->sbml->elems->category);
    free_tab(parse->sbml->elems->content);
    free_string(parse->sbml->elems->name);
    free(parse->sbml->elems);
    free(parse->sbml);
    free_linked_list(parse);
    free(parse);
    return (SUCCESS);
}
