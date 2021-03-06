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

#ifndef WORLD_H
#define WORLD_H

#define E 2.71828182846
#define PI 3.14159265359
#define SCREEN_X 1920
#define SCREEN_Y 1080

typedef struct button
{
    int pos_x;
    int pos_y;
    int size_x;
    int size_y;
    sfColor color1;
    sfColor color2;
    sfColor color3;
    char *txt;
    char on;
} button_t;

typedef struct world
{
    int x;
    int y;
    sfRenderWindow *cam;
    float *mat_start;
    char **sun_grid;
    char mv;
    framebuffer_t *cam_buf;
    sfRenderWindow *edi;
    float **mesh;
    framebuffer_t *edi_buf;
    int edi_x;
    int edi_y;
    int brush;
    int brush_type;
    button_t *edi_buttons;
    sfText *txt;
    sfFont *font;
    int buton_nb;
    float sun;
    int cs;
} world_t;

void button0(world_t *world, int nb);
void button1(world_t *world, int nb);
void button2(world_t *world, int nb);
void button3(world_t *world, int nb);
void button4(world_t *world, int nb);
void button5(world_t *world, int nb);
void button6(world_t *world, int nb);
void button7(world_t *world, int nb);
void button8(world_t *world, int nb);
void button9(world_t *world, int nb);
sfColor calc_color(float **mesh, int i, int x, char **sun_grid);
void drop_water(float **mesh, int *xy, float f, float n);
void draw_window(sfRenderWindow *win, framebuffer_t *fb);
void draw_brush(world_t *world);
void draw_map(world_t *world);
void draw_player(world_t *world);
int main_edit(world_t *world);
void init_edit(world_t *world);
char calc_flag(float **points);
char **calc_sun_grid(float **mesh, int x, int y, world_t *world);
int interact_butons(world_t *world);
char button(world_t *world, int b_nb);
void init_edit(world_t *world);
void init_buttons(world_t *world);
void init_map(world_t *world);
void init_cam(world_t *world);
world_t **main_cam(sfRenderWindow *win);
void draw_mesh(world_t *world, float **points);
void aply_flags(char flag, float **points, int *i_v, int xy);
void draw_shape(sfConvexShape *shape, sfVector2f **vecs, sfColor color,
    world_t *world);
char did_we_draw(sfVector2f **vecs, float **points, int i, int y);
int min_i(int a, int b);
float **create_mesh(int x, int y, int d);
float perlin(float x, float y);
int take_movement_input(float *mat_start, world_t *world);
void free_points(float **points);
float **mesh_to_points(float **mesh, int x, int y);
float **rotate_points(float **points, float *mat);
world_t *create_world(int x, int y);

#endif
