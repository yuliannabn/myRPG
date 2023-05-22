/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** main.c
*/

#include "rpg.h"

void mouse_update(rpg_t *rpg)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(rpg->window);
    sfVector2f position = {(float)mouse_pos.x, (float)mouse_pos.y};
    sfSprite_setPosition(rpg->mouse, position);
    sfRenderWindow_drawSprite(rpg->window, rpg->mouse, NULL);
}

void window_configure(rpg_t *rpg)
{
    rpg->vid_mod = (sfVideoMode){800, 600, 32};
    rpg->window = window_init(rpg->vid_mod, config_parse_index(FPS_INDEX));
    rpg->m->music = music_init(MUSIC_PATH);
    rpg->mouse = sprite_init(MOUSE_SPRITE, (sfVector2f){0.8, 0.8});
    rpg->m->inv->open = false, rpg->m->inv->close = true;
    rpg->m->pause->open = false, rpg->m->pause->close = true;
}

int main(void)
{
    rpg_t *rpg = rpg_init();
    window_configure(rpg);

    while (sfRenderWindow_isOpen(rpg->window)) {
        sfRenderWindow_clear(rpg->window, sfBlack);
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
            analyse_events(rpg->window, rpg->event, rpg->m);
        display(rpg->window, rpg->m);
        mouse_update(rpg);
        sfRenderWindow_display(rpg->window);
    }
    resources_cleanup(rpg);
    return (SUCCESS);
}
