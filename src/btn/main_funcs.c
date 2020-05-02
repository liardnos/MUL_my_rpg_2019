/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Main funcs of btns
*/

#include "menu.h"
#include "rpg.h"

void btn_quit(win_t *win, int *returned)
{
    my_printf("[RM] Exiting\n");
    sfRenderWindow_close(win->win);
}

int btn_play_init(win_t *win, int *returned, game_t *cpy)
{
    player_t *p = cpy->players->next->data;
    
    p->anim = init_player_animator();
    cpy->entities = lld_init();
    cpy->items = lld_init();
    cpy->bl = init_texture("assets/tilesx64.png");
    cpy->it = init_texture("assets/itemsx64.png");
    cpy->ef = init_texture("assets/effectsx64.png");
    cpy->bar = init_texture("assets/hud/bar.png");
    cpy->inv = init_texture("assets/hud/inventory.png");
    if (!cpy->bl || !cpy->it || !cpy->ef || !cpy->entities || !cpy->items
    || !cpy->inv || !cpy->bar || !cpy->players || !p->anim) {
        *returned = 84;
        return (0);
    }
    return (1);
}

void btn_play(win_t *win, int *returned)
{
    game_t *cpy;
    my_printf("[RM] Launch game\n");
    win->game = load_game();
    if (!win->game){
        win->game = malloc(sizeof(game_t));
        if (!win->game) {
            *returned = 84;
            return;
        }
        cpy = win->game;
        cpy->map = generate_map();
        cpy->players = lld_init();
        player_add_player(cpy);
    }
    cpy = win->game;
    if (!btn_play_init(win, returned, cpy)) {
        *returned = 84;
        return;
    }
    win->menu = 3;
    engine_create_item(cpy, 0, 0, 1, 1, 100000, 32);
    engine_create_item(cpy, 4, 0, 1, 1, 100000, 32);
    engine_create_item(cpy, 2, 0, 1, 4, 100000, 32);
    engine_create_item(cpy, 1, 0, 2, BOW, 100000, 1);
    engine_create_item(cpy, 2, 0, 2, ARROW, 100000, 32);
    sfVector2f pos = {0, 10};
    mob_skeleton_add(win->game, pos);
    mob_zombie_add(win->game, pos);
    pos.x = 10;
    mob_skeleton_add(win->game, pos);
    mob_zombie_add(win->game, pos);

}
