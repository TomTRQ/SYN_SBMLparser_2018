/*
** EPITECH PROJECT, 2019
** Function that is called by main
** File description:
** SBML Parser
*/

#include <stdlib.h>
#include "sbml.h"
#include "const.h"

int start_program(int argc, char **argv)
{
    parse_t *parse = initiate_structs();
    char *file = NULL;

    if (parse == NULL)
        return (ERROR);
    if (print_h(argc, argv) == 1)
        return (SUCCESS);
    file = get_file_content(argv[1]);
    if (file == NULL || file[0] == '\0' || \
    get_flags(argc, argv, parse) == ERROR)
        return (ERROR);
    if (parse_file(file, parse) == ERROR)
        return (ERROR);
    if (print_content(parse) == ERROR)
        return (ERROR);
    return (free_structs(parse, file));
}