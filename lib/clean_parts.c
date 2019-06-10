/*
** EPITECH PROJECT, 2019
** clean_parts.c
** File description:
** clean parts of string
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

char *remove_first_letter(char *str)
{
    int i = 1;
    int j = 0;
    char *new = malloc(sizeof(char) * my_strlen(str));

    while (str[i] != '\0') {
        new[j] = str[i];
        i = i + 1;
        j = j + 1;
    }
    new[j] = '\0';
    return (new);
}

char *remove_arrows_string(char *str)
{
    if (str == NULL || my_strlen(str) < 2)
        return (NULL);
    if (str[my_strlen(str) - 1] == '>')
        str[my_strlen(str) - 1] = '\0';
    if (str[my_strlen(str) - 1] == '/')
        str[my_strlen(str) - 1] = '\0';
    if (str[0] == '<')
        str = remove_first_letter(str);
    if (str[0] == '/')
        str = remove_first_letter(str);
    return (str);
}

int skip_string(int i, char *str, char *cleaned, int *pos)
{
    char delimiter = str[i];

    i += 1;
    (*pos) += 1;
    while (str[i] && str[i] != delimiter) {
        cleaned[(*pos)] = str[i];
        (*pos) += 1;
        i += 1;
    }
    cleaned[(*pos)] = str[i];
    i += 1;
    (*pos) += 1;
    return (i);
}

char *clean_begin(char *str)
{
    int size = strlen(str);
    int to_remove = 0;
    char *cleaned = NULL;
    int diff = 0;

    for (int i = 0; str[i]; ++i)
        if (str[to_remove] == '\t' || str[to_remove] == ' ')
            ++to_remove;
        else
            break;
    diff = to_remove;
    cleaned = malloc(sizeof(char) * (size - diff + 1));
    if (!cleaned)
        return (NULL);
    for (int i = 0; i < size - diff + 1; ++i)
        cleaned[i] = '\0';
    for (; str[to_remove]; ++to_remove)
        cleaned[to_remove - diff] = str[to_remove];
    free(str);
    return (cleaned);
}

char *clean_end(char *str)
{
    int size = strlen(str);
    int to_remove = 0;
    char *cleaned = NULL;
    int diff = 0;

    for (int i = size - 1; i >= 0; --i)
        if (str[i] == '\t' || str[i] == ' ')
            to_remove++;
        else
            break;
    diff = size - (size - to_remove);
    cleaned = malloc(sizeof(char) * (size - diff + 1));
    if (!cleaned)
        return (NULL);
    for (int i = 0; i < size - diff + 1; ++i)
        cleaned[i] = '\0';
    for (int i = 0; i < (size - to_remove); ++i)
        cleaned[i] = str[i];
    free(str);
    return (cleaned);
}