/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** potion bar functions
*/

#include "rpg.h"

static int init_text_for_potion_bar(potion_bar_t *potion_bar)
{
    load_text(potion_bar->entity->parole, (sfVector2f) {0, 0}, "", 15);
    if (potion_bar == NULL)
        return (84);
    return (0);
}

potion_bar_t **init_potion_bar(sfView *view)
{
    potion_bar_t **potion_bar = malloc(sizeof(potion_bar_t *) * 7);
    int x = sfView_getCenter(view).x + 30;
    int y = sfView_getCenter(view).y + 20;
    int left = 0;
    if (potion_bar == NULL)
        return (NULL);
    for (int i = 0; i < 6; i++) {
        potion_bar[i] = malloc(sizeof(potion_bar_t));
        potion_bar[i]->status = 0;
        if ((potion_bar[i]->entity = load_entity(potion_bar[i]->entity,
        "./ressources/game/potions_bar.png", (sfVector2f) {x, y},
        (sfIntRect) {left, 0, 15, 23})) == NULL)
            return (NULL);
        if (init_text_for_potion_bar(potion_bar[i]) == 84)
            return (NULL);
        left += 15;
        x += 50;
    }
    potion_bar[6] = NULL;
    return potion_bar;
}

static void set_potion_bar_position(game_t *game, int i)
{
    sfSprite_setPosition(game->potion_bar[i]->entity->picture->sprite,
    game->potion_bar[i]->entity->picture->pos);
    sfText_setPosition(game->potion_bar[i]->entity->parole->text,
    (sfVector2f) {game->potion_bar[i]->entity->picture->pos.x,
    game->potion_bar[i]->entity->picture->pos.y - 30});
}

void display_potion_bar(sfRenderWindow *window, game_t *game)
{
    int time_potion[6] = {0, 30, 30, 300, 120, 300};
    char *nb = NULL;

    for (int i = 0, x = 0; game->potion_bar[i] != NULL; i++)
        if (game->potion_bar[i]->status == 1 && game->inv[i]->status == 1) {
            nb = my_itoa(time_potion[i] - game->inv[i]->clock->seconds);
            game->potion_bar[i]->entity->picture->pos =
            sfRenderWindow_mapPixelToCoords(window,
            (sfVector2i) {80 + x, 900}, game->view);
            set_potion_bar_position(game, i);
            sfText_setString(game->potion_bar[i]->entity->parole->text, nb);
            sfRenderWindow_drawSprite(window,
            game->potion_bar[i]->entity->picture->sprite, NULL);
            sfRenderWindow_drawText(window,
            game->potion_bar[i]->entity->parole->text, NULL);
            if (my_strcmp(nb, "0") != 0)
                free(nb);
            x += 125;
        }
}

void destroy_potion_bar(potion_bar_t **potion_bar)
{
    for (int i = 0; i < 6; i++) {
        destroy_text(potion_bar[i]->entity->parole);
        potion_bar[i]->entity->parole = NULL;
        destroy_entity(potion_bar[i]->entity);
        free(potion_bar[i]);
    }
    free(potion_bar);
}
