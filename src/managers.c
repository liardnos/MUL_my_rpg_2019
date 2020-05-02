/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Managers of draw & event
*/

#include "my.h"
#include "rpg.h"

void keys_manager(win_t *win, sfEvent event)
{
    player_t *ply;

    sfKeyboard_isKeyPressed(sfKeyI) && win->menu == 3 ? win->menu = 5 : 0;
    sfKeyboard_isKeyPressed(sfKeyP) && win->menu == 3 ? win->menu = 6 : 0;
    if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEscape)) {
        win->menu == 3 ? win->menu = 4 : 0;
        win->menu == 5 ? win->menu = 3 : 0;
        win->menu == 6 ? win->menu = 3 : 0;
        win->menu == 7 ? win->menu = 6 : 0;
        win->menu == 8 ? win->menu = 6 : 0;
    }
    if (event.type == sfEvtMouseWheelScrolled && win->menu == 3) {
        sfMouseWheelEvent *event2 = (void *)(&event);
        ply = win->game->players->next->data;
        event2->x < 0 ? ply->select-- : ply->select++;
        ply->select < 0 ? ply->select = 8 : 0;
        ply->select %= 9;
    }
}

int event_manager(win_t *win, button_t **buttons, sfEvent event, int *returned)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(win->win);
    win->menu >= 3 && event.type == sfEvtMouseLeft ? win->menu = 4 : 0;
    win->menu == 5 ? inventory_events(win, event) : 0;
    keys_manager(win, event);
    button_event(win, buttons, event, returned);
    if (*returned != 0)
        return (0);
    return (1);
}

void scene_manager(win_t *win, button_t **buttons, int *returned)
{
    if (win->menu >= 3 && !win->game)
        return;
    !win->menu ? draw_home(win) : 0;
    win->menu >= 3 ? draw_game(win), draw_hud(win) : 0;
    win->menu == 5 ? draw_inv(win) : 0;
    win->menu == 6 ? draw_dialog(win) : 0;
    win->menu == 7 ? draw_quest(win) : 0;
    win->menu == 8 ? draw_skills(win) : 0;
    if (win->menu == 3) {
        engine(win->game, win);
        mob(win);
        particles_draw(win, win->particles);
    }
    button_main(win, (button_t **)buttons);
    replace_mouse(win);
}

void player_manager(win_t *win)
{
    player_t *ply = win->game->players->next->data;

    if (ply->hp <= 0) {
        drop_inventory(win->game, ply->inventory);
        ply->x = HOME_X;
        ply->y = HOME_Y;
        ply->hp = ply->maxhp;
    }
}
