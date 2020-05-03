/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Skills menu
*/

#include "rpg.h"

void draw_skill(win_t *win, sfIntRect rect, sfVector2f pos, char *name)
{
    sfSprite_setTextureRect(win->game->ef->sprite, rect);
    sfSprite_setPosition(win->game->ef->sprite, pos);
    sfRenderWindow_drawSprite(win->win, win->game->ef->sprite, 0);
    sfText_setCharacterSize(win->txt->text, 22);
    pos.x += 50;
    pos.y += 30;
    sfText_setPosition(win->txt->text, pos);
    sfText_setString(win->txt->text, name);
    sfRenderWindow_drawText(win->win, win->txt->text, 0);
}

void draw_skill_cur(win_t *win, sfVector2f pos, int nb, char *max)
{
    char *str;
    char *strt;

    pos.x += pos.x > 800 ? 140 : 220;
    pos.y += 30;
    strt = my_nts(nb);
    str = my_strcat("(", strt), free(strt);
    strt = my_strcat(str, max), free(str);
    sfText_setString(win->txt->text, strt);
    sfText_setPosition(win->txt->text, pos);
    sfRenderWindow_drawText(win->win, win->txt->text, 0);
    free(strt);
}

void draw_skills(win_t *win)
{
    game_t *game = win->game;
    player_t *ply = win->game->players->next->data;
    sfVector2f pos = {534, 371};
    char *name[] = {"JumpBoost", "Health", "Resistance", "NoFall", "Speed",
    "Attack"};
    char *max[] = {"/3)", "/10)", "/5)", "/1)", "/5)", "/5)"};
    int value[6] = {game->jumpb, ply->maxhp, game->shield, game->nofall,
    game->speed, game->attack};
    sfIntRect rect = {0, 0, 64, 64};

    sfSprite_setPosition(win->game->hud->sprite, pos);
    sfRenderWindow_drawSprite(win->win, win->game->hud->sprite, 0);
    rect.left = 128, pos.x += 50, pos.y += 70;
    for (int x = 0; x < 6; x++) {
        draw_skill(win, rect, pos, name[x]);
        draw_skill_cur(win, pos, value[x], max[x]);
        rect.left += 64;
        pos.y += 64;
        x == 2 ? pos.y = 371 + 70, pos.x += 425 : 0;
    }
}
