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
#include "screen.h"

#define JUMP_HIGHT 2.5
#define JUMP_SPEED pow(JUMP_HIGHT*2*GRAVITY, 0.5)

#define ANIM_JUMP 110.0, -45.0, h_head, 0.0, 45.0, -110.0
#define ANIM_WALK1 45.0, -45.0, h_head, 0.0, 45.0, -45.0
#define ANIM_WALK2 -45.0, 45.0, h_head, 0.0, -45.0, 45.0
#define ANIM_STAND 0.0, 0.0, h_head, 0.0, 0.0, 0.0

#define ITEM_DUR 18000
#define HOME_X 0.5
#define HOME_Y 65.0

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
    int hard;
} block_t;

typedef struct map
{
    lld_t *map;
    int size_l;
    int size_r;
    char new;
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
pos_t *mpos(float x, float y, float a);

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
    BANNER1 = 6,
    BANNER2 = 7,
    BANNER3 = 8,
    BANNER4 = 9,
    BANNER5 = 10,
    BOW = 11,
    BOW_ARROW = 12,
    BOWL = 13,
    BRICK = 14,
    BUCKET = 15,
    BUCKET_LAVA = 16,
    BUCKET_WATER = 17,
    CARROT = 18,
    CLAY_BALL = 19,
    FISH_RAW = 20,
    FISH = 21,
    BOAR = 22,
    FOX = 23,
    COOKIE = 24,
    COTTON_BLUE = 25,
    COTTON_GREEN = 26,
    COTTON_RED = 27,
    COTTON_WHITE = 28,
    FISHING_ROAD = 29,
    BOOK = 30,
    MUSHROOM = 31,
    DIAMOND = 32,
    COAL = 33,
    GOLD = 34,
    IRON = 35,
    PICKAXE_WOOD = 36,
    PICKAXE_STONE = 37,
    PICKAXE_IRON = 38,
    PICKAXE_DIAMOND = 39,
    BOAR_RAW = 40,
    FOX_RAW = 41,
    SEED = 42,
    SHOVEL_WOOD = 43,
    SHOVEL_STONE = 44,
    SHOVEL_IRON = 45,
    SHOVEL_DIAMOND = 46,
    SOUP = 47,
    STICK = 48,
    SWORD_WOOD = 49,
    SWORD_STONE = 50,
    SWORD_IRON = 51,
    SWORD_DIAMOND = 52,
    TORCH = 53,
    WHEAT = 54
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
    int maxhp;
    int select;
    int **inventory;
} player_t;

typedef struct entity
{
    float x;
    float y;
    float vx;
    float vy;
    char wall_l;
    char wall_r;
    int anim_sate;
    char floor;
    animator_t *anim;
    int hp;
    int type;
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

typedef struct arrow
{
    float x;
    float y;
    float vx;
    float vy;
    int type;
} arrow_t;

typedef struct body
{
    texture_t *head;
    texture_t *body;
    texture_t *arm;
    sfSprite *arm_l;
    texture_t *leg;
    sfSprite *leg_l;
}body_t;

typedef struct game
{
    lld_t *players;
    lld_t *entities;
    lld_t *items;
    lld_t *proj;
    map_t *map;
    texture_t *it;
    texture_t *bl;
    texture_t *ef;
    texture_t *bar;
    texture_t *inv;
    texture_t *choose;
    texture_t *hud;
    body_t *player;
    body_t *skeleton;
    body_t *zombie;
    body_t *alien;
    int quest;
    int select;
    int jumpb;
    int shield;
    int speed;
    int attack;
    int nofall;
    int skills;
    sfVector2i old;
} game_t;

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
    int type;
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
    text_t *txt;
    int menu;
    sfVideoMode mode;
    lld_t *particles;
    sfClock *clock;
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
    void (*func)(win_t *win, int *returned);
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
void button_event(win_t *win, button_t **buttons, sfEvent event, int *ret);
void end_free(win_t *win, button_t **buttons);
void change_icon(sfRenderWindow *window);
void replace_mouse(win_t *win);
void **init_buttons(void **buttons);
int launch_game(void);
int event_manager(win_t *win, button_t **button, sfEvent event, int *returned);
void scene_manager(win_t *win, button_t **buttons, int *returned);
void btn_quit(win_t *win, int *returned);
void btn_skinr(win_t *win, int *returned);
void btn_skinl(win_t *win, int *returned);
void btn_play(win_t *win, int *returned);
void btn_opt(win_t *win, int *returned);
void btn_back(win_t *win, int *returned);
void btn_help(win_t *win, int *returned);
void btn_resume(win_t *win, int *returned);
void btn_return(win_t *win, int *returned);
void btn_quit_game(win_t *win, int *returned);
void btn_reset(win_t *win, int *returned);
void btn_quests(win_t *win, int *returned);
void btn_skills(win_t *win, int *returned);
void btn_complete(win_t *win, int *returned);

void draw_home(win_t *win);
void draw_quest(win_t *win);
void draw_param(win_t *win);
void draw_skills(win_t *win);
void draw_game(win_t *win);
void draw_dialog(win_t *win);
void free_game(win_t *win);

int quest_one(win_t *win);
int quest_two(win_t *win);
int quest_three(win_t *win);
int quest_four(win_t *win);

int **init_inventory();
void free_inventory(int **inventory);
int take_inv(int **inv, int type, int item, int nb);
int give_inv(int **inventory, int type, int item, int nb);
void draw_inv(win_t *win);
void inventory_events(win_t *win, sfEvent event);
int same(int first, int second);
void draw_quantity(win_t *win, sfVector2f pos, int nb);
void add_max(int *item, int *to_add);
#define GRAVITY 10

int engine(game_t *game, win_t *win);

int player_add_player(game_t *game);
animator_t *init_player_animator(game_t *game);
int flr(float x);

game_t *load_game();
int save_game(game_t *game);
int engine_create_item(game_t *game, float x, float y, ...);
void delete_save(void);
body_t *init_body(char *name);

void free_map(map_t *map);
void draw_item(win_t *win, sfIntRect rect, sfVector2f pos, int thing);
void mob(win_t *win);
void draw_entity(win_t *win);
void animate_player(win_t *win);
int mob_zombie_add(game_t *game, sfVector2f pos);
float player_head(win_t *win, player_t *player);
animator_t *init_zombie_animator(game_t *game);

texture_t *init_texture(char *path);
void draw_hud(win_t *win);

typedef struct world
{
    int x;
    int y;
    sfRenderWindow *cam;
    float *mat_start;
    char **sun_grid;
    char mv;
    framebuffer_t *cam_buf;
    sfRenderWindow *edi;
    float **mesh;
    framebuffer_t *edi_buf;
    int edi_x;
    int edi_y;
    int brush;
    int brush_type;
    button_t *edi_buttons;
    sfText *txt;
    sfFont *font;
    int buton_nb;
    float sun;
    int cs;
} world_t;

block_t blockss[61][1];

world_t **main_cam(sfRenderWindow *win);
int mob_skeleton_add(game_t *game, sfVector2f pos);
float perlin(float x, float y);
animator_t *init_skeleton_animator(game_t *game);

typedef struct particle
{
    float x;
    float y;
    float vx;
    float vy;
    float a;
    float va;
    int life;
    sfSprite *sprite;
} particle_t;

void particle_add(lld_t *p_lld, ...);
lld_t *particle_array();
void particle_for_block(win_t *win, int item, float x, float y);
void particles_draw(win_t *win, lld_t *p_lld);

void particle_free(win_t *win);
void breaking(win_t *win, block_t ***block, sfVector2f pos);
int check_assets(void);
void fight(win_t *win, player_t *player);

void player_manager(win_t *win);
void drop_inventory(game_t *game, int **inv);
void clear_inventory(int **inventory);
int mob_pnj_add(game_t *game, sfVector2f pos);
void mob_pnj(win_t *win, entity_t *pnj);
animator_t *init_pnj_animator(game_t *game);

void free_texture(texture_t *texture);
void free_body(body_t *body);
void free_game_b(game_t *cpy);

void btn_jumpb(win_t *win, int *returned);
void btn_health(win_t *win, int *returned);
void btn_shield(win_t *win, int *returned);
void btn_nofall(win_t *win, int *returned);
void btn_speed(win_t *win, int *returned);
void btn_attack(win_t *win, int *returned);
#endif
