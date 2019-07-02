/*
** EPITECH PROJECT, 2019
** File that adds elements to the print list
** File description:
** SBML Parser
*/

#include <stdlib.h>
#include "sbml.h"
#include "const.h"

print_t *check_if_new_elem(parse_t *parse, elements_t *element)
{
    print_t *new = malloc(sizeof(print_t));

    if (new == NULL || element == NULL)
        return (parse->print);
    if (already_existing_name(parse->print, element->name) == 0) {
        if (parse->print == NULL) {
            parse->print = new;
            parse->print->next = NULL;
        } else {
            new->next = parse->print;
            parse->print = new;
        }
        parse->print->name = my_strcpy(parse->print->name, element->name);
        parse->print->content = fill_content_tab(element);
    }
    return (parse->print);
}

print_t *add_model_and_sbml(print_t *print, parse_t *parse)
{
    print_t *model = malloc(sizeof(print_t));
    print_t *sbml = malloc(sizeof(print_t));

    if (model == NULL || sbml == NULL)
        return (NULL);
    model->next = print;
    print = model;
    if (parse->model->elems != NULL && parse->model->elems->name != NULL)
        print->name = my_strcpy(print->name, parse->model->elems->name);
    print->content = fill_content_tab(parse->model->elems);
    sbml->next = print;
    print = sbml;
    if (parse->sbml->elems != NULL && parse->sbml->elems->name != NULL)
        print->name = my_strcpy(print->name, parse->sbml->elems->name);
    print->content = fill_content_tab(parse->sbml->elems);
    if (print->content == NULL || print->next->content == NULL)
        return (NULL);
    return (print);
}