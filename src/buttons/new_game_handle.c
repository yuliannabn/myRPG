/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** new_game_handle.c
*/

#include "rpg.h"

void handle_slot1(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)evt;

    if (str_len(cfg_file_title_get()) > 0
    && !str_equal(cfg_file_title_get(), "Slot 1")) {
        load_map(win, menu, evt);
        return;
    }
    button_array_destroy(menu->buttons);
    sprite_array_destroy(menu->sp);
    menu->buttons =
    init_button_array(OPEN_CONF("src/txt_buttons/create_charac.conf"));
    menu->sp =
    init_sprite_array(OPEN_CONF("src/txt_sprites/new_game_sprites.conf"));
}
