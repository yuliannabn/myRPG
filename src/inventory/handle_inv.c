/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** handle_inv.c
*/

#include "rpg.h"

void handle_inventory(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)evt;
    menu->inv->sp =
        init_sprite_array(OPEN_CONF("src/txt_sprites/inv_sprites.conf"));
    menu->inv->buttons =
    init_button_array(OPEN_CONF("src/txt_buttons/inv_butt.conf"));
    sfText_setString(menu->inv->sp[7]->text, str_cut(menu->file[4], '='));
    sfText_setString(menu->inv->sp[8]->text, str_cut(menu->file[5], '='));
    sfText_setString(menu->inv->sp[9]->text, str_cut(menu->file[6], '='));
    sfText_setString(menu->inv->sp[10]->text, str_cut(menu->file[3], '='));
    store_info(menu);
}

void handle_pause(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)evt;
    menu->pause->sp =
        init_sprite_array(OPEN_CONF("src/txt_sprites/pause_menu.conf"));
    menu->pause->buttons =
    init_button_array(OPEN_CONF("src/txt_buttons/pause_but.conf"));
}

void handle_resume(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)evt;
    menu->pause->close = !menu->pause->close;
}
