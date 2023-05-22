/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** init_map
*/

#include "rpg.h"

int count_tiles(char **file)
{
    int i = 0;

    while (file[i] && !str_equal(file[i], " ")) {
        i++;
    }
    return (i);
}

tile_t **init_tiles(char **file, int *index)
{
    int nb_tiles = count_tiles(file + *index);
    tile_t **tiles = malloc(sizeof(tile_t *) * nb_tiles + 1);
    sfTexture *texture = NULL;
    sfVector2f origin = {0, 0};

    for (int i = 0; i < nb_tiles; i++) {
        tiles[i] = malloc(sizeof(tile_t));
        tiles[i]->is_collide = file[*index][2] == '1';
        texture = sfTexture_createFromFile(file[*index] + 12, NULL);
        tiles[i]->sprite = sfSprite_create();
        sfSprite_setTexture(tiles[i]->sprite, texture, sfTrue);
        origin.x = get_nbr(file[*index] + 4);
        origin.y = get_nbr(file[*index] + 8);
        sfSprite_setOrigin(tiles[i]->sprite, origin);
        *index += 1;
    }
    *index += 1;
    return (tiles);
}

tile_t ***create_layer(char **file, int *i, int px, int py)
{
    if (!file[*i]) return (NULL);
    tile_t **tiles = init_tiles(file, i);
    int x = str_len(file[*i]), y = count_tiles(file + *i);
    tile_t ***layer = malloc(sizeof(tile_t **) * (y + 1));

    for (int j = 0; j < y; j++, *i += 1) {
        layer[j] = malloc(sizeof(tile_t *) * (x + 1));
        for (int k = 0; k < x; k++) {
            layer[j][k] = malloc(sizeof(tile_t));
            layer[j][k]->is_collide = tiles[file[*i][k] - '0']->is_collide;
            layer[j][k]->pos = (sfVector2f){k * 32 - j * 32 + px,
            j * 16 + k * 16 + py};
            layer[j][k]->sprite = sfSprite_copy(tiles[file[*i][k]-'0']->sprite);
            sfSprite_setPosition(layer[j][k]->sprite, layer[j][k]->pos);
            layer[j][k]->id = (sfVector2i){k, j};
        }
        layer[j][x] = NULL;
    }
    *i += 1, layer[y] = NULL;
    return (layer);
}

map_t *init_map(char **file, int px, int py)
{
    map_t *map = malloc(sizeof(map_t));
    int i = 0;

    map->layer0 = create_layer(file, &i, px, py);
    map->layer1 = create_layer(file, &i, px, py);
    map->background = sprite_init("src/images/sky.png", (sfVector2f){1.1, 1.1});

    return (map);
}
