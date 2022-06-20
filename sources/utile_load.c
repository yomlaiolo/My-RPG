/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** Load functions
*/

#include "rpg.h"

int load_sprite(sprite_t *s, char *path, sfVector2f pos, sfIntRect rect)
{
    s->sprite = NULL;
    s->sprite = sfSprite_create();
    s->texture = sfTexture_createFromFile(path, NULL);
    if (s->texture == NULL || s->sprite == NULL)
        return 84;
    s->pos = pos;
    s->rect = rect;
    s->nb_rect = 0;
    sfSprite_setPosition(s->sprite, s->pos);
    sfSprite_setTexture(s->sprite, s->texture, sfFalse);
    sfSprite_setTextureRect(s->sprite, s->rect);
    return 0;
}

int load_text_rpg(text_t *text, sfVector2f pos, char *str, int size)
{
    text->text = sfText_create();
    text->font = sfFont_createFromFile("./ressources/lose/morris.ttf");
    if (text->font == NULL || text->text == NULL)
        return 84;
    text->pos = pos;
    text->str = str;
    sfText_setCharacterSize(text->text, size);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, text->pos);
    sfText_setString(text->text, text->str);
    sfText_setColor(text->text, sfBlack);
    return 0;
}

int load_text(text_t *text, sfVector2f pos, char *str, int size)
{
    text->text = sfText_create();
    text->font = sfFont_createFromFile("ressources/text/alagard.ttf");
    if (text->font == NULL || text->text == NULL)
        return 84;
    text->pos = pos;
    text->str = str;
    sfText_setCharacterSize(text->text, size);
    sfText_setFont(text->text, text->font);
    sfText_setPosition(text->text, text->pos);
    sfText_setString(text->text, text->str);
    sfText_setColor(text->text, sfBlack);
    return 0;
}

int load_music(music_t *music, char *str, int volume)
{
    music->music = sfMusic_createFromFile(str);
    if (music->music == NULL)
        return 84;
    music->volume = volume;
    music->played = 0;
    sfMusic_setVolume(music->music, music->volume);
    sfMusic_setLoop(music->music, sfTrue);
    sfMusic_play(music->music);
    return 0;
}

int load_sound(sound_t *sound, char *str)
{
    sound->sound = sfSound_create();
    sound->buffer = sfSoundBuffer_createFromFile(str);
    sound->volume = 100;
    if (sound->buffer == NULL || sound->sound == NULL)
        return 84;
    sfSound_setBuffer(sound->sound, sound->buffer);
    sfSound_setVolume(sound->sound, sound->volume);
    return 0;
}
