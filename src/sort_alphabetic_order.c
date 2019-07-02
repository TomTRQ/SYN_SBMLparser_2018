/*
** EPITECH PROJECT, 2019
** File that sorts by alphabetic name
** File description:
** SBML Parser
*/

#include <stdlib.h>
#include <stdio.h>
#include "sbml.h"
#include "const.h"

void sort_string_alphabetic_order(elements_t **elements, char *name)
{
    int j = 0;
    char **str = NULL;
    char *temp = NULL;
    int count = find_content_number(elements, "name", name);

    str = malloc(sizeof(char *) * (count + 1));
    if (str == NULL || count == 0)
        return;
    for (int i = 0; name != NULL && elements[i] != NULL; i++)
        if (my_strcmp(get_string_from_elem(elements[i], \
        "compartment"), name) == 0) {
            str[j] = my_strcpy(str[j], get_string_from_elem(elements[i], \
            "name"));
            j += 1;
        }
    for (int i = 0; name == NULL && elements[i] != NULL; i++)
        str[i] = my_strcpy(str[i], get_string_from_elem(elements[i], "name"));
    sort_and_print_tab(count, str, temp);
}

char **sort_alphabetic_order(char **content)
{
    int count = 0;
    char *temp = NULL;

    for (; content[count] != NULL; count++);
    for (int i = 0; i <= count; i++)
        for (int j = i + 1; j <= count - 1; j++)
            modify_tab(content, &temp, i, j);
    return (content);
}

char **sort_list_alphabetically(print_t *print)
{
    char **sorted = NULL;
    print_t *temp = print;
    int count = 0;
    int i = 0;

    for (; temp != NULL; count++)
        temp = temp->next;
    sorted = malloc(sizeof(char *) * (count + 1));
    if (sorted == NULL)
        return (NULL);
    temp = print;
    while (temp != NULL) {
        sorted[i] = my_strcpy(sorted[i], temp->name);
        temp = temp->next;
        i += 1;
    }
    sorted[i] = NULL;
    sorted = sort_alphabetic_order(sorted);
    return (sorted);
}