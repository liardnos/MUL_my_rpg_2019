/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main for my_rpg
*/

#include <SFML/Graphics.h>
#include <stdlib.h>


#ifndef _rpg_h_
#define _rpg_h_
typedef unsigned long int u64;

float **create_mesh(int x1, int y2, int x, int y, int d);

#define E 2.71828182846
#define PI 3.14159265359
#define MAP_Y 256

typedef struct block {
    int type;
    sfColor color;
    char solid;
} block_t;

block_t **generate_line(int x, int d);
block_t *create_line(int x);
#endif
