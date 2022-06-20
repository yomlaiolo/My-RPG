/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** monster_action
*/

#include "rpg.h"

void phase_one_move(game_t *game, int *tab, int *tab2, monster_t *tmp)
{
    if (tmp->entity->picture->pos.x < game->player->picture->pos.x &&
    tab[0] == 0 && tab2[0] == 0) {
        tmp->entity->picture->pos.x -= rand() % 50 * tmp->speed * game->d_time;
        tmp->entity->picture->rect.top = 192;
    }
    if (tmp->entity->picture->pos.x > game->player->picture->pos.x &&
    tab[3] == 0 && tab2[3] == 0) {
        tmp->entity->picture->pos.x += rand() % 50 * tmp->speed * game->d_time;
        tmp->entity->picture->rect.top = 160;
    }
    if (tmp->entity->picture->pos.y < game->player->picture->pos.y &&
    tab[2] == 0 && tab2[2] == 0) {
        tmp->entity->picture->pos.y -= rand() % 50 * tmp->speed * game->d_time;
        tmp->entity->picture->rect.top = 128;
    }
    if (tmp->entity->picture->pos.y > game->player->picture->pos.y &&
    tab[1] == 0 && tab2[1] == 0) {
        tmp->entity->picture->pos.y += rand() % 50 * tmp->speed * game->d_time;
        tmp->entity->picture->rect.top = 224;
    }
}

void phase_zero_move(game_t *game, int *tab, monster_t *tmp)
{
    if (tmp->entity->picture->pos.x < game->player->picture->pos.x &&
    tab[0] == 0) {
        tmp->entity->picture->pos.x += rand() % 50 * tmp->speed * game->d_time;
        tmp->entity->picture->rect.top = 192;
    }
    if (tmp->entity->picture->pos.x > game->player->picture->pos.x &&
    tab[3] == 0) {
        tmp->entity->picture->pos.x -= rand() % 50 * tmp->speed * game->d_time;
        tmp->entity->picture->rect.top = 160;
    }
    if (tmp->entity->picture->pos.y < game->player->picture->pos.y &&
    tab[2] == 0) {
        tmp->entity->picture->pos.y += rand() % 50 * tmp->speed * game->d_time;
        tmp->entity->picture->rect.top = 128;
    }
    if (tmp->entity->picture->pos.y > game->player->picture->pos.y &&
    tab[1] == 0) {
        tmp->entity->picture->pos.y -= rand() % 50 * tmp->speed * game->d_time;
        tmp->entity->picture->rect.top = 224;
    }
}

void final_move(game_t *game, int *tab, int *tab2, monster_t *tmp)
{
    tmp->is_moving = 1;
    if (tmp->phase == 1)
        phase_one_move(game, tab, tab2, tmp);
    else
        phase_zero_move(game, tab, tmp);
    restart_clock(tmp->entity->clock);
    sfSprite_setPosition(tmp->entity->picture->sprite,
    tmp->entity->picture->pos);
}

void put_n_pixel(framebuffer_t *framebuffer, int x, sfColor color)
{
    int ligne = 0;
    int col = 0;
    for (int i = 0; i < x; i++, col++) {
        if (col == framebuffer->width) {
            col = 0;
            ligne++;
        }
        put_pixel(framebuffer, col, ligne, color);
    }
}
