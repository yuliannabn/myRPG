/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** events.c
*/

#include "rpg.h"

void button_press_manage(sfRenderWindow *win, menu_t *m, sfEvent evt)
{
    button_press_handle(win, m->buttons, evt, m);
    button_press_handle(win, m->inv->buttons, evt, m);
    button_press_handle(win, m->pause->buttons, evt, m);
}

void button_hover_manage(menu_t *m, sfEvent evt)
{
    button_hover_handle(m->buttons, evt);
    button_hover_handle(m->inv->buttons, evt);
    button_hover_handle(m->pause->buttons, evt);
}

void fill_input(menu_t *menu, sfEvent *evt)
{
    button_t *box = NULL;
    char *str = NULL;
    for (int i = 0; menu->buttons && menu->buttons[i]; i++)
        if (menu->buttons[i]->state == PRESSED)
            box = menu->buttons[i];
    if (!box || !box->text)
        return;
    str = (char *)sfText_getString((const sfText *)box->text);
    if (str_equal(str, " "))
        str = "";
    if (CHAR_INPUT >= 32 && CHAR_INPUT <= 126 && str_len(str) < 36)
        str = str_cat_char(str, CHAR_INPUT);
    if (CHAR_INPUT == BACKSPACE)
        str[str_len(str) - 1] = '\0';
    sfText_setString(box->text, str);
    if (menu && menu->name) free(menu->name);
    menu->name =
        str_dup((char *)sfText_getString((const sfText *)box->text));
}

void analyse_events(sfRenderWindow *window, sfEvent event, menu_t *menu)
{
    if (event.type == sfEvtMouseMoved)
        button_hover_manage(menu, event);
    if (event.type == sfEvtMouseButtonPressed)
        button_press_manage(window, menu, event);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && menu->inv->open && menu->pause->open) {
        if (event.key.code == sfKeyI) {
            handle_inventory(window, menu, &event);
            menu->inv->close = !menu->inv->close;
        }
        if (event.key.code == sfKeyEscape) {
            handle_pause(window, menu, &event);
            menu->pause->close = !menu->pause->close;
        }
        if (menu->map) movement(menu, event);
    }
    if (event.type == sfEvtTextEntered) fill_input(menu, &event);
}
