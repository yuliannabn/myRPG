/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** init_char
*/

#include "char.h"

void stats_update(char_t *ch)
{
    ch->health = config_parse_index(HEALTH_INDEX);
    ch->atk = config_parse_index(ATK_INDEX);
    ch->def = config_parse_index(DEF_INDEX);
    sfText_setString
        (ch->stats,
        stats_get_string(ch->name, ch->level_exp, ch->health));
}

char_t *character_init(char *name, char *sprite, sfRenderWindow *win)
{
    char_t *new = malloc(sizeof(char_t));
    sfVector2u window_size = sfRenderWindow_getSize(win);

    new->name = name;
    new->sprite = sprite_init(sprite, (sfVector2f){1, 1});
    new->rect = (sfIntRect){0, 0, 32, 36}, new->clock = sfClock_create();
    new->pos = SCREEN_MIDDLE, sfSprite_setPosition(new->sprite, new->pos);
    new->health = config_parse_index(HEALTH_INDEX);
    new->atk = config_parse_index(ATK_INDEX);
    new->def = config_parse_index(DEF_INDEX);
    new->level_exp = 0;
    new->stats = character_stat_text_init(win);
    sfText_setString
        (new->stats, stats_get_string(name, new->level_exp, new->health));
    return (new);
}

// needs error handling
char_t *character_cgf_init(char *name, sfRenderWindow *win)
{
    char **data = get_initializers(INIT_PATH, "main");

    if (!data)
        return (NULL);
    char_t *character = character_init(name, PATH_SPRITE, win);
    free_string_array(data);
    return (character);
}

// direction.x = start of animation, direction.y = end of animation
void character_move(char_t *chara, sfVector2f direction)
{
    sfTime time = sfClock_getElapsedTime(chara->clock);

    if (!chara)
        return;
    if (chara->rect.left < WALK_START || chara->rect.left > WALK_LIMIT)
        chara->rect.left = WALK_START;
    if (sfTime_asSeconds(time) > 0.3)
        chara->rect.left += TILE_SIZE, sfClock_restart(chara->clock);
    if (chara->rect.left >= WALK_LIMIT)
        chara->rect.left = WALK_START;
}
