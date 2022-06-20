/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** monsters_colisions
*/

#include "rpg.h"

int *entity_colision2(entity_t *entity, game_t *game, int *tab, int i)
{
    if (entity->picture->pos.x + 33 >= game->map_block[i][0] &&
    entity->picture->pos.y + 32 >= game->map_block[i][2] &&
    entity->picture->pos.y <= game->map_block[i][3] - 12 &&
    entity->picture->pos.x <= game->map_block[i][1] - 42)
        tab[0] = 1;
    if (entity->picture->pos.y + 10 <= game->map_block[i][3] &&
    entity->picture->pos.x + 25 >= game->map_block[i][0] &&
    entity->picture->pos.x + 5 <= game->map_block[i][1] &&
    entity->picture->pos.y + 16 >= game->map_block[i][2])
        tab[1] = 1;
    return tab;
}

int *entity_colision(entity_t *entity, game_t *game)
{
    int *tab = malloc(sizeof(int) * 4);
    tab[0] = 0;
    tab[1] = 0;
    tab[2] = 0;
    tab[3] = 0;
    for (int i = 0; game->map_block[i]; i++) {
        tab = entity_colision2(entity, game, tab, i);
        if (entity->picture->pos.y + 33 >= game->map_block[i][2] &&
        entity->picture->pos.x + 25 >= game->map_block[i][0] &&
        entity->picture->pos.x + 5 <= game->map_block[i][1] &&
        entity->picture->pos.y + 32 <= game->map_block[i][3])
            tab[2] = 1;
        if (entity->picture->pos.x <= game->map_block[i][1] &&
        entity->picture->pos.y + 32 >= game->map_block[i][2] &&
        entity->picture->pos.y <= game->map_block[i][3] - 12 &&
        entity->picture->pos.x >= game->map_block[i][0] - 12)
            tab[3] = 1;
    }
    return tab;
    free(tab);
}

int *monster_separator2(entity_t *entity, entity_t *entity2, int *tab)
{
    if (entity->picture->pos.x + 33 >= entity2->picture->pos.x &&
    entity->picture->pos.y + 32 >= entity2->picture->pos.y &&
    entity->picture->pos.y <= entity2->picture->pos.y + 32 - 12 &&
    entity->picture->pos.x <= entity2->picture->pos.x - 42)
        tab[0] = 1;
    if (entity->picture->pos.y + 10 <= entity2->picture->pos.y + 32 &&
    entity->picture->pos.x + 25 >= entity2->picture->pos.x &&
    entity->picture->pos.x + 5 <= entity2->picture->pos.x + 32 &&
    entity->picture->pos.y + 16 >= entity2->picture->pos.y)
        tab[1] = 1;
    return tab;
}

int *monster_separator(entity_t *entity, entity_t *entity2, int *tab)
{
    tab = monster_separator2(entity, entity2, tab);
    if (entity->picture->pos.y + 33 >= entity2->picture->pos.y &&
    entity->picture->pos.x + 25 >= entity2->picture->pos.x &&
    entity->picture->pos.x + 5 <= entity2->picture->pos.x + 32 &&
    entity->picture->pos.y + 32 <= entity2->picture->pos.y + 32)
        tab[2] = 1;
    if (entity->picture->pos.x <= entity2->picture->pos.x + 32 &&
    entity->picture->pos.y + 32 >= entity2->picture->pos.y &&
    entity->picture->pos.y <= entity2->picture->pos.y + 32 - 12 &&
    entity->picture->pos.x >= entity2->picture->pos.x - 12)
        tab[3] = 1;
    return tab;
}

monster_t *init_monster(int **tab, int i)
{
    monster_t *monster = malloc(sizeof(monster_t));
    char *texture = select_monster_texture(tab, i);

    monster->entity = NULL;
    if ((monster->entity = load_entity(monster->entity,
    texture, (sfVector2f) {tab[i][0], tab[i][1]},
    (sfIntRect) {0, 0, 32, 32})) == NULL)
        return (NULL);
    init_monster_clock(monster);
    set_monster_info(monster, tab, i);
    monster->framebuffer = framebuffer_create(40, 40, monster->pos_start);
    put_n_pixel(monster->framebuffer, 10, sfBlack);
    monster->next = NULL;
    monster->life_bar = malloc(sizeof(sprite_t));
    if (load_sprite(monster->life_bar, "./ressources/game/mob_life.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 32, 3}) == 84)
        return (NULL);
    return monster;
}
