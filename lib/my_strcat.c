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

    if (dest == NULL)
        return (src);
    else if (src == NULL)
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
