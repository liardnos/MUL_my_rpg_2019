/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw man
*/

#include "rpg.h"

void draw_man(win_t *win)
{
    sfVector2f pos = {600, 500};

    sfText_setPosition(win->txt->text, pos);
    sfText_setCharacterSize(win->txt->text, 32);
    sfText_setString(win->txt->text, "Need help for keys ? goto ./my_rpg -h");
    sfRenderWindow_drawText(win->win, win->txt->text, 0);
    pos.y += 100;
    sfText_setPosition(win->txt->text, pos);
    sfText_setString(win->txt->text,
    "To start quests talk to the alien (T Key)");
    sfRenderWindow_drawText(win->win, win->txt->text, 0);
}
