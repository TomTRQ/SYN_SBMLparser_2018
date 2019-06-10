/*
** EPITECH PROJECT, 2019
** file that creates structs
** File description:
** SBMLParser
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct elements_s
{
    char *name;
    char **category;
    char **content;
} elements_t;

typedef struct sbml_s
{
    elements_t *elems;
} sbml_t;

typedef struct model_s
{
    elements_t *elems;
} model_t;

typedef struct list_s
{
    char *name;
    elements_t **elems;
    struct list_s *next;
} list_t;

typedef struct parse_s
{
    char *i_option;
    int e_option;
    int json_option;
    sbml_t *sbml;
    model_t *model;
    list_t *list;
} parse_t;

#endif