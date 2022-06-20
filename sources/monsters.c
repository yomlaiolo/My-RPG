/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** generate_monsters
*/

#include "rpg.h"

char *select_monster_texture(int **tab, int i)
{
    char *texture = "./ressources/game/ghost.png";

    if (tab[i][4] == 1)
        texture = "./ressources/game/ghost.png";
    if (tab[i][4] == 2)
        texture = "./ressources/game/bat.png";
    if (tab[i][4] == 3)
        texture = "./ressources/game/lizard.png";
    if (tab[i][4] == 4)
        texture = "./ressources/game/doctor.png";
    if (tab[i][4] == 5)
        texture = "./ressources/game/skelet.png";
    if (tab[i][4] == 42)
        texture = "./ressources/game/final_boss.png";
    if (tab[i][4] == 7)
        texture = "./ressources/game/lands_boss.png";
    if (tab[i][4] == 8)
        texture = "./ressources/game/lands_sbire.png";
    return texture;
}

void set_monster_info(monster_t *monster, int **tab, int i)
{
    monster->pos_start = (sfVector2f) {tab[i][0], tab[i][1]};
    monster->hp = tab[i][2];
    monster->is_moving = 0;
    monster->speed = 1;
    monster->dead = 0;
    monster->max_hp = tab[i][2];
    monster->attack = tab[i][3];
    monster->phase = 0;
}

monster_t *generate_monsters(void)
{
    monster_t *monster = NULL;
    monster_t *temp = monster;
    int **tab = NULL;

    tab = parsing_stairs(tab, "./game_files/monsters.rpg");
    if (tab == NULL || (monster = init_monster(tab, 0)) == NULL)
        return (NULL);
    temp = monster;
    for (int i = 1; tab[i]; i++) {
        if ((temp->next = init_monster(tab, i)) == NULL)
            return (NULL);
        temp = temp->next;
    }
    destroy_int_array(tab);
    return monster;
}

void respawn_monster(monster_t *tmp, game_t *game)
{
    if (tmp->dead == 2 && tmp->attack_clock->seconds > 15
    && game->pause == 0) {
        tmp->hp = tmp->max_hp;
        tmp->dead = 0;
        tmp->entity->picture->pos = tmp->pos_start;
        sfSprite_setPosition(tmp->entity->picture->sprite,
        tmp->entity->picture->pos);
    }
}

void restart_monsters(monster_t *monster, game_t *game)
{
    monster_t *tmp = monster;

    while (tmp != NULL) {
        if (tmp->dead == 1 && tmp->hp <= 5) {
            restart_clock(tmp->attack_clock);
            restart_clock(tmp->entity->clock);
            tmp->dead = 2;
        }
        manage_clock(tmp->attack_clock, game->pause);
        manage_clock(tmp->entity->clock, game->pause);
        if (tmp->entity->clock->seconds > 0.1 && game->pause == 0) {
            restart_clock(tmp->entity->clock);
            update_pixel(tmp->framebuffer, sfBlack, sfBlack);
        }
        respawn_monster(tmp, game);
        tmp = tmp->next;
    }
}
