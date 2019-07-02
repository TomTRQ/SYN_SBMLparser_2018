/*
** EPITECH PROJECT, 2019
** Get nb of characters in a string
** File description:
** SBML Parser
*/

#include <stdlib.h>

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