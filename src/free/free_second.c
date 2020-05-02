/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Second file for free
*/

#include "rpg.h"

void free_body(body_t *body)
{
    free_texture(body->arm);
    free_texture(body->leg);
    free_texture(body->head);
    free_texture(body->body);
    sfSprite_destroy(body->arm_l);
    sfSprite_destroy(body->leg_l);
    free(body);
}
