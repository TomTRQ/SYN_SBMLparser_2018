/*
** EPITECH PROJECT, 2019
** SBMLParser
** File description:
** sbml.h
*/

#ifndef SBML_H
#define SBML_H

#include "structs.h"
#include "my.h"

//PRINT_H.c
int print_h(int argc, char **argv);

//GET_CONTENT.C
char *get_file_content(char *file);
int get_flags(int argc, char **argv, parse_t *parse);

//INITIATE_STRUCTS.C
list_t *add_element_linked_list(parse_t *parse, char *str, char *file, int i);
parse_t *initiate_structs(void);
int free_structs(parse_t *parse);

//PARSING.C
int parse_file(char *file, parse_t *parse);
int find_char_number(char *str, char c);

//PRINT_CONTENT.C
int print_content(parse_t *parse);

#endif