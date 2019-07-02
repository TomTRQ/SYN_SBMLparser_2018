/*
** EPITECH PROJECT, 2019
** File that sorts tab alphabetycally and prints it
** File description:
** SBML Parser
*/

#include <stdlib.h>
#include <stdio.h>
#include "sbml.h"
#include "const.h"

void sort_and_print_tab(int count, char **str, char *temp)
{
    for (int i = 0; i <= count; i++)
        for (int j = i + 1; j <= count - 1; j++)
            modify_tab(str, &temp, i, j);
    print_and_free_tab(str, temp, count);
}

void modify_tab(char **str, char **temp, int i, int j)
{
    if (my_strcmp(str[i], str[j]) > 0) {
        *temp = my_strcpy(*temp, str[i]);
        str[i] = my_strcpy(str[i], str[j]);
        str[j] = my_strcpy(str[j], *temp);
    }
}

void print_and_free_tab(char **str, char *temp, int count)
{
    str[count] = NULL;
    for (int i = 0; str[i] != NULL; i++)
        printf("--->%s\n", str[i]);
    free_string(temp);
    free_tab(str);
}