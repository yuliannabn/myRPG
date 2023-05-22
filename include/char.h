/*
** EPITECH PROJECT, 2023
** myrpg
** File description:
** char
*/

#ifndef CHAR_H_
    #define CHAR_H_

    #include "pui.h"
    #include "files.h"
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>

    #define INIT_PATH   "src/character/character_init.cfg"
    #define INFO_PATH   "src/txt_sprites/char_sprites.conf"
    #define FONT_PATH   "src/fonts/arial.ttf"
    #define CHARAC      "main"
    #define FIRE_E      "fireball"
    #define SPIKES_E    "spikes"
    #define JOCK_E      "jock"
    #define NPC         "npc"
    #define PATH_SPRITE data[2]
    #define POS         data[3]
    #define TILE_SIZE    32
    #define HEALTH_INDEX 4
    #define DEF_INDEX    5
    #define ATK_INDEX    6
    #define WALK_START  direction.x
    #define WALK_LIMIT  direction.y
    #define SCREEN_MIDDLE (sfVector2f) {                \
                            (window_size.x / 2) - TILE_SIZE / 2,   \
                            (window_size.y / 2) - TILE_SIZE / 2   \
                        }
    #define PLAYER_TOP (sfVector2f) {                   \
                            SCREEN_MIDDLE.x - 13,   \
                            SCREEN_MIDDLE.y - 50    \
                        }
    #define M_DOWN      (sfVector2f) { \
                            0, 128     \
                        }
    #define M_UP        (sfVector2f){  \
                            160, 256   \
                        }
    #define M_LEFT      (sfVector2f){  \
                            384, 512   \
                        }
    #define M_RIGHT     (sfVector2f){  \
                            256, 384   \
                        }
    #define KEY_EVENT    evt.key.code

    struct char_s;
    struct enemy_s;
    struct npc_s;

    typedef void (*enemy_attack)(struct enemy_s *, struct char_s *);
    typedef void (*char_attack)(struct char_s *, struct enemy_s *);
    // will load script, restarts script when talked to at start
    typedef void (*npc_talk)(struct npc_s *);

    enum attack_type {
        SPIKES,
        FIRE,
        JOCK
    };

    // will have more stuff later
    typedef struct enemy_s {
        char *name;
        enum attack_type attack;
        sfSprite *sprite;
        sfIntRect rect;
        sfClock *clock;
        enemy_attack attack_action;
        int health;
        sfVector2f pos;
    } enemy_t;

    typedef struct char_s {
        char *name;
        sfSprite *sprite;
        sfIntRect rect;
        sfClock *clock;
        char_attack attack_action;
        sfText *stats;
        int health, level_exp, atk, def;
        sfVector2f pos;
    } char_t;

    typedef struct npc_s {
        char *name;
        sfSprite *sprite;
        sfIntRect rect;
        sfClock *clock;
        sfVector2f pos;
        npc_talk talk_action;
    } npc_t;

    typedef struct mobs_s {
        int enemy_count;
        char_t *character;
        enemy_t **enemies;
    } mobs_t;

    sfSprite *sprite_init(char *path, sfVector2f scale);
    sfText *character_stat_text_init(sfRenderWindow *win);
    void stats_update(char_t *ch);
    int config_parse_index(int index);
    void character_move(char_t *chara, sfVector2f pos);
    char *ptr_find_name(char **strings, char *request);
    char *stats_get_string(char *name, int exp, int health);
    char *int_to_str(int num);
    char_t *character_cgf_init(char *name, sfRenderWindow *win);
    char_t *character_init(char *name, char *sprite, sfRenderWindow *win);
    void    character_display(sfRenderWindow *win, char_t *chara);
    char **get_initializers(char *file, char *request_name);

#endif
