/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** Task02
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *temp = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 2);

    if (dest == NULL || dest[0] == '\0')
        return (src);
    else if (src == NULL || src[0] == '\0')
        return (dest);
    for (i = 0; dest[i] != '\0'; i++)
        temp[i] = dest[i];
    temp[i] = ' ';
    i = i + 1;
    for (j = 0; src[j] != '\0'; j++)
        temp[i + j] = src[j];
    temp[i + j] = '\0';
    return (temp);
}
