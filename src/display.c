/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display.c
*/

#include "rpg.h"

void layer_display(sfRenderWindow *win, tile_t ***layer)
{
    if (!layer || !(*layer))
        return;
    for (int i = 0; layer[i]; i++) {
        for (int j = 0; layer[i][j]; j++) {
            sfRenderWindow_drawSprite(win, layer[i][j]->sprite, NULL);
        }
    }
}

void display_map(sfRenderWindow *win, map_t *map)
{
    if (!map)
        return;
    if (map->background)
        sfRenderWindow_drawSprite(win, map->background, NULL);
    layer_display(win, map->layer0);
    layer_display(win, map->layer1);
}

void display(sfRenderWindow *win, menu_t *m)
{
    display_map(win, m->map);
    character_display(win, m->character);
    sprite_array_display(win, m->sp, true);
    buttons_display(win, m->buttons, m->buttons ? m->buttons[0]->show : false);
    sprite_array_display(win, m->inv->sp, m->inv->close);
    buttons_display(win, m->inv->buttons, m->inv->close);
    sprite_array_display(win, m->pause->sp, m->pause->close);
    buttons_display(win, m->pause->buttons, m->pause->close);
}
