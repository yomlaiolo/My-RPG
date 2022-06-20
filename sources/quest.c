/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** quest
*/

#include "rpg.h"

void monster_quest(monster_t *tmp, game_t *game)
{
    if (tmp->hp <= 0 && tmp->max_hp == 10 && game->main_quest == 1)
        game->main_quest = 2;
    if (tmp->hp <= 0 && tmp->max_hp == 15 && game->main_quest == 2)
        game->main_quest = 3;
    if (tmp->hp <= 0 && tmp->max_hp == 20 && game->main_quest == 4)
        game->main_quest = 5;
    if (tmp->hp <= 0 && tmp->max_hp == 42)
        game->win = 1;
}

void witch_quest(pnj_t *pnj, scene_t *scene) {
    if (pnj->nb < 4 && scene->game->main_quest == 1)
        pnj->nb++;
    if (scene->game->main_quest == 2 && pnj->nb < 7) {
        if (pnj->nb < 4)
            pnj->nb = 4;
        pnj->nb++;
    }
    if (scene->game->main_quest == 3) {
        pnj->nb++;
        if (scene->game->inv[3]->quantity < 5)
            scene->game->inv[3]->quantity += 2;
        scene->game->main_quest = 4;
    }
    if (scene->game->main_quest == 4 && pnj->nb < 10)
        pnj->nb++;
    if (scene->game->main_quest == 5 && pnj->nb < 12) {
        pnj->nb++;
        if (scene->game->inv[5]->quantity < 5)
            scene->game->inv[5]->quantity += 1;
    }
}

void main_quest(pnj_t *pnj, scene_t *scene)
{
    if (scene->game->player_info->stat->monsters_killed >= 5
    && (my_strcmp(pnj->name, "Trainer") == 0
    || my_strcmp(pnj->name, "Desertor") == 0
    || my_strcmp(pnj->name, "Snowgirl") == 0))
        scene->game->pnj_tmp->nb = 3;
    if (my_strcmp(pnj->name, "Grandpa") == 0) {
        if (pnj->nb < 7)
            pnj->nb++;
        if (scene->game->main_quest == 1 && pnj->nb < 9)
            pnj->nb++;
    }
    if (my_strcmp(pnj->name, "Witch") == 0)
        witch_quest(pnj, scene);
}
