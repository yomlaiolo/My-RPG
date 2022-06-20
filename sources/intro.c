/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** intro
*/

#include "rpg.h"

void init_logo(sfRenderWindow *window)
{
    sfImage *image = NULL;
    sfUint8 const *icon = NULL;

    image = sfImage_createFromFile("ressources/game/logo.png");
    icon = sfImage_getPixelsPtr(image);
    sfRenderWindow_setIcon(window, 144, 144, icon);
}

int checker_status(sfEvent event, sprite_t *sprite, sfRenderWindow *window)
{
    int status = 0;

    if (event.type == sfEvtMouseButtonPressed && sprite->rect.left != 130) {
        sprite->rect.left = 130;
        sfRenderWindow_destroy(window);
        window = sfRenderWindow_create((sfVideoMode) {1920, 1080, 32},
        "HELOS", sfFullscreen, NULL);
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        status = 1;
    } else if (event.type == sfEvtMouseButtonPressed) {
        sprite->rect.left = 65;
        sfRenderWindow_destroy(window);
        window = sfRenderWindow_create((sfVideoMode) {1920, 1080, 32},
        "HELOS", sfClose, NULL);
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        init_logo(window);
        status = 1;
    }
    return status;
}

int checker(sfVector2i mouse_pos, sprite_t *sprite, sfEvent event,
sfRenderWindow *window)
{
    int status = 0;

    if (mouse_pos.x >= sprite->pos.x && mouse_pos.x <= sprite->pos.x +
    sprite->rect.width && mouse_pos.y >= sprite->pos.y && mouse_pos.y <=
    sprite->pos.y + sprite->rect.height) {
        status = checker_status(event, sprite, window);
        if (sprite->rect.left == 0)
            sprite->rect.left = 65;
    } else if (sprite->rect.left != 130)
        sprite->rect.left = 0;
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return status;
}

void set_option_values(int *tab, opt_info_t *info, sfRenderWindow *window)
{
    if (tab[0] != -1)
        info->music = tab[0];
    if (tab[1] != -1)
        info->sound = tab[1];
    if (tab[2] != -1)
        info->speed = tab[2];
    if (tab[3] != -1) {
        info->display = tab[3];
        sfRenderWindow_setFramerateLimit(window, info->display);
    }
}

void option_gestion(intro_t *intro, sfRenderWindow *window, sfEvent event,
opt_info_t *info)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    int *info_opt = malloc(sizeof(int) * 4);
    int skip = 0;

    intro->option_content->exit = over_test(intro->option_content->exit, 64,
    window, event);
    if (intro->option_content->exit->status == 1) {
        intro->option->status = 0;
        intro->option_content->exit->status = 0;
    }
    skip = checker(mouse, intro->option_content->skip, event, window);
    if (skip > info->skip)
        info->skip = skip;
    set_slider(intro->option_content, window, event, info_opt);
    set_option_values(info_opt, info, window);
    free(info_opt);
}
