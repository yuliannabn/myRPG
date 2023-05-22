/*
** EPITECH PROJECT, 2023
** antman
** File description:
** files
*/

#ifndef FILES_H_
    #define FILES_H_

    #include <sys/stat.h>
    #include <fcntl.h>
    #include "pui.h"

    char        *open_file      (char *path);
    int        error_message    (void);

#endif
