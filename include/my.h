/*
** EPITECH PROJECT, 2019
** SBMLParser
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

char *my_strcat(char *dest, char *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcpy(char *dest, char *src);
char *get_word(char *str, char c, int nb);
int my_strcmp(char *s1, char const *s2);
void my_putstr(char *str);
int my_strlen(char *str);
void my_putnbr(int nb);
char *clean_str(char *str, int free_source);
char *clean_begin(char *str);
char *clean_end(char *str);
char *remove_useless_characters_string(char *str);
int my_strlen(char *str);

#endif