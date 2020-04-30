/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Header for RPG
*/

#ifndef rpg_h
#define rpg_h

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "my.h"

typedef struct texture
{
    sfTexture *tex;
    sfSprite *sprite;
}texture_t;

#define E 2.71828182846
#define PI 3.14159265359
#define MAP_Y 256

typedef struct block {
    int type;
    sfColor color;
    char solid;
    int id;
} block_t;

typedef struct map
{
    lld_t *map;
    int size_l;
    int size_r;
} map_t;


block_t **generate_line(int x, int d);
block_t **generate_getcolum(map_t *map, int x);
map_t *generate_map();
block_t ***generator_getmap(map_t *map, sfIntRect *rect);

typedef struct pos
{
    float x;
    float y;
    float a;
} pos_t;

typedef struct member
{
    sfSprite *sprite;
    pos_t *pos;
    pos_t *pos2;
    pos_t *pos3;
    float ag;
} member_t;

typedef struct animator
{
    lld_t *member;
    pos_t *pos;
    float time;
    float dtime;
} animator_t;


sfVector2f alloc_vector2f(float x, float y);
pos_t *malloc_pos(float x, float y, float a);

animator_t *animator_init();
int animator_setpos(animator_t *anim, pos_t *coor);
int animator_addmenber(animator_t *anim, pos_t *pos, sfSprite *sprite);

int animator_draw(sfRenderWindow *window, animator_t *anim);
int animator_animate(animator_t *anim);
int animator_goto(animator_t *anim, ...);
void animator_free(animator_t *anim);

typedef enum
{
    APPLE = 0,
    ARROW = 1,
    AXE_WOOD = 2,
    AXE_STONE = 3,
    AXE_IRON = 4,
    AXE_DIAMOND = 5,
    BANNER1 = 7,
    BANNER2 = 8,
    BANNER3 = 9,
    BANNER4 = 10,
    BANNER5 = 11,
    BOW = 12,
    BOW_ARROW = 13,
    BOWL = 14,
    BRICK = 15,
    BUCKET = 16,
    BUCKET_LAVA = 17,
    BUCKET_WATER = 18,
    CARROT = 19,
    CLAY_BALL = 20,
    FISH_RAW = 21,
    FISH = 22,
    BOAR = 23,
    FOX = 24,
    COOKIE = 25,
    COTTON_BLUE = 26,
    COTTON_GREEN = 27,
    COTTON_RED = 28,
    COTTON_WHITE = 29,
    FISHING_ROAD = 30,
    BOOK = 31,
    MUSHROOM = 32,
    DIAMOND = 33,
    COAL = 34,
    GOLD = 35,
    IRON = 36,
    PICKAXE_WOOD = 37,
    PICKAXE_STONE = 38,
    PICKAXE_IRON = 39,
    PICKAXE_DIAMOND = 40,
    BOAR_RAW = 41,
    FOX_RAW = 42,
    SEED = 43,
    SHOVEL_WOOD = 44,
    SHOVEL_STONE = 45,
    SHOVEL_IRON = 46,
    SHOVEL_DIAMOND = 47,
    SOUP = 48,
    STICK = 49,
    SWORD_WOOD = 50,
    SWORD_STONE = 51,
    SWORD_IRON = 52,
    SWORD_DIAMOND = 53,
    TORCH = 54,
    WHEAT = 55
}items;

typedef enum
{
    STONEBRICK = 0,
    BRICKBLOCK = 1,
    CACTUS = 2,
    CARROT_0 = 3,
    CARROT_1 = 4,
    CARROT_2 = 5,
    CLAY = 6,
    COBBLE = 7,
    COTTON_BLOCK_B = 8,
    COTTON_BLOCK_G = 9,
    COTTON_BLOCK_R = 10,
    COTTON_BLOCK_W = 11,
    WORKBENCH = 12,
    DIRT = 13,
    GRASS = 14,
    SNOW_DIRT = 15,
    STONE_FENCE = 16,
    WOOD_FENCE = 17,
    GLASS = 18,
    WOOD_GLASS = 19,
    FERN_0 = 20,
    FERN_1 = 21,
    FERN_2 = 22,
    FERN_3 = 23,
    FERN_4 = 24,
    FERN_5 = 25,
    GRAVEL = 26,
    ICE = 27,
    LADDER = 28,
    LAVA = 29,
    LEAVES_0 = 30,
    LEAVES_1 = 31,
    LEAVES_2 = 32,
    LEAVES_3 = 33,
    MUSH_0 = 34,
    MUSH_1 = 35,
    MUSH_2 = 36,
    PLANT_B = 37,
    PLANT_G = 38,
    PLANT_R = 39,
    PLANT_W = 40,
    FURNACE = 41,
    SAND = 42,
    DOOR_OPEN_0 = 43,
    DOOR_CLOSE = 44,
    DOOR_OPEN_1 = 45,
    WOOD_PLANKS = 46,
    STONE = 47,
    ORE_IRON = 48,
    ORE_COAL = 49,
    ORE_DIAMOND = 50,
    ORE_GOLD = 51,
    SNOW_STONE = 52,
    LOG = 53,
    BIRCH = 54,
    WATER = 55,
    SEED_0 = 56,
    SEED_1 = 57,
    SEED_2 = 58,
    SEED_3 = 59
}blocks;


typedef struct player
{
    float x;
    float y;
    float vx;
    float vy;
    char floor;
    animator_t *anim;
    int hp;
    int **inventory;
} player_t;

typedef struct entity
{
    float x;
    float y;
    float vx;
    float vy;
    char floor;
    animator_t *anim;
    int hp;
} entity_t;

typedef struct item
{
    float x;
    float y;
    float vx;
    float vy;
    int type;
    int item;
    int life;
    int stack;
} item_t;

//items & blocks

typedef struct game
{
    lld_t *players;
    lld_t *entities;
    lld_t *items;
    map_t *map;
    texture_t *it;
    texture_t *bl;
} game_t;

/* -- Include CSFML -- */

/* -- For coords -- */

#define X ((*cpy)->attrib->pos.x * ((float) win->x))
#define Y ((*cpy)->attrib->pos.y * ((float) win->y))
#define SX ((*cpy)->attrib->size.x)
#define SY ((*cpy)->attrib->size.y)
#define CFG_MENU_PARAM (1)

typedef struct my_text
{
    sfText *text;
    sfFont *font;
}text_t;

typedef struct config
{
    int sound;
    int fps;
    int difficulty;
}config_t;

typedef struct win
{
    int x;
    int y;
    sfRenderWindow *win;
    texture_t *mouse;
    texture_t *click;
    texture_t *logo;
    config_t *config;
    game_t *game;
    int menu;
    sfVideoMode mode;
}win_t;

typedef struct att_s
{
    sfVector2f size;
    sfVector2f pos;
}att_t;

typedef struct button
{
    att_t *attrib;
    sfTexture *tex;
    sfTexture *tex_h;
    sfSprite *sprite;
    sfSprite *sprite_h;
    void (*func)(win_t *win);
    int menu;
    int hover;
    int pressed;
}button_t;

/* -- FUNCS -- */

win_t *create_window(int *returned, char *name);
att_t *set_attrib(float x, float y, int width, int depth);
button_t *add_button(int menu, void *func, char *path, att_t *attrib);
void **add_to_array(void **buttons, button_t *new);
void button_main(win_t *win, button_t **buttons);
void button_event(win_t *win, button_t **buttons, sfEvent event);
void end_free(win_t *win, button_t **buttons);
void change_icon(sfRenderWindow *window);
void replace_mouse(win_t *win);
void **init_buttons(void **buttons);
int launch_game(void);
void event_manager(win_t *win, button_t **button, sfEvent event, int *returned);
void scene_manager(win_t *win, button_t **buttons, int *returned);
void draw_home(win_t *win);
void btn_quit(win_t *win);
void btn_play(win_t *win);
void btn_opt(win_t *win);
void btn_back(win_t *win);
void btn_help(win_t *win);
void btn_resume(win_t *win);
void btn_return(win_t *win);
void btn_quit_game(win_t *win);
void draw_game(win_t *win);
void free_game(win_t *win);

int **init_inventory();
void free_inventory(int **inventory);
int take_inv(int **inv, int type, int item, int nb);
int give_inv(int **inventory, int type, int item, int nb);
void draw_inv(win_t *win);
#define GRAVITY 10

int engine(game_t *game);

int player_add_player(game_t *game);
animator_t *init_player_animator();
int flr(float x);

game_t *load_game();
int save_game(game_t *game);
int engine_create_item(game_t *game, float x, float y, ...);

#endif
