/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** particles
*/

#include "rpg.h"

void load_bulle(bulle_t *bulle, int num)
{
    if (num >= 2) {
        bulle->x_limit = 394;
        bulle->y_limit = 250;
        bulle->x = 1848;
        bulle->y = 693;
    }
    if (num < 2) {
        bulle->x_limit = 295;
        bulle->y_limit = 117;
        bulle->x = 325;
        bulle->y = 1545;
    }
    bulle->step = 0;
    bulle->framebuffer = framebuffer_create(13, 5, (sfVector2f) {985, 1000});
    init_bulle(bulle);
    bulle->next = NULL;
}

bulle_t *make_bulles(void)
{
    bulle_t *bulle = malloc(sizeof(bulle_t));
    bulle_t *tmp = bulle;
    int num = 0;

    load_bulle(bulle, num);
    num++;
    while (num != 7) {
        tmp->next = malloc(sizeof(bulle_t));
        tmp = tmp->next;
        load_bulle(tmp, num);
        num++;
    }
    tmp->next = NULL;
    return (bulle);
}

void init_bulle(bulle_t *bulle)
{
    sfVector2f pos = {bulle->x, bulle->y};

    pos.x += rand() % bulle->x_limit;
    pos.y += rand() % bulle->y_limit;
    for (int i = 2; i < bulle->framebuffer->width - 2; i++)
        put_pixel(bulle->framebuffer, i, bulle->framebuffer->height - 1,
        sfWhite);
    sfSprite_setPosition(bulle->framebuffer->sprite->sprite, pos);
}

void display_bulles(sfRenderWindow *window, bulle_t *bulle)
{
    bulle_t *tmp = bulle;

    while (tmp != NULL) {
        display_particles(window, tmp->framebuffer);
        tmp = tmp->next;
    }
}
