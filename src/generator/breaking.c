/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** breaking_block
*/
#include <math.h>
#include "rpg.h"

void breaking_b(win_t *win, block_t ***block, sfVector2f pos, block_t *b)
{
    static float status = 0;
    sfVector2i vec = sfMouse_getPosition((sfWindow *)win->win);
    player_t *p = win->game->players->next->data;
    if (p->inventory[3][p->select] / 100 % 100 >= PICKAXE_WOOD &&
    p->inventory[3][p->select] / 100 % 100 <= PICKAXE_DIAMOND &&
    p->inventory[3][p->select] /10000 % 10 == 2){
        if (vec.x < 0 || vec.y < 0 || vec.x > 1920 || vec.y > 1080) return;
        if (sfMouse_isButtonPressed(sfMouseLeft)){
            status += (p->inventory[3][p->select] / 100 % 100 + 1 - PICKAXE_WOOD) * 0.75;
            particle_for_block(win, b->type, p->x+(-pos.x + vec.x-1920/2)/64+1,
            p->y+(-pos.y+vec.y-1080/2)/64+1);
            if (status > b->hard && b->hard != -1){
                engine_create_item(win->game, p->x+(vec.x-1920/2)/64, p->y+(
                vec.y-1080/2)/64-0.25, 1, b->type, 18000, 1);
                block[(int)((vec.x+pos.x)/64)][(int)((vec.y+pos.y)/64)]
                = blockss[ICE], status = 0;
            }
        } else
            status = 0;
    }
}

void breaking(win_t *win, block_t ***block, sfVector2f pos)
{
    player_t *p = win->game->players->next->data;
    sfVector2i vec = sfMouse_getPosition((sfWindow *)win->win);
    if (vec.x < 0 || vec.y < 0 || vec.x > 1920 || vec.y > 1080) return;
    block_t *b = block[(int)((vec.x+pos.x)/64)][(int)((vec.y+pos.y)/64)];

    breaking_b(win, block, pos, b);
    if (sfMouse_isButtonPressed(sfMouseRight)){
        if (b->type == ICE && p->inventory[3][p->select]/10000 % 10 == 1){
            int type = p->inventory[3][p->select]/100%100;
            take_inv(p->inventory, 1, type, 1) ?
            block[(int)((vec.x+pos.x)/64)][(int)((vec.y+pos.y)/64)] =
            blockss[type] : 0;
        }
    }
}
