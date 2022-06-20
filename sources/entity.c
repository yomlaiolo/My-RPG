/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** Load functions
*/

#include "rpg.h"

void init_clock(clockk_t *timer)
{
    timer->clock = sfClock_create();
    timer->seconds = 0;
    timer->times.microseconds = 0;
    timer->diff = 0;
}

entity_t *load_entity(entity_t *entity, char *filename,
sfVector2f coords, sfIntRect rect)
{
    entity = malloc(sizeof(entity_t));
    entity->picture = malloc(sizeof(sprite_t));
    entity->parole = malloc(sizeof(text_t));
    entity->clock = malloc(sizeof(clockk_t));
    entity->framebuffer = framebuffer_create(25, 15, coords);
    put_n_pixel(entity->framebuffer, 5, (sfColor) {62, 53, 70, 255});
    init_clock(entity->clock);
    if (load_sprite(entity->picture, filename, coords, rect) == 84)
        return (NULL);
    return entity;
}
