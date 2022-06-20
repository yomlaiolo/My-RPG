/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** inv
*/

#include "rpg.h"

void set_pos_inv(game_t *g, int i, sfRenderWindow *w)
{
    if (g->inv[i]->quantity > 5)
        g->inv[i]->quantity = 5;
    g->inv[i]->quantity_text->pos = sfRenderWindow_mapPixelToCoords
    (w, (sfVector2i) {970, 50 + i * 160}, g->view);
    g->inv[i]->sprite->pos = sfRenderWindow_mapPixelToCoords
    (w, (sfVector2i) {1200, 50 + i * 160}, g->view);
    g->inv[i]->text->pos = sfRenderWindow_mapPixelToCoords
    (w, (sfVector2i) {1350, 50 + i * 160}, g->view);
    g->inv[i]->use->pos = sfRenderWindow_mapPixelToCoords
    (w, (sfVector2i) {147, 450}, g->view);
    set_var_inv(g, i, w);
}

void set_var_inv(game_t *g, int i, sfRenderWindow *w)
{
    char *nb = my_itoa(g->inv[i]->quantity);
    char *str = my_strcat(nb, " / 5");

    sfText_setPosition(g->inv[i]->text->text, g->inv[i]->text->pos);
    sfText_setPosition(g->inv[i]->quantity_text->text, g->inv[i]->
    quantity_text->pos);
    sfSprite_setPosition(g->inv[i]->sprite->sprite, g->inv[i]->sprite->pos);
    sfSprite_setPosition(g->inv[i]->use->sprite, g->inv[i]->use->pos);
    sfText_setString(g->inv[i]->quantity_text->text, str);
    sfSprite_setScale(g->inv[i]->sprite->sprite, (sfVector2f) {g->scale,
    g->scale});
    sfText_setScale(g->inv[i]->text->text, (sfVector2f) {g->scale, g->scale});
    sfText_setScale(g->inv[i]->quantity_text->text, (sfVector2f) {g->scale,
    g->scale});
    sfRenderWindow_drawText(w, g->inv[i]->text->text, NULL);
    sfRenderWindow_drawText(w, g->inv[i]->quantity_text->text, NULL);
    sfRenderWindow_drawSprite(w, g->inv[i]->sprite->sprite, NULL);
    free(str);
    if (my_strcmp(nb, "0") != 0)
        free(nb);
}

void malloc_set_inv(game_t *g, int i)
{
    g->inv[i] = malloc(sizeof(item_t));
    g->inv[i]->quantity_text = malloc(sizeof(text_t));
    g->inv[i]->text = malloc(sizeof(text_t));
    g->inv[i]->sprite = malloc(sizeof(sprite_t));
    g->inv[i]->sprite2 = malloc(sizeof(sprite_t));
    g->inv[i]->use = malloc(sizeof(sprite_t));
    g->inv[i]->id = i;
    g->inv[i]->status = 0;
    g->inv[i]->quantity = 0;
    g->inv[i]->clock = NULL;
    g->inv[i]->sprite2->status = 0;
}

int set_inv(game_t *game, int i, int x)
{
    char *str = NULL;
    char *nb = NULL;

    malloc_set_inv(game, i);
    nb = my_itoa(game->inv[i]->quantity);
    str = my_strcat(nb, " / 5");
    if (load_text(game->inv[i]->quantity_text, (sfVector2f) {1450, x},
    str, 25) == 84) {
        free(str);
        return 84;
    }
    free(str);
    if (my_strcmp(nb, "0") != 0)
        free(nb);
    if (load_sprite(game->inv[i]->sprite, "ressources/game/potions.png",
    (sfVector2f) {300, 300 + i * 50}, (sfIntRect) {i * 24, 0, 24, 36}) == 84)
        return 84;
    return 0;
}

scene_t *manage_inventory(scene_t *scene, sfEvent event)
{
    if (scene->scene == 2 && scene->game->is_inv == 1
    && event.type == sfEvtKeyReleased
    && (event.key.code == sfKeyE || event.key.code == sfKeyEscape)) {
        scene->game->is_inv = 0;
        scene->game->pause = 3;
        for (int i = 0; i < 6; i++)
            scene->game->inv[i]->sprite2->status = 0;
        return scene;
    }
    if (scene->scene == 2 && scene->game->is_inv == 0
    && scene->game->m_pause == 0 && scene->game->pause == 0
    && event.type == sfEvtKeyReleased && event.key.code == sfKeyE) {
        scene->game->is_inv = 1;
        scene->game->pause = 1;
        return scene;
    }
    return scene;
}
