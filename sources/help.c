/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** help functions
*/

#include "rpg.h"

void display_help(sfRenderWindow *window, intro_t *intro)
{
    if (intro->help_open == 1 && intro->how_to_play != NULL) {
        sfRenderWindow_drawSprite(window, intro->how_to_play->sprite, NULL);
    }
    if (intro->help_open == 0) {
        intro->how_to_play = malloc(sizeof(sprite_t));
        load_sprite(intro->how_to_play, "ressources/intro/how_to_play.png",
        (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080});
        intro->help_open = 1;
    }
}

void close_help(intro_t *intro)
{
    if (intro->help_open == 1) {
        intro->help_open = 0;
        destroy_sprite(intro->how_to_play);
        intro->help->status = 0;
    }
}
