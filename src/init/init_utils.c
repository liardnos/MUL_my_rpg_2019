/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Init generic things
*/

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
