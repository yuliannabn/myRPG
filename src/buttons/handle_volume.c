/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** handel_volume
*/

#include "rpg.h"

void handle_m_mute(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)evt;
    sfMusic_setVolume(menu->music, 0);
    menu->file[1] = str_cat("Music=", "0");
}

void handle_m_music(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)evt;
    sfMusic_setVolume(menu->music, 50);
    menu->file[1] = str_cat("Music=", "50");
}
