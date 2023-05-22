/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** character_parse
*/

#include "rpg.h"

char *ptr_find_name(char **strings, char *request)
{
    int a = 0, b = 0;

    while (strings[a]) {
        for (b = 0; request[b] && strings[a][b] == request[b]; b++);
        if (b == str_len(request))
            return (strings[a]);
        a++;
    }
    return (NULL);
}

char *stats_get_string(char *name, int exp, int health)
{
    char *name_exp = str_cat(name, "\nexp: ");
    char *expe = str_cat(name_exp, int_to_str(exp));
    char *exp_health = str_cat(expe, "\nhealth: ");
    char *heal = str_cat(exp_health, int_to_str(health));

    free(name_exp), free(expe), free(exp_health);
    return (heal);
}

sfText *character_stat_text_init(sfRenderWindow *win)
{
    sfVector2u window_size = sfRenderWindow_getSize(win);
    sfText *new = sfText_create();

    sfText_setFont(new, sfFont_createFromFile(FONT_PATH));
    sfText_setColor(new, sfWhite);
    sfText_setCharacterSize(new, 13);
    sfText_setPosition(new, PLAYER_TOP);
    return (new);
}

char **get_initializers(char *file, char *request_name)
{
    char *text = open_file(file);

    if (!text)
        return (NULL);
    char **lines = str_to_word(text, '\n');
    char *ptr = str_dup(ptr_find_name(lines, request_name));
    free_string_array(lines), free(text);

    return (str_to_word(ptr, ':'));
}
