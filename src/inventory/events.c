/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Inventory events
*/

#include "rpg.h"

int is_well_placed(win_t *win, sfVector2i *pos)
{
    sfVector2i try = {0, 0};

    for (int y = 0; y < 4; y++) {
        try.y = (int) (557 + 64 * y + (y == 3 ? 33 : 0));
        for (int x = 0; x < 9; x++) {
            try.x = (int) (648 + 71 * x);
            if (pos->x >= try.x && pos->x <= try.x + 34 &&
                pos->y >= try.y && pos->y <= try.y + 34) {
                pos->x = x, pos->y = y;
                return (1);
            }
        }
    }
    return (0);
}

void add_on_stack(int **inv, game_t *game, sfVector2i pos)
{
    if ((game->select % 100) + (inv[pos.y][pos.x] % 100) <= 64) {
        inv[pos.y][pos.x] += game->select % 100;
        inv[game->old.y][game->old.x] = 0;
        game->select = 0;
    } else {
        inv[game->old.y][game->old.x] -= ((inv[pos.y][pos.x] % 100) - 64) * -1;
        inv[pos.y][pos.x] += ((inv[pos.y][pos.x] % 100) - 64) * -1;
        game->select = 0;
    }
}

void switch_properly(int **inv, game_t *game, sfVector2i pos)
{
    int temp;

    if (pos.x == game->old.x && pos.y == game->old.y) {
        game->select = 0;
        return;
    }
    temp = inv[pos.y][pos.x];
    if (same(inv[pos.y][pos.x], game->select)) {
        if (inv[pos.y][pos.x] % 100 < 64) {
            add_on_stack(inv, game, pos);
        } else {
            inv[pos.y][pos.x] = game->select;
            inv[game->old.y][game->old.x] = temp;
            game->select = 0;
        }
    } else {
        inv[pos.y][pos.x] = game->select;
        inv[game->old.y][game->old.x] = temp;
        game->select = 0;
    }
}

void inventory_events(win_t *win, sfEvent event)
{
    sfVector2i pos = sfMouse_getPosition((sfWindow *)win->win);
    player_t *ply = win->game->players->next->data;

    if (event.type == sfEvtMouseButtonPressed) {
        if (is_well_placed(win, &pos) && sfMouse_isButtonPressed(sfMouseLeft)) {
            win->game->select = ply->inventory[pos.y][pos.x];
            win->game->old.x = pos.x;
            win->game->old.y = pos.y;
        }
    }
    if (event.type == sfEvtMouseButtonReleased) {
        if (is_well_placed(win, &pos) && win->game->select != 0)
            switch_properly(ply->inventory, win->game, pos);
        else
            printf("Hello\n"),win->game->select = 0;
    }
}
