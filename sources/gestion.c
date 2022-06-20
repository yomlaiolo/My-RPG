/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** gestion
*/

#include "rpg.h"

sfVector2f print_mouse(scene_t *scene, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);
    sfVector2f mouse_pos = (sfVector2f) {mouse.x, mouse.y};

    if (scene->scene == 2) {
        sfSprite_setScale(scene->mouse->sprite, (sfVector2f) {0.3, 0.3});
        mouse_pos = sfRenderWindow_mapPixelToCoords(window, mouse,
        scene->game->view);
    }
    if (scene->scene == 1 || scene->scene == 32)
        sfSprite_setScale(scene->mouse->sprite, (sfVector2f) {1, 1});
    if (scene->scene == 2 && scene->game->m_pause == 1)
        sfSprite_setScale(scene->mouse->sprite, (sfVector2f) {1, 1});
    scene->mouse->pos = mouse_pos;
    scene->mouse->rect = (sfIntRect) {0, 0, 32, 32};
    sfSprite_setPosition(scene->mouse->sprite, scene->mouse->pos);
    sfSprite_setTextureRect(scene->mouse->sprite, scene->mouse->rect);
    if ((scene->scene != 4 && scene->scene != 2) || (scene->scene == 2
    && (scene->game->is_inv == 1 || scene->game->m_pause == 1)))
        sfRenderWindow_drawSprite(scene->window, scene->mouse->sprite, NULL);
    return mouse_pos;
}

void move_all(scene_t *scene)
{
    update_time(scene->game);
    colision_event(scene->game);
    move_event(scene->game);
    move_monster(scene->game);
    move_pnj(scene->game);
    sfView_setSize(scene->game->view, (sfVector2f) {1920, 1080});
}

void main_game(scene_t *scene)
{
    if (scene->scene == 2) {
        move_all(scene);
        manage_zone(scene->game);
        if (scene->game->m_pause == 0) {
            zoom_stairs(scene->game, scene->window);
            sfView_setCenter(scene->game->view,
            scene->game->player->picture->pos);
            sfView_move(scene->game->view, (sfVector2f) {30, 35});
        } else
            sfView_setCenter(scene->game->view, (sfVector2f) {960, 1080 / 2});
        manage_bars(scene);
        timer_potion(scene);
        if (scene->game->pause == 1)
            scene->game->pause = 2;
        if (scene->game->pause == 3)
            scene->game->pause = 0;
    }
}

scene_info_t gestion(scene_t *scene, sfRenderWindow *window)
{
    intro_gestion(scene);
    game_gestion(scene);
    lose_gestion(scene);
    main_game(scene);
    win_gestion(scene);
    manage_event(scene);
    if (sfRenderWindow_isOpen(scene->window) == sfFalse)
        return (scene_info_t) {scene->scene, scene->angle, scene->window,
        scene->intro, scene->lose, scene->game, scene->args, scene->mouse,
        scene->opt_info, scene->mouse_pos};
    scene->mouse_pos = print_mouse(scene, window);
    sfRenderWindow_display(scene->window);
    return (scene_info_t) {scene->scene, scene->angle, scene->window,
    scene->intro, scene->lose, scene->game, scene->args, scene->mouse,
    scene->opt_info, scene->mouse_pos};
}

scene_t *lose_gestion(scene_t *scene)
{
    if (scene->scene == 31) {
        sfView_reset(scene->game->view, (sfFloatRect) {0, 0, 1920, 1080});
        sfRenderWindow_setView(scene->window, scene->game->view);
        destroy_game(scene->game);
        scene->scene = 32;
        scene->lose = init_lose();
    }
    if (scene->scene == 32) {
        display_lose(scene->window, scene->lose);
    }
    return scene;
}
