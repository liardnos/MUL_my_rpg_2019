/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** save for my_rpg
*/
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rpg.h"
#include "my.h"

int save_map(map_t *map)
{
    int fd = open("save/map", O_TRUNC | O_CREAT | O_WRONLY, 7+7*8+7*8*8);

    int check_some = 0;
    if (fd < 0) return (0);
    write(fd, &map->size_l, sizeof(int));
    write(fd, &map->size_r, sizeof(int));
    for (lld_t *mv = map->map->next; mv; mv = mv->next){
        block_t **block = mv->data;
        for (int i = 0; i < MAP_Y; i++){
            check_some += block[i]->type;
            write(fd, &block[i]->type, sizeof(int));
        }
    }
    write(fd, &check_some, sizeof(int));
    close(fd);
    my_printf("[RM] map saved\n");
    return (1);
}

int save_player(player_t *p)
{
    int fd = open("save/player", O_TRUNC | O_CREAT | O_WRONLY, 7+7*8+7*8*8);

    if (fd < 0) return (0);
    write(fd, &p->x, sizeof(float));
    write(fd, &p->y, sizeof(float));
    write(fd, &p->vx, sizeof(float));
    write(fd, &p->vy, sizeof(float));
    write(fd, &p->hp, sizeof(int));
    write(fd, &p->maxhp, sizeof(int));
    write(fd, p->inventory[-1], sizeof(int)*4);
    write(fd, p->inventory[0], sizeof(int)*9);
    write(fd, p->inventory[1], sizeof(int)*9);
    write(fd, p->inventory[2], sizeof(int)*9);
    write(fd, p->inventory[3], sizeof(int)*9);
    close(fd);
    my_printf("[RM] player saved\n");
}

int save_gameb(game_t *game)
{
    int fd = open("save/game", O_TRUNC | O_CREAT | O_WRONLY, 7+7*8+7*8*8);

    if (fd < 0) return (0);
    write(fd, &game->quest, sizeof(int));
    close(fd);
    my_printf("[RM] game saved\n");
}

int save_game(game_t *game)
{
    my_printf("[RM] saving game...\n");
    save_gameb(game);
    my_printf("[RM] saving map...\n");
    save_map(game->map);
    my_printf("[RM] saving player...\n");
    save_player(game->players->next->data);
    my_printf("[RM] save completed!\n");
    return (1);
}

void delete_save(void)
{
    int fd = open("save/player", O_TRUNC | O_CREAT | O_WRONLY, 7+7*8+7*8*8);
    write(fd, "this save as been delete", 24);
    close(fd);
}
