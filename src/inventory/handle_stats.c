/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** handle_stats.c
*/

#include "rpg.h"

void change_line(char *new, char **old)
{
    if (!new || !old)
        return;
    if (*old)
        free(*old);
    *old = new;
}

void handle_hp(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)evt;
    int num = get_nbr(str_cut(menu->file[4], '='));
    int points = get_nbr(str_cut(menu->file[3], '='));

    if (points == 0)
        return;
    num += 3, points -= 1;
    change_line(str_cat(HP, int_to_str(num)), &(menu->file)[4]);
    change_line(str_cat(STAT, int_to_str(points)), &(menu->file)[3]);
    store_info(menu);
    stats_update(menu->character);
    handle_inventory(win, menu, evt);
}

void handle_def(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)evt;
    int num = get_nbr(str_cut(menu->file[5], '='));
    int points = get_nbr(str_cut(menu->file[3], '='));

    if (points == 0)
        return;
    num += 1, points -= 1;
    change_line(str_cat(DEF, int_to_str(num)), &menu->file[5]);
    change_line(str_cat(STAT, int_to_str(points)), &menu->file[3]);
    store_info(menu);
    stats_update(menu->character);
    handle_inventory(win, menu, evt);
}

void handle_str(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)evt;
    int num = get_nbr(str_cut(menu->file[6], '='));
    int points = get_nbr(str_cut(menu->file[3], '='));

    if (points == 0)
        return;
    num += 2, points -= 1;
    change_line(str_cat(STR, int_to_str(num)), &menu->file[6]);
    change_line(str_cat(STAT, int_to_str(points)), &menu->file[3]);
    store_info(menu);
    stats_update(menu->character);
    handle_inventory(win, menu, evt);
}
