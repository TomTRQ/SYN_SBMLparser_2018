/*
** EPITECH PROJECT, 2019
** ON SYNTHESE PAS NOUS
** File description:
** Requirement.c
*/

#include <stdio.h>
#include <stdlib.h>

static int find_cut_char(char c)
{
    if (c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122)
        return (1);
    else
        return (0);
}

static int spliter_count(char const *tab)
{
    int i = 0;
    int words = 0;

    while (tab[i] != '\0') {
        words += (find_cut_char(tab[i]) == 0 && tab[i] != '\0');
        for (; tab[i] != '\0' && find_cut_char(tab[i]) == 0; i++);
        i++;
    }
    return (words);
}

char **my_str_to_word_array_synthesis(char const *str)
{
    char **args = NULL;
    int size = spliter_count(str);
    int i = 0;
    int k = 0;

    args = malloc(sizeof(char *) * (size + 1));
    for (int j = 0; j < size; j++) {
        for (k = 0 ; find_cut_char(str[i + k]) == 0 && \
        str[i + k] != '\0' ; k++);
        args[j] = malloc(sizeof(char) * (k + 1));
        for (int l = 0; l < k; l++, i++)
            args[j][l] = str[i];
        args[j][k] = '\0';
        i++;
    }
    args[size] = NULL;
    return (args);
}