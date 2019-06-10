/*
** EPITECH PROJECT, 2019
** File that parses the content
** File description:
** SBML Parser
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "sbml.h"
#include "const.h"

static const char *parts_name[5] = {"listOfCompartments", "listOfSpecies", \
"listOfReactions", "listOfReactants", "listOfProducts"};

int find_char_number(char *str, char c)
{
    int i = 0;
    int nbr = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0') {
        if (str[i] == c)
            nbr += 1;
        i = i + 1;
    }
    return (nbr);
}

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

void parse_string(char *str, parse_t *parse, elements_t *elems)
{
    int i = 2;
    int params = find_char_number(str, ' ') + 1;
    char *elem = NULL;
    int ptr = 0;

    if (str == NULL)
        return;
    while (i <= params) {
        elem = get_word(str, ' ', i);
        elem = get_full_name(elem, str, &i);
        elems->category[ptr] = get_word(elem, '=', 1);
        elems->content[ptr] = remove_useless_characters_string\
        (get_word(elem, '=', 2));
        printf("CATEGORY:%s\n", elems->category[ptr]);
        printf("CONTENT:%s\n", elems->content[ptr]);
        free(elem);
        i = i + 1;
        ptr += 1;
    }
    printf("\n");
}

int add_elements_struct(char *str, elements_t *elems, parse_t *parse)
{
    int count = find_char_number(str, '=');
    char *cut = NULL;

    if (count == 0)
        return (SUCCESS);
    str = clean_str(str, 0);
    elems = malloc(sizeof(elements_t));
    elems->category = malloc(sizeof(char *) * (count + 1));
    elems->content = malloc(sizeof(char *) * (count + 1));
    cut = get_word(str, ' ', 1);
    if (elems == NULL || cut == NULL || \
    elems->category == NULL || elems->content == NULL)
        return (ERROR);
    elems->name = my_strcpy(elems->name, cut);
    printf("NAME:%s\n", elems->name);
    parse_string(str, parse, elems);
    free(elems);
    return (SUCCESS);
}

int parse_file(char *file, parse_t *parse)
{
    int parts = 0;
    int line = 0;
    char *str = NULL;

    add_elements_struct(get_word(file, '\n', 1), parse->sbml->elems, parse);
    add_elements_struct(get_word(file, '\n', 2), parse->model->elems, parse);
    for (int i = 3; parts <= 5; i++, line++) {
        str = get_word(file, '\n', i);
        str = clean_str(str, 0);
        for (; parts <= 4 && my_strcmp(str, parts_name[parts]) == 0;\
        line = 0, parts += 1)
            parse->list = add_element_linked_list(parse, str, file, i);
        if (str == NULL || str[0] == '\0')
            return (SUCCESS);
        if (add_elements_struct(str, parse->list->elems[line], parse) == ERROR)
            return (ERROR);
        free(str);
    }
    return (SUCCESS);
}