/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu.c
*/

#include "rpg.h"

inventory_t *inv_init(void)
{
    inventory_t *inv = malloc(sizeof(inventory_t));

    inv->sp = NULL, inv->buttons = NULL;
    inv->open = 0, inv->close = 0;
    return (inv);
}

menu_t *menu_init(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->buttons =
        init_button_array(OPEN_CONF(MENU_BUTTONS_CONFIG));
    menu->sp =
        init_sprite_array(OPEN_CONF(MENU_SPRITES_CONFIG));
    menu->file = OPEN_CONF(GENERAL_INFO);
    menu->map = NULL;
    menu->inv = NULL;
    menu->character = NULL;
    menu->cringe = sfSound_create();
    sfSoundBuffer *buff = sfSoundBuffer_createFromFile("src/sounds/cringe.ogg");
    sfSound_setBuffer(menu->cringe, buff);
    store_info(menu);
    return (menu);
}

void my_menu(menu_t *m)
{
    m->buttons = init_button_array(OPEN_CONF(MENU_BUTTONS_CONFIG));
    m->sp = init_sprite_array(OPEN_CONF(MENU_SPRITES_CONFIG));
    store_info(m);
}
