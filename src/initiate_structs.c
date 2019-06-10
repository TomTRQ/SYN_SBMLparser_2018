/*
** EPITECH PROJECT, 2019
** file that initiates structs
** File description:
** SBML Parser
*/

#include <stdio.h>
#include <stdlib.h>
#include "sbml.h"
#include "const.h"

int find_size_tab(char *str, char *file, int line)
{
    char *new_line = NULL;
    int count = 0;

    line += 1;
    new_line = get_word(file, '\n', line);
    while (find_char_number(new_line, '=') > 0) {
        line += 1;
        count += 1;
        new_line = get_word(file, '\n', line);
    }
    new_line = get_word(file, '\n', line + 1);
    return (count);
}

list_t *add_element_linked_list(parse_t *parse, char *str, char *file, int line)
{
    list_t *new = malloc(sizeof(list_t));
    list_t *temp = parse->list;
    int size = find_size_tab(str, file, line);

    if (new == NULL)
        return (NULL);
    if (parse->list == NULL) {
        parse->list = new;
        parse->list->next = NULL;
    } else {
        new->next = parse->list;
        parse->list = new;
    }
    new->name = my_strcpy(new->name, str);
    new->elems = malloc(sizeof(elements_t) * (size + 1));
    new->elems[size] = NULL;
    printf("NAME LIST:%s\n------------------\n", new->name);
    return (parse->list);
}

parse_t *initiate_structs(void)
{
    parse_t *parse = malloc(sizeof(parse_t));

    if (parse == NULL)
        return (NULL);
    parse->sbml = malloc(sizeof(sbml_t));
    parse->model = malloc(sizeof(model_t));
    parse->list = NULL;
    if (parse->sbml == NULL || parse->model == NULL)
        return (NULL);
    parse->sbml->elems = malloc(sizeof(elements_t) * 2);
    parse->model->elems = malloc(sizeof(elements_t) * 2);
    if (parse->sbml->elems == NULL || parse->model->elems == NULL)
        return (NULL);
    parse->i_option = NULL;
    parse->e_option = 0;
    parse->json_option = 0;
    return (parse);
}

int free_structs(parse_t *parse)
{
    free(parse);
    return (SUCCESS);
}