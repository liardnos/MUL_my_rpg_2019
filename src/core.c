/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Core of the rpg
*/

#include <stdlib.h>
#include "my.h"
#include "rpg.h"

//FIXME

void main_loop(int *returned, win_t *win, button_t **buttons)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(win->win)) {
        if (*returned == 84)
            return;
        sfRenderWindow_clear(win->win, sfBlack);
        while (sfRenderWindow_pollEvent(win->win, &event)) {
            if (!event_manager(win, buttons, event, returned))
                return;
        }
        //if (sfTime_asSeconds(sfClock_getElapsedTime(win->clock)) >= 1 / 120.0) {
        scene_manager(win, buttons, returned);
            //sfClock_restart(win->clock);
        //}
        player_manager(win);
        sfRenderWindow_display(win->win);
    }
}

int launch_game(void)
{
    int seed;
    void **buttons = 0;
    win_t *win;
    int returned = 0;

    if (!check_assets() || !(win = create_window(&returned, "Raftminec")) ||
    !(buttons = init_buttons(buttons)))
        return (84);
    win->game = 0;
    srand((unsigned int)(unsigned long int) &seed);
    change_icon(win->win);
    sfText_setFont(win->txt->text, win->txt->font);
    sfWindow_setFramerateLimit((sfWindow *) win->win, 60);
    main_loop(&returned, win, (button_t **)buttons);
    end_free(win, (button_t **)buttons);
    return (returned);
}
