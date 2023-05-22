/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** display_fncs
*/

#include "rpg.h"

void character_display(sfRenderWindow *win, char_t *chara)
{
    if (!chara)
        return;
    sfSprite_setTextureRect(chara->sprite, chara->rect);
    sfRenderWindow_drawSprite(win, chara->sprite, NULL);
    sfRenderWindow_drawText(win, chara->stats, NULL);
}

void sprite_array_display(sfRenderWindow *win, sprites_t **sprites, bool show)
{
    if (!sprites || !(*sprites))
        return;
    for (int j = 0; sprites[j] && show; j++) {
        sfRenderWindow_drawSprite(win, sprites[j]->sprite, NULL);
        if (sprites[j]->text)
            sfRenderWindow_drawText(win, sprites[j]->text, NULL);
    }
}

void buttons_display(sfRenderWindow *win, button_t **buttons, bool close)
{
    if (!buttons || !(*buttons))
        return;
    for (int a = 0; buttons && buttons[a] && close && buttons[a]->show; a++) {
        sfRenderWindow_drawRectangleShape(win, buttons[a]->rect, NULL);
        if (buttons[a]->text)
            sfRenderWindow_drawText(win, buttons[a]->text, NULL);
    }
}
