/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** get_nbr
*/

#include "../../include/pui.h"

bool check_dot(char *src)
{
    int a = 0, count = 0;

    if (!src)
        return (ERROR);
    while (src[a] != '\0') {
        if (src[a] == '.')
            count++;
        if (count > 1 || !is_number(src[a]) && src[a] != '.')
            return (false);
        a++;
    }
    return (true);
}

double get_float(int a, char *src, int num)
{
    double dec = (double)num;
    long long mult = 10;

    while (src[a]) {
        dec += (double)(src[a] - 48) / (double)mult;
        mult *= 10;
        a++;
    }
    return (dec);
}

int check_op(char c, int value)
{
    if (c == '+' && value != 0)
        return (0);
    if (c == '-' && value != 0)
        return (0);
    if (c != '+' && c != '-')
        return (0);
    return (1);
}

double get_nbr(char *str)
{
    int value = 0;
    int i = 0;
    int sign = 1;

    while (str[i]) {
        if (str[i] == '-')
            sign = (-1);
        if (!(str[i] >= '0' && str[i] <= '9') && !check_op(str[i], value))
            return (value *sign);
        if (str[i] >= '0' && str[i] <= '9')
            value = value * 10 + (str[i] - '0');
        i++;
    }
    return (value * sign);
}

float my_get_float(char *str)
{
    int i = 0;
    int j = 0;
    float num = 0;
    while (str[i]) {
        if (str[i] < '0' && str[i] > '9' && str[i] != '.')
            return -1;
        if (str[i] == '.') {
            j = 1;
            i++;
        }
        num += str[i] - 48;
        num = num * 10;
        i++;
        j++;
    }
    while (j != 0) {
        num = num / 10;
        j--;
    }
    return num;
}
