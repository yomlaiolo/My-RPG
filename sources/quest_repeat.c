/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** quest_repeat
*/

#include "rpg.h"

void desertor_quest(pnj_t *pnj, scene_t *scene)
{
    if (my_strcmp(pnj->name, "Desertor") == 0) {
        if (pnj->nb == 1) {
            scene->game->pnj_tmp = pnj;
            scene->game->player_info->stat->monsters_killed = 0;
            pnj->nb = 2;
            return;
        }
        if (pnj->nb == 3) {
            scene->game->inv[4]->quantity += 1;
            scene->game->player_info->stat->monsters_killed = 0;
            pnj->nb = 4;
            return;
        }
        if (pnj->nb == 4) {
            scene->game->pnj_tmp = pnj;
            scene->game->player_info->stat->monsters_killed = 0;
            pnj->nb = 2;
            return;
        }
    }
}

void trainer_quest(pnj_t *pnj, scene_t *scene)
{
    if (my_strcmp(pnj->name, "Trainer") == 0) {
        if (pnj->nb == 1) {
            scene->game->pnj_tmp = pnj;
            scene->game->player_info->stat->monsters_killed = 0;
            pnj->nb = 2;
            return;
        }
        if (pnj->nb == 3) {
            scene->game->inv[1]->quantity += 1;
            scene->game->player_info->stat->monsters_killed = 0;
            pnj->nb = 4;
            return;
        }
        if (pnj->nb == 4) {
            scene->game->pnj_tmp = pnj;
            scene->game->player_info->stat->monsters_killed = 0;
            pnj->nb = 2;
            return;
        }
    }
}

void snow_quest(pnj_t *pnj, scene_t *scene)
{
    if (my_strcmp(pnj->name, "Snowgirl") == 0) {
        if (pnj->nb == 1) {
            scene->game->pnj_tmp = pnj;
            scene->game->player_info->stat->monsters_killed = 0;
            pnj->nb = 2;
            return;
        }
        if (pnj->nb == 3) {
            scene->game->inv[2]->quantity += 2;
            scene->game->player_info->stat->monsters_killed = 0;
            pnj->nb = 4;
            return;
        }
        if (pnj->nb == 4) {
            scene->game->pnj_tmp = pnj;
            scene->game->player_info->stat->monsters_killed = 0;
            pnj->nb = 2;
            return;
        }
    }
}
