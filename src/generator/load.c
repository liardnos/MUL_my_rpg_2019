/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** load for my_rpg
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "rpg.h"
#include "my.h"

map_t *load_map(void)
{
    map_t *map = malloc(sizeof(map_t));
    int check_some2;
    int fd = open("save/map", O_RDONLY);
    int buf[MAP_Y];
    int check_some = 0;
    if (fd < 0 || !map) return (0);
    map->new = 1, map->map = lld_init();
    if (read(fd, &map->size_l, sizeof(int)) != sizeof(int)) return (0);
    if (read(fd, &map->size_r, sizeof(int)) != sizeof(int)) return (0);
    for (int i = -map->size_l; i <= map->size_r; i++){
        block_t **block = malloc(sizeof(block_t *)*(MAP_Y + 2));
        block[0] = 0, block[MAP_Y+1] = 0, block++;
        if (read(fd, buf, sizeof(int) * MAP_Y) != sizeof(int) * MAP_Y);
        for (int j = 0; j < MAP_Y; j++)
            check_some += buf[j], block[j] = blockss[buf[j]];
        lld_insert(map->map, (u64)map->map->data, block);
    }
    read(fd, &check_some2, sizeof(int));
    close(fd);
    return (check_some2 == check_some ? map : 0);
}

player_t *load_player(void)
{
    int fd = open("save/player", O_RDONLY);
    player_t *p = malloc(sizeof(player_t));

    if (fd < 0 || !p) return (0);
    p->floor = 0;
    p->inventory = init_inventory();
    read(fd, &p->x, sizeof(float)) != sizeof(float) ? (p = 0) :
    read(fd, &p->y, sizeof(float)) != sizeof(float) ? (p = 0) :
    read(fd, &p->vx, sizeof(float)) != sizeof(float) ? (p = 0) :
    read(fd, &p->vy, sizeof(float)) != sizeof(float) ? (p = 0) :
    read(fd, &p->hp, sizeof(int)) != sizeof(int) ? (p = 0) :
    read(fd, &p->maxhp, sizeof(int)) != sizeof(int) ? (p = 0) :
    read(fd, p->inventory[-1], sizeof(int) * 4) != sizeof(int) * 4 ? (p = 0) :
    read(fd, p->inventory[0], sizeof(int) * 9) != sizeof(int) * 9 ? (p = 0) :
    read(fd, p->inventory[1], sizeof(int) * 9) != sizeof(int) * 9 ? (p = 0) :
    read(fd, p->inventory[2], sizeof(int) * 9) != sizeof(int) * 9 ? (p = 0) :
    read(fd, p->inventory[3], sizeof(int) * 9) != sizeof(int) * 9 ? (p = 0) : 0;
    close(fd);
    return (p);
}

game_t *load_gameb(void)
{
    game_t *game = malloc(sizeof(game_t));
    int fd = open("save/game", O_RDONLY);

    memset(game, 0, sizeof(game_t));
    if (!game || fd < 0)
        return (0);
    read(fd, &game->quest, sizeof(int)) != sizeof(int) ? (game = 0) :
    read(fd, &game->jumpb, sizeof(int)) != sizeof(int) ? (game = 0) :
    read(fd, &game->shield, sizeof(int)) != sizeof(int) ? (game = 0) :
    read(fd, &game->speed, sizeof(int)) != sizeof(int) ? (game = 0) :
    read(fd, &game->attack, sizeof(int)) != sizeof(int) ? (game = 0) :
    read(fd, &game->nofall, sizeof(int)) != sizeof(int) ? (game = 0) :
    read(fd, &game->skills, sizeof(float)) != sizeof(int) ? (game = 0) :
    read(fd, &game->mob_kill, sizeof(int)) != sizeof(int) ? (game = 0) :
    0;
    close(fd);
    return (game);
}

game_t *load_game(void)
{
    game_t *game = load_gameb();
    if (!game) return (0);
    game->players = lld_init();
    my_printf("[RM] loading player...\n");
    player_t *player = load_player();
    if (!player) return (0);
    lld_insert(game->players, 0, player);
    my_printf("[RM] loading map...\n");
    game->map = load_map();
    if (!game->map) return (0);
    my_printf("[RM] load completed\n");
    return (game);
}
