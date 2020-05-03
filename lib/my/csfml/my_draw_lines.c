/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** hello
*/

#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../my.h"
#include "../screen.h"

void my_draw_line_b(framebuffer_t *buf, sfFloatRect size, sfColor color)
{
    int y = 0;
    float coef = size.left / size.top;

    if (size.top > 0.0)
        for (float x = 0; y <= size.top; y++, x += coef)
            my_put_pixel(buf, size.width+x, size.height+y, color);
    else if (size.top < 0.0)
        for (float x = 0; y >= size.top; y--, x -= coef)
            my_put_pixel(buf, size.width+x, size.height+y, color);
}

void my_draw_line(framebuffer_t *buf, sfVector2f *v0, sfVector2f *v1,
    sfColor color)
{
    sfFloatRect size = {v1->x - v0->x, v1->y - v0->y, v0->x, v0->y};
    float y = 0;

    if (size.left == 0 && size.top == 0)
        return;
    else if (size.left*size.left > size.top*size.top){
        float coef = size.top / size.left;
        if (size.left > 0.0)
            for (float x = 0; x <= size.left; x++, y += coef)
                my_put_pixel(buf, size.width+x, size.height+y, color);
        else if (size.left < 0.0)
            for (float x = 0; x >= size.left; x--, y -= coef)
                my_put_pixel(buf, size.width+x, size.height+y, color);
    } else
        my_draw_line_b(buf, size, color);

}

void my_draw_lines(framebuffer_t *buf, sfVector2f **vects, int n, sfColor color)
{
    for (int i = 0; i < n-1; i++){
        my_draw_line(buf, vects[i], vects[i+1], color);
    }
}
