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

    path = my_strcat(main_path, "arm");
    body->arm = init_texture(path);
    free(path);
    path = my_strcat(main_path, "body");
    body->body = init_texture(path);
    free(path);
    path = my_strcat(main_path, "head");
    body->head = init_texture(path);
    free(path);
    path = my_strcat(main_path, "leg");
    body->leg = init_texture(path);
    free(path);
}

body_t *init_body(char *name)
{
    body_t *body = malloc(sizeof(body_t));
    char *main_path;

    if (!body)
        return (0);
    main_path = my_strcat("assets/characters/", name);
    init_parts(body, main_path);
    return (body);
}
