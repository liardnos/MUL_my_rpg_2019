/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** generator for my_rpg
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rpg.h"
#include "my.h"
#include "gen.h"

//FIXME

void breaking(win_t *win, block_t ***block, sfVector2f pos)
{
    static float status = 0;
    player_t *p = win->game->players->next->data;
    sfVector2i vec = sfMouse_getPosition((sfWindow *)win->win);
    if (vec.x < 0 || vec.y < 0 || vec.x > 1920 || vec.y > 1080) return;
    block_t *b = block[(int)((vec.x+pos.x)/64)][(int)((vec.y+pos.y)/64)];

    if (sfMouse_isButtonPressed(sfMouseLeft)){
        status += 1;
        if (status > b->hard && b->hard != -1){
            engine_create_item(win->game, p->x+(vec.x-1920/2)/64, p->y+(vec.y-1080/2)/64-0.25, 1, b->type, 18000, 1);
            block[(int)((vec.x+pos.x)/64)][(int)((vec.y+pos.y)/64)] = blockss[ICE];
            status = 0;
        }
    } else
        status = 0;
    if (sfMouse_isButtonPressed(sfMouseRight)){
        if (b->type == ICE && p->inventory[3][p->select]/10000 % 10 == 1){
            int type = p->inventory[3][p->select]/100%100;
            take_inv(p->inventory, 1, type, 1) ?
            block[(int)((vec.x+pos.x)/64)][(int)((vec.y+pos.y)/64)] = blockss[type] : 0;
        }
    }
}

block_t *calc_block(float height)
{
    height += 50;
    block_t *a = 0;
    height > 0 ? a = blockss[ICE] : 0;
    height <= 0 && height >= -20  ? a = blockss[DIRT] : 0;
    height < -20 ? a = blockss[STONE] : 0;
    srand((u64)height*100);
    (u64)a->type == STONE && !(((u64)height % 50) / 4) ? a = blockss[ORE_COAL] : 0;
    ((u64)a->type == STONE && !(rand() % 50)) ? a = blockss[ORE_IRON] : 0;
    ((u64)a->type == STONE && !(rand() % 100)) ? a = blockss[ORE_DIAMOND] : 0;
    return (a);
}

void generate_line_post(block_t **blocks)
{
    for (int i = 1; blocks[i+1]; i++)
        if (blocks[i]->type == DIRT && blocks[i-1]->type == ICE)
            blocks[i] = blockss[GRASS];
}

block_t **generate_line(int x, int d)
{
    block_t **line = malloc(sizeof(block_t *) * (MAP_Y + 2));
    float line_f[MAP_Y];
    int y = 0;

    line++;
    x < 0 ? x = 1.1*pow(2, d)-x : 0;
    line[MAP_Y] = 0;
    line[-1] = 0;
    for (; y < MAP_Y; y++){
        line_f[y] = (80 - y*2);
        for (int d_nb = 0; d_nb < d; d_nb++)
            line_f[y] += perlin((float)x/(1.1*pow(2, d_nb)), (float)y/(1.1*pow(2, d_nb)))*pow(2, d_nb);
    }
    line[y] = 0;
    for (y = 0; y < MAP_Y; y++)
        line[y] = calc_block(line_f[y]);
    generate_line_post(line);
    return (line);
}

map_t *generate_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    if (!map)
        return (0);
    map->map = lld_init();
    map->size_l = 0;
    map->size_r = 0;
    map->new = 1;
    lld_insert(map->map, 0, generate_line(0, 6));
    return (map);
}

block_t **generate_getcolum(map_t *m, int x)
{
    static int here_p = 0;
    static lld_t *here = 0; m->new ? m->new = 0, here = m->map->next, here_p = -m->size_l : 0;

    while (x != here_p){
        if (x > here_p){
            here_p++;
            here->next == 0 ? lld_insert(m->map, (u64)m->map->data, generate_line(here_p, 6)), m->size_r++ : 0;
            here = here->next;
        } else {
            here_p--;
            here->prev == 0 ? lld_insert(m->map, 0, generate_line(here_p, 6)), m->size_l++ : 0;
            here = here->prev;
        }
    }
    return (here->data);
}

block_t ***generator_getmap(map_t *map, sfIntRect *rect)
{
    block_t ***block = malloc(sizeof(block_t **) * (rect->width+2));

    if (!block)
        return (0);
    block++;
    block[-1] = 0;
    block[rect->width] = 0;
    for (int i = 0; i < rect->width; i++){
        block[i] = generate_getcolum(map, rect->left+i)+rect->top;
    }
    return (block);
}
