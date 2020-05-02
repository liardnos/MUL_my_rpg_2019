/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Check if all assets are here
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "rpg.h"

int try_to_open(char *path)
{
    int fd;

    for (int x = 0; path[x]; x++)
        if (path[x] == '\n')
            path[x] = 0;
    fd = open(path, O_RDONLY);
    if (fd == -1) {
        my_putstr("Unable to find/read ");
        my_putstr(path);
        my_putstr(" fix it :)\n");
        return (0);
    }
    close(fd);
    return (1);
}

int check_assets(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("assets.txt", "r");
    if (!fp)
        return (0);
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == '\n')
            break;
        if (!try_to_open(line))
            return (0);
    }
    free(line);
    return (1);
}
