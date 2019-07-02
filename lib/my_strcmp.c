/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my_strcmp
*/

#include <stdlib.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (84);
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    if (s1[i] == '\0' && s2[i] == '\0')
        return (0);
    if (s1[i] > s2[i])
        return (1);
    if (s1[i] < s2[i])
        return (-1);
    return (2);
}
