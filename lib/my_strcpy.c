/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** my_strcpy
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

char *my_strcpy(char *dest, char *src)
{
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (!dest)
        return (NULL);
    for (int i = 0; i < (int)my_strlen(src) + 1; ++i)
        dest[i] = '\0';
    for (int i = 0; src[i]; ++i)
        dest[i] = src[i];
    return (dest);
}