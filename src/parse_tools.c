/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** parse_tools
*/

#include "rpg.h"

char *cfg_file_title_get(void)
{
    char **tmp = OPEN_CONF(GENERAL_INFO);
    char *str = str_cut(tmp[2], '=');
    free_string_array(tmp);
    return (str_dup(str));
}

int config_parse_index(int index)
{
    char **tmp = OPEN_CONF(GENERAL_INFO);
    char *str = str_cut(tmp[index], '=');
    int num = get_nbr(str);
    free_string_array(tmp);
    return (num);
}

void store_info(menu_t *m)
{
    int fd = open(GENERAL_INFO, O_WRONLY);
    int i = 0;

    for (i = 0; m->file[i]; i++) {
        write(fd, m->file[i], str_len(m->file[i]));
        write(fd, "\n", 1);
    }
    close(fd);
}
