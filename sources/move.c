/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** move
*/

#include "rpg.h"

void recup_mp(game_t *game)
{
    game->player_info->recup = 1;
    restart_clock(game->player_info->clock);
}

void set_move(game_t *game)
{
    if (game->move[0] == 1 && game->count->count1 == 0)
        game->player->picture->pos.x += game->speed * game->d_time;
    if (game->move[1] == 1 && game->count->count2 == 0)
        game->player->picture->pos.y -= game->speed * game->d_time;
    if (game->move[2] == 1 && game->count->count3 == 0)
        game->player->picture->pos.y += game->speed * game->d_time;
    if (game->move[3] == 1 && game->count->count4 == 0)
        game->player->picture->pos.x -= game->speed * game->d_time;
    if (game->player_info->stat->mp <= 10)
        game->move[5] = 0;
}

void move_event(game_t *game)
{
    if (game->move[4] == 1 && game->player_info->stat->mp > 0 && (game->move[0]
    == 1 || game->move[1] == 1 || game->move[2] == 1 || game->move[3] == 1)) {
        update_pixel(game->player->framebuffer, (sfColor) {62, 53, 70, 255},
        (sfColor) {62, 53, 70, 255});
        game->speed = 130;
        game->player_info->stat->mp -= 25 * game->d_time /
        game->player_info->stat->endurence;
    } else {
        game->speed = 70;
        if (game->player_info->recup == 1 && game->player_info->stat->mp <
        game->player_info->stat->mp_max && sfClock_getElapsedTime(game->
        player_info->clock->clock).microseconds / 1000000.0 > 0.8)
            game->player_info->stat->mp += 15 * game->d_time;
    }
    set_move(game);
}

void move_conds(game_t *game, int i)
{
    if (game->player->picture->pos.x + 33 >= game->map_block[i][0] &&
    game->player->picture->pos.y + 32 >= game->map_block[i][2] &&
    game->player->picture->pos.y <= game->map_block[i][3] - 12 &&
    game->player->picture->pos.x <= game->map_block[i][1] - 42)
        game->count->count1++;
    if (game->player->picture->pos.y + 10 <= game->map_block[i][3] &&
    game->player->picture->pos.x + 25 >= game->map_block[i][0] &&
    game->player->picture->pos.x + 5 <= game->map_block[i][1] &&
    game->player->picture->pos.y + 16 >= game->map_block[i][2])
        game->count->count2++;
}

void move_pixel(entity_t *entity, game_t *game)
{
    if (game->move[0] == 1 && game->pause == 0) {
        entity->picture->rect.top = 192;
        entity->framebuffer->sprite->pos.x = entity->picture->pos.x - 10;
        entity->framebuffer->sprite->pos.y = entity->picture->pos.y + 18;
    }
    if (game->move[3] == 1 && game->pause == 0) {
        entity->framebuffer->sprite->pos.x = entity->picture->pos.x + 13;
        entity->framebuffer->sprite->pos.y = entity->picture->pos.y + 18;
        entity->picture->rect.top = 160;
    }
    if (game->move[1] == 1 && game->pause == 0) {
        entity->picture->rect.top = 224;
        entity->framebuffer->sprite->pos.x = entity->picture->pos.x + 3;
        entity->framebuffer->sprite->pos.y = entity->picture->pos.y + 30;
    }
    if (game->move[2] == 1 && game->pause == 0) {
        entity->picture->rect.top = 128;
        entity->framebuffer->sprite->pos.x = entity->picture->pos.x + 3;
        entity->framebuffer->sprite->pos.y = entity->picture->pos.y + 12;
    }
}
