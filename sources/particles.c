/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** particles
*/

#include "rpg.h"

void pos_aleatoire(int *w_rand, int *h_rand, framebuffer_t *framebuffer,
sfColor old_color)
{
    int w = framebuffer->width;
    int h = framebuffer->height;
    int rank = (w_rand[0] + (framebuffer->width * h_rand[0])) * 4;
    w_rand[0] = rand() % w;
    h_rand[0] = rand() % h;
    while (framebuffer->pixels[rank] == old_color.r &&
    framebuffer->pixels[rank + 1] == old_color.g &&
    framebuffer->pixels[rank + 2] == old_color.b &&
    framebuffer->pixels[rank + 3] == old_color.a) {
            w_rand[0] = rand() % w;
            h_rand[0] = rand() % h;
            rank = (w_rand[0] + (w * h_rand[0])) * 4;
    }
}

void update_pixel(framebuffer_t *framebuffer, sfColor old_color,
sfColor new_color)
{
    int w = framebuffer->width;
    int h = framebuffer->height;
    int w_rand = 0;
    int h_rand = 0;

    cpy_framebuffer(framebuffer);
    for (int i = 0; i < w * h * 4; i += 4) {
        pos_aleatoire(&w_rand, &h_rand, framebuffer, old_color);
        if (framebuffer->pixels_save[i] == old_color.r &&
        framebuffer->pixels_save[i + 1] == old_color.g &&
        framebuffer->pixels_save[i + 2] == old_color.b &&
        framebuffer->pixels_save[i + 3] == old_color.a) {
            framebuffer->pixels[i] = 0;
            framebuffer->pixels[i + 1] = 0;
            framebuffer->pixels[i + 2] = 0;
            framebuffer->pixels[i + 3] = 0;
            put_pixel(framebuffer, w_rand, h_rand, new_color);
        }
    }
}

void display_particles(sfRenderWindow *window, framebuffer_t *framebuffer)
{
    sfTexture_updateFromPixels(framebuffer->sprite->texture,
    framebuffer->pixels, framebuffer->width, framebuffer->height, 0, 0);
    sfRenderWindow_drawSprite(window, framebuffer->sprite->sprite, NULL);
}

void put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color)
{
    unsigned int rank = (x + (framebuffer->width * y)) * 4;

    if ((x >= 0) && (x < framebuffer->width) &&
        (y >= 0) && (y < framebuffer->height)) {
        framebuffer->pixels[rank] = color.r;
        framebuffer->pixels[rank + 1] = color.g;
        framebuffer->pixels[rank + 2] = color.b;
        framebuffer->pixels[rank + 3] = color.a;
    }
    return;
}

framebuffer_t *framebuffer_create(int width, int height, sfVector2f pos)
{
    framebuffer_t *pixels = malloc(sizeof(framebuffer_t));

    pixels->width = width;
    pixels->height = height;
    pixels->sprite = malloc(sizeof(sprite_t));
    pixels->sprite->pos = pos;
    pixels->sprite->rect = (sfIntRect) {0, 0, width, height};
    pixels->sprite->texture = sfTexture_create(width, height);
    pixels->clock = malloc(sizeof(clockk_t));
    init_clock(pixels->clock);
    pixels->sprite->sprite = sfSprite_create();
    sfSprite_setTexture(pixels->sprite->sprite, pixels->sprite->texture,
    sfFalse);
    sfSprite_setPosition(pixels->sprite->sprite, pixels->sprite->pos);
    pixels->pixels = malloc(sizeof(sfUint8) * width * height * 4);
    pixels->pixels_save = malloc(sizeof(sfUint8) * width * height * 4);
    for (int i = 0; i < (width * height * 4); i++)
        pixels->pixels[i] = 0;
    return pixels;
}
