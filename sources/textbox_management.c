/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** rest of function for textbox management
*/

#include "rpg.h"

void manage_event_textbox(scene_t *scene, int type, char *name, int nb)
{
    if (type == 1) {
        scene->game->pause = 1;
        scene->game->activate_textbox = 1;
        scene->game->textbox = init_textbox(get_dialogs(scene->game->dialogs,
        name, nb), scene->game->view, scene);
        scene->game->setting_speed = scene->opt_info->speed;
        scene->game->speed_text = scene->opt_info->speed;
        if (scene->game->textbox == NULL) {
            scene->game->pause = 3;
            scene->game->activate_textbox = 0;
        }
    } else if (type == 0 && scene->game->textbox->finish == 0)
        scene->game->speed_text = 100;
    if (type == 0 && scene->game->textbox->finish == 1) {
        scene->game->pause = 3;
        scene->game->activate_textbox = 0;
        scene->game->textbox->finish = 0;
        scene->game->speed_text = scene->game->setting_speed;
        destroy_textbox(scene->game->textbox, scene->game);
    }
}

float calcul_speed_text(int speed)
{
    return ((0.002 * (80 - (float) speed * 50 / 50.00)));
}

textbox_t *init_textbox(char *text, sfView *view, scene_t *scene)
{
    if (text == NULL)
        return NULL;
    textbox_t *textbox = malloc(sizeof(textbox_t));
    entity_t *entity = NULL;

    init_var_textbox(textbox, text);
    if (set_volume_textbox(textbox, scene) == 84)
        return NULL;
    if ((textbox->textbox = load_entity(entity, "ressources/text/textbox.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 400, 135})) == NULL)
        return NULL;
    if (load_text(textbox->textbox->parole, (sfVector2f) {10, 20}, " ", 15)
    == 84)
        return NULL;
    sfText_setColor(textbox->textbox->parole->text, sfWhite);
    sfSprite_setPosition(textbox->textbox->picture->sprite, (sfVector2f) {
    sfView_getCenter(view).x - 200, sfView_getCenter(view).y});
    return textbox;
}

void destroy_textbox(textbox_t *textbox, game_t *game)
{
    if (textbox != NULL) {
        if (game->pnj_tmp->anim == 1 || (my_strncmp(game->pnj_tmp->name,
        "Chest", 5) == 0 && game->pnj_tmp->drop == -1)) {
            destroy_sound(textbox->speak);
            game->pnj_tmp->drop = -2;
        }
        destroy_sprite(textbox->textbox->picture);
        destroy_clocck(textbox->textbox->clock);
        destroy_framebuffer(textbox->textbox->framebuffer);
        if (textbox->textbox->parole != NULL)
            destroy_text(textbox->textbox->parole);
        free(textbox->textbox);
        free(textbox);
        textbox = NULL;
    }
}
