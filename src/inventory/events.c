/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Inventory events
*/

#include "rpg.h"

int is_well_placed(win_t *win, sfVector2i pos)
{
    sfVector2i try = {0, 0};

    for (int y = 0; y < 3; y++) {
        try.y = (int) (557 + 64 * y + (y == 3 ? 33 : 0));
        for (int x = 0; x < 9; x++) {
            try.x = (int) (648 + 71 * x);
            if (pos.x >= try.x && pos.x <= try.x + 34 &&
                pos.y >= try.y && pos.y <= try.y + 34)
                return (1);
        }
    }
    return (0);
}

void inventory_events(win_t *win, sfEvent event)
{
    sfVector2i pos = sfMouse_getPosition((sfWindow *)win->win);

    if (is_well_placed(win, pos) && event.type == sfEvtMouseButtonPressed);
}
