/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Init buttons
*/

#include "my.h"
#include "menu.h"

void **init_buttons(void **buttons)
{
    char *path;
    void *res;

    path = my_strdup("assets/btn/solo");
    res = add_button(0, &btn_play, path, set_attrib(0.30,0.35,800,78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/help");
    res = add_button(0, &btn_play, path, set_attrib(0.30,0.5,800,78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/options");
    res = add_button(0, &btn_play, path, set_attrib(0.30,0.65,800,78));
    buttons = add_to_array(buttons, res);
    path = my_strdup("assets/btn/quit");
    res = add_button(0, &btn_quit, path, set_attrib(0.30,0.8,800,78));
    buttons = add_to_array(buttons, res);
    /*path = my_strdup("assets/btn/back");
    res = add_button(1, &btn_back, path, set_attrib(0.4348,0.8,250,110));
    buttons = add_to_array(buttons, res);*/
    //buttons = init_buttons_two(buttons);
    return (buttons);
}
