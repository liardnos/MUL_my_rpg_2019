/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Init generic things
*/

#include "rpg.h"

texture_t *init_texture(char *path)
{
    texture_t *texture = malloc(sizeof(texture_t));

    if (!texture)
        return (0);
    texture->tex = sfTexture_createFromFile(path, 0);
    texture->sprite = sfSprite_create();
    if (!texture->tex || !texture->sprite)
        return (0);
    sfSprite_setTexture(texture->sprite, texture->tex, sfTrue);
    return (texture);
}

void init_parts(body_t *body, char *main_path)
{
    char *path;

    path = my_strcat(main_path, "_arm");
    body->arm = init_texture(path);
    free(path);
    path = my_strcat(main_path, "_body");
    body->body = init_texture(path);
    free(path);
    path = my_strcat(main_path, "_head");
    body->head = init_texture(path);
    free(path);
    path = my_strcat(main_path, "_leg");
    body->leg = init_texture(path);
    free(path);
}

void scale_body(body_t *body)
{
    sfVector2f scale = {0.5, 0.5};

    sfSprite_setScale(body->leg->sprite, scale);
    sfSprite_setScale(body->arm->sprite, scale);
    sfSprite_setScale(body->arm_l, scale);
    sfSprite_setScale(body->leg_l, scale);
    sfSprite_setScale(body->body->sprite, scale);
    sfSprite_setScale(body->head->sprite, scale);
}

body_t *init_body(char *name)
{
    body_t *body = malloc(sizeof(body_t));
    char *main_path;

    if (!body)
        return (0);
    main_path = my_strcat("assets/characters/", name);
    init_parts(body, main_path);
    body->leg_l = sfSprite_create();
    body->arm_l = sfSprite_create();
    if (!body->arm_l || !body->leg_l || !body->body || !body->head ||
    !body->leg || !body->arm)
        return (0);
    sfSprite_setTexture(body->leg_l, body->leg->tex, sfTrue);
    sfSprite_setTexture(body->arm_l, body->arm->tex, sfTrue);
    free(main_path);
    scale_body(body);
    return (body);
}
