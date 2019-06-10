/*
** EPITECH PROJECT, 2019
** File that prints the content
** File description:
** SBML Parser
*/

#include <stdlib.h>
#include "sbml.h"
#include "const.h"

int print_content(parse_t *parse)
{
    list_t *temp = parse->list;

    for (int i = 0; i < 20; i++)
        printf("\n");
    while (temp != NULL) {
        printf("%s\n", temp->elems[0]->name);
        temp = temp->next;
    }
    return (SUCCESS);
}