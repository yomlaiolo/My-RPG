/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** display
*/

#include "rpg.h"

void display_lose(sfRenderWindow *window, lose_t *lose)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, lose->intro->sprite, NULL);
    sfRenderWindow_drawSprite(window, lose->quit->sprite, NULL);
    sfRenderWindow_drawSprite(window, lose->menu->sprite, NULL);
    sfRenderWindow_drawText(window, lose->text->text, NULL);
}

void display_options_intro(sfRenderWindow *window, intro_t *intro)
{
    sfRenderWindow_drawSprite(window, intro->option_content->font->sprite,
    NULL);
    sfRenderWindow_drawSprite(window,
    intro->option_content->display->sprite, NULL);
    sfRenderWindow_drawSprite(window, intro->option_content->exit->sprite,
    NULL);
    sfRenderWindow_drawSprite(window,
    intro->option_content->music_volume->sprite, NULL);
    sfRenderWindow_drawSprite(window,
    intro->option_content->sound_volume->sprite, NULL);
    sfRenderWindow_drawSprite(window,
    intro->option_content->skip->sprite, NULL);
    sfRenderWindow_drawSprite(window,
    intro->option_content->text_speed->sprite, NULL);
    sfRenderWindow_drawText(window, intro->option_content->text->text, NULL);
}

void display_intro(sfRenderWindow *window, intro_t *intro)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, intro->intro->sprite, NULL);
    sfRenderWindow_drawSprite(window, intro->play->sprite, NULL);
    sfRenderWindow_drawSprite(window, intro->help->sprite, NULL);
    sfRenderWindow_drawSprite(window, intro->option->sprite, NULL);
    sfRenderWindow_drawSprite(window, intro->quit->sprite, NULL);
    if (intro->option->status == 1)
        display_options_intro(window, intro);
    if (intro->help->status == 1)
        display_help(window, intro);
}

void display_game(sfRenderWindow *window, game_t *g)
{
    sfRenderWindow_clear(window, (sfColor) {253, 243, 243, 255});
    sfRenderWindow_setView(window, g->view);
    sfRenderWindow_drawSprite(window, g->map->sprite, NULL);
    display_bulles(window, g->bulles);
    if (g->speed == 150)
        display_particles(window, g->player->framebuffer);
    display_pnj(window, g->pnj);
    sfRenderWindow_drawSprite(window, g->player->picture->sprite, NULL);
    for (int i = 0; g->map_render[i] != NULL; i++)
        sfRenderWindow_drawSprite(window, g->map_render[i]->sprite, NULL);
    display_monster(window, g->monsters, g);
    inventory(g, window);
    display_potion_bar(window, g);
    display_textbox(window, g);
    sfRenderWindow_drawSprite(window, g->player_info->life->sprite, NULL);
    sfRenderWindow_drawSprite(window, g->player_info->life_bar->sprite, NULL);
    sfRenderWindow_drawSprite(window, g->player_info->mp->sprite, NULL);
    sfRenderWindow_drawSprite(window, g->player_info->mp_bar->sprite, NULL);
    if (g->m_pause == 1)
        display_pause(g, window);
}
