/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** animator_main
*/

#include "rpg.h"

//FIXME

animator_t *init_player_animator()
{
    sfTexture *t_head = sfTexture_createFromFile("assets/Characters/Player male/male_head.png", 0);
    sfTexture *t_body = sfTexture_createFromFile("assets/Characters/Player male/male_body.png", 0);
    sfTexture *t_arm = sfTexture_createFromFile("assets/Characters/Player male/male_arm.png", 0);
    sfTexture *t_leg = sfTexture_createFromFile("assets/Characters/Player male/male_leg.png", 0);
    sfSprite *s_head = sfSprite_create();
    sfSprite *s_body = sfSprite_create();
    sfSprite *s_arm_l = sfSprite_create();
    sfSprite *s_arm_r = sfSprite_create();
    sfSprite *s_leg_l = sfSprite_create();
    sfSprite *s_leg_r = sfSprite_create();
    sfVector2f scale = {0.5, 0.5};
    sfSprite_setScale(s_head, scale);
    sfSprite_setScale(s_body, scale);
    sfSprite_setScale(s_arm_l, scale);
    sfSprite_setScale(s_arm_r, scale);
    sfSprite_setScale(s_leg_l, scale);
    sfSprite_setScale(s_leg_r, scale);
    sfSprite_setTexture(s_head, t_head, sfTrue);
    sfSprite_setTexture(s_body, t_body, sfTrue);
    sfSprite_setTexture(s_arm_l, t_arm, sfTrue);
    sfSprite_setTexture(s_arm_r, t_arm, sfTrue);
    sfSprite_setTexture(s_leg_l, t_leg, sfTrue);
    sfSprite_setTexture(s_leg_r, t_leg, sfTrue);
    sfSprite_setOrigin(s_head, alloc_vector2f(32, 64));
    sfSprite_setOrigin(s_body, alloc_vector2f(22, 30));
    sfSprite_setOrigin(s_arm_l, alloc_vector2f(14, 0));
    sfSprite_setOrigin(s_arm_r, alloc_vector2f(14, 0));
    sfSprite_setOrigin(s_leg_l, alloc_vector2f(14, -14));
    sfSprite_setOrigin(s_leg_r, alloc_vector2f(14, -14));
    animator_t *me = animator_init();
    animator_addmenber(me, malloc_pos(0, -11, 22.5), s_arm_l);
    animator_addmenber(me, malloc_pos(0, 10, 22.5), s_leg_l);
    animator_addmenber(me, malloc_pos(0, -15, 5), s_head);
    animator_addmenber(me, malloc_pos(0, 0, 0), s_body);
    animator_addmenber(me, malloc_pos(0, 10, -22.5), s_leg_r);
    animator_addmenber(me, malloc_pos(0, -11, -22.5), s_arm_r);
    animator_setpos(me, malloc_pos(1920/2, 1080/2, 0));
}
