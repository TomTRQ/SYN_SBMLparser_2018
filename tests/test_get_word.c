/*
** EPITECH PROJECT, 2019
** test get_word.c
** File description:
** SBML Parser
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sbml.h"
#include "my.h"

Test(get_word, null_pointer)
{
    char *str = NULL;
    char *result = NULL;

    result = get_word(str, ' ', 1);
    cr_assert_null(result);
}

Test(get_word, first_word)
{
    char *str = "hello world";
    char *result = NULL;

    result = get_word(str, ' ', 1);
    cr_assert_str_eq(result, "hello");
    free(result);
}

Test(get_word, middle_word)
{
    char *str = "hello dreadful world";
    char *result = NULL;

    result = get_word(str, ' ', 2);
    cr_assert_str_eq(result, "dreadful");
    free(result);
}

Test(get_word, non_existing_word)
{
    char *str = "hello world";
    char *result = NULL;

    result = get_word(str, ' ', 4);
    cr_assert_str_eq(result, "");
    free(result);
}