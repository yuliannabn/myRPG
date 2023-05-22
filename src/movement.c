/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** movement
*/

#include "rpg.h"

bool is_next(tile_t *tile, float x, float y)
{
    x = x + 400, y += 316;
    int left = tile->pos.x, right = tile->pos.x + 64;
    int top = tile->pos.y, bottom = tile->pos.y + 32;
    float dx = 0, dy = 0, distance = 0;
    static float old_dis = 25.0f;
    static sfVector2i id = {0, 0};

    if (id.x <= tile->id.x && id.y <= tile->id.y)
        old_dis = 25.0f;
    if (x >= left && x <= right && y >= top && y <= bottom) {
        dx = x - (left + right) / 2.0f;
        dy = y - (top + bottom) / 2.0f;
        distance = sqrtf(dx * dx + dy * dy);
        if (distance < old_dis) {
            old_dis = distance;
            return (true);
        }
    }
    return (false);
}

tile_t *get_next_tile(map_t *map, sfVector2f offset)
{
    if (!map) return (NULL);
    tile_t *tile = NULL;

    for (int i = 0; map->layer0[i]; i++) {
        for (int j = 0; map->layer0[i][j]; j++) {
            tile = map->layer0[i][j]->is_collide &&
            is_next(map->layer0[i][j], -offset.x, -offset.y) ? map->layer0[i][j]
            : map->layer1[i][j]->is_collide &&
            is_next(map->layer1[i][j], -offset.x, -offset.y) ? map->layer1[i][j]
            : tile;
        }
    }
    return (tile);
}

void move(tile_t *next_tile, menu_t *m, sfVector2f map, sfVector2f chr)
{
    if (next_tile)
        return;
    sfSound_play(m->cringe);
    move_map(m->map, map, m->buttons);
    character_move(m->character, chr);
}

bool move_diagonal(menu_t *m, sfVector2f (*value_array)[4])
{
    tile_t *next_tile = NULL;
    if ((IS_DIAG(sfKeyUp, sfKeyLeft)) || (IS_DIAG(sfKeyW, sfKeyA))) {
        next_tile = get_next_tile(m->map, (sfVector2f){5, 5});
        move(next_tile, m, (sfVector2f){5, 5}, value_array[0][1]);
        return (true);
    } else if ((IS_DIAG(sfKeyUp, sfKeyRight)) || (IS_DIAG(sfKeyW, sfKeyD))) {
        next_tile = get_next_tile(m->map, (sfVector2f){-5, 5});
        move(next_tile, m, (sfVector2f){-5, 5}, value_array[0][1]);
        return (true);
    }
    if ((IS_DIAG(sfKeyDown, sfKeyLeft)) || (IS_DIAG(sfKeyS, sfKeyA))) {
        next_tile = get_next_tile(m->map, (sfVector2f){5, -5});
        move(next_tile, m, (sfVector2f){5, -5}, value_array[1][1]);
        return (true);
    } else if ((IS_DIAG(sfKeyDown, sfKeyRight)) || (IS_DIAG(sfKeyS, sfKeyD))) {
        next_tile = get_next_tile(m->map, (sfVector2f){-5, -5});
        move(next_tile, m, (sfVector2f){-5, -5}, value_array[1][1]);
        return (true);
    }
    return (false);
}

void movement(menu_t *m, sfEvent evt)
{
    int move_array[][4] = MOVEMENT_ARRAY;
    sfVector2f value_array[][4] = MOVES_ARRAY;
    tile_t *next_tile = NULL;

    if (move_diagonal(m, value_array))
        return;
    for (int a = 0; a < 4; a++)
        if ((KEY_EVENT == move_array[a][0] || KEY_EVENT == move_array[a][1])) {
            next_tile = get_next_tile(m->map, value_array[a][0]);
            move(next_tile, m, value_array[a][0], value_array[a][1]);
        }
}
