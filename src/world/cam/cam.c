/*
** EPITECH PROJECT, 2019
** my_str_isprintable
** File description:
** hello
*/

#include <stdlib.h>
#include "my.h"
#include "screen.h"
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Keyboard.h>
#include <math.h>
#include <stdio.h>
#include "../world.h"

world_t **main_cam(sfRenderWindow *win)
{
    static world_t *world = 0; !world ? world = create_world(128, 128) : 0;
    world->cam = win;
    do {
        sfRenderWindow_clear(win, sfBlack);
        world->mv &= 2;
        for (int i = 0; i < world->x*world->y/100; i++){
            int xy[] = {rand()%(world->x-2)+1, rand()%(world->y-2)+1,
            world->x, world->y};
            if (world->mesh[xy[0]][xy[1]] < -20)
                drop_water(world->mesh, xy, 0.5, 0);
        }
        world->mv |= take_movement_input(world->mat_start, world);
        float **points = mesh_to_points(world->mesh, world->x, world->y);
        float **points2 = rotate_points(points, world->mat_start);
        draw_mesh(world, points2+2);
        free_points(points2);
        free_points(points);
        draw_window(world->cam, world->cam_buf);
    } while (world->mv);
    return (&world);
}

int take_movement_input(float *mat_s, world_t *world)
{
    int mv = 0;
    sfKeyboard_isKeyPressed(sfKeyZ) ? mat3_tz(mat_s, 1), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyS) ? mat3_tz(mat_s, -1), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyQ) ? mat3_tx(mat_s, 1), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyD) ? mat3_tx(mat_s, -1), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyE) ? mat3_ty(mat_s, 1), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyA) ? mat3_ty(mat_s, -1), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyW) ? mat3_rz(mat_s, PI/180), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyX) ? mat3_rz(mat_s, -PI/180), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyLeft) ? mat3_ry(mat_s, -PI/180), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyRight) ? mat3_ry(mat_s, PI/180), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyUp) ? mat3_rx(mat_s, PI/180), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyDown) ? mat3_rx(mat_s, -PI/180), mv = 1 : 0;
    return (mv);
}
