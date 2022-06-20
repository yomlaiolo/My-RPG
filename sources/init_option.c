/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** init_option
*/

#include "rpg.h"

void set_option(option_t *o)
{
    sfSprite_setPosition(o->display->sprite, o->display->pos);
    sfSprite_setPosition(o->text_speed->sprite, o->text_speed->pos);
    sfSprite_setPosition(o->skip->sprite, o->skip->pos);
    sfSprite_setPosition(o->exit->sprite, o->exit->pos);
    sfSprite_setPosition(o->music_volume->sprite, o->music_volume->pos);
    sfSprite_setPosition(o->sound_volume->sprite, o->sound_volume->pos);
    sfSprite_setPosition(o->font->sprite, o->font->pos);
    sfSprite_setTextureRect(o->display->sprite, o->display->rect);
    sfSprite_setTextureRect(o->text_speed->sprite, o->text_speed->rect);
    sfSprite_setTextureRect(o->skip->sprite, o->skip->rect);
    sfSprite_setTextureRect(o->exit->sprite, o->exit->rect);
    sfSprite_setTextureRect(o->music_volume->sprite, o->music_volume->rect);
    sfSprite_setTextureRect(o->sound_volume->sprite, o->sound_volume->rect);
    sfSprite_setTextureRect(o->font->sprite, o->font->rect);
}

int set_sprite_volume(option_t *o, char *str, opt_info_t *i)
{
    if ((o->music_volume = init_sprite(str, (sfVector2f) {1030 +
    (i->music * 246 / 100), 475}, (sfIntRect) {0, 0, 24, 45})) == NULL)
        return 84;
    if ((o->sound_volume = init_sprite(str, (sfVector2f) {1030 +
    (i->sound * 246 / 100), 750}, (sfIntRect) {0, 0, 24, 45})) == NULL)
        return 84;
    return 0;
}

int set_sprite_option(option_t *o, char *str, opt_info_t *i)
{
    if ((o->display = init_sprite(str, (sfVector2f) {485 +
    (i->display * 246 / 100), 290}, (sfIntRect) {0, 0, 24, 45})) == NULL)
        return 84;
    if ((o->text_speed = init_sprite(str, (sfVector2f) {485 +
    (i->speed * 246 / 100), 750}, (sfIntRect) {0, 0, 24, 45})) == NULL)
        return 84;
    if ((o->skip = init_sprite("./ressources/options/check.png", (sfVector2f)
    {575, 555}, (sfIntRect) {0 + (i->skip * 130), 0, 65, 64})) == NULL)
        return 84;
    if ((o->exit = init_sprite("./ressources/options/exit.png", (sfVector2f)
    {1445, 180}, (sfIntRect) {0, 0, 65, 64})) == NULL)
        return 84;
    if (set_sprite_volume(o, str, i) == 84)
        return 84;
    if ((o->font = init_sprite("./ressources/options/options.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080})) == NULL)
        return 84;
    return 0;
}

option_t *init_option(opt_info_t *info)
{
    option_t *option = malloc(sizeof(option_t));
    char *str = "./ressources/options/cursor.png";

    if (set_sprite_option(option, str, info) == 84)
        return NULL;
    option->text = malloc(sizeof(text_t));
    load_text_rpg(option->text, (sfVector2f) {- 100, - 100}, "0", 50);
    sfText_setColor(option->text->text, sfGreen);
    set_option(option);
    return option;
}
