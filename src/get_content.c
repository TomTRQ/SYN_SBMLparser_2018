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
#include "const.h"

int right_file_name(char *str)
{
    int i = 0;
    int column = my_strlen(str) - 5;
    char *buffer = malloc(sizeof(char) * 6);

    if (buffer == NULL || column < 0)
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

    if (fd == -1 || right_file_name(file) == ERROR)
        return (NULL);
    stat(file, &buff);
    tab[0] = buff.st_size;
    buffer = malloc(sizeof(char) * (tab[0] + 1));
    if (buffer == NULL)
        return (NULL);
    tab[1] = read(fd, buffer, tab[0] - 1);
    buffer[tab[1]] = '\0';
    close(fd);
    return (buffer);
}

int invalid_arguments(int argc, char **argv)
{
    int i = 2;

    while (i < argc) {
        if (argv[i][0] == '-' && my_strcmp(argv[i], "-e") != 0 \
        && my_strcmp(argv[i], "-json") != 0 && my_strcmp(argv[i], "-i") != 0)
            return (ERROR);
        if (argv[i][0] != '-' && argv[i - 1][0] != '-')
            return (ERROR);
        i += 1;
    }
    return (SUCCESS);
}

int get_flags(int argc, char **argv, parse_t *parse)
{
    int count = 1;

    if (argc == 2)
        return (SUCCESS);
    while (argv[count] != NULL) {
        if (my_strcmp(argv[count], "-e") == 0)
            parse->e_option = 1;
        if (my_strcmp(argv[count], "-json") == 0)
            parse->json_option = 1;
        if (my_strcmp(argv[count], "-i") == 0 && argv[count + 1] != \
        NULL && argv[count + 1][0] != '-')
            parse->i_option = my_strcpy(parse->i_option, argv[count + 1]);
        else if (my_strcmp(argv[count], "-i") == 0)
            parse->i_option = my_strcpy(parse->i_option, "WRONG");
        count += 1;
    }
    return (invalid_arguments(argc, argv));
}