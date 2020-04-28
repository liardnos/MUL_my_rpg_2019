/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Managers of draw & event
*/

#include "menu.h"
#include "my.h"

void event_manager(win_t *win, button_t **buttons, sfEvent event, int *returned)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(win->win);
    button_event(win, buttons, event);
}

void scene_manager(win_t *win, button_t **buttons, int *returned)
{
    !win->menu ? draw_home(win) : 0;
    button_main(win, (button_t **)buttons);
    replace_mouse(win);
}
