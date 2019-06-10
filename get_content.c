/*
** EPITECH PROJECT, 2019
** File that gets the content entered
** File description:
** SBML Parser
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "sbml.h"

int right_file_name(char *str)
{
    int i = 0;
    int column = my_strlen(str) - 5;
    char *buffer = malloc(sizeof(char) * 6);

    if (buffer == NULL || column <= 0)
        return (ERROR);
    for (; column < my_strlen(str); i++) {
        buffer[i] = str[column];
        column = column + 1;
    }
    buffer[i] = '\0';
    if (my_strcmp(buffer, ".sbml") == 0) {
        free(buffer);
        return (SUCCESS);
    }
    free(buffer);
    return (ERROR);
}

char *get_file_content(char *file)
{
    int fd = open(file, O_RDONLY);
    char *buffer = NULL;
    struct stat buff;
    int tab[2] = {0, 0};
    char *buffer2 = malloc(sizeof(char) * 100);

    if (buffer2 == NULL || fd == -1 || right_file_name(file) == ERROR)
        return (NULL);
    stat(file, &buff);
    tab[0] = buff.st_size;
    buffer = malloc(sizeof(char) * (tab[0] + 1));
    read(fd, buffer2, 1);
    for (; buffer2[0] != '\n';)
        read(fd, buffer2, 1);
    tab[1] = read(fd, buffer, tab[0] - 1);
    buffer[tab[1]] = '\0';
    free(buffer2);
    close(fd);
    return (buffer);
}

int get_flags(int argc, char **argv, parse_t *parse)
{
    int count = 0;

    if (argc == 2)
        return (SUCCESS);
    while (argv[count] != NULL) {
        if (my_strcmp(argv[count], "-e") == 0)
            parse->e_option = 1;
        if (my_strcmp(argv[count], "-json") == 0)
            parse->json_option = 1;
        if (my_strcmp(argv[count], "-i") == 0 && argv[count + 1] != NULL)
            parse->i_option = argv[count + 1];
        else if (my_strcmp(argv[count], "-i") == 0 && argv[count + 1] == NULL)
            return (ERROR);
        count += 1;
    }
    return (SUCCESS);
}