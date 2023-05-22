/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** data_destroys
*/

#include "rpg.h"

void resources_cleanup(rpg_t *rpg)
{
    sfMusic_stop(rpg->m->music);
    sfRenderWindow_destroy(rpg->window);
    if (rpg->m->character) {
        sfClock_destroy(rpg->m->character->clock);
        sfSprite_destroy(rpg->m->character->sprite);
    }
}

void button_array_destroy(button_t **buttons)
{
    if (!buttons || !(*buttons))
        return;
    for (int i = 0; buttons[i]; i++) {
        sfRectangleShape_destroy(buttons[i]->rect);
        sfText_destroy(buttons[i]->text);
    }
}

void sprite_array_destroy(sprites_t **sprites)
{
    if (!sprites || !(*sprites))
        return;
    for (int j = 0; sprites[j]; j++) {
        sfSprite_destroy(sprites[j]->sprite);
        sfText_destroy(sprites[j]->text);
    }
}
