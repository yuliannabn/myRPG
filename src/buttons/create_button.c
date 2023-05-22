/*
** EPITECH PROJECT, 2022
** buttons
** File description:
** menu.c
*/

#include "rpg.h"
#include "pui.h"

sfRectangleShape *create_rect(sfVector2f pos, sfVector2f size, char *img)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);

    if (!img || !str_equal(img, "NULL")) {
        sfTexture *texture = sfTexture_createFromFile(img, NULL);
        sfRectangleShape_setTexture(rect, texture, true);
    }
    return (rect);
}

sfText *create_text(char *str, sfVector2f pos, int size, char *font_path)
{
    if (!font_path || str_equal(font_path, "NULL"))
        return (NULL);
    sfFont *font = sfFont_createFromFile(font_path);
    sfText *text = sfText_create();

    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    sfText_setCharacterSize(text, size);
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    return (text);
}

void fill_function(button_t *button, char *str)
{
    handler handlers[] = BUTT_PTR;
    char *handlers_str[] = BUTT_STR;
    button->handler = NULL;

    for (int i = 0; i < BUTTON_COUNT; i++) {
        if (str_equal(str, handlers_str[i]))
            button->handler = handlers[i];
    }
}

button_t *create_button(char **info)
{
    button_t *button = malloc(sizeof(button_t));
    char *str = info[0];
    sfVector2f pos = {get_nbr(info[1]), get_nbr(info[2])};
    sfVector2f size = {get_nbr(info[3]), get_nbr(info[4])};
    char *img_path = info[5];
    sfVector2f text_pos = {get_nbr(info[6]), get_nbr(info[7])};
    int text_size = get_nbr(info[8]);
    char *font = info[9];
    button->show = str_equal(info[11], "1") ? true : false;
    button->input = str_equal(info[12], "1") ? true : false;
    button->color = sfWhite;
    button->rect = create_rect(pos, size, img_path);
    button->text = create_text(str, text_pos, text_size, font);
    button->is_hover = &is_hover; button->is_clicked = &is_clicked;
    button->is_released = &is_released; button->state = NONE;
    fill_function(button, info[10]); return (button);
}

button_t **init_button_array(char **lines)
{
    button_t **buttons = malloc(sizeof(button_t *) * (arr_len(lines) + 1));
    int i = 1;

    while (lines[i]) {
        buttons[i - 1] = create_button(str_to_word(lines[i], ':'));
        i++;
    }
    buttons[i - 1] = NULL;
    return (buttons);
}
