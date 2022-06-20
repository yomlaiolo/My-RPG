/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** init_sound
*/

#include "rpg.h"

int set_sword_sound(game_t *g)
{
    g->sword = malloc(sizeof(sound_t *) * 4);
    for (int i = 0; i < 4; i++)
        g->sword[i] = malloc(sizeof(sound_t));
    if (load_sound(g->sword[0], "./ressources/music/sword1.ogg") == 84)
        return 84;
    if (load_sound(g->sword[1], "./ressources/music/sword2.ogg") == 84)
        return 84;
    if (load_sound(g->sword[2], "./ressources/music/sword3.ogg") == 84)
        return 84;
    if (load_sound(g->sword[3], "./ressources/music/sword4.ogg") == 84)
        return 84;
    return 0;
}
