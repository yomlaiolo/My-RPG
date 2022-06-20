/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** potion
*/

#include "rpg.h"

void use_potions(scene_t *scene, int i)
{
    switch (scene->game->inv[i]->id) {
        case 0:
            use_potion_heal(scene, i);
            break;
        case 1:
            use_potion_atk(scene, i);
            break;
        case 2:
            use_potion_endurance(scene, i);
            break;
        case 3:
            use_potion_fire(scene, i);
            break;
        case 4:
            use_potion_antidote(scene, i);
            break;
        case 5:
            use_potion_ice(scene, i);
            break;
    }
}

void use_potion_heal(scene_t *scene, int i)
{
    if (scene->game->player_info->stat->hp < scene->game->player_info->
    stat->hp_max) {
        scene->game->player_info->stat->hp += 40;
        scene->game->inv[i]->quantity--;
        if (scene->game->player_info->stat->hp > scene->game->
        player_info->stat->hp_max)
            scene->game->player_info->stat->hp = scene->game->
            player_info->stat->hp_max;
    }
}

void timer_potion(scene_t *scene)
{
    if (scene->game->inv[1]->clock != NULL)
        timer_atk(scene);
    if (scene->game->inv[2]->clock != NULL)
        timer_endurance(scene);
    if (scene->game->inv[3]->clock != NULL)
        timer_fire(scene);
    if (scene->game->inv[4]->clock != NULL)
        timer_antidote(scene);
    if (scene->game->inv[5]->clock != NULL)
        timer_ice(scene);
}

void manage_zone(game_t *game)
{
    int desert[4] = {305, 1232, 2289, 4800};
    int desert2[4] = {1232, 2920, 2980, 4800};
    int snow[4] = {3500, 4800, 160, 4800};

    if (((game->player->picture->pos.x > desert[0] && game->player->picture->
    pos.x < desert[1] && game->player->picture->pos.y > desert[2] && game->
    player->picture->pos.y < desert[3]) || (game->player->picture->pos.x >
    desert2[0] && game->player->picture->pos.x < desert2[1] && game->player->
    picture->pos.y > desert2[2] && game->player->picture->pos.y < desert2[3]))
    && game->player_info->fire == 0)
        game->player_info->stat->hp -= 8 * game->d_time;
    if ((game->player->picture->pos.x > snow[0] && game->player->picture->pos.x
    < snow[1] && game->player->picture->pos.y > snow[2] && game->player->
    picture->pos.y < snow[3]) && game->player_info->ice == 0)
        game->player_info->stat->hp -= 8 * game->d_time;
}

void select_potion(scene_t *scene, sfEvent event)
{
    for (int i = 0; i < 6; i++) {
        if (event.type == sfEvtMouseButtonReleased && scene->mouse_pos.x >=
        scene->game->inv[i]->sprite->pos.x && scene->mouse_pos.x <=
        scene->game->inv[i]->sprite->pos.x + 2400 && scene->mouse_pos.y >=
        scene->game->inv[i]->sprite->pos.y && scene->mouse_pos.y <=
        scene->game->inv[i]->sprite->pos.y + 36) {
            set_status_inv(scene, i);
        }
        if (event.type == sfEvtMouseButtonReleased &&
        scene->game->inv[i]->sprite2->status == 1 && scene->mouse_pos.x >=
        scene->game->inv[i]->use->pos.x && scene->mouse_pos.x <=
        scene->game->inv[i]->use->pos.x + 88 && scene->mouse_pos.y >=
        scene->game->inv[i]->use->pos.y && scene->mouse_pos.y <=
        scene->game->inv[i]->use->pos.y + 30 && scene->game->inv[i]->quantity
        > 0) {
            use_potions(scene, i);
        }
    }
}
