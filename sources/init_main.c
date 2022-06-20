/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** main inits of the my_rpg project.
*/

#include "rpg.h"

opt_info_t *init_opt_info(void)
{
    opt_info_t *opt_info = malloc(sizeof(opt_info_t));
    opt_info->display = 60;
    opt_info->music = 50;
    opt_info->sound = 50;
    opt_info->speed = 50;
    opt_info->skip = 0;
    return opt_info;
}

scene_t *init_scene_save(sfRenderWindow *window, args_t *args, scene_t *scene)
{
    scene->scene = 1;
    scene->window = window;
    scene->opt_info = init_opt_info();
    if ((scene->intro = init_intro(scene->opt_info)) == NULL)
        return NULL;
    scene->game = NULL;
    scene->lose = NULL;
    scene->angle = 0;
    scene->args = args;
    init_clock(scene->clock = malloc(sizeof(clockk_t)));
    if ((scene->mouse = init_sprite("./ressources/game/mouse.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 32, 32})) == NULL)
        return NULL;
    if (load_music(scene->music = malloc(sizeof(music_t)),
    "./ressources/music/win.ogg", 100) == 84)
        return NULL;
    if (test_file(scene, window) == 84)
        return NULL;
    scene->mouse_pos = (sfVector2f) {0, 0};
    return (scene);
}
