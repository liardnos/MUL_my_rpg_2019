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

//FIXME
//id color solide pos
const block_t blockss[8][1] = {
    {-1, {0x6A, 0x0D, 0xAD, 255}, 0, 0},
    {STONE, {136, 140, 141, 255}, 1, 1},   //stone
    {DIRT, {101, 53, 20, 255}, 1, 2},     //dirt
    {-1, {135, 206, 235, 255}, 0, 3},    //air
    {ORE_COAL, {50, 50, 50, 255}, 1, 4}, //coal
    {ORE_IRON, {132, 125, 115, 255}, 1, 5}, //iron
    {ORE_DIAMOND, {185, 242, 255, 255}, 1, 6}, //diamond
    {0}
};

float lerp(float a, float b, float w) {
    return (1.0 - w)*a + w*b;
}

float ***grid_grad(int x, int y)
{
    float ***grad = malloc(sizeof(float *) * (x+1));

    srand(0);
    for (int i = 0; i < x; i++){
        grad[i] = malloc(sizeof(float *) * (y+1));
        int ii = 0;
        for (; ii < y; ii++){
            grad[i][ii] = malloc(sizeof(float) * 2);
            grad[i][ii][0] = ((rand()%5000)/2500.0-1);
            grad[i][ii][1] = ((rand()%5000)/2500.0-1);
        }
        grad[i][ii] = 0;
    }
    grad[y] = 0;
    return (grad);
}

float dotGridGradient(int ix, int iy, float x, float y)
{
    static float ***grad = 0;

    if (!grad)
        grad = grid_grad(128, 128);
    float dx = x - (float)ix;
    float dy = y - (float)iy;

    return (dx*grad[iy%128][ix%128][0] + dy*grad[iy%128][ix%128][1]);
}

float perlin(float x, float y)
{
    int x0 = (int)x;
    int x1 = x0 + 1;
    int y0 = (int)y;
    int y1 = y0 + 1;
    float sx = x - (float)x0;
    float sy = y - (float)y0;
    float n0, n1, ix0, ix1, value;
    n0 = dotGridGradient(x0, y0, x, y);
    n1 = dotGridGradient(x1, y0, x, y);
    ix0 = lerp(n0, n1, sx);
    n0 = dotGridGradient(x0, y1, x, y);
    n1 = dotGridGradient(x1, y1, x, y);
    ix1 = lerp(n0, n1, sx);
    value = lerp(ix0, ix1, sy);
    return value;
}

block_t *calc_block(float height)
{
    height += 50;
    block_t *a = 0;
    height > 0 ? a = blockss[3] : 0;
    height <= 0 && height >= -20  ? a = blockss[2] : 0;
    height < -20 ? a = blockss[1] : 0;
    srand(height*100);
    (u64)a->type == 1 && !((u64)height % 50 / 4) ? a = blockss[4] : 0;
    ((u64)a->type == 1 && (rand() % 50) == 0) ? a = blockss[5] : 0;
    ((u64)a->type == 1 && (rand() % 100) == 0) ? a = blockss[6] : 0;
    return (a);
}

block_t **generate_line(int x, int d)
{
    block_t **line = malloc(sizeof(block_t *) * (MAP_Y + 2));
    line++;
    float line_f[MAP_Y];
    int y = 0;

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
    lld_insert(map->map, 0, generate_line(0, 6));
    return (map);
}

block_t **generate_getcolum(map_t *m, int x)
{
    static int here_p = 0;
    static lld_t *here = 0; !here ? here = m->map->next, here_p = -m->size_l : 0;

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

void free_map(map_t *map)
{
    for (lld_t *mv = map->map->next; mv; mv = mv->next)
        free(mv->data-sizeof(block_t *));
    lld_free(map->map);
    free(map);
}


//save and load

map_t *load_map(void)
{
    map_t *map = malloc(sizeof(map_t));
    int fd = open("save/map", O_RDONLY);
    if (fd < 0) return (0);
    map->map = lld_init();
    if (read(fd, &map->size_l, sizeof(int)) != sizeof(int)) return (0);
    if (read(fd, &map->size_r, sizeof(int)) != sizeof(int)) return (0);
    int buf[MAP_Y];
    int check_some = 0;
    for (int i = -map->size_l; i <= map->size_r; i++){
        block_t **block = malloc(sizeof(block_t *)*(MAP_Y+2));
        block[0] = 0, block[MAP_Y+1] = 0, block++;
        if (read(fd, buf, sizeof(int)*MAP_Y) != sizeof(int)*MAP_Y);
        for (int j = 0; j < MAP_Y; j++)
            check_some += buf[j], block[j] = blockss[buf[j]];
        lld_insert(map->map, (u64)map->map->data, block);
    }
    int check_some2;
    read(fd, &check_some2, sizeof(int));
    close(fd);
    if (check_some2 != check_some) return (0);
    return (map);
}

player_t *load_player(void)
{
    int fd = open("save/player", O_RDONLY);
    if (fd < 0) return (0);
    player_t *p = malloc(sizeof(player_t));
    if (!p) return (0);
    p->floor = 0;
    p->inventory = init_inventory();
    read(fd, &p->x, sizeof(float)) != sizeof(float) ? (p = 0) :
    read(fd, &p->y, sizeof(float)) != sizeof(float) ? (p = 0) :
    read(fd, &p->vx, sizeof(float)) != sizeof(float) ? (p = 0) :
    read(fd, &p->vy, sizeof(float)) != sizeof(float) ? (p = 0) :
    read(fd, &p->hp, sizeof(int)) != sizeof(int) ? (p = 0) :
    read(fd, p->inventory[-1], sizeof(int)*4) != sizeof(int)*4 ? (p = 0) :
    read(fd, p->inventory[0], sizeof(int)*9) != sizeof(int)*9 ? (p = 0) :
    read(fd, p->inventory[1], sizeof(int)*9) != sizeof(int)*9 ? (p = 0) :
    read(fd, p->inventory[2], sizeof(int)*9) != sizeof(int)*9 ? (p = 0) :
    read(fd, p->inventory[3], sizeof(int)*9) != sizeof(int)*9 ? (p = 0) : 0;
    close(fd);
    return (p);
}

game_t *load_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    if (!game) return (0);
    game->players = lld_init();
    my_printf("[RM] loading player...\n");
    player_t *player = load_player();
    if (!player) return (0);
    lld_insert(game->players, 0, player);
    my_printf("[RM] loading map...\n");
    game->map = load_map();
    if (!game->map) return (0);
    my_printf("[RM] load completed\n");
    return (game);
}

int save_map(map_t *map)
{
    int fd = open("save/map", O_TRUNC | O_CREAT | O_WRONLY, 7+7*8+7*8*8);

    int check_some = 0;
    if (fd < 0) return (0);
    write(fd, &map->size_l, sizeof(int));
    write(fd, &map->size_r, sizeof(int));
    for (lld_t *mv = map->map->next; mv; mv = mv->next){
        block_t **block = mv->data;
        for (int i = 0; i < MAP_Y; i++){
            check_some += block[i]->id;
            write(fd, &block[i]->id, sizeof(int));
        }
    }
    write(fd, &check_some, sizeof(int));
    close(fd);
    my_printf("[RM] map saved\n");
}

int save_player(player_t *p)
{
    int fd = open("save/player", O_TRUNC | O_CREAT | O_WRONLY, 7+7*8+7*8*8);
    if (fd < 0) return (0);
    write(fd, &p->x, sizeof(float));
    write(fd, &p->y, sizeof(float));
    write(fd, &p->vx, sizeof(float));
    write(fd, &p->vy, sizeof(float));
    write(fd, &p->hp, sizeof(int));
    write(fd, p->inventory[-1], sizeof(int)*4);
    write(fd, p->inventory[0], sizeof(int)*9);
    write(fd, p->inventory[1], sizeof(int)*9);
    write(fd, p->inventory[2], sizeof(int)*9);
    write(fd, p->inventory[3], sizeof(int)*9);
    close(fd);
    my_printf("[RM] player saved\n");
}

int save_game(game_t *game)
{
    my_printf("[RM] saving map...\n");
    save_map(game->map);
    my_printf("[RM] saving player...\n");
    save_player(game->players->next->data);
    my_printf("[RM] game saved\n");
    return (1);
}

void delete_save(void)
{
    int fd = open("save/player", O_TRUNC | O_CREAT | O_WRONLY, 7+7*8+7*8*8);
    write(0, "this save as been delete", 24);
    close(fd);
}
