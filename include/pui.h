/*
** EPITECH PROJECT, 2023
** pui_print
** File description:
** pui
*/

#ifndef PUI_H_
    #define PUI_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <stdbool.h>

    #define     FAILURE         84
    #define     ERROR          -1
    #define     SUCCESS         0
    #define     ERROR_OUT       2
    #define     STD_OUT         1

    void        put_char            (char a);
    void        print_error         (char *str);
    void        put_nbr             (int number);
    void        put_float           (float number, int decimals);
    void        put_string          (char *string);
    void        free_string_array   (char **array);
    void        copy_word           (int *a, int word_size, char *res,
    char *arg);
    int         str_len             (char const *string);
    int         arr_len             (char **array);
    float       my_get_float        (char *str);
    double      get_nbr             (char *src);
    double      get_float           (int a, char *src, int num);
    bool        str_equal           (char *str, char *other);
    bool        is_number           (char a);
    bool        is_letter           (char a);
    bool        is_alphanumeric     (char *str);
    char       *int_to_str          (int num);
    char       *str_cut             (char *str, char c);
    char       *str_dup             (char const *src);
    char       *str_cat             (char *dest, char const *src);
    char      **delete_in_str_array (char **arr, char **str_ptr);
    char      **cpy_str_array       (char **arr);
    char      **str_to_word_double  (char *arguments, char *seps);
    char      **str_to_word         (char *str, char sep);
    char       *str_cat_char        (char *dest, char c);

#endif
