/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Skills menu
*/

#include "rpg.h"

void draw_skill(win_t *win, sfIntRect rect, sfVector2f pos, char *name)
{

}

void draw_skill__cur(win_t *win, sfVector2f pos, int nb, int max)
{

}

void draw_skills(win_t *win)
{
    sfVector2f pos = {534, 371};

    sfSprite_setPosition(win->game->hud->sprite, pos);
    sfRenderWindow_drawSprite(win->win, win->game->hud->sprite, 0);
}
