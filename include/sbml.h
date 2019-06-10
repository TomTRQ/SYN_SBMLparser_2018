/*
** EPITECH PROJECT, 2019
** SBMLParser
** File description:
** sbml.h
*/

#ifndef SBML_H
#define SBML_H

#include "structs.h"
#include "const.h"
#include "my.h"

//PRINT_H.c
int print_h(int argc, char **argv);

//GET_CONTENT.C
char *get_file_content(char *file);
int get_flags(int argc, char **argv, parse_t *parse);

parse_t *initiate_structs(void);
int free_structs(parse_t *parse);

#endif