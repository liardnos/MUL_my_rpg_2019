/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** animator_main
*/

#include "rpg.h"

animator_t *init_pnj_animator(game_t *game)
{
    sfSprite_setOrigin(game->alien->head->sprite, alloc_vector2f(50, 50));
    sfSprite_setOrigin(game->alien->body->sprite, alloc_vector2f(22, 10));
    sfSprite_setOrigin(game->alien->arm_l, alloc_vector2f(14, -10));
    sfSprite_setOrigin(game->alien->arm->sprite, alloc_vector2f(14, -10));
    sfSprite_setOrigin(game->alien->leg_l, alloc_vector2f(14, -14));
    sfSprite_setOrigin(game->alien->leg->sprite, alloc_vector2f(14, -14));
    animator_t *me = animator_init();
    animator_addmenber(me, mpos(0, -11, 22.5), game->alien->arm_l);
    animator_addmenber(me, mpos(0, 10, 22.5), game->alien->leg_l);
    animator_addmenber(me, mpos(0, -15, 5), game->alien->head->sprite);
    animator_addmenber(me, mpos(0, 0, 0), game->alien->body->sprite);
    animator_addmenber(me, mpos(0, 10, -22.5), game->alien->leg->sprite);
    animator_addmenber(me, mpos(0, -11, -22.5), game->alien->arm->sprite);
    animator_setpos(me, mpos(1920/2, 1080/2, 0));
}
