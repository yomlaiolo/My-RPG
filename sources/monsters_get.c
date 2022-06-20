/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** monsters_get
*/

#include "rpg.h"

int get_pos(monster_t *tmp)
{
    if ((tmp->entity->picture->pos.x > 303 &&
    tmp->entity->picture->pos.x < 1311 &&
    tmp->entity->picture->pos.y > 2284 &&
    tmp->entity->picture->pos.y < 4756) ||
    (tmp->entity->picture->pos.x > 1330 &&
    tmp->entity->picture->pos.x < 2918 &&
    tmp->entity->picture->pos.y > 2978 &&
    tmp->entity->picture->pos.y < 4752))
        return (1);
    return (0);
}

float get_distance(sfVector2f pos1, sfVector2f pos2)
{
    float x = (pos1.x - 16) - (pos2.x - 16);
    float y = (pos1.y - 16) - (pos2.y - 16);

    return (sqrt(x * x + y * y));
}

void display_monster_alive(monster_t *tmp, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, tmp->entity->picture->sprite, NULL);
    calcul_monster_life(tmp);
    tmp->life_bar->pos = tmp->entity->picture->pos;
    tmp->life_bar->pos.y -= 10;
    sfSprite_setPosition(tmp->life_bar->sprite, tmp->life_bar->pos);
    sfRenderWindow_drawSprite(window, tmp->life_bar->sprite, NULL);
}

void display_monster(sfRenderWindow *window, monster_t *monster, game_t *game)
{
    monster_t *tmp = monster;

    while (tmp != NULL) {
        if (tmp->hp > 0)
            display_monster_alive(tmp, window);
        if (tmp->hp <= 0 && tmp->max_hp <= 5)
            display_particles(window, tmp->framebuffer);
        monster_quest(tmp, game);
        if (tmp->dead == 0 && tmp->max_hp <= 5 && tmp->hp <= 0) {
            tmp->dead = 1;
            game->player_info->stat->monsters_killed++;
            tmp->entity->picture->pos = (sfVector2f) {- 100, - 100};
            sfSprite_setPosition(tmp->entity->picture->sprite,
            tmp->entity->picture->pos);
        }
        tmp = tmp->next;
    }
    restart_monsters(monster, game);
}

void init_monster_clock(monster_t *monster)
{
    monster->attack_clock = malloc(sizeof(clockk_t));
    monster->poison_clock = malloc(sizeof(clockk_t));
    init_clock(monster->attack_clock);
    init_clock(monster->poison_clock);
}
