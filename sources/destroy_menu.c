/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** destroy_menu
*/

#include "rpg.h"

void destroy_option(option_t *option)
{
    destroy_sprite(option->font);
    destroy_sprite(option->display);
    destroy_sprite(option->exit);
    destroy_sprite(option->music_volume);
    destroy_sprite(option->sound_volume);
    destroy_sprite(option->skip);
    destroy_sprite(option->text_speed);
    destroy_text(option->text);
    free(option);
}

void destroy_menu_pause(pause_t *menu_pause)
{
    destroy_sprite(menu_pause->pause);
    destroy_sprite(menu_pause->resume);
    destroy_sprite(menu_pause->exit);
    destroy_sprite(menu_pause->options);
    destroy_option(menu_pause->option_content);
    free(menu_pause);
}

void destroy_lose(lose_t *lose)
{
    destroy_sprite(lose->intro);
    destroy_sprite(lose->quit);
    destroy_sprite(lose->menu);
    destroy_text(lose->text);
    free(lose);
}

void destroy_intro(intro_t *intro)
{
    if (intro->music != NULL)
        destroy_music(intro->music);
    destroy_sprite(intro->play);
    destroy_sprite(intro->option);
    destroy_sprite(intro->help);
    destroy_sprite(intro->quit);
    destroy_sprite(intro->intro);
    destroy_option(intro->option_content);
    free(intro);
}

void destroy_map_render(sprite_t **map_render)
{
    for (int i = 0; map_render[i]; i++)
        destroy_sprite(map_render[i]);
    free(map_render);
}
