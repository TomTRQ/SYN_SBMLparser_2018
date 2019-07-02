/*
** EPITECH PROJECT, 2019
** File that gets a certain string from struct
** File description:
** SBML Parser
*/

#include <stdlib.h>
#include "sbml.h"
#include "const.h"

char *get_string_from_elem(elements_t *element, char *name)
{
    int i = 0;

    if (name == NULL || element == NULL || element->category == NULL)
        return (NULL);
    while (element->category[i] != NULL) {
        if (my_strcmp(element->category[i], name) == 0)
            return (element->content[i]);
        i = i + 1;
    }
    return (NULL);
}
