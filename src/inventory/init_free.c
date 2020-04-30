/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Inventory Init & Free
*/

#include <stdlib.h>

int **init_inventory()
{
    int **inv;

    inv = malloc(sizeof(int *) * 6);
    if (!inv || !(inv[0] = malloc(sizeof(int) * 5)))
        return (0);
    inv[5] = 0;
    inv[0][4] = 0;
    inv++;
    for (int x = 0; x < 4; x++) {
        inv[x] = malloc(sizeof(int) * 10);
        for (int i = 0; i < 10; i++)
            inv[x][i] = 0;
    }
    return (inv);
}

void free_inventory(int **inventory)
{
    if (inventory) {
        free(inventory[-1]);
        for (int x = 0; x < 5; x++)
            free(inventory[x]);
        inventory--;
        free(inventory);
    }
}
