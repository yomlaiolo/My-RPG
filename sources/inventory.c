/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** inventory
*/

#include "rpg.h"

char **get_text(void)
{
    char **tab = malloc(sizeof(char *) * 6);

    tab[0] = "Heal potion";
    tab[1] = "Strength potion";
    tab[2] = "Endurance potion";
    tab[3] = "Fire elixir";
    tab[4] = "Antidote elixir";
    tab[5] = "Ice elixir";
    return tab;
}

int init_inventory(game_t *game)
{
    game->inv = malloc(sizeof(item_t *) * 6);
    game->inventory_back = malloc(sizeof(sprite_t));
    if (load_sprite(game->inventory_back, "ressources/game/inv.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080}) == 84)
        return 84;
    sfSprite_setScale(game->inventory_back->sprite, (sfVector2f) {game->scale,
    game->scale});
    game->is_inv = 0;
    return 0;
}

int load_sprite_inv(game_t *game, int i, sfRenderWindow *window)
{
    if (load_sprite(game->inv[i]->use, "ressources/game/use.png",
    sfRenderWindow_mapPixelToCoords(window, (sfVector2i) {200, 400},
    game->view), (sfIntRect) {0, 0, 88, 30}) == 84)
        return 84;
    if (load_sprite(game->inv[i]->sprite2, "ressources/game/potions.png",
    sfRenderWindow_mapPixelToCoords(window, (sfVector2i) {250, 250},
    game->view), (sfIntRect) {i * 24, 0, 24, 36}) == 84)
        return 84;
    return 0;
}

int load_inventory(game_t *game, sfRenderWindow *window)
{
    char **tab = get_text();

    if (init_inventory(game) == 84)
        return 84;
    for (int i = 0, x = 310; i < 6; i++) {
        if (set_inv(game, i, x) == 84)
            return 84;
        if (load_text(game->inv[i]->text, sfRenderWindow_mapPixelToCoords
        (window, (sfVector2i) {1200, x += 100}, game->view), tab[i], 20) == 84)
            return 84;
        if (load_sprite_inv(game, i, window) == 84)
            return 84;
        sfSprite_setScale(game->inv[i]->sprite2->sprite,
        (sfVector2f) {1.5, 1.5});
    }
    free(tab);
    return 0;
}

void inventory(game_t *g, sfRenderWindow *w)
{
    sfVector2f p = sfRenderWindow_mapPixelToCoords(w, (sfVector2i)
    {0, 0}, g->view);

    if (g->is_inv == 0)
        return;
    sfSprite_setPosition(g->inventory_back->sprite, p);
    sfRenderWindow_drawSprite(w, g->inventory_back->sprite, NULL);
    sfSprite_setScale(g->inventory_back->sprite,
    (sfVector2f) {g->scale, g->scale});
    p = sfRenderWindow_mapPixelToCoords(w, (sfVector2i) {1000, 530}, g->view);
    for (int i = 0; i < 6; i++) {
        set_pos_inv(g, i, w);
        if (g->inv[i]->sprite2->status == 1) {
            sfSprite_setPosition(g->inv[i]->sprite2->sprite, g->inv[i]->
            sprite2->pos);
            sfSprite_setPosition(g->inv[i]->use->sprite, g->inv[i]->use->pos);
            sfRenderWindow_drawSprite(w, g->inv[i]->sprite2->sprite, NULL);
            sfRenderWindow_drawSprite(w, g->inv[i]->use->sprite, NULL);
        }
    }
}
