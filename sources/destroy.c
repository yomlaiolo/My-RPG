/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** destroy
*/

#include "rpg.h"

void destroy_sound(sound_t *sound)
{
    if (sound->sound != NULL) {
        sfSound_stop(sound->sound);
        sfSound_destroy(sound->sound);
    }
    if (sound->buffer != NULL)
        sfSoundBuffer_destroy(sound->buffer);
    free(sound);
}

void destroy_music(music_t *music)
{
    if (music->music != NULL) {
        sfMusic_stop(music->music);
        sfMusic_destroy(music->music);
    }
    free(music);
}

void destroy_text(text_t *text)
{
    if (text->text != NULL)
        sfText_destroy(text->text);
    if (text->font != NULL)
        sfFont_destroy(text->font);
    if (text != NULL) {
        free(text);
        text = NULL;
    }
}

void destroy_sprite(sprite_t *sprite)
{
    if (sprite != NULL) {
        if (sprite->sprite != NULL)
            sfSprite_destroy(sprite->sprite);
        if (sprite->texture != NULL)
            sfTexture_destroy(sprite->texture);
        free(sprite);
    }
}

void destroy_sword_sound(game_t *g)
{
    for (int i = 0; i < 4; i++)
        destroy_sound(g->sword[i]);
    free(g->sword);
}
