/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** perlin for my_rpg
*/

#include <unistd.h>
#include "rpg.h"
#include "my.h"

float lerp(float a, float b, float w) {
    return (1.0 - w) * a + w * b;
}

float ***grid_grad(int x, int y)
{
    float ***grad = malloc(sizeof(float *) * (x+1));

    srand(0);
    for (int i = 0; i < x; i++){
        grad[i] = malloc(sizeof(float *) * (y+1));
        int ii = 0;
        for (; ii < y; ii++){
            grad[i][ii] = malloc(sizeof(float) * 2);
            grad[i][ii][0] = ((rand() % 5000) / 2500.0 - 1);
            grad[i][ii][1] = ((rand() % 5000) / 2500.0 - 1);
        }
        grad[i][ii] = 0;
    }
    grad[y] = 0;
    return (grad);
}

float dotGridGradient(int ix, int iy, float x, float y)
{
    static float ***grad = 0;
    float dx = x - (float)ix;
    float dy = y - (float)iy;

    if (!grad)
        grad = grid_grad(128, 128);
    return (dx*grad[iy%128][ix%128][0] + dy*grad[iy%128][ix%128][1]);
}

float perlin(float x, float y)
{
    int x0 = (int)x;
    int x1 = x0 + 1;
    int y0 = (int)y;
    int y1 = y0 + 1;
    float sx = x - (float)x0;
    float sy = y - (float)y0;
    float n0;
    float n1;
    float ix0;
    float ix1;
    float value;

    n0 = dotGridGradient(x0, y0, x, y);
    n1 = dotGridGradient(x1, y0, x, y);
    ix0 = lerp(n0, n1, sx);
    n0 = dotGridGradient(x0, y1, x, y);
    n1 = dotGridGradient(x1, y1, x, y);
    ix1 = lerp(n0, n1, sx);
    value = lerp(ix0, ix1, sy);
    return value;
}
