/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_sprite.c
*/

#include "rpg.h"

sprites_t *create_sprite(char **info)
{
    sprites_t *sp = malloc(sizeof(sprites_t));
    char *str = info[0];
    sfVector2f text_pos = {get_nbr(info[6]), get_nbr(info[7])};
    int text_size = get_nbr(info[8]);
    char *font = info[9];
    sp->sprite = sfSprite_create();
    sp->texture =
        sfTexture_createFromFile(info[1], NULL);
    sfSprite_setTexture(sp->sprite, sp->texture, sfTrue);
    if (!str_equal(info[2], "NULL") && !str_equal(info[3], "NULL")) {
        sfVector2f pos = {get_nbr(info[2]), get_nbr(info[3])};
        sfSprite_setPosition(sp->sprite, pos);
    }
    if (!str_equal(info[4], "NULL") && !str_equal(info[5], "NULL")) {
        sfVector2f scale = {my_get_float(info[4]), my_get_float(info[5])};
        sfSprite_setScale(sp->sprite, scale);
    }
    sp->text = create_text(str, text_pos, text_size, font);
    return (sp);
}

sprites_t **init_sprite_array(char **lines)
{
    sprites_t **sp = malloc(sizeof(sprites_t *) * (arr_len(lines) + 1));
    int i = 1;

    while (lines[i]) {
        sp[i - 1] = create_sprite(str_to_word(lines[i], ':'));
        i++;
    }
    sp[i - 1] = NULL;
    return (sp);
}
