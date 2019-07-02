/*
** EPITECH PROJECT, 2019
** File that prints the content without options
** File description:
** SBML Parser
*/

#include <stdlib.h>
#include <stdio.h>
#include "sbml.h"
#include "const.h"

int already_existing_name(print_t *list, char *name)
{
    print_t *temp = list;

    if (name == NULL)
        return (1);
    while (temp != NULL) {
        if (my_strcmp(temp->name, name) == 0)
            return (1);
        temp = temp->next;
    }
    return (0);
}

char **fill_content_tab(elements_t *element)
{
    int count = 0;
    int i = 0;
    char **to_return = NULL;

    if (element == NULL || element->category == NULL)
        return (NULL);
    for (; element->category[count] != NULL; count++);
    to_return = malloc(sizeof(char *) * (count + 1));
    if (to_return == NULL)
        return (NULL);
    while (element->category[i] != NULL) {
        to_return[i] = my_strcpy(to_return[i], element->category[i]);
        i += 1;
    }
    to_return[i] = NULL;
    return (to_return);
}

print_t *found_name_to_print(print_t *temp, print_t *print, \
char **sorted, int *pos)
{
    if (my_strcmp(sorted[*pos], temp->name) == 0) {
        if (temp->name != NULL && temp->name[0] != '\0')
            printf("%s\n", temp->name);
        temp->content = sort_alphabetic_order(temp->content);
        for (int j = 0; temp->content[j] != NULL; j++)
            printf("--->%s\n", temp->content[j]);
        *pos += 1;
        temp = print;
    } else
        temp = temp->next;
    return (temp);
}

int print_sorted_list(print_t *print)
{
    print_t *temp = print;
    char **sorted = sort_list_alphabetically(temp);
    int pos = 0;
    int loop = 0;

    if (sorted == NULL)
        return (ERROR);
    for (; sorted[loop] != NULL; loop++);
    while (sorted[pos] != NULL && pos < loop && temp != NULL)
        temp = found_name_to_print(temp, print, sorted, &pos);
    return (SUCCESS);
}

int print_without_option(parse_t *parse)
{
    list_t *temp = parse->list;
    int i = 0;

    parse->print = NULL;
    while (temp != NULL) {
        while (temp->elems != NULL && temp->elems[i] != NULL) {
            parse->print = check_if_new_elem(parse, temp->elems[i]);
            if (parse->print == NULL)
                return (ERROR);
            i += 1;
        }
        i = 0;
        temp = temp->next;
    }
    parse->print = add_model_and_sbml(parse->print, parse);
    if (parse->print == NULL)
        return (ERROR);
    return (print_sorted_list(parse->print));
}