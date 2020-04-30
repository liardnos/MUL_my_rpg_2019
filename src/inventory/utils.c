/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Inventory core
*/

// Item T|ID|QT 111
// Blocks = 1 & Items = 2

int same(int first, int second)
{
    first /= 100;
    second /= 100;
    return (first == second ? 1 : 0);
}

int available(int **inv, int item)
{
    int cur = 0;
    int need = item % 100;

    for (int y = 0; inv[y]; y++)
        for (int x = 0; x < 9; x++) {
            if (same(inv[y][x], item))
                cur += inv[y][x] % 100;
            if (cur >= need)
                return (1);
        }
    return (0);
}

int give_inv(int **inventory, int type, int item, int nb)
{
    int to_add = 0;

    if (nb > 64 || nb < 0 || type > 2 || type < 1)
        return (0);
    to_add = type * 10000 + item * 100 + nb;
    for (int y = 0; inventory[y]; y++)
        for (int x = 0; x < 9; x++) {
            if (!inventory[y][x]) {
                inventory[y][x] = to_add;
                return (1);
            }
    }
    return (0);
}

void remove_it(int *in_inv, int *to_rm)
{
    if (((*in_inv) % 100) >= ((*to_rm) % 100)) {
        *in_inv -= (*to_rm) % 100;
        *to_rm -= (*to_rm) % 100;
    } else {
        *to_rm -= (*in_inv) % 100;
        *in_inv = 0;
    }
}

int take_inv(int **inv, int type, int item, int nb)
{
    int to_rm = 0;
    int old;

    if (nb > 64 || nb < 0 || type < 1 || type > 2)
        return (0);
    to_rm = type * 10000 + item * 100 + nb;
    if (!available(inv, to_rm))
        return (0);
    for (int y = 0; inv[y]; y++)
        for (int x = 0; x < 9; x++) {
            if (same(inv[y][x], to_rm))
                remove_it(&(inv[y][x]), &to_rm);
            if (!(to_rm % 100))
                return (1);
        }
    return (0);
}
