/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** fps.c
*/

#include "rpg.h"

void handle_fps(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)win, (void)evt;
    if (!menu->buttons[7]->show && !menu->buttons[8]->show
    && !menu->buttons[9]->show) {
        menu->buttons[9]->show = true;
        menu->buttons[8]->show = true;
        menu->buttons[7]->show = true;
    } else {
        menu->buttons[9]->show = false;
        menu->buttons[8]->show = false;
        menu->buttons[7]->show = false;
    }
}

void handle_fps30(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)evt;
    sfRenderWindow_setFramerateLimit(win, 30);
    sfText_setString(menu->buttons[0]->text, "30");
    menu->buttons[7]->show = false;
    menu->buttons[8]->show = false;
    menu->buttons[9]->show = false;
    menu->file[0] = str_cat("FPS=", "30");
}

void handle_fps60(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)evt;
    sfRenderWindow_setFramerateLimit(win, 60);
    sfText_setString(menu->buttons[0]->text, "60");
    menu->buttons[7]->show = false;
    menu->buttons[8]->show = false;
    menu->buttons[9]->show = false;
    menu->file[0] = str_cat("FPS=", "60");

}

void handle_fps90(sfRenderWindow *win, menu_t *menu, sfEvent *evt)
{
    (void)evt;
    sfRenderWindow_setFramerateLimit(win, 90);
    sfText_setString(menu->buttons[0]->text, "90");
    menu->buttons[7]->show = false;
    menu->buttons[8]->show = false;
    menu->buttons[9]->show = false;
    menu->file[0] = str_cat("FPS=", "90");
}
