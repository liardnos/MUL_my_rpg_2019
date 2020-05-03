/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** func for zombie
*/

#include <math.h>
#include "rpg.h"

void spawn_mod(win_t *win)
{
    static int spawn = 0;
    player_t *p = win->game->players->next->data;
    sfVector2f pos = {p->x + rand()%200-100, HOME_Y};

    if (win->game->quest > 2){
        spawn+= win->game->quest - 2;
        if (spawn > 3600){
            while (fabsf(pos.x-p->x) < 15)
                pos.x = p->x + rand()%100-50;
            rand() % 2 ? mob_zombie_add(win->game, pos, win->game->quest*2) : 0;
            rand() % 2 ? mob_skeleton_add(win->game, pos, win->game->quest) : 0;
            spawn = 0;
        }
    }
}

void spawn_mobs(win_t *win, int nb, int hp)
{
    player_t *p = win->game->players->next->data;
    sfVector2f pos = {p->x + rand()%200-100, HOME_Y};

    for (int i = 0; i < nb; i++){
        pos.x = p->x + rand()%200-100;
        while (fabsf(pos.x-p->x) < 15)
            pos.x = p->x + rand()%100-50;
        rand() % 2 ? mob_zombie_add(win->game, pos, win->game->quest*2) : 0;
        rand() % 2 ? mob_skeleton_add(win->game, pos, win->game->quest) : 0;
    }
}
