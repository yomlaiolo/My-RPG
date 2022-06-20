/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** calcul
*/

#include "rpg.h"

void calcul_bar_percent(player_t *player_info)
{
    player_info->life_bar->rect.width = player_info->stat->hp * 79 /
    player_info->stat->hp_max;
    sfSprite_setTextureRect(player_info->life_bar->sprite,
    player_info->life_bar->rect);
    player_info->mp_bar->rect.width = player_info->stat->mp * 78 /
    player_info->stat->mp_max;
    sfSprite_setTextureRect(player_info->mp_bar->sprite,
    player_info->mp_bar->rect);
}

void calcul_monster_life(monster_t *monster)
{
    monster->life_bar->rect.width = monster->hp * 32 /
    monster->max_hp;
    sfSprite_setTextureRect(monster->life_bar->sprite,
    monster->life_bar->rect);
}
