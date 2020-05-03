/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Quest menu
*/

#include "rpg.h"

const char *str[11][10] =
    {{
    "Welcome stranger !\0",
    "I've some quests for you,\0",
    "Press this Complete button !\0",
    "And I'll give you a sword !\0",
    0
    }, {
    "Hey you !\0",
    "Your sword is in your inventory,\0",
    "Try to switch it in your toolbar.\0",
    "And I'll give you a pickaxe !\0",
    0
    }, {
    "Now that you've the pickaxe,\0",
    "Please bring me coal ore (5).\0",
    "And you'll have a reward...\0",
    0
    }, {
    "Hey boiiii !\0",
    "I saw that you've a skill point !\0",
    "Try to spend it in skill menu.\0",
    "After this I'll give you a gift.\0",
    "(Bow & Arrows)\0",
    0
    }, {
    "Hola amigo !\0",
    "If you give me 20 stone !\0",
    "I'll give you stone tools.\0",
    "Seems legit ya ?\0",
    "What are you waiting for ?\0",
    0
    }, {
    "Heyyyyy !\0",
    "I need some iron (10),\0",
    "And I have some arrows (32)\0",
    "You want some ?\0",
    0
    }, {
    "Bonjour !\0",
    "Sometimes enemies spawn here,\0",
    "Can you kill some of them ? (> 3)\0",
    "Reward : Iron Sword !\0",
    0
    }, {
    "Wassup !\0",
    "If you bring me iron (32),\0",
    "I could give you an iron pickaxe.\0",
    0
    }, {
    "Hey !\0",
    "Have you seen ?\0",
    "If you kill mobs you win skill points !\0",
    "Gooo kill more (10)\0",
    "Reward : Diamond Sword\0",
    0
    }, {
    "Hey !\0",
    "I'm so poor !\0",
    "If you bring me 32 diamonds !\0",
    "I'll give you a diamond pickaxe\0",
    0
    }, {
    "Now, bring me a carrot !\0",
    "Go away !!\0",
    0
    }
    };

void draw_quest(win_t *win)
{
    sfVector2f pos = {534, 371};

    sfSprite_setPosition(win->game->hud->sprite, pos);
    sfRenderWindow_drawSprite(win->win, win->game->hud->sprite, 0);
    sfText_setCharacterSize(win->txt->text, 20);
    pos.y += 38;
    pos.x += 30;
    for (int y = 0; str[win->game->quest][y]; y++) {
        sfText_setString(win->txt->text, str[win->game->quest][y]);
        sfText_setPosition(win->txt->text , pos);
        sfRenderWindow_drawText(win->win, win->txt->text, 0);
        pos.y += 25;
    }
}
