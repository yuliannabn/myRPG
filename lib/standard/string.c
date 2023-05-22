/*
** EPITECH PROJECT, 2023
** pui_print
** File description:
** display a string
*/

#include "../../include/pui.h"

void put_string(char *string)
{
    write(1, string, str_len(string));
}

char *str_cut(char *str, char c)
{
    char *str1 = malloc(sizeof(char) * str_len(str));
    int i = 0;
    int j = 0;

    while (str[i] != c)
        i++;
    i++;
    while (str[i]) {
        str1[j] = str[i];
        i++;
        j++;
    }
    str1[j] = '\0';
    return str1;
}
