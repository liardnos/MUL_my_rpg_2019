/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Init buttons
*/

#include "my.h"
#include "rpg.h"

void **init_buttons_five(void **buttons)
{
    char *path;
    void *res;

    path = my_strdup("assets/btn/add");
    res = add_button(1, &btn_skinr, path, set_attrib(0.674, 0.6, 81, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/rm");
    res = add_button(1, &btn_skinl, path, set_attrib(0.30, 0.6, 81, 78));
    buttons = add_to_array(buttons, res);
    return (buttons);
}

void **init_buttons_four(void **buttons)
{
    char *path;
    void *res;

    path = my_strdup("assets/btn/add");
    res = add_button(8, &btn_jumpb, path, set_attrib(0.478, 0.39, 81, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/add");
    res = add_button(8, &btn_health, path, set_attrib(0.478, 0.465, 81, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/add");
    res = add_button(8, &btn_shield, path, set_attrib(0.478, 0.54, 81, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/add");
    res = add_button(8, &btn_nofall, path, set_attrib(0.647, 0.39, 81, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/add");
    res = add_button(8, &btn_speed, path, set_attrib(0.647, 0.465, 81, 78));
    buttons = add_to_array(buttons, res);
    buttons = init_buttons_five(buttons);
    return (buttons);
}

void **init_buttons_three(void **buttons)
{
    char *path;
    void *res;

    path = my_strdup("assets/btn/quests");
    res = add_button(6, &btn_quests, path, set_attrib(0.291, 0.4277, 800, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/skills");
    res = add_button(6, &btn_skills, path, set_attrib(0.291, 0.501, 800, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/complete");
    res = add_button(7, &btn_complete, path, set_attrib(0.291, 0.56, 800, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/add");
    res = add_button(8, &btn_attack, path, set_attrib(0.647, 0.54, 81, 78));
    buttons = add_to_array(buttons, res);
    buttons = init_buttons_four(buttons);
    return (buttons);
}

void **init_buttons_two(void **buttons)
{
    char *path;
    void *res;

    path = my_strdup("assets/btn/back");
    res = add_button(2, &btn_back, path, set_attrib(0.30, 0.85, 800, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/resume");
    res = add_button(4, &btn_resume, path, set_attrib(0.30, 0.35, 800, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/home");
    res = add_button(4, &btn_return, path, set_attrib(0.30, 0.5, 800, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/quit");
    res = add_button(4, &btn_quit_game, path, set_attrib(0.30, 0.65, 800, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/delete");
    res = add_button(1, &btn_reset, path, set_attrib(0.30, 0.73, 800, 78));
    buttons = add_to_array(buttons, res);
    buttons = init_buttons_three(buttons);
    return (buttons);
}

void **init_buttons(void **buttons)
{
    char *path;
    void *res;

    path = my_strdup("assets/btn/solo");
    res = add_button(0, &btn_play, path, set_attrib(0.30, 0.35, 800, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/help");
    res = add_button(0, &btn_help, path, set_attrib(0.30, 0.5, 800, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/options");
    res = add_button(0, &btn_opt, path, set_attrib(0.30, 0.65, 800, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/quit");
    res = add_button(0, &btn_quit, path, set_attrib(0.30, 0.8, 800, 78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/back");
    res = add_button(1, &btn_back, path, set_attrib(0.30, 0.85, 800, 78));
    buttons = add_to_array(buttons, res);
    buttons = init_buttons_two(buttons);
    return (buttons);
}
