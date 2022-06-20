/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** event
*/

#include "rpg.h"

void colision_event(game_t *game)
{
    game->count->count1 = 0;
    game->count->count2 = 0;
    game->count->count3 = 0;
    game->count->count4 = 0;
    for (int i = 0; game->map_block[i]; i++) {
        move_conds(game, i);
        if (game->player->picture->pos.y + 33 >= game->map_block[i][2] &&
        game->player->picture->pos.x + 25 >= game->map_block[i][0] &&
        game->player->picture->pos.x + 5 <= game->map_block[i][1] &&
        game->player->picture->pos.y + 32 <= game->map_block[i][3])
            game->count->count3++;
        if (game->player->picture->pos.x <= game->map_block[i][1] &&
        game->player->picture->pos.y + 32 >= game->map_block[i][2] &&
        game->player->picture->pos.y <= game->map_block[i][3] - 12 &&
        game->player->picture->pos.x >= game->map_block[i][0] - 12)
            game->count->count4++;
    }
}

void update_time(game_t *game)
{
    static float old = 0;
    float time = sfClock_getElapsedTime
    (game->total_clock->clock).microseconds / 1000000.0;
    game->d_time = time - old;
    old = time;
    if (game->pause != 0)
        game->d_time = 0;
}

void close_scene(scene_t *scene)
{
    if (scene->scene == 1)
        destroy_intro(scene->intro);
    if (scene->scene == 2)
        destroy_game(scene->game);
    if (scene->scene == 32)
        destroy_lose(scene->lose);
}

sprite_t *over_test(sprite_t *sprite, int move, sfRenderWindow *window,
sfEvent event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    if (mouse_pos.x >= sprite->pos.x && mouse_pos.x <= sprite->pos.x +
    sprite->rect.width && mouse_pos.y >= sprite->pos.y && mouse_pos.y <=
    sprite->pos.y + sprite->rect.height) {
        if (event.type == sfEvtMouseButtonPressed) {
            sprite->rect.left = move * 2;
            sprite->clicked = 1;
        }
        if (event.type == sfEvtMouseButtonReleased) {
            sprite->status = 1;
            sprite->clicked = 0;
        }
        if (sprite->clicked == 0)
            sprite->rect.left = move;
    } else {
        sprite->rect.left = 0;
    }
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return sprite;
}

void close_event(scene_t *scene, sfEvent event)
{
    if ((scene->scene == 1 && scene->intro->quit->status == 1)
    || (scene->scene == 1 && event.type == sfEvtClosed)) {
        close_scene(scene);
        sfRenderWindow_close(scene->window);
    }
    if (scene->scene == 32 && scene->lose->menu->status == 1) {
        close_scene(scene);
        scene->scene = 11;
    }
    if (((scene->scene == 32 && scene->lose->quit->status == 1)
    || (scene->scene == 32 && event.type == sfEvtClosed)
    || (scene->scene == 4 && event.type == sfEvtClosed))) {
        close_scene(scene);
        sfRenderWindow_close(scene->window);
    }
}
