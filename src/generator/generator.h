/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main for my_rpg
*/

#include <SFML/Graphics.h>
#include <stdlib.h>


#ifndef _generator_h_
#define _generator_h_
typedef unsigned long int u64;

#define E 2.71828182846
#define PI 3.14159265359
#define MAP_Y 256

typedef struct block {
    int type;
    sfColor color;
    char solid;
} block_t;

typedef struct map
{
    lld_t *map;
    int size_l;
    int size_r;
} map_t;


block_t **generate_line(int x, int d);
lld_t *generate_getcolum(map_t *map, int x);
map_t *generate_map();
block_t ***generator_getmap(map_t *map, sfIntRect *rect);

#endif
