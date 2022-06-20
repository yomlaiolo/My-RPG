/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** render_texture
*/

#include "rpg.h"

sprite_t *fill_sprite(char *path, sfIntRect rect,
sfVector2f pos)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sprite->pos = pos;
    sprite->nb_rect = 0;
    sprite->status = 0;
    sprite->clicked = 0;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    return (sprite);
}

sprite_t **create_sprite_tab(sprite_t **sprite_tab)
{
    sprite_tab = malloc(sizeof(sprite_t *) * 8);
    sprite_tab[0] = fill_sprite("./ressources/game/save.png",
    (sfIntRect) {0, 0, 32, 42}, (sfVector2f) {982, 768});
    sprite_tab[1] = fill_sprite("./ressources/game/lamp.png",
    (sfIntRect) {0, 0, 20, 35} , (sfVector2f) {943, 1063});
    sprite_tab[2] = fill_sprite("./ressources/game/lamp.png",
    (sfIntRect) {0, 0, 20, 30} , (sfVector2f) {942, 1127});
    sprite_tab[3] = fill_sprite("./ressources/game/village_entrance.png",
    (sfIntRect) {0, 0, 144, 76} , (sfVector2f) {924, 1224});
    sprite_tab[4] = fill_sprite("./ressources/game/marketred.png",
    (sfIntRect) {0, 0, 96, 120} , (sfVector2f) {1324, 1041});
    sprite_tab[5] = fill_sprite("./ressources/game/save.png",
    (sfIntRect) {0, 0, 32, 37} , (sfVector2f) {1122, 4444});
    sprite_tab[6] = fill_sprite("./ressources/game/save.png",
    (sfIntRect) {0, 0, 32, 37} , (sfVector2f) {2995, 4627});
    sprite_tab[7] = NULL;

    return sprite_tab;
}
