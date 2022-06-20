/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** pause
*/

#include "rpg.h"

void set_slider(option_t *option_content, sfRenderWindow *window,
sfEvent event, int *info_opt)
{
    option_content->mouse_pos = sfMouse_getPositionRenderWindow(window);
    info_opt[0] = slider(event, option_content->music_volume,
    (coords_t) {1040, 1290}, option_content);
    info_opt[1] = slider(event, option_content->sound_volume,
    (coords_t) {1040, 1290}, option_content);
    info_opt[2] = slider(event, option_content->text_speed,
    (coords_t) {495, 740}, option_content);
    info_opt[3] = slider(event, option_content->display,
    (coords_t) {495, 740}, option_content);
}

int pause_option(game_t *game, sfRenderWindow *window, opt_info_t *info,
sfEvent event)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    int *info_opt = malloc(sizeof(int) * 4);
    int skip;

    game->menu_pause->option_content->exit = over_test
    (game->menu_pause->option_content->exit, 64, window, event);
    if (game->menu_pause->option_content->exit->status == 1) {
        game->menu_pause->options->status = 0;
        game->menu_pause->option_content->exit->status = 0;
    }
    skip = checker(mouse, game->menu_pause->option_content->skip, event,
    window);
    if (skip == 1)
        info->skip = 1;
    set_slider(game->menu_pause->option_content, window, event, info_opt);
    set_option_values(info_opt, info, window);
    free(info_opt);
    return 0;
}

int manage_pause(game_t *game, sfRenderWindow *window, sfEvent event,
opt_info_t *info)
{
    if (game->menu_pause->options->status == 0) {
        over_test(game->menu_pause->resume, 400, window, event);
        over_test(game->menu_pause->options, 260, window, event);
        over_test(game->menu_pause->exit, 200, window, event);
    }
    if (game->menu_pause->exit->status == 1) {
        game->menu_pause->exit->status = 0;
        game->m_pause = 0;
        return 22;
    }
    if (game->menu_pause->resume->status == 1) {
        game->m_pause = 0;
        game->menu_pause->resume->status = 0;
        game->pause = 3;
    }
    if (game->menu_pause->options->status == 1) {
        pause_option(game, window, info, event);
    }
    return 2;
}

void display_pause_options(game_t *g, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window,
    g->menu_pause->option_content->font->sprite,
    NULL);
    sfRenderWindow_drawSprite(window,
    g->menu_pause->option_content->display->sprite, NULL);
    sfRenderWindow_drawSprite(window,
    g->menu_pause->option_content->exit->sprite, NULL);
    sfRenderWindow_drawSprite(window,
    g->menu_pause->option_content->music_volume->sprite, NULL);
    sfRenderWindow_drawSprite(window,
    g->menu_pause->option_content->sound_volume->sprite, NULL);
    sfRenderWindow_drawSprite(window,
    g->menu_pause->option_content->skip->sprite, NULL);
    sfRenderWindow_drawSprite(window,
    g->menu_pause->option_content->text_speed->sprite, NULL);
    sfRenderWindow_drawText(window,
    g->menu_pause->option_content->text->text, NULL);
}

void display_pause(game_t *g, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, g->menu_pause->pause->sprite, NULL);
    sfRenderWindow_drawSprite(window, g->menu_pause->resume->sprite, NULL);
    sfRenderWindow_drawSprite(window, g->menu_pause->exit->sprite, NULL);
    sfRenderWindow_drawSprite(window, g->menu_pause->options->sprite, NULL);
    if (g->menu_pause->options->status == 1)
        display_pause_options(g, window);
}
