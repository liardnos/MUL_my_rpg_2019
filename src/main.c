/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Main file
*/

#include "menu.h"
#include "my.h"

void print_help(void)
{
    
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[0], "-h") == 0)
        print_help();
    else if (ac == 1)
        return (launch_game());
    else
        return (84);
    return (0);
}
