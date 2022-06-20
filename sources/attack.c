/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** attack
*/

#include "rpg.h"

int set_attack_values(game_t *game, int already)
{
    monster_t *tmp = game->monster_tmp;

    tmp->hp -= game->player_info->stat->atk;
    already++;
    game->attack = 0;
    return already;
}

int verify_attack3(entity_t *entity, game_t *game, int top, int already)
{
    monster_t *tmp = game->monster_tmp;

    if (top == 256 && tmp->entity->picture->pos.x >
    entity->picture->pos.x - 16 && tmp->entity->picture->pos.x <
    entity->picture->pos.x + 20 && tmp->entity->picture->pos.y >=
    entity->picture->pos.y && tmp->entity->picture->pos.y <
    entity->picture->pos.y + 48)
        already = set_attack_values(game, already);
    if (top == 288 && tmp->entity->picture->pos.x + 32 <
    entity->picture->pos.x + 8 && tmp->entity->picture->pos.x >
    entity->picture->pos.x - 40 && tmp->entity->picture->pos.y >
    entity->picture->pos.y - 16 && tmp->entity->picture->pos.y <
    entity->picture->pos.y + 48)
        already = set_attack_values(game, already);
    return already;
}

int verify_attack2(entity_t *entity, game_t *game, int top, int already)
{
    monster_t *tmp = game->monster_tmp;

    already = verify_attack3(entity, game, top, already);
    if (top == 320 && tmp->entity->picture->pos.x >
    entity->picture->pos.x + 16 && tmp->entity->picture->pos.x <
    entity->picture->pos.x + 40 && tmp->entity->picture->pos.y >
    entity->picture->pos.y - 16 && tmp->entity->picture->pos.y <
    entity->picture->pos.y + 48)
        already = set_attack_values(game, already);
    if (top == 352 && tmp->entity->picture->pos.x >
    entity->picture->pos.x - 16 && tmp->entity->picture->pos.x <
    entity->picture->pos.x + 20 && tmp->entity->picture->pos.y + 24
    <= entity->picture->pos.y && tmp->entity->picture->pos.y
    + 48 > entity->picture->pos.y)
        already = set_attack_values(game, already);
    return already;
}

void verify_attack(entity_t *entity, game_t *g)
{
    int already = 0;
    int top = entity->picture->rect.top;
    monster_t *tmp = g->monsters;
    static int sound = 0;
    int n = rand() % 4;
    if (entity->picture->nb_rect == 3 && already == 0 && g->attack == 1) {
        g->player_info->stat->mp -= 100 * g->d_time /
        g->player_info->stat->endurence;
        if (sfSound_getStatus(g->sword[n]->sound) != sfPlaying && sound == 0) {
            sfSound_play(g->sword[n]->sound);
            sound = 1;
        }
        recup_mp(g);
        while (tmp != NULL) {
            g->monster_tmp = tmp;
            already = verify_attack2(entity, g, top, already);
            tmp = tmp->next;
        }
    } else
        sound = 0;
}

void attack(entity_t *entity, game_t *game)
{
    move_pixel(entity, game);
    sfSprite_setPosition(entity->framebuffer->sprite->sprite,
    entity->framebuffer->sprite->pos);
    if (game->move[5] == 1) {
        if (entity->picture->rect.top >= 128)
            entity->picture->rect.top += 128;
        else {
            entity->picture->nb_rect = 0;
            entity->picture->rect.top += 384;
        }
    }
}
