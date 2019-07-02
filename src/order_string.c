/*
** EPITECH PROJECT, 2019
** File that orders the string
** File description:
** SBML Parser
*/

#include <stdio.h>
#include <stdlib.h>
#include "sbml.h"
#include "const.h"

char *get_full_name(char *elem, char *str, int *i)
{
    int close = 0;
    char *second = 0;

    if (find_char_number(elem, '"') == 1)
        close = 1;
    while (close == 1) {
        *i = *i + 1;
        second = get_word(str, ' ', *i);
        elem = my_strcat(elem, second);
        if (second[0] == '\0' || find_char_number(second, '"') == 1)
            close = 0;
        free(second);
    }
    return (elem);
}

void print_ordered_tab(char **tab)
{
    for (int a = 0; tab[a] != NULL; a++) {
        if (tab[a + 1] == NULL)
            printf("%s", tab[a]);
        else
            printf("%s + ", tab[a]);
    }
    free_tab(tab);
}

int order_string(char *str)
{
    int i = 1;
    int count = 0;
    char **tab = NULL;
    int k = 0;

    if (str == NULL)
        return (SUCCESS);
    for (int j = 0; str[j] != '\0'; j++)
        if (str[j] == ' ')
            count += 1;
    tab = malloc(sizeof(char *) * (count / 2 + 2));
    for (; i <= count; i += 2, k++)
        tab[k] = my_strcat(get_word(str, ' ', i), get_word(str, ' ', i + 1));
    tab[k] = NULL;
    tab = sort_alphabetic_order(tab);
    print_ordered_tab(tab);
    return (SUCCESS);
}