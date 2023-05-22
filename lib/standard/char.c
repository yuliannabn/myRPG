/*
** EPITECH PROJECT, 2023
** pui_print
** File description:
** print a single character
*/

#include "../../include/pui.h"

void print_error(char *str)
{
    write(2, str, (str_len(str)));
}

void put_char(char a)
{
    write(1, &a, 1);
}
