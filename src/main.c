/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main for my_rpg
*/

#include "rpg.h"

void print_help(void)
{
    my_printf("Raft Minec - Help :\n");
    my_printf("<--- KeyBinding --->\n");
    my_printf("`Z`, `Q`, `D` - move keys.\n");
    my_printf("`I` - inventory\n");
    my_printf("`T` - Talk to alien (Need to be near of him)\n");
    my_printf("`ESCAPE` - pause key or back from menus.\n");
    my_printf("`Drag'n'drop + LEFT CLICK` -  in inventory switch items.\n");
    my_printf("`MOUSEWHEEL` - move in toolbar.\n");
    my_printf("`LEFT CLICK` - Attack with sword or Break with Pickaxe.\n");
    my_printf("`RIGHT CLICK` - Attack with bow or Place Block.\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && !(my_strcmp(av[1], "-h"))) {
        print_help();
        return (0);
    } else if (ac == 1)
        return (launch_game());
    else {
        return (84);
    }
}
