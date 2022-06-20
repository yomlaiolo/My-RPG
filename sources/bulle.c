/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** particles
*/

#include "rpg.h"

void help_step(framebuffer_t *framebuffer, int step)
{
    if (step == 1) {
        put_pixel(framebuffer, 2, framebuffer->height - 1, sfWhite);
        put_pixel(framebuffer, 3, framebuffer->height - 1, sfWhite);
        put_pixel(framebuffer, 4, framebuffer->height - 1, sfWhite);
        put_pixel(framebuffer, 5, framebuffer->height - 1, sfWhite);
        put_pixel(framebuffer, 8, framebuffer->height - 1, sfWhite);
        put_pixel(framebuffer, 9, framebuffer->height - 1, sfWhite);
        put_pixel(framebuffer, 10, framebuffer->height - 1, sfWhite);
    }
    if (step == 2) {
        put_pixel(framebuffer, 2, framebuffer->height - 1, sfWhite);
        put_pixel(framebuffer, 3, framebuffer->height - 1, sfWhite);
        put_pixel(framebuffer, 9, framebuffer->height - 1, sfWhite);
        put_pixel(framebuffer, 10, framebuffer->height - 1, sfWhite);
    }
    if (step == 6) {
        put_pixel(framebuffer, 2, framebuffer->height - 1, sfWhite);
        put_pixel(framebuffer, 10, framebuffer->height - 1, sfWhite);
    }
}

void end_step(bulle_t *bulle, int h)
{
    if (bulle->step == 4) {
        put_pixel(bulle->framebuffer, 2, h, sfWhite);
        put_pixel(bulle->framebuffer, 2, h - 3, sfWhite);
        put_pixel(bulle->framebuffer, 3, h - 3, sfWhite);
        put_pixel(bulle->framebuffer, 3, h - 2, sfWhite);
        put_pixel(bulle->framebuffer, 3, h - 1, sfWhite);
        put_pixel(bulle->framebuffer, 9, h - 1, sfWhite);
        put_pixel(bulle->framebuffer, 9, h - 2, sfWhite);
        put_pixel(bulle->framebuffer, 9, h - 3, sfWhite);
        put_pixel(bulle->framebuffer, 10, h - 3, sfWhite);
        put_pixel(bulle->framebuffer, 10, h, sfWhite);
    }
    if (bulle->step == 5) {
        put_pixel(bulle->framebuffer, 0, h, sfWhite);
        put_pixel(bulle->framebuffer, 1, h - 1, sfWhite);
        put_pixel(bulle->framebuffer, 2, h, sfWhite);
        put_pixel(bulle->framebuffer, 10, h, sfWhite);
        put_pixel(bulle->framebuffer, 11, h - 1, sfWhite);
        put_pixel(bulle->framebuffer, 12, h, sfWhite);
    }
}

void mid_step(bulle_t *bulle, int h)
{
    if (bulle->step == 2) {
        put_pixel(bulle->framebuffer, 4, h - 1, sfWhite);
        put_pixel(bulle->framebuffer, 5, h - 1, sfWhite);
        put_pixel(bulle->framebuffer, 8, h - 1, sfWhite);
        put_pixel(bulle->framebuffer, 7, h - 2, sfWhite);
        put_pixel(bulle->framebuffer, 6, h - 2, sfWhite);
    }
    if (bulle->step == 3) {
        put_pixel(bulle->framebuffer, 2, h, sfWhite);
        put_pixel(bulle->framebuffer, 3, h - 1, sfWhite);
        put_pixel(bulle->framebuffer, 4, h - 2, sfWhite);
        put_pixel(bulle->framebuffer, 5, h - 3, sfWhite);
        put_pixel(bulle->framebuffer, 6, h - 3, sfWhite);
        put_pixel(bulle->framebuffer, 7, h - 3, sfWhite);
        put_pixel(bulle->framebuffer, 8, h - 2, sfWhite);
        put_pixel(bulle->framebuffer, 9, h - 1, sfWhite);
        put_pixel(bulle->framebuffer, 10, h, sfWhite);
    }
    help_step(bulle->framebuffer, bulle->step);
    end_step(bulle, h);
}

void step_bulle(bulle_t *bulle, int pause)
{
    int h = bulle->framebuffer->height - 1;

    manage_clock(bulle->framebuffer->clock, pause);
    if (bulle->framebuffer->clock->seconds > 0.3 && bulle->step <= 7) {
        restart_clock(bulle->framebuffer->clock);
        bulle->step += 1;
    }
    if (bulle->framebuffer->clock->seconds > 1) {
        init_bulle(bulle);
        restart_clock(bulle->framebuffer->clock);
        bulle->step = 0;
    }
    bulle->framebuffer = fill_buffer(bulle->framebuffer, sfTransparent);
    if (bulle->step == 1) {
        put_pixel(bulle->framebuffer, 7, h - 1, sfWhite);
        put_pixel(bulle->framebuffer, 6, h - 1, sfWhite);
    }
    mid_step(bulle, h);
}

void step_all_bulle(bulle_t *bulle, int pause)
{
    bulle_t *tmp = bulle;

    while (tmp != NULL) {
        step_bulle(tmp, pause);
        tmp = tmp->next;
    }
}
