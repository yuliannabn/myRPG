/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** buttons.c
*/

#include "rpg.h"

void change_color_rect(button_t *button, int a)
{
    sfColor color;
    if (a == 0)
        color = button->color;
    else {
        color = sfRectangleShape_getFillColor(button->rect);
        color.a += color.a == 255 ? -a : a;
    }
    sfRectangleShape_setFillColor(button->rect, color);
}

sfBool is_hover(button_t *button, sfMouseMoveEvent *mouse)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&rect, mouse->x, mouse->y)) {
        if (button->state == NONE)
            change_color_rect(button, 75);
        button->state = HOVER;
        return true;
    } else if (button->state == HOVER)
        change_color_rect(button, 0);
    button->state = NONE;
    return false;
}

sfBool is_clicked(button_t *button, sfMouseButtonEvent *mouse)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&rect, mouse->x, mouse->y)) {
        button->state = PRESSED;
        return true;
    }
    return false;
}

sfBool is_released(button_t *button, sfMouseButtonEvent *mouse)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (!sfFloatRect_contains(&rect, mouse->x, mouse->y)) {
        button->state = RELEASED;
        return true;
    }
    return false;
}
