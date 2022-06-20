/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** generate pnj
*/

#include "rpg.h"

static void turn_pnj(game_t *game, pnj_t *tmp)
{
    int d_x = game->player->picture->pos.x - tmp->entity->picture->pos.x;
    int d_y = game->player->picture->pos.y - tmp->entity->picture->pos.y;

    if (abs(d_x) > abs(d_y))
        if (game->player->picture->pos.x - tmp->entity->picture->pos.x < 0)
            tmp->entity->picture->rect.top = 32;
        else
            tmp->entity->picture->rect.top = 64;
    else
        if (game->player->picture->pos.y - tmp->entity->picture->pos.y < 0)
            tmp->entity->picture->rect.top = 96;
        else
            tmp->entity->picture->rect.top = 0;
}

void move_pnj(game_t *game)
{
    pnj_t *tmp = game->pnj;

    while (tmp != NULL) {
        manage_clock(tmp->entity->clock, game->pause);
        if (tmp->anim == 1 && game->pause == 0 && tmp->entity->clock->seconds
        > 0.35) {
            tmp->entity->picture->rect.left += 32;
            restart_clock(tmp->entity->clock);
            turn_pnj(game, tmp);
        }
        if (tmp->entity->picture->rect.left > 96)
            tmp->entity->picture->rect.left = 0;
        sfSprite_setTextureRect(tmp->entity->picture->sprite,
        tmp->entity->picture->rect);
        tmp = tmp->next;
    }
}

int get_intersects(scene_t *scene, sfEvent event, pnj_t *tmp)
{
    sfIntRect rect1 = {0, 0, 0, 0};
    sfIntRect rect2 = {0, 0, 0, 0};
    rect1 = (sfIntRect) {scene->game->player->picture->pos.x,
    scene->game->player->picture->pos.y, 32, 32};
    rect2 = (sfIntRect) {tmp->entity->picture->pos.x,
    tmp->entity->picture->pos.y, 32, 32};
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF &&
    scene->game->activate_textbox == 0 && get_dialogs(scene->game->dialogs,
    tmp->name, tmp->nb) != NULL && sfIntRect_intersects(&rect1, &rect2,
    NULL) == 1 && scene->game->pause == 0) {
        scene->game->pnj_tmp = tmp;
        main_quest(tmp, scene);
        manage_event_textbox(scene, 1, tmp->name, tmp->nb);
        give_item(scene->game, tmp);
        trainer_quest(tmp, scene);
        desertor_quest(tmp, scene);
        snow_quest(tmp, scene);
        return (0);
    }
    return (1);
}

int manage_pnj_event(scene_t *scene, sfEvent event)
{
    pnj_t *tmp = scene->game->pnj;

    while (tmp != NULL) {
        if (get_intersects(scene, event, tmp) == 0)
            return (0);
        tmp = tmp->next;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyF &&
    scene->game->activate_textbox == 1) {
        manage_event_textbox(scene, 0, NULL, 0);
    }
    return 0;
}
