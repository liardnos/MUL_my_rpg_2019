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


#define E 2.71828182846
#define PI 3.14159265359

typedef struct player
{
    float x;
    float y;
} player_t;

typedef struct entity
{
    float x;
    float y;
} entity_t;

typedef struct game
{
    player_t *players;

} game_t;


#endif
