/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** potion_timer
*/

#include "rpg.h"

void timer_atk(scene_t *scene)
{
    if (scene->game->inv[1]->clock != NULL)
        manage_clock(scene->game->inv[1]->clock, scene->game->pause);
    if (scene->game->inv[1]->clock != NULL && scene->game->inv[1]->clock->
    seconds > 30 && scene->game->inv[1]->status == 1) {
        scene->game->player_info->stat->atk /= 2;
        scene->game->inv[1]->status = 0;
        destroy_clocck(scene->game->inv[1]->clock);
        scene->game->inv[1]->clock = NULL;
    }
}

void timer_endurance(scene_t *scene)
{
    if (scene->game->inv[2]->clock != NULL)
        manage_clock(scene->game->inv[2]->clock, scene->game->pause);
    if (scene->game->inv[2]->clock != NULL && scene->game->inv[2]->clock->
    seconds > 30 && scene->game->inv[2]-> status == 1) {
        scene->game->player_info->stat->endurence = 1;
        scene->game->inv[2]->status = 0;
        destroy_clocck(scene->game->inv[2]->clock);
        scene->game->inv[2]->clock = NULL;
    }
}

void timer_fire(scene_t *scene)
{
    if (scene->game->inv[3]->clock != NULL)
        manage_clock(scene->game->inv[3]->clock, scene->game->pause);
    if (scene->game->inv[3]->clock != NULL && scene->game->inv[3]->clock->
    seconds > 300 && scene->game->inv[3]->status == 1) {
        scene->game->player_info->fire = 0;
        scene->game->inv[3]->status = 0;
        destroy_clocck(scene->game->inv[3]->clock);
        scene->game->inv[3]->clock = NULL;
    }
}

void timer_antidote(scene_t *scene)
{
    if (scene->game->inv[4]->clock != NULL)
        manage_clock(scene->game->inv[4]->clock, scene->game->pause);
    if (scene->game->inv[4]->clock != NULL && scene->game->inv[4]->clock->
    seconds > 120 && scene->game->inv[4]->status == 1) {
        scene->game->player_info->antidote = 0;
        scene->game->inv[4]->status = 0;
        destroy_clocck(scene->game->inv[4]->clock);
        scene->game->inv[4]->clock = NULL;
    }
}

void timer_ice(scene_t *scene)
{
    if (scene->game->inv[5]->clock != NULL)
        manage_clock(scene->game->inv[5]->clock, scene->game->pause);
    if (scene->game->inv[5]->clock != NULL && scene->game->inv[5]->clock->
    seconds > 300 && scene->game->inv[5]->status == 1) {
        scene->game->player_info->ice = 0;
        scene->game->inv[5]->status = 0;
        destroy_clocck(scene->game->inv[5]->clock);
        scene->game->inv[5]->clock = NULL;
    }
}
