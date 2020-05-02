/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** animator_main
*/

#include "rpg.h"

animator_t *init_player_animator(game_t *game)
{
    sfSprite_setOrigin(game->player->head->sprite, alloc_vector2f(32, 64));
    sfSprite_setOrigin(game->player->body->sprite, alloc_vector2f(22, 30));
    sfSprite_setOrigin(game->player->arm_l, alloc_vector2f(14, 0));
    sfSprite_setOrigin(game->player->arm->sprite, alloc_vector2f(14, 0));
    sfSprite_setOrigin(game->player->leg_l, alloc_vector2f(14, -14));
    sfSprite_setOrigin(game->player->leg->sprite, alloc_vector2f(14, -14));
    animator_t *me = animator_init();
    animator_addmenber(me, mpos(0, -11, 22.5), game->player->arm_l);
    animator_addmenber(me, mpos(0, 10, 22.5), game->player->leg_l);
    animator_addmenber(me, mpos(0, -15, 5), game->player->head->sprite);
    animator_addmenber(me, mpos(0, 0, 0), game->player->body->sprite);
    animator_addmenber(me, mpos(0, 10, -22.5), game->player->leg->sprite);
    animator_addmenber(me, mpos(0, -11, -22.5), game->player->arm->sprite);
    animator_setpos(me, mpos(1920/2, 1080/2, 0));
}
