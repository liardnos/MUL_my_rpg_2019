/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Draw inventory
*/

#include "rpg.h"

// FIXME

void draw_inv(win_t *win)
{
    player_t *ply = win->game->players->next->data;
    sfVector2f pos = {650, 412};
    sfIntRect rect = {0, 0, 64, 64};

    for (int y = 0; ply->inventory[y]; y++) {
        for (int x = 0; x < 9; x++) {
            rect.left = ply->inventory[y][x] / 100 % 100;
            pos.x = 650 + 64 * x;
            if (ply->inventory[y][x] != 0 && ply->inventory[y][x] / 10000 == 1) {
                sfSprite_setTextureRect(win->game->bl->sprite, rect);
                sfSprite_setPosition(win->game->bl->sprite, pos);
                sfRenderWindow_drawSprite(win->win, win->game->bl->sprite, 0);
            }
            if (ply->inventory[y][x] != 0 && ply->inventory[y][x] / 10000 == 2) {
                sfSprite_setTextureRect(win->game->it->sprite, rect);
                sfSprite_setPosition(win->game->it->sprite, pos);
                sfRenderWindow_drawSprite(win->win, win->game->it->sprite, 0);
            }
        }
        pos.y = 412 + 64 * y;
    }
}

/*
my_rpg #&> valgrind_log
==21132== Memcheck, a memory error detector
==21132== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==21132== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==21132== Command: ./my_rpg
==21132==
==21132== Warning: noted but unhandled ioctl 0x6458 with no size/direction hints.
==21132==    This could cause spurious value errors to appear.
==21132==    See README_MISSING_SYSCALL_OR_IOCTL for guidance on writing a proper wrapper.
==21132== Conditional jump or move depends on uninitialised value(s)
==21132==    at 0x40294B: draw_inv (inventory.c:18)
==21132==    by 0x4017CB: scene_manager (managers.c:25)
==21132==    by 0x40140A: main_loop (core.c:28)
==21132==    by 0x401506: launch_game (core.c:48)
==21132==    by 0x4016A3: main (main.c:25)
==21132==  Uninitialised value was created by a heap allocation
==21132==    at 0x483880B: malloc (vg_replace_malloc.c:309)
==21132==    by 0x405D8B: init_inventory (init_free.c:14)
==21132==    by 0x402A63: btn_play (main_funcs.c:30)
==21132==    by 0x404C39: button_click (events.c:17)
==21132==    by 0x404DB4: button_event (events.c:38)
==21132==    by 0x401769: event_manager (managers.c:18)
==21132==    by 0x4013D4: main_loop (core.c:26)
==21132==    by 0x401506: launch_game (core.c:48)
==21132==    by 0x4016A3: main (main.c:25)
==21132==
==21132== Use of uninitialised value of size 8
==21132==    at 0x40271C: draw_inv (inventory.c:20)
==21132==    by 0x4017CB: scene_manager (managers.c:25)
==21132==    by 0x40140A: main_loop (core.c:28)
==21132==    by 0x401506: launch_game (core.c:48)
==21132==    by 0x4016A3: main (main.c:25)
==21132==  Uninitialised value was created by a heap allocation
==21132==    at 0x483880B: malloc (vg_replace_malloc.c:309)
==21132==    by 0x405D8B: init_inventory (init_free.c:14)
==21132==    by 0x402A63: btn_play (main_funcs.c:30)
==21132==    by 0x404C39: button_click (events.c:17)
==21132==    by 0x404DB4: button_event (events.c:38)
==21132==    by 0x401769: event_manager (managers.c:18)
==21132==    by 0x4013D4: main_loop (core.c:26)
==21132==    by 0x401506: launch_game (core.c:48)
==21132==    by 0x4016A3: main (main.c:25)
==21132==
==21132== Invalid read of size 4
==21132==    at 0x40271C: draw_inv (inventory.c:20)
==21132==    by 0x4017CB: scene_manager (managers.c:25)
==21132==    by 0x40140A: main_loop (core.c:28)
==21132==    by 0x401506: launch_game (core.c:48)
==21132==    by 0x4016A3: main (main.c:25)
==21132==  Address 0x2073656c69665f6c is not stack'd, malloc'd or (recently) free'd
==21132==
==21132==
==21132== Process terminating with default action of signal 11 (SIGSEGV): dumping core
*/
