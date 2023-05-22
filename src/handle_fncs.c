/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** handle_fncs
*/

#include "rpg.h"

void button_hover_handle(button_t **buttons, sfEvent evt)
{
    for (int i = 0; buttons && buttons[i] && buttons[i]->show; i++)
        IS_HOVER(buttons[i]);
}

void button_press_handle(sfRenderWindow *win, button_t **buttons, sfEvent evt,
menu_t *m)
{
    for (int i = 0; buttons && buttons[i]; i++) {
        if (IS_PRESSED(buttons[i]) && buttons[i]->show)
            buttons[i]->handler(win, m, &evt);
    }
}
