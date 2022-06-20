/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** main of the my_rpg project.
*/

#include "rpg.h"

int test_file(scene_t *scene, sfRenderWindow *window)
{
    sound_t *test = malloc(sizeof(sound_t));

    if ((scene->win = init_sprite("./ressources/game/credits.png",
    (sfVector2f) {0, 1080}, (sfIntRect) {0, 0, 1920, 3240})) == NULL)
        return 84;
    if ((scene->game = init_game(window, scene, scene->opt_info)) == NULL)
        return 84;
    destroy_game(scene->game);
    if ((scene->lose = init_lose()) == NULL)
        return 84;
    destroy_lose(scene->lose);
    if (load_sound(test, "ressources/music/speak.ogg") == 84)
        return 84;
    destroy_sound(test);
    test = malloc(sizeof(sound_t));
    if (load_sound(test, "ressources/music/chest.ogg") == 84)
        return 84;
    destroy_sound(test);
    return 0;
}

void destroy_scene(scene_t *scene)
{
    destroy_sprite(scene->win);
    destroy_music(scene->music);
    destroy_sprite(scene->mouse);
    sfClock_destroy(scene->clock->clock);
    free(scene->clock);
    free(scene->opt_info);
    free(scene);
}

int window_run(sfRenderWindow *window, args_t *args)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if ((scene = init_scene_save(window, args, scene)) == NULL)
        return 84;
    while (sfRenderWindow_isOpen(window)) {
        gestion(scene, window);
    }
    destroy_scene(scene);
    return 0;
}

int window_initialisation(unsigned int width, unsigned int height,
char *title, args_t *args)
{
    sfRenderWindow *window;
    sfImage *image = sfImage_createFromFile("ressources/game/logo.png");
    sfUint8 const *icon = NULL;
    sfVideoMode video_mode = {width, height, 1};

    if (image == NULL)
        return (84);
    icon = sfImage_getPixelsPtr(image);
    window = sfRenderWindow_create(video_mode, title, sfClose,
    NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfRenderWindow_setIcon(window, 144, 144, icon);
    if ((window_run(window, args)) == 84)
        return 84;
    sfImage_destroy(image);
    sfRenderWindow_destroy(window);
    return 0;
}

int main(int argc, const char *argv[])
{
    args_t *args = init_args(argc, argv);

    srand((long) &args);
    if (args->h == 1)
        return 0;
    if (window_initialisation(1920, 1080, "HELOS", args) == 84)
        return 84;
    free(args);
    return 0;
}
