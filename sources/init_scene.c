/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** init_scene
*/

#include "rpg.h"

sprite_t *init_sprite(char *path, sfVector2f pos, sfIntRect rect)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(path, NULL);
    if (sprite->texture == NULL || sprite->sprite == NULL) {
        free(sprite);
        return NULL;
    }
    sprite->nb_rect = 1;
    sprite->rect = rect;
    sprite->pos = pos;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sprite->status = 0;
    sprite->clicked = 0;
    return sprite;
}

int load_sprite_intro(intro_t *intro)
{
    if ((intro->play = init_sprite("./ressources/intro/start.png",
    (sfVector2f) {750, 380}, (sfIntRect) {0, 0, 400, 100})) == NULL)
        return 84;
    if ((intro->option = init_sprite("./ressources/intro/options.png",
    (sfVector2f) {820, 510}, (sfIntRect) {0, 0, 260, 50})) == NULL)
        return 84;
    if ((intro->help = init_sprite("./ressources/intro/help.png",
    (sfVector2f) {840, 600}, (sfIntRect) {0, 0, 200, 60})) == NULL)
        return 84;
    intro->how_to_play = NULL;
    intro->help_open = 0;
    if ((intro->quit = init_sprite("./ressources/intro/quit.png",
    (sfVector2f) {840, 690}, (sfIntRect) {0, 0, 200, 60})) == NULL)
        return 84;
    return 0;
}

intro_t *init_intro(opt_info_t *info)
{
    intro_t *intro = malloc(sizeof(intro_t));

    intro->intro = malloc(sizeof(sprite_t));
    if (load_sprite(intro->intro, "./ressources/intro/intro.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080}) == 84)
        return NULL;
    intro->music = malloc(sizeof(music_t));
    if (load_music(intro->music, "./ressources/music/intro.ogg", 0) == 84)
        return NULL;
    set_sound(intro->music, 50);
    if (load_sprite_intro(intro) == 84)
        return NULL;
    if ((intro->option_content = init_option(info)) == NULL)
        return NULL;
    return intro;
}

int set_text_lose(lose_t *lose)
{
    lose->text = malloc(sizeof(text_t));
    if (load_text_rpg(lose->text, (sfVector2f) {850, 400}, "Game Over", 50)
    == 84)
        return 84;
    sfText_setColor(lose->text->text, (sfColor) {60, 31, 20, 255});
    return 0;
}

lose_t *init_lose(void)
{
    lose_t *lose = malloc(sizeof(lose_t));
    lose->intro = malloc(sizeof(sprite_t));
    if (load_sprite(lose->intro, "./ressources/intro/intro.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080}) == 84)
        return NULL;
    if ((lose->quit = init_sprite("./ressources/intro/quit.png",
    (sfVector2f) {850, 700}, (sfIntRect) {0, 0, 200, 60})) == NULL)
        return NULL;
    if ((lose->menu = init_sprite("./ressources/lose/menu.png",
    (sfVector2f) {850, 550}, (sfIntRect) {0, 0, 200, 50})) == NULL)
        return NULL;
    if (set_text_lose(lose) == 84)
        return NULL;
    return lose;
}
