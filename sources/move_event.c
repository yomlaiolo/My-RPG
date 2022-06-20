/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** move_event
*/

#include "rpg.h"

void pressed_move(game_t *game, sfKeyCode key)
{
    switch (key) {
        case sfKeyD:
            game->move[0] = 1;
            break;
        case sfKeyZ:
            game->move[1] = 1;
            break;
        case sfKeyS:
            game->move[2] = 1;
            break;
        case sfKeyQ:
            game->move[3] = 1;
            break;
        default:
        break;
    }
}

void pressed(game_t *game, sfEvent event)
{
    sfKeyCode key = event.key.code;
    switch (key) {
        case sfKeyLShift:
            game->move[4] = 1;
            game->player_info->recup = 0;
            break;
        case sfKeyK:
            if (game->player_info->stat->mp >= 10 &&
            game->player_info->sword == 1)
                game->move[5] = 1;
            break;
        default:
        pressed_move(game, key);
    }
}

void released_move(game_t *game, sfKeyCode key)
{
    switch (key) {
        case sfKeyD:
            game->move[0] = 0;
            break;
        case sfKeyZ:
            game->move[1] = 0;
            break;
        case sfKeyS:
            game->move[2] = 0;
            break;
        case sfKeyQ:
            game->move[3] = 0;
            break;
        default:
        break;
    }
}

void released(game_t *game, sfEvent event)
{
    sfKeyCode key = event.key.code;
    switch (key) {
        case sfKeyLShift:
            game->move[4] = 0;
            recup_mp(game);
            break;
        case sfKeyK:
            game->move[5] = 0;
            break;
        default:
        released_move(game, key);
    }
}

int movement_event(sfEvent event, scene_t *scene)
{
    if (event.type == sfEvtKeyPressed && scene->scene == 2)
        pressed(scene->game, event);
    if (event.type == sfEvtKeyReleased && scene->scene == 2)
        released(scene->game, event);
    if (scene->scene == 1 && scene->intro->play->status == 1)
        return 12;
    if (scene->scene == 1 && scene->intro->option->status == 1)
        option_gestion(scene->intro, scene->window, event, scene->opt_info);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP &&
    scene->scene == 2)
        return 22;
    close_event(scene, event);
    return 0;
}
