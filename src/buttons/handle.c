/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** handle.c
*/

#include "rpg.h"

void handle_quit(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)evt;
    store_info(menu);
    sfRenderWindow_close(win);
}

void handle_null(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)menu, (void)evt;
}

void handle_new_game(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)evt;
    button_array_destroy(menu->buttons);

    menu->buttons =
        init_button_array(OPEN_CONF("src/txt_buttons/new_game.conf"));
    sfText_setString(menu->buttons[0]->text, str_cut(menu->file[2], '='));
}

void handle_go_back(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)evt;
    button_array_destroy(menu->buttons);
    sprite_array_destroy(menu->sp);

    menu->inv->open = false;
    my_menu(menu);
}

void combat(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)evt;
    int i = get_nbr(str_cut(menu->file[3], '='));
    int hp = get_nbr(str_cut(menu->file[4], '='));
    for (int i = 0; menu->buttons[i]; i++) {
        if (menu->buttons[i]->state == 2) {
            sfRectangleShape_setPosition(menu->buttons[i]->rect,
                (sfVector2f){-1000, -1000});
        }
    } i++, hp -= 3; menu->character->level_exp += 1;
    if (get_nbr(str_cut(menu->file[5], '=')) >= 10) hp += 1;
    menu->file[3] = str_cat("Stat_Points=", int_to_str(i));
    menu->file[4] = str_cat("HP=", int_to_str(hp));
    store_info(menu); stats_update(menu->character);
    if (hp <= 0) {
        menu->character->level_exp = 0;
        menu->file[5] = str_cat("DEF=", int_to_str(5));
        menu->file[3] = str_cat("Stat_Points=", int_to_str(0));
        menu->file[4] = str_cat("HP=", int_to_str(30));
        menu->file[6] = str_cat("STR=", int_to_str(10));
        store_info(menu); menu->buttons[7]->show = true;
    }
}
