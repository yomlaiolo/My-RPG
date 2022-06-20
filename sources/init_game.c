/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** init_game
*/

#include "rpg.h"

int set_game_sprites(game_t *game, opt_info_t *info)
{
    game->map_render = create_sprite_tab(game->map_render);
    game->colision_sound = malloc(sizeof(sound_t));
    game->main_quest = 0;
    game->win = 0;
    if ((game->menu_pause->pause = init_sprite("./ressources/game/pause.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080})) == NULL)
        return 84;
    if ((game->menu_pause->exit = init_sprite("./ressources/intro/quit.png",
    (sfVector2f) {840, 730}, (sfIntRect) {0, 0, 200, 60})) == NULL)
        return 84;
    if ((game->menu_pause->resume = init_sprite("./ressources/game/resume.png",
    (sfVector2f) {757, 343}, (sfIntRect) {0, 0, 400, 100})) == NULL)
        return 84;
    if ((game->menu_pause->options = init_sprite("./ressources/intro/options\
.png", (sfVector2f) {825, 555}, (sfIntRect) {0, 0, 260, 50})) == NULL)
        return 84;
    if (set_opt(game, info) == 84)
        return 84;
    return 0;
}

int set_game(game_t *game, entity_t *entity, sprite_t *map, opt_info_t *info)
{
    set_game_info(game, entity, map);
    if (set_game_sprites(game, info) == 84 || parsing_colision(game) == 84)
        return 84;
    if ((game->stairs = parsing_stairs(game->stairs,
    "./game_files/stairs.rpg")) == NULL)
        return 84;
    if ((game->dialogs = init_dialogs()) == NULL)
        return 84;
    game->potion_bar = NULL;
    if ((game->potion_bar = init_potion_bar(game->view)) == NULL) {
        return 84;
    }
    game->pnj = NULL;
    if ((game->pnj = init_pnj(&(pnj_info_t) {game->pnj,
    "./ressources/game/receiver.png", "Villager1", 1, 0,
    (sfVector2f) {1050, 1190}, 1})) == NULL)
        return 84;
    if (load_pnj(game->pnj) == 84)
        return 84;
    return 0;
}

int set_game_inv(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    if ((game->musics = init_zone_music()) == NULL)
        return 84;
    if (scene != NULL) {
        game->speed_text = scene->opt_info->speed;
        game->setting_speed = scene->opt_info->speed;
    }
    if (load_inventory(game, window) == 84)
        return 84;
    return 0;
}

game_t *init_game(sfRenderWindow *window, scene_t *scene, opt_info_t *info)
{
    game_t *game = malloc(sizeof(game_t));
    entity_t *entity = NULL;
    sprite_t *map = malloc(sizeof(sprite_t));

    game->menu_pause = malloc(sizeof(pause_t));
    if ((entity = load_entity(entity, "./ressources/game/hero.png",
    (sfVector2f) {540, 450}, (sfIntRect) {0, 128, 32, 32})) == NULL)
        return NULL;
    if (load_sprite(map, "./ressources/game/map.png", (sfVector2f) {0, 0},
    (sfIntRect) {0, 0, 5000, 5000}) == 84)
        return NULL;
    game->total_clock = malloc(sizeof(clockk_t));
    init_clock(game->total_clock);
    if (set_game(game, entity, map, info) == 84)
        return NULL;
    if (set_game_inv(scene, game, window) == 84)
        return NULL;
    if (set_sword_sound(game) == 84)
        return NULL;
    return game;
}

void set_game_info(game_t *game, entity_t *entity, sprite_t *map)
{
    game->count = malloc(sizeof(count_t));
    game->count->count1 = 0;
    game->count->count2 = 0;
    game->count->count3 = 0;
    game->count->count4 = 0;
    game->move = malloc(sizeof(int) * 6);
    game->move = memset(game->move, 0, sizeof(int) * 6);
    game->pause = 0;
    game->m_pause = 0;
    game->map = map;
    game->textbox = NULL;
    game->player = entity;
    game->player_info = set_player_info();
    game->view = sfView_create();
    game->zoom = 0.3;
    game->speed = 70;
    game->activate_textbox = 0;
    game->scale = 1;
    game->bulles = make_bulles();
    game->pnj_tmp = NULL;
}
