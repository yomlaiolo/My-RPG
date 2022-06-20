/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** music
*/

#include "rpg.h"

void malloc_zone(music_zone_t *zone)
{
    zone->fade = malloc(sizeof(clockk_t));
    zone->village = malloc(sizeof(music_t));
    zone->forest = malloc(sizeof(music_t));
    zone->desert = malloc(sizeof(music_t));
    zone->snow = malloc(sizeof(music_t));
    zone->boss = malloc(sizeof(music_t));
}

music_zone_t *init_zone_music(void)
{
    music_zone_t *zone = malloc(sizeof(music_zone_t));

    malloc_zone(zone);
    init_clock(zone->fade);
    if (load_music(zone->village, "ressources/music/village.ogg", 50) == 84)
        return NULL;
    sfMusic_pause(zone->village->music);
    if (load_music(zone->forest, "ressources/music/forest.ogg", 0) == 84)
        return NULL;
    sfMusic_pause(zone->forest->music);
    if (load_music(zone->desert, "ressources/music/desert.ogg", 0) == 84)
        return NULL;
    sfMusic_pause(zone->desert->music);
    if (load_music(zone->boss, "ressources/music/boss.ogg", 0) == 84)
        return NULL;
    sfMusic_pause(zone->boss->music);
    if (load_music(zone->snow, "ressources/music/snow.ogg", 0) == 84)
        return NULL;
    sfMusic_pause(zone->snow->music);
    return zone;
}

static void fade_gestion(music_t *music, game_t *game, opt_info_t *info)
{
    if (music->played == -2) {
        sfMusic_play(music->music);
        music->played = -1;
    }
    if (music->played == -1 && game->musics->fade->seconds > 0.05) {
        music->volume += 1;
        sfMusic_setVolume(music->music, music->volume);
        restart_clock(game->musics->fade);
    }
    if (sfMusic_getVolume(music->music) == info->music &&
    music->played == -1)
        music->played = 1;
    if (music->played == 0) {
        sfMusic_play(music->music);
        music->played = 1;
    }
    if (music->played == 1) {
        set_sound(music, info->music);
    }
}

void gestion_zone_sound(game_t *game, opt_info_t *info, int *tab,
music_t *music)
{
    int x = game->player->picture->pos.x;
    int y = game->player->picture->pos.y;

    manage_clock(game->musics->fade, game->pause);
    if (x > tab[0] && x < tab[1] && y > tab[2] && y < tab[3]) {
        fade_gestion(music, game, info);
    } else {
        if (music->played != 1)
            music->played = 1;
        if (sfMusic_getVolume(music->music) < 0.01) {
            sfMusic_stop(music->music);
            music->played = -2;
        }
        if (game->musics->fade->seconds > 0.1 && music->played == 1) {
            music->volume -= 1;
            sfMusic_setVolume(music->music, music->volume);
            sfClock_restart(game->musics->fade->clock);
        }
    }
}

void call_musics(game_t *game, opt_info_t *info)
{
    int village[4] = {0, 1545, 0, 1315};
    int forest[4] = {320, 3430, 1350, 2190};
    int forest2[4] = {1338, 3430, 2190, 2955};
    int forest3[4] = {1580, 3435, 200, 1380};
    int forest4[4] = {2950, 3450, 2950, 4745};
    int desert[4] = {315, 1250, 2300, 4720};
    int desert2[4] = {1340, 2915, 2990, 4755};
    int snow[4] = {3470, 4750, 175, 3250};
    int boss[4] = {3470, 4750, 3260, 4755};
    gestion_zone_sound(game, info, village, game->musics->village);
    gestion_zone_sound(game, info, forest, game->musics->forest);
    gestion_zone_sound(game, info, forest2, game->musics->forest);
    gestion_zone_sound(game, info, forest3, game->musics->forest);
    gestion_zone_sound(game, info, forest4, game->musics->forest);
    gestion_zone_sound(game, info, desert, game->musics->desert);
    gestion_zone_sound(game, info, desert2, game->musics->desert);
    gestion_zone_sound(game, info, boss, game->musics->boss);
    gestion_zone_sound(game, info, snow, game->musics->snow);
}
