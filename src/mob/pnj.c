/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** func for png
*/

#include <math.h>
#include "rpg.h"

int mob_pnj_add(game_t *game, sfVector2f pos)
{
    entity_t *pnj = malloc(sizeof(entity_t);
    if (!pnj) return (0);

    zomb->x = 10;
    zomb->y = HOME_X;
    zomb->hp = 200000000;
    zomb->floor = 0;
    zomb->vx = 0;
    zomb->vy = 0;
    zomb->type = 3;
    zomb->anim_sate = 0;
    png->anim = animator_png_create();
    lld_insert(game->entities, 0, pnj);
}

int mob_zombie_add(game_t *game, sfVector2f pos)
{
    entity_t *zomb = malloc(sizeof(entity_t));

    if (!zomb) return (0);
    zomb->x = pos.x;
    zomb->y = pos.y;
    zomb->anim = init_zombie_animator();
    lld_insert(game->entities, 0, zomb);
}
