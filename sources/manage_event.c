/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** manage_event
*/

#include "rpg.h"

void manage_bars(scene_t *scene)
{
    sfVector2i pos = {10, 60};
    sfVector2i pos2 = {10, 10};

    sfSprite_setScale(scene->game->player_info->life->sprite,
    (sfVector2f) {scene->game->scale, scene->game->scale});
    sfSprite_setScale(scene->game->player_info->life_bar->sprite,
    (sfVector2f) {scene->game->scale, scene->game->scale});
    sfSprite_setScale(scene->game->player_info->mp->sprite,
    (sfVector2f) {scene->game->scale, scene->game->scale});
    sfSprite_setScale(scene->game->player_info->mp_bar->sprite,
    (sfVector2f) {scene->game->scale, scene->game->scale});
    sfSprite_setPosition(scene->game->player_info->life->sprite,
    sfRenderWindow_mapPixelToCoords(scene->window, pos2, scene->game->view));
    sfSprite_setPosition(scene->game->player_info->life_bar->sprite,
    sfRenderWindow_mapPixelToCoords(scene->window, pos2, scene->game->view));
    sfSprite_setPosition(scene->game->player_info->mp->sprite,
    sfRenderWindow_mapPixelToCoords(scene->window, pos, scene->game->view));
    sfSprite_setPosition(scene->game->player_info->mp_bar->sprite,
    sfRenderWindow_mapPixelToCoords(scene->window, pos, scene->game->view));
    calcul_bar_percent(scene->game->player_info);
}

scene_t *manage_pause_event(scene_t *scene, sfEvent event)
{
    if (scene->scene == 2 && event.type == sfEvtKeyReleased && event.key.code
    == sfKeyEscape && scene->game->m_pause == 0
    && scene->game->is_inv == 0 && scene->game->pause == 0) {
        sfView_zoom(scene->game->view, 1);
        scene->game->m_pause = 1;
        scene->game->pause = 1;
        return scene;
    }
    if (scene->scene == 2 && event.type == sfEvtKeyReleased && event.key.code
    == sfKeyEscape && scene->game->m_pause == 1) {
        scene->game->m_pause = 0;
        scene->game->pause = 3;
        return scene;
    }
    return scene;
}

void manage_over_test(scene_t *scene, sfEvent event)
{
    if (scene->scene == 1 && scene->intro->option->status == 0 &&
    scene->intro->help->status == 0) {
        scene->intro->play = over_test(scene->intro->play, 400,
        scene->window, event);
        scene->intro->option = over_test(scene->intro->option, 260,
        scene->window, event);
        scene->intro->help = over_test(scene->intro->help, 200,
        scene->window, event);
        scene->intro->quit = over_test(scene->intro->quit, 200,
        scene->window, event);
    }
    if (scene->scene == 32) {
        scene->lose->quit = over_test(scene->lose->quit, 200,
        scene->window, event);
        scene->lose->menu = over_test(scene->lose->menu, 200,
        scene->window, event);
    }
    if (scene->scene == 1 && event.type == sfEvtKeyReleased && event.key.code
    == sfKeyEscape && scene->intro->help_open == 1)
        close_help(scene->intro);
}

void manage_event_scene2(scene_t *scene, sfEvent event)
{
    if (scene->scene == 2) {
        call_musics(scene->game, scene->opt_info);
        play_colision(scene);
        manage_pnj_event(scene, event);
        if (scene->game->m_pause == 1)
            scene->scene = manage_pause(scene->game,
            scene->window, event, scene->opt_info);
        if (scene->game->win == 1)
            scene->scene = 41;
        else
            sfMusic_stop(scene->music->music);
    }
    if (scene->scene != 4)
        sfMusic_stop(scene->music->music);
}

void manage_event(scene_t *scene)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(scene->window, &event)) {
        if (manage_event_close(scene, event) == 1)
            return;
        scene = manage_pause_event(scene, event);
        scene = manage_inventory(scene, event);
        manage_over_test(scene, event);
        if (scene->scene == 2 && scene->game->is_inv == 1)
            select_potion(scene, event);
        if (scene->scene == 1)
            sfMusic_setVolume(scene->intro->music->music,
            (float) scene->opt_info->music);
        if (movement_event(event, scene) != 0)
            scene->scene = movement_event(event, scene);
        if (scene->scene == 4 && event.type == sfEvtKeyReleased
        && event.key.code == sfKeyEscape)
            scene->scene = 11;
        manage_event_scene2(scene, event);
    }
}
