/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** slider functions
*/

#include "rpg.h"

int slider_clicked(int pos, sfVector2i mouse_pos,
coords_t border, sfText *text)
{
    pos = ((float) mouse_pos.x - (float) border.x) /
    ((float) border.y - (float) border.x) * 100;
    if (pos > 100)
        pos = 100;
    sfText_setString(text, my_itoa(pos));
    sfText_setPosition(text,
    (sfVector2f) {mouse_pos.x - 25, mouse_pos.y + 30});
    if (pos < 33)
        sfText_setColor(text, sfRed);
    else if (pos < 66)
        sfText_setColor(text, sfYellow);
    else
        sfText_setColor(text, sfGreen);
    return pos;
}

static int set_sprite_pos_x(sprite_t *sprite, coords_t border,
sfVector2i mouse_pos)
{
    if (sprite->clicked == 1 && sprite->pos.x > border.x - 20 &&
    sprite->pos.x < border.y + 20)
        sprite->pos.x = mouse_pos.x - 15;
    if (sprite->pos.x <= border.x)
        sprite->pos.x = border.x + 5;
    if (sprite->pos.x >= border.y)
        sprite->pos.x = border.y - 10;
    return (0);
}

int slider(sfEvent event, sprite_t *sprite, coords_t border,
option_t *option_content)
{
    int pos = -1;

    if (option_content->mouse_pos.x >= border.x &&
    option_content->mouse_pos.x <= border.y + sprite->rect.width &&
    option_content->mouse_pos.y >= sprite->pos.y &&
    option_content->mouse_pos.y <= sprite->pos.y + sprite->rect.height) {
        if (event.type == sfEvtMouseButtonPressed)
            sprite->clicked = 1;
        if (event.type == sfEvtMouseButtonReleased)
            sprite->clicked = 0;
        if (sprite->clicked == 1)
            pos = slider_clicked(pos, option_content->mouse_pos, border,
            option_content->text->text);
        set_sprite_pos_x(sprite, border, option_content->mouse_pos);
    }
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    return pos;
}
