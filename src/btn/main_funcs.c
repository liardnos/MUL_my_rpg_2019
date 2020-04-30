/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Main funcs of btns
*/

#include "menu.h"
#include "rpg.h"

void btn_quit(win_t *win)
{
    sfRenderWindow_close(win->win);
}

// FIXME EDIT THIS

void btn_play(win_t *win)
{
    game_t *cpy;

    win->game = load_game();
    if (!win->game){
        win->game = malloc(sizeof(game_t));
        cpy = win->game;
        cpy->map = generate_map();
        cpy->players = lld_init();
        player_add_player(cpy);
        player_t *p = cpy->players->next->data;
        p->inventory = init_inventory();
    }
    cpy = win->game;
    player_t *p = cpy->players->next->data;
    p->anim = init_player_animator();
    cpy->entities = lld_init();
    cpy->items = lld_init();
    cpy->bl = malloc(sizeof(texture_t));
    cpy->it = malloc(sizeof(texture_t));
    cpy->it->tex = sfTexture_createFromFile("assets/itemsx64.png", 0);
    cpy->bl->tex = sfTexture_createFromFile("assets/tilesx64.png", 0);
    cpy->it->sprite = sfSprite_create();
    cpy->bl->sprite = sfSprite_create();
    sfSprite_setTexture(cpy->it->sprite, cpy->it->tex, sfTrue);
    sfSprite_setTexture(cpy->bl->sprite, cpy->bl->tex, sfTrue);
    engine_create_item(cpy, 0, 0, 1, 1, 100000, 32);
    win->menu = 3;

}
