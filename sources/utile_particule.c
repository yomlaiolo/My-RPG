/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** particles
*/

#include "rpg.h"

void cpy_framebuffer(framebuffer_t *framebuffer)
{
    for (int i = 0; i < framebuffer->width * framebuffer->height * 4; i++)
        framebuffer->pixels_save[i] = framebuffer->pixels[i];
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}

framebuffer_t *fill_buffer(framebuffer_t *framebuffer, sfColor color)
{
    int w = framebuffer->width;
    int h = framebuffer->height;

    for (int i = 0; i < w * h * 4; i++)
        framebuffer->pixels[i] = color.r;
    return framebuffer;
}
