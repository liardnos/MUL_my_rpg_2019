/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Managers of draw & event
*/

#include "my.h"
#include "rpg.h"

void event_manager(win_t *win, button_t **buttons, sfEvent event, int *returned)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(win->win);
    sfKeyboard_isKeyPressed(sfKeyI) && win->menu == 3 ? win->menu = 5 : 0;
    sfKeyboard_isKeyPressed(sfKeyEscape) && win->menu == 3 ? win->menu = 4 : 0;
    sfKeyboard_isKeyPressed(sfKeyEscape) && win->menu == 5 ? win->menu = 3 : 0;
    button_event(win, buttons, event);
}

void scene_manager(win_t *win, button_t **buttons, int *returned)
{
    !win->menu ? draw_home(win) : 0;
    win->menu >= 3 ? draw_game(win) : 0;
    win->menu == 5 ? draw_inv(win) : 0;
    button_main(win, (button_t **)buttons);
    replace_mouse(win);
}
