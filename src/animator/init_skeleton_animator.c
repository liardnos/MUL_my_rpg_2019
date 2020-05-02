/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** animator_main
*/

#include "rpg.h"

animator_t *init_skeleton_animator(game_t *game)
{
    sfSprite_setOrigin(game->skeleton->head->sprite, alloc_vector2f(32, 64));
    sfSprite_setOrigin(game->skeleton->body->sprite, alloc_vector2f(22, 30));
    sfSprite_setOrigin(game->skeleton->arm_l, alloc_vector2f(14, 0));
    sfSprite_setOrigin(game->skeleton->arm->sprite, alloc_vector2f(14, 0));
    sfSprite_setOrigin(game->skeleton->leg_l, alloc_vector2f(14, -14));
    sfSprite_setOrigin(game->skeleton->leg->sprite, alloc_vector2f(14, -14));
    animator_t *me = animator_init();
    animator_addmenber(me, mpos(0, -11, 22.5), game->skeleton->arm_l);
    animator_addmenber(me, mpos(0, 10, 22.5), game->skeleton->leg_l);
    animator_addmenber(me, mpos(0, -15, 5), game->skeleton->head->sprite);
    animator_addmenber(me, mpos(0, 0, 0), game->skeleton->body->sprite);
    animator_addmenber(me, mpos(0, 10, -22.5), game->skeleton->leg->sprite);
    animator_addmenber(me, mpos(0, -11, -22.5), game->skeleton->arm->sprite);
    animator_setpos(me, mpos(1920/2, 1080/2, 0));
}
