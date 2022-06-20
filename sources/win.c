/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** win
*/

#include "rpg.h"

/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** win
*/

#include "rpg.h"

void run_win(scene_t *scene)
{
    manage_clock(scene->clock, 0);
    sfRenderWindow_clear(scene->window, sfBlack);
    sfRenderWindow_drawSprite(scene->window, scene->win->sprite, NULL);
    if (scene->clock->seconds >= 0.001) {
        restart_clock(scene->clock);
        scene->win->pos.y -= 1;
        sfSprite_setPosition(scene->win->sprite, scene->win->pos);
    }
    if (scene->win->pos.y <= -3240)
        scene->scene = 11;
}

void win_gestion(scene_t *scene)
{
    if (scene->scene == 41) {
        sfView_reset(scene->game->view, (sfFloatRect) {0, 0, 1920, 1080});
        sfRenderWindow_setView(scene->window, scene->game->view);
        destroy_game(scene->game);
        scene->win->pos = (sfVector2f) {0, 1080};
        sfSprite_setPosition(scene->win->sprite, scene->win->pos);
        sfMusic_play(scene->music->music);
        scene->scene = 4;
    } else if (scene->scene == 4) {
        run_win(scene);
    }
}
