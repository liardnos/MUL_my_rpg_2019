/*
** EPITECH PROJECT, 2020
**
** File description:
** func for zombie
*/

#include <math.h>
#include "rpg.h"

float zombie_head(win_t *win, entity_t *entity, player_t *player)
{
    sfVector2i vec = {player->x, player->y};
    member_t *member = entity->anim->member->next->next->next->data;

    vec.x -= entity->x, vec.y -= entity->y;
    float d = pow(pow(vec.x, 2)+pow(vec.y, 2), 0.5);
    float head_angle = 0;
    if (d != 0)
        head_angle = acos((float)vec.y / (float)d);
    vec.x > 0 ? head_angle *= -1 : 0;

    sfVector2f vec1 = {-0.5, 0.5};
    sfVector2f vec2 = {0.5, 0.5};
    if (head_angle < 0)
        head_angle -= PI, sfSprite_setScale(member->sprite, vec1);
    else
        sfSprite_setScale(member->sprite, vec2);
    return (head_angle/PI*180-90);
}

void draw_entity(win_t *win)
{
    sfVector2f pos = {0, 0};
    lld_t *lld = win->game->entities;
    player_t *p = win->game->players->next->data;

    for (lld_t *mv = lld->next; mv; mv = mv->next){
        entity_t *entity = mv->data;

        pos.x = (entity->x - p->x) * 64 + 1920/2;
        pos.y = (entity->y - p->y) * 64 + 1080/2;
        animator_setpos(entity->anim, malloc_pos(pos.x, pos.y, 0));
        animator_draw((sfRenderWindow *)win->win, entity->anim);
        sfVector2i posi = {(int)p->x, (int)p->y};
        if (!animator_animate(entity->anim)){
            float h_head = zombie_head(win, entity, p);
            if (entity->anim_sate & 0x1)
                animator_goto(entity->anim, 60.0, ANIM_WALK1);
            else
                animator_goto(entity->anim, 60.0, ANIM_WALK2);
            entity->anim_sate ^= 1;
        }
    }
}
