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

int btn_play_init_two(win_t *win, game_t *cpy)
{
    player_t *p = cpy->players->next->data;

    cpy->player = init_body(win->config->type ? "female" : "male");
    cpy->skeleton = init_body("skeleton");
    cpy->zombie = init_body("zombie");
    cpy->alien = init_body("alien");
    p->anim = init_player_animator(cpy);
    if (!cpy->player || !cpy->zombie || !cpy->alien || !cpy->skeleton ||
    !p->anim)
        return (0);
}

int btn_play_init(win_t *win, int *returned, game_t *cpy)
{
    player_t *p = cpy->players->next->data;

    p->select = 0;
    cpy->entities = lld_init();
    cpy->items = lld_init();
    cpy->bl = init_texture("assets/tilesx64.png");
    cpy->it = init_texture("assets/itemsx64.png");
    cpy->ef = init_texture("assets/effectsx64.png");
    cpy->bar = init_texture("assets/hud/bar.png");
    cpy->inv = init_texture("assets/hud/inventory.png");
    cpy->hud = init_texture("assets/hud/quests_hud.png");
    cpy->choose = init_texture("assets/hud/choose_hud.png");
    if (!cpy->bl || !cpy->it || !cpy->ef || !cpy->entities || !cpy->items
    || !cpy->inv || !cpy->bar || !cpy->players || !cpy->choose ||
    !cpy->hud || !btn_play_init_two(win, cpy)) {
        *returned = 84;
        return (0);
    }
    return (1);
}

void btn_play_set_value(win_t *win)
{
    win->game->quest = 0;
    win->game->nofall = 0;
    win->game->jumpb = 0;
    win->game->attack = 0;
    win->game->speed = 0;
    win->game->shield = 0;
}

//FIXME

void btn_play(win_t *win, int *returned)
{
    my_printf("[RM] Launch game\n");
    win->game = load_game();
    if (!win->game){
        win->game = malloc(sizeof(game_t));
        if (!win->game) {
            *returned = 84;
            return;
        }
        win->game->map = generate_map();
        win->game->players = lld_init();
        btn_play_set_value(win);
        player_add_player(win->game);
    }
    if (!btn_play_init(win, returned, win->game)) {
        *returned = 84;
        return;
    }
    win->menu = 3;
    win->game->proj = lld_init();
    sfVector2f pnj = {0, 0};
    mob_pnj_add(win->game, pnj);
    engine_create_item(win->game, 0, 0, 1, 1, 100000, 32);
    engine_create_item(win->game, 4, 0, 1, 1, 100000, 32);
    engine_create_item(win->game, 2, 0, 1, 4, 100000, 32);
    engine_create_item(win->game, 1, 0, 2, BOW, 100000, 1);
    engine_create_item(win->game, 2, 0, 2, ARROW, 100000, 32);
    sfVector2f pos = {0, 10};
    mob_skeleton_add(win->game, pos);
    mob_zombie_add(win->game, pos);
    pos.x = 10;
    mob_skeleton_add(win->game, pos);
    mob_zombie_add(win->game, pos);

}
