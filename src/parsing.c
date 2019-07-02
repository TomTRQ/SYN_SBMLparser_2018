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

void loop_add_parse_string(char *str, elements_t *elems, \
char *argument, int *ptr)
{
    int params = find_char_number(str, ' ') + 1;
    int i = 2;

    while (i <= params) {
        argument = get_word(str, ' ', i);
        argument = get_full_name(argument, str, &i);
        elems->category[*ptr] = get_word(argument, '=', 1);
        elems->content[*ptr] = remove_useless_characters_string\
        (get_word(argument, '=', 2));
        i = i + 1;
        *ptr += 1;
        free(argument);
    }
}

int parse_string(char *str, elements_t *elems)
{
    char *argument = NULL;
    int ptr = 0;

    if (str != NULL && str[0] == '\0')
        return (SUCCESS);
    if (str == NULL)
        return (ERROR);
    loop_add_parse_string(str, elems, argument, &ptr);
    elems->category[ptr] = NULL;
    elems->content[ptr] = NULL;
    return (SUCCESS);
}

elements_t *add_elements_struct(char *str, elements_t *elems)
{
    int count = find_char_number(str, '=');
    char *cut = NULL;

    str = clean_str(str, 1);
    if (str != NULL && str[0] == '/')
        str[0] = '\0';
    elems = malloc(sizeof(elements_t));
    if (elems == NULL)
        return (NULL);
    elems->category = malloc(sizeof(char *) * (count + 1));
    elems->content = malloc(sizeof(char *) * (count + 1));
    cut = get_word(str, ' ', 1);
    if (cut == NULL || elems->category == NULL || elems->content == NULL)
        return (NULL);
    elems->name = my_strcpy(elems->name, cut);
    parse_string(str, elems);
    free(str);
    return (elems);
}

void add_sbml_model_parse_struct(parse_t *parse, char *file)
{
    parse->sbml->elems = add_elements_struct\
    (get_word(file, '\n', 2), parse->sbml->elems);
    parse->model->elems = add_elements_struct(get_word\
    (file, '\n', 3), parse->model->elems);
}

int parse_file(char *file, parse_t *parse)
{
    char *str = NULL;

    add_sbml_model_parse_struct(parse, file);
    for (int i = 4, parts = 0, line = 0; parts <= 5; i++) {
        str = get_word(file, '\n', i);
        str = clean_str(str, 1);
        if (str == NULL || str[0] == '\0')
            return (SUCCESS);
        for (; parts <= 4 && find_part_loop(&parts, str) \
        == 1; line = 0)
            parse->list = add_element_linked_list(parse, str, file, i);
        if (find_char_number(str, '=') > 0 && parse->list != NULL && \
        parse->list->elems != NULL) {
            parse->list->elems[line] = add_elements_struct\
            (str, parse->list->elems[line]);
            line += 1;
        }
    }
    return (SUCCESS);
}