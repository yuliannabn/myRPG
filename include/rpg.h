/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** rpg.h
*/

#ifndef RPG_H_
    #define RPG_H_

    #include <math.h>
    #include <stddef.h>
    #include <stdbool.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include "pui.h"
    #include "char.h"
    #include "files.h"

    #define SPEED               10
    #define BACKSPACE           8
    #define FPS_INDEX           0
    #define VOLUME_INDEX        1
    #define CHAR_INPUT          evt->text.unicode
    #define MYRPG               "MyRPG"
    #define MUSIC_PATH          "src/sounds/Skyrim.ogg"
    #define MOUSE_SPRITE        "./src/images/mouse.png"
    #define GENERAL_INFO        "general_info.txt"
    #define MENU_BUTTONS_CONFIG "src/txt_buttons/menu_but.conf"
    #define MENU_SPRITES_CONFIG "src/txt_sprites/menu_sprite.conf"
    #define HP                  "HP="
    #define STAT                "Stat_Points="
    #define DEF                 "DEF="
    #define STR                 "STR="

    #define OPEN_CONF(file)     str_to_word(open_file(file), '\n')
    #define IS_HOVER(button)    button->is_hover(button, &evt.mouseMove)
    #define IS_PRESSED(button)  button->is_clicked(button, &evt.mouseButton)
    #define IS_RELEASED(button) button->is_released(button, &evt.mouseButton)
    #define BUTTON_COUNT        19

    #define IS_DIAG(key1, key2) \
    (sfKeyboard_isKeyPressed(key1) && sfKeyboard_isKeyPressed(key2))

    #define MAP_DOWN    (sfVector2f) { \
                            0, -SPEED  \
                        }
    #define MAP_UP      (sfVector2f) { \
                            0, SPEED   \
                        }
    #define MAP_LEFT    (sfVector2f) { \
                            SPEED, 0   \
                        }
    #define MAP_RIGHT   (sfVector2f) { \
                            -SPEED, 0  \
                        }
    #define MOVE_NBR            4

    #define MOVEMENT_ARRAY { {  \
            sfKeyUp, sfKeyW     \
        }, {                    \
            sfKeyDown, sfKeyS   \
        }, {                    \
            sfKeyLeft, sfKeyA   \
        }, {                    \
            sfKeyRight, sfKeyD  \
        }                       \
    }

    #define MOVES_ARRAY { {     \
            MAP_UP, M_UP        \
        }, {                    \
            MAP_DOWN, M_DOWN    \
        }, {                    \
            MAP_LEFT, M_LEFT    \
        }, {                    \
            MAP_RIGHT, M_RIGHT  \
        }                       \
    }

    #define BUTT_STR { \
        "handle_null", "handle_new_game", "handle_settings",    \
        "handle_load", "handle_quit", "handle_go_back",         \
        "handle_fps", "handle_fps30", "handle_fps60",           \
        "handle_fps90", "handle_slot1", "handle_m_mute",        \
        "handle_m_music", "load_map", "handle_resume",          \
        "handle_hp", "handle_def", "handle_str",                \
        "combat"                                                \
    }
    #define BUTT_PTR { \
        &handle_null, &handle_new_game, &handle_settings,       \
        &handle_load, &handle_quit, &handle_go_back,            \
        &handle_fps, &handle_fps30, &handle_fps60,              \
        &handle_fps90, &handle_slot1, &handle_m_mute,           \
        &handle_m_music, &load_map, &handle_resume,             \
        &handle_hp, &handle_def, &handle_str,                   \
        &combat                                                 \
    }

    struct menu_s;
    enum button_state {
        NONE = 0,
        HOVER,
        PRESSED,
        RELEASED
    };

    typedef struct button_s {
        sfRectangleShape *rect;
        sfText *text;
        bool show;
        bool input;
        void (*handler)(sfRenderWindow *win, struct menu_s *m, sfEvent *evt);
        sfBool (*is_hover)(struct button_s *, sfMouseMoveEvent *);
        sfBool (*is_clicked)(struct button_s *, sfMouseButtonEvent *);
        sfBool (*is_released)(struct button_s *, sfMouseButtonEvent *);
        sfColor color;
        enum button_state state;
    } button_t;

    typedef struct sprites_s {
        sfSprite *sprite;
        sfTexture *texture;
        sfText *text;
    } sprites_t;

    typedef struct inventory_s {
        button_t **buttons;
        sprites_t **sp;
        bool open;
        bool close;
    } inventory_t;

    typedef struct tile_s {
        sfSprite *sprite;
        bool is_collide;
        sfVector2f pos;
        sfVector2i id;
    } tile_t;

    typedef struct map_s {
        tile_t ***layer0;
        tile_t ***layer1;
        sfSprite *background;
    } map_t;

    typedef struct menu_s {
        button_t **buttons;
        char_t *character;
        sprites_t **sp;
        inventory_t *inv;
        inventory_t *pause;
        map_t *map;
        char **file;
        char *name;
        sfMusic *music;
        sfSound *cringe;
    } menu_t;

    typedef struct rpg_s {
        sfSprite *mouse;
        sfTexture *mouse_texture;
        sfEvent event;
        sfRenderWindow *window;
        sfVideoMode vid_mod;
        sfClock *clock;
        menu_t *m;
    } rpg_t;

    typedef void (*handler) (sfRenderWindow *, struct menu_s *, sfEvent *);

    void my_menu(menu_t *m);
    char *cfg_file_title_get(void);
    void resources_cleanup(rpg_t *rpg);
    void button_array_destroy(button_t **buttons);
    void sprite_array_destroy(sprites_t **sprites);
    menu_t *menu_init(void);
    void change_line(char *new, char **old);
    rpg_t *rpg_init(void);
    sfMusic *music_init(char *path);
    sfRenderWindow *window_init(sfVideoMode videomode, int FR);
    sfSprite *sprite_init(char *path, sfVector2f scale);
    inventory_t *inv_init(void);
    void button_hover_handle(button_t **buttons, sfEvent evt);
    void button_press_handle(sfRenderWindow *win, button_t **buttons,
    sfEvent evt, menu_t *m);
    void character_display(sfRenderWindow *win, char_t *chara);
    void sprite_array_display(sfRenderWindow *win, sprites_t **sprites,
    bool show);
    void buttons_display(sfRenderWindow *win, button_t **buttons, bool close);
    void analyse_events(sfRenderWindow *window, sfEvent event, menu_t *menu);
    void display(sfRenderWindow *win, menu_t *m);
    void handle_null(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_quit(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_new_game(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_load(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_settings(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_go_back(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_fps(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_fps30(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_fps60(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_fps90(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_slot1(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_name(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_inventory(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_m_music(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_m_mute(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_pause(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_resume(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_hp(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_def(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void handle_str(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    void combat(sfRenderWindow *win, menu_t *menu, sfEvent *evt);
    sfBool is_hover(button_t *button, sfMouseMoveEvent *mouse);
    sfBool is_clicked(button_t *button, sfMouseButtonEvent *mouse);
    sfBool is_released(button_t *button, sfMouseButtonEvent *mouse);
    button_t **init_button_array(char **lines);
    sprites_t **init_sprite_array(char **lines);
    sfSprite *sprite_init(char *path, sfVector2f scale);
    sfText *create_text(char *str, sfVector2f pos, int size, char *font_path);
    float my_get_float(char *str);
    void store_info(menu_t *m);
    char *str_cut(char *str, char c);
    char *int_to_str(int num);
    map_t *init_map(char **file, int px, int py);
    void load_map(sfRenderWindow *win, menu_t *m, sfEvent *evt);
    void movement(menu_t *m, sfEvent evt);
    void move_map(map_t *map, sfVector2f offset, button_t **buttons);

#endif
