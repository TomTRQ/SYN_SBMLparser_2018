/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** test_clean_str
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sbml.h"
#include "my.h"

Test(clean_str, nothing_to_clean)
{
    char *to_parse = NULL;
    char *cleaned = NULL;

    cr_redirect_stderr();
    to_parse = malloc(sizeof(char) * 6);
    my_strncpy(to_parse, "Hello", 5);
    cleaned = clean_str(to_parse, 1);
    cr_assert_str_eq(cleaned, "Hello\0");
    free(cleaned);
}

Test(clean_str, simple_clean)
{
    char *to_parse = NULL;
    char *cleaned = NULL;

    cr_redirect_stderr();
    to_parse = malloc(sizeof(char) * 15);
    my_strncpy(to_parse, "I am     Batman", 14);
    cleaned = clean_str(to_parse, 1);
    cr_assert_str_eq(cleaned, "I am Batma\0");
    free(cleaned);
}

Test(clean_str, clean_with_tab)
{
    char *to_parse = NULL;
    char *cleaned = NULL;

    cr_redirect_stderr();
    to_parse = malloc(sizeof(char) * 15);
    my_strncpy(to_parse, "I am  \t  Batman", 14);
    cleaned = clean_str(to_parse, 1);
    cr_assert_str_eq(cleaned, "I am Batma\0");
    free(cleaned);
}