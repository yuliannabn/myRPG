/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** handle_2.c
*/

#include "rpg.h"

void handle_load(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)evt;
    button_array_destroy(menu->buttons);

    menu->buttons =
        init_button_array(OPEN_CONF("src/txt_buttons/new_game.conf"));
    sfText_setString(menu->buttons[0]->text, str_cut(menu->file[2], '='));
}

void handle_settings(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)evt;
    button_array_destroy(menu->buttons);
    sprite_array_destroy(menu->sp);

    menu->buttons =
        init_button_array(OPEN_CONF("src/txt_buttons/setting.conf"));
    menu->sp =
        init_sprite_array(OPEN_CONF("src/txt_sprites/sett_sprites.conf"));
    if (!str_equal(menu->file[0], "FPS=")) {
        char *str = str_cut(menu->file[0], '=');
        sfText_setString(menu->buttons[0]->text, str);
        sfRenderWindow_setFramerateLimit(win, get_nbr(str));
    }
}
