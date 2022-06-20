/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** set
*/

#include "rpg.h"

void set_sound(music_t *music, float volume)
{
    music->volume = volume;
    sfMusic_setLoop(music->music, sfTrue);
    sfMusic_setVolume(music->music, music->volume);
}

void set_stats_player(player_t *player)
{
    player->stat->hp = 100;
    player->stat->hp_max = 100;
    player->stat->mp = 100;
    player->stat->mp_max = 100;
    player->stat->atk = 1;
    player->stat->def = 10;
    player->stat->endurence = 1;
    player->antidote = 0;
    player->fire = 0;
    player->ice = 0;
    player->stat->monsters_killed = 0;
    player->sword = 0;
}

player_t *set_player_info(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->stat = malloc(sizeof(stat_t));
    set_stats_player(player);
    player->life_bar = init_sprite("./ressources/game/life.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 79, 11});
    player->life = init_sprite("./ressources/game/life.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 11, 79, 11});
    player->mp_bar = init_sprite("./ressources/game/stamina.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 78, 18});
    player->mp = init_sprite("./ressources/game/stamina.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 18, 78, 18});
    player->clock = malloc(sizeof(clockk_t));
    init_clock(player->clock);
    player->recup = 0;
    player->last_damage = malloc(sizeof(clockk_t));
    init_clock(player->last_damage);
    return player;
}

int set_opt(game_t *game, opt_info_t *info)
{
    if ((game->menu_pause->option_content = init_option(info)) == NULL)
        return 84;
    if (load_sound(game->colision_sound, "./ressources/music/colision.ogg")
    == 84)
        return 84;
    if ((game->monsters = generate_monsters()) == NULL)
        return 84;
    return 0;
}

void set_status_inv(scene_t *scene, int i)
{
    scene->game->inv[i]->sprite2->pos =
    sfRenderWindow_mapPixelToCoords(scene->window, (sfVector2i)
    {235, 200}, scene->game->view);
    scene->game->inv[i]->use->pos =
    sfRenderWindow_mapPixelToCoords(scene->window, (sfVector2i)
    {148, 450}, scene->game->view);
    scene->game->inv[i]->sprite2->status = 1;
    for (int a = 0; a < 6; a++) {
        if (i != a)
            scene->game->inv[a]->sprite2->status = 0;
    }
}
