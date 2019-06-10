/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** clean_str
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my.h"
#include "const.h"
#include "sbml.h"

static void skip_more_spaces(int *i, char *str)
{
    int pos = *i;

    if (str[pos] == '\t')
        str[pos] = ' ';
    for (; str[pos + 1] && (str[pos + 1] == '\t'
        || str[pos + 1] == ' '); ++pos);
    *i = pos;
}

static int get_nb_word(char *str)
{
    int nb_word = 0;

    for (int i = 0; str[i]; ++i) {
        if (str[i] == '\t' || str[i] == ' ') {
            ++nb_word;
            skip_more_spaces(&i, str);
        }
        if (str[i + 1] == '\0') {
            ++nb_word;
            return (nb_word);
        }
    }
    return (nb_word);
}

static int get_nb_char(char *str)
{
    int chara = 0;

    for (int i = 0; str[i]; ++i)
        if (str[i] != '\t' && str[i] != ' ')
            ++chara;
    return (chara);
}

char *clean_double_space(char *str)
{
    int nb_chara = get_nb_char(str) + get_nb_word(str) - 1;
    char *cleaned = malloc(sizeof(char) * (nb_chara + 1));
    int pos = 0;

    if (!cleaned)
        return (NULL);
    for (int i = 0; i < nb_chara + 1; ++i)
        cleaned[i] = '\0';
    for (int i = 0; str[i]; i++, pos++) {
        cleaned[pos] = str[i];
        if (str[i] == ' ' || str[i] == '\t')
            skip_more_spaces(&i, str);
    }
    free(str);
    return (cleaned);
}

char *clean_str(char *str, int free_source)
{
    int size = my_strlen(str);
    char *result = malloc(sizeof(char) * (size + 1));

    if (!result)
        return (NULL);
    result = my_strcpy(result, str);
    result = clean_begin(result);
    if (!result)
        return (NULL);
    result = clean_end(result);
    if (!result)
        return (NULL);
    result = clean_double_space(result);
    if (!result)
        return (NULL);
    if (free_source == 1)
        free(str);
    result = remove_useless_characters_string(result);
    return (result);
}