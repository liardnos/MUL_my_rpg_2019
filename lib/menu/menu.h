/*
** EPITECH PROJECT, 2020
** menu
** File description:
** header for menu
*/

/* -- Include CSFML -- */

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

/* -- For coords -- */

#define X ((*cpy)->attrib->pos.x * ((float) win->x))
#define Y ((*cpy)->attrib->pos.y * ((float) win->y))
#define SX ((*cpy)->attrib->size.x)
#define SY ((*cpy)->attrib->size.y)
#define CFG_MENU_PARAM (1)

typedef struct my_text
{
    sfText *text;
    sfFont *font;
}text_t;

typedef struct texture
{
    sfTexture *tex;
    sfSprite *sprite;
}texture_t;

typedef struct config
{
    int sound;
    int fps;
    int difficulty;
}config_t;

typedef struct win
{
    int x;
    int y;
    sfRenderWindow *win;
    texture_t *mouse;
    texture_t *click;
    texture_t *logo;
    config_t *config;
    int menu;
    sfVideoMode mode;
}win_t;

typedef struct att_s
{
    sfVector2f size;
    sfVector2f pos;
}att_t;

typedef struct button
{
    att_t *attrib;
    sfTexture *tex;
    sfTexture *tex_h;
    sfSprite *sprite;
    sfSprite *sprite_h;
    void (*func)(win_t *win);
    int menu;
    int hover;
    int pressed;
}button_t;

/* -- FUNCS -- */

win_t *create_window(int *returned, char *name);
att_t *set_attrib(float x, float y, int width, int depth);
button_t *add_button(int menu, void *func, char *path, att_t *attrib);
void **add_to_array(void **buttons, button_t *new);
void button_main(win_t *win, button_t **buttons);
void button_event(win_t *win, button_t **buttons, sfEvent event);
void end_free(win_t *win, button_t **buttons);
void change_icon(sfRenderWindow *window);
void replace_mouse(win_t *win);
void **init_buttons(void **buttons);
int launch_game(void);
void event_manager(win_t *win, button_t **button, sfEvent event, int *returned);
void scene_manager(win_t *win, button_t **buttons, int *returned);
void draw_home(win_t *win);
void btn_quit(win_t *win);
