/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** Load functions
*/

#include "rpg.h"

void change_rect(sprite_t *picture)
{
    int rect[4] = {0, 1, 2, 3};

    if (picture->nb_rect == 4)
        picture->nb_rect = 0;
    picture->rect.left = 32 * rect[picture->nb_rect];
    picture->nb_rect += 1;
    sfSprite_setTextureRect(picture->sprite, picture->rect);
}

void monster_rect(game_t *game)
{
    monster_t *tmp = game->monsters;

    while (game->monsters != NULL) {
        change_rect(game->monsters->entity->picture);
        game->monsters = game->monsters->next;
    }
    game->monsters = tmp;
}

void clock_rect(entity_t *entity, game_t *game)
{
    if (game->pause == 2)
        entity->clock->seconds = 0;
    if (entity->clock->seconds >= 0.3) {
        monster_rect(game);
        change_rect(entity->picture);
        restart_clock(entity->clock);
        game->attack = 1;
    }
    if (entity->clock->seconds >= 0.15 && entity->picture->rect.top > 224) {
        if (entity->picture->rect.left < 96 ||
        entity->clock->seconds >= 0.25) {
            change_rect(entity->picture);
            monster_rect(game);
            restart_clock(entity->clock);
            game->attack = 1;
        }
    }
}

void stay(entity_t *entity, game_t *game)
{
    static int is_moving = 0;

    entity->clock->times = sfClock_getElapsedTime(entity->clock->clock);
    entity->clock->seconds = entity->clock->times.microseconds / 1000000.0;
    clock_rect(entity, game);
    attack(entity, game);
    if (game->move[0] == 0 && game->move[1] == 0 && game->move[2] == 0 &&
    game->move[3] == 0) {
        if (is_moving == 0 || entity->picture->rect.top >= 128)
            entity->picture->rect.top -= 128;
        is_moving = 1;
    } else
        is_moving = 0;
    if (game->move[5] == 1)
        verify_attack(entity, game);
    sfSprite_setTextureRect(entity->picture->sprite, entity->picture->rect);
}
