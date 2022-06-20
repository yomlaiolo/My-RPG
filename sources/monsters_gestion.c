/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** monsters_gestion
*/

#include "rpg.h"

int *manage_attack_colision(game_t *game, int *tab, monster_t *tmp)
{
    sfIntRect rect1 = (sfIntRect) {game->player->picture->pos.x,
    game->player->picture->pos.y, 32, 32};
    sfIntRect rect2 = (sfIntRect) {tmp->entity->picture->pos.x,
    tmp->entity->picture->pos.y, 32, 32};
    tab = entity_colision(tmp->entity, game);
    if (sfIntRect_intersects(&rect1, &rect2, NULL) == 1) {
        if (tmp->attack_clock->seconds > 1 &&
        game->player_info->stat->hp > 0 && tmp->hp > 0 &&
        game->player_info->last_damage->seconds > 2) {
            tmp->phase = 1;
            game->player_info->stat->hp -= tmp->attack;
            restart_clock(tmp->attack_clock);
            restart_clock(game->player_info->last_damage);
        }
        tab[0] = 1;
        tab[1] = 1;
        tab[2] = 1;
        tab[3] = 1;
    }
    return tab;
}

void manage_m_to_m_colisions(monster_t *tmp, monster_t *tmp2, int count,
int *tab2)
{
    int count2 = 0;

    while (tmp2 != NULL) {
        count2++;
        if (count != count2 && tmp2->hp > 0 && tmp2->max_hp <= 5)
            tab2 = monster_separator(tmp->entity, tmp2->entity,
            tab2);
        tmp2 = tmp2->next;
    }
}

void manage_phases(game_t *game, monster_t *tmp)
{
    manage_clock(tmp->attack_clock, game->pause);
    manage_clock(tmp->poison_clock, game->pause);
    if (tmp->phase == 1
    && tmp->attack_clock->seconds >= 1.5) {
        tmp->phase = 0;
        restart_clock(tmp->attack_clock);
    }
    if (get_distance(game->player->picture->pos, tmp->entity->picture->pos)
        < 70 && tmp->poison_clock->seconds > 0.8 &&
        get_pos(tmp) == 1 && tmp->hp > 0 &&
        game->player_info->antidote == 0 && game->pause == 0) {
            game->player_info->stat->hp -= tmp->attack / 8;
            restart_clock(tmp->poison_clock);
        }
}

void manage_clock_and_move(game_t *game, int *tab, int *tab2, monster_t *tmp)
{
    manage_clock(tmp->entity->clock, game->pause);
    manage_clock(tmp->attack_clock, game->pause);
    manage_clock(game->player_info->last_damage, game->pause);
    if (get_distance(game->player->picture->pos,
    tmp->entity->picture->pos) < 200) {
        final_move(game, tab, tab2, tmp);
    } else if (tmp->entity->picture->rect.top >= 128)
        tmp->entity->picture->rect.top -= 128;
}

void move_monster(game_t *game)
{
    monster_t *tmp = game->monsters;
    monster_t *tmp2 = game->monsters;
    int *tab = NULL;
    int tab2[4] = {0, 0, 0, 0};
    int count = 0;

    while (tmp != NULL) {
        manage_phases(game, tmp);
        if (tmp->hp > 0) {
            tab = manage_attack_colision(game, tab, tmp);
            count++;
            tmp2 = game->monsters;
            manage_m_to_m_colisions(tmp, tmp2, count, tab2);
            manage_clock_and_move(game, tab, tab2, tmp);
            free(tab);
        }
        tmp = tmp->next;
    }
}
