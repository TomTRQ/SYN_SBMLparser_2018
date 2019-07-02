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

//START_PROGRAM.C
int start_program(int argc, char **argv);

//PRINT_H.c
int print_h(int argc, char **argv);

//PRINT_JSON.C
int print_json_option(void);

//ORDER_STRING.C
int order_string(char *str);
char *get_full_name(char *elem, char *str, int *i);
int find_part_loop(int *parts, char *str);

//PRINT_I.C
int print_i_without_extra(parse_t *parse, char *name);
int print_reaction(parse_t *parse, char *name);
int print_species(parse_t *parse, char *name);

//ADD_ELEMENTS_PRINT_LIST.C
print_t *check_if_new_elem(parse_t *parse, elements_t *element);
print_t *add_model_and_sbml(print_t *print, parse_t *parse);

//GET_CONTENT.C
char *get_file_content(char *file);
int get_flags(int argc, char **argv, parse_t *parse);
int right_file_name(char *str);

//INITIATE_STRUCTS.C
list_t *add_element_linked_list(parse_t *parse, char *str, char *file, int i);
parse_t *initiate_structs(void);
int free_structs(parse_t *parse, char *file);

//FREE_STRUCTS.C
void free_tab(char **tab);
void free_string(char *str);

//PARSING.C
int parse_file(char *file, parse_t *parse);
int find_char_number(char *str, char c);

//PRINT_CONTENT.C
int print_content(parse_t *parse);
char *get_string_from_elem(elements_t *element, char *name);

//SORT_ALPHABETIC_ORDER
void sort_string_alphabetic_order(elements_t **elements, char *name);
void modify_tab(char **str, char **temp, int i, int j);
char **sort_alphabetic_order(char **content);
char **sort_list_alphabetically(print_t *print);

//PRINT_WITHOUT_OPTIONS.C
int print_without_option(parse_t *parse);
char **fill_content_tab(elements_t *element);
int already_existing_name(print_t *list, char *name);

//PRINT_OTHER_ARGUMENTS.C
int print_compartment(parse_t *parse, char *name);
int print_other_argument(parse_t *parse);

//SORT_AND_PRINT_TAB.C
void sort_and_print_tab(int count, char **str, char *temp);
void modify_tab(char **str, char **temp, int i, int j);
void print_and_free_tab(char **str, char *temp, int count);

//TOOLS.C
int find_content_number(elements_t **elements, char *name, char *param);
int find_element_list(char *cat_to_find, char *name_to_find, \
char const *parts, parse_t *parse);
char *get_part_strings(char *category, char const *parts, parse_t *parse);

#endif