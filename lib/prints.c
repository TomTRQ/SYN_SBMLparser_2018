/*
** EPITECH PROJECT, 2019
** prints
** File description:
** all prints functions
*/

#include <unistd.h>

int my_strlen(char *str)
{
    int size = 0;

    for (; str != NULL && str[size] != '\0'; size++);
    return (size);
}

void my_putstr(char *str)
{
    if (str != NULL)
        write(1, str, my_strlen(str));
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    } else
        my_putchar(nb + '0');
}

int my_cmp(char *base, char *compare)
{
    if ((base == NULL && compare != NULL) || (base != NULL && compare == NULL))
        return (1);
    for (int i = 0; base != NULL && base[i] != '\0'; i++)
        if (base[i] != compare[i])
            return (1);
    for (int i = 0; compare != NULL && compare[i] != '\0'; i++)
        if ((base[i] != compare[i]))
            return (1);
    return (0);
}
