/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** pnj_item
*/

#include "rpg.h"

void get_drop(game_t *game, pnj_t *pnj)
{
    if (pnj->drop == 7) {
        game->player_info->sword = 1;
        game->main_quest = 1;
    }
    if (pnj->drop == 8)
        game->player_info->stat->mp_max += 25;
    if (pnj->drop == 9)
        game->player_info->stat->hp_max += 25;
    if (pnj->drop == 10)
        game->player_info->stat->atk *= 2;
    if (pnj->drop != -1 && pnj->drop < 6 && game->inv[pnj->drop]->quantity < 5)
        game->inv[pnj->drop - 1]->quantity++;
    pnj->nb++;
    pnj->drop = -1;
    pnj->entity->picture->rect.left += 32;
    sfSprite_setTextureRect(pnj->entity->picture->sprite,
    pnj->entity->picture->rect);
}

int give_item(game_t *game, pnj_t *pnj)
{
    if (my_strncmp(pnj->name, "Statue", 6) == 0 && pnj->drop == -1) {
        game->player_info->stat->hp = game->player_info->stat->hp_max;
        game->player_info->stat->mp = game->player_info->stat->mp_max;
    }
    if (pnj->drop != -1 && pnj->drop != -2 && pnj->anim == 0)
        get_drop(game, pnj);
    if (my_strcmp(pnj->name, "Runner") == 0
    && pnj->drop != -1 && pnj->drop != -2) {
        if (game->inv[pnj->drop]->quantity < 5)
            game->inv[pnj->drop - 1]->quantity += 2;
        pnj->nb++;
        pnj->drop = -1;
    }
    return 0;
}
