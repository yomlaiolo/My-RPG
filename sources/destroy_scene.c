/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** destroy_scene
*/

#include "rpg.h"

void destroy_zone_sound(music_zone_t *musics)
{
    destroy_music(musics->village);
    destroy_music(musics->forest);
    destroy_music(musics->desert);
    destroy_music(musics->snow);
    destroy_music(musics->boss);
    destroy_clocck(musics->fade);
    free(musics);
}

void destroy_framebuffer(framebuffer_t *framebuffer)
{
    destroy_sprite(framebuffer->sprite);
    destroy_clocck(framebuffer->clock);
    free(framebuffer->pixels);
    free(framebuffer->pixels_save);
    free(framebuffer);
}

void destroy_entity(entity_t *entity)
{
    destroy_sprite(entity->picture);
    destroy_clocck(entity->clock);
    destroy_framebuffer(entity->framebuffer);
    if (entity->parole != NULL)
        free(entity->parole);
    free(entity);
}

void destroy_monster(monster_t *monster)
{
    monster_t *tmp = monster;
    monster_t *tmp2 = monster;

    while (tmp != NULL) {
        tmp = tmp->next;
        destroy_entity(tmp2->entity);
        destroy_sprite(tmp2->life_bar);
        destroy_clocck(tmp2->attack_clock);
        destroy_clocck(tmp2->poison_clock);
        destroy_framebuffer(tmp2->framebuffer);
        free(tmp2);
        tmp2 = tmp;
    }
}

void destroy_int_array(int **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
