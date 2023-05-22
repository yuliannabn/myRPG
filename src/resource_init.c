/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** resource_init
*/

#include "rpg.h"

rpg_t *rpg_init(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    rpg->clock = sfClock_create();
    rpg->m = menu_init();
    rpg->m->inv = inv_init();
    rpg->m->pause = inv_init();
    return (rpg);
}

sfMusic *music_init(char *path)
{
    sfMusic *music = sfMusic_createFromFile(path);
    sfMusic_play(music);
    sfMusic_setVolume(music, config_parse_index(VOLUME_INDEX));
    sfMusic_setLoop(music, sfTrue);
    return (music);
}

sfRenderWindow *window_init(sfVideoMode videomode, int FR)
{
    sfRenderWindow *window =
        sfRenderWindow_create(videomode, MYRPG, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, FR);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return (window);
}

sfSprite *sprite_init(char *path, sfVector2f scale)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}
