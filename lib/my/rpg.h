/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Header for RPG
*/

#ifndef rpg_h
#define rpg_h

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

typedef struct ply_s
{
    int life;
    int skin;
    int moving;
    sfVector2f pos;
    sfT
}ply_t;

typedef unsigned long int u64;

#define E 2.71828182846
#define PI 3.14159265359

typedef struct player
{
    float x;
    float y;
    animator_t *anim;
} player_t;

typedef struct entity
{
    float x;
    float y;
    int hp;
} entity_t;

typedef struct item
{
    float x;
    float y;
    int type;
    int
} item_t;

//items & blocks

typedef struct game
{
    player_t *players;
    lld_t *entities;
    lld_t *items;
    map_t *map;
    texture_t *items;
    texture_t *blocks;
} game_t;

#endif
