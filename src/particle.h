/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** particle.h
*/

typedef struct particle
{
    float x;
    float vx;
    float y;
    float vy;
    float a;
    float va;
    int life;
    sfSprite *sprite;
} particle_t;

void particle_add(lld_t *p_lld, particle_t *p);
lld_t *particle_array();
void particles_draw(sfRenderWindow *win, lld_t *p_lld);
