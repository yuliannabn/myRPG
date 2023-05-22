/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** move_map
*/

#include "rpg.h"

void move_map(map_t *map, sfVector2f offset, button_t **buttons)
{
    for (int i = 0; map->layer0 && map->layer0[i]; i++)
        for (int j = 0; map->layer0[i][j]; j++) {
            map->layer0[i][j]->pos.x += offset.x;
            map->layer0[i][j]->pos.y += offset.y;
            map->layer1[i][j]->pos.x += offset.x;
            map->layer1[i][j]->pos.y += offset.y;
            sfSprite_move(map->layer0[i][j]->sprite, offset);
            sfSprite_move(map->layer1[i][j]->sprite, offset);
        }
    for (int i = 0; buttons && buttons[i]; i++) {
        sfRectangleShape_move(buttons[i]->rect, offset);
        if (buttons[i]->show)
            sfText_move(buttons[i]->text, offset);
    }
}
