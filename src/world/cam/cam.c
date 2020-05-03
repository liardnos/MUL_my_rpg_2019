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

int take_movement_input(float *mat_start, world_t *world)
{
    int mv = 0;
    static sfVector2i mouse_o = {0, 0};
    sfVector2i mouse = sfMouse_getPositionRenderWindow(world->cam);
    if (mouse.x < 0 || mouse.y < 0 || mouse.x > SCREEN_X || mouse.y > SCREEN_Y)
        return (0);
    sfKeyboard_isKeyPressed(sfKeyZ) ? mat3_tz(mat_start, 1), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyS) ? mat3_tz(mat_start, -1), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyQ) ? mat3_tx(mat_start, 1), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyD) ? mat3_tx(mat_start, -1), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyE) ? mat3_ty(mat_start, 1), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyA) ? mat3_ty(mat_start, -1), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyW) ? mat3_rz(mat_start, PI/180), mv = 1 : 0;
    sfKeyboard_isKeyPressed(sfKeyX) ? mat3_rz(mat_start, -PI/180), mv = 1 : 0;
    if (sfMouse_isButtonPressed(sfMouseLeft)){
        float vx = mouse.x - mouse_o.x;
        float vy = mouse.y - mouse_o.y;
        mat3_rx(mat_start, vy/180), mat3_ry(mat_start, -vx/180), mv = 1;
    }
    mouse_o = mouse;
    return (mv);
}
