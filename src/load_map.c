/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** load_map
*/

#include "rpg.h"

void load_map(sfRenderWindow *win, menu_t *m, sfEvent *evt)
{
    (void)win, (void)evt;
    if (!m->map) {
        sfMusic_destroy(m->music);
        m->music = sfMusic_createFromFile("src/sounds/ambient.ogg");
        sfMusic_setLoop(m->music, sfTrue);
        sfMusic_play(m->music);
        sfMusic_setVolume(m->music, get_nbr(str_cut(m->file[1], '=')));
    }
    m->map = init_map(OPEN_CONF("src/maps/maze.txt"), 368, 280);
    m->character =
        character_cgf_init((char *)sfText_getString(m->buttons[0]->text), win);
    m->buttons = init_button_array(OPEN_CONF("src/txt_buttons/enemies.conf"));
    m->sp = NULL;
    m->inv->open = 1;
    m->pause->open = 1;
    change_line(str_cat("SLOT1=", m->name), &(m->file)[2]);
    store_info(m);
}
