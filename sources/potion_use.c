/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** use_potion
*/

#include "rpg.h"

void use_potion_atk(scene_t *scene, int i)
{
    if (scene->game->inv[i]->status == 0) {
        scene->game->player_info->stat->atk *= 2;
        scene->game->inv[i]->status = 1;
        scene->game->inv[i]->quantity--;
        scene->game->inv[i]->clock = malloc(sizeof(clockk_t));
        init_clock(scene->game->inv[i]->clock);
        scene->game->potion_bar[i]->status = 1;
    }
}

void use_potion_endurance(scene_t *scene, int i)
{
    if (scene->game->inv[i]->status == 0) {
        scene->game->player_info->stat->endurence = 3;
        scene->game->inv[i]->status = 1;
        scene->game->inv[i]->quantity--;
        scene->game->inv[i]->clock = malloc(sizeof(clockk_t));
        init_clock(scene->game->inv[i]->clock);
        scene->game->potion_bar[i]->status = 1;
    }
}

void use_potion_fire(scene_t *scene, int i)
{
    if (scene->game->inv[i]->status == 0) {
        scene->game->player_info->fire = 1;
        scene->game->inv[i]->status = 1;
        scene->game->inv[i]->quantity--;
        scene->game->inv[i]->clock = malloc(sizeof(clockk_t));
        init_clock(scene->game->inv[i]->clock);
        scene->game->potion_bar[i]->status = 1;
    }
}

void use_potion_antidote(scene_t *scene, int i)
{
    if (scene->game->inv[i]->status == 0) {
        scene->game->player_info->antidote = 1;
        scene->game->inv[i]->status = 1;
        scene->game->inv[i]->quantity--;
        scene->game->inv[i]->clock = malloc(sizeof(clockk_t));
        init_clock(scene->game->inv[i]->clock);
        scene->game->potion_bar[i]->status = 1;
    }
}

void use_potion_ice(scene_t *scene, int i)
{
    if (scene->game->inv[i]->status == 0) {
        scene->game->player_info->ice = 1;
        scene->game->inv[i]->status = 1;
        scene->game->inv[i]->quantity--;
        scene->game->inv[i]->clock = malloc(sizeof(clockk_t));
        init_clock(scene->game->inv[i]->clock);
        scene->game->potion_bar[i]->status = 1;
    }
}
