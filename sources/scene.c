/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** scene
*/

#include "rpg.h"

int run_intro(intro_t *intro, sfRenderWindow *window)
{
    display_intro(window, intro);
    return 1;
}

int run_game(scene_t *scene, sfRenderWindow *window, int angle,
args_t *args)
{
    angle = ventilator(scene->game, args, angle);
    if (scene->game->pause == 0)
        stay(scene->game->player, scene->game);
    sfSprite_setPosition(scene->game->player->picture->sprite,
    scene->game->player->picture->pos);
    step_all_bulle(scene->game->bulles, scene->game->pause);
    if (scene->game->activate_textbox == 1)
        animate_textbox(scene->game->textbox, scene->game->view,
        scene->game->speed_text);
    display_game(window, scene->game);
    return angle;
}

scene_t *intro_gestion(scene_t *scene)
{
    if (scene->scene == 11) {
        if ((scene->intro = init_intro(scene->opt_info)) == NULL)
            sfRenderWindow_close(scene->window);
        scene->scene = 1;
    }
    if (scene->scene == 12) {
        destroy_intro(scene->intro);
        scene->scene = 21;
        return scene;
    }
    if (scene->scene == 1) {
        scene->scene = run_intro(scene->intro, scene->window);
    }
    return scene;
}

scene_t *game_gestion(scene_t *scene)
{
    if (scene->scene == 21) {
        if ((scene->game = init_game(scene->window, scene, scene->opt_info))
        == NULL)
            sfRenderWindow_close(scene->window);
        scene->scene = 2;
    }
    if (scene->scene == 2) {
        scene->angle = run_game(scene, scene->window, scene->angle,
        scene->args);
        if (scene->game->player_info->stat->hp <= 0)
            scene->scene = 31;
    }
    if (scene->scene == 22) {
        sfView_reset(scene->game->view, (sfFloatRect) {0, 0, 1920, 1080});
        sfRenderWindow_setView(scene->window, scene->game->view);
        destroy_game(scene->game);
        scene->scene = 11;
        return scene;
    }
    return scene;
}

int manage_event_close(scene_t *scene, sfEvent event)
{
    if (scene->scene == 2 && event.type == sfEvtClosed) {
        destroy_game(scene->game);
        sfRenderWindow_close(scene->window);
        return 1;
    }
    return 0;
}
