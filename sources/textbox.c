/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** function for textbox management
*/

#include "rpg.h"

void init_var_textbox(textbox_t *textbox, char *text)
{
    textbox->next = 0;
    textbox->finish = 0;
    textbox->parser = 0;
    textbox->text = text;
}

int set_volume_textbox(textbox_t *textbox, scene_t *scene)
{
    if (scene->game->pnj_tmp->anim == 1) {
        textbox->speak = malloc(sizeof(sound_t));
        if (load_sound(textbox->speak, "ressources/music/speak.ogg") == 84)
            return 84;
        sfSound_setVolume(textbox->speak->sound, scene->opt_info->sound);
        sfSound_play(textbox->speak->sound);
    } else if (my_strncmp(scene->game->pnj_tmp->name, "Chest", 5) == 0
    && scene->game->pnj_tmp->drop != -1 && scene->game->pnj_tmp->drop != -2) {
        textbox->speak = malloc(sizeof(sound_t));
        if (load_sound(textbox->speak, "ressources/music/chest.ogg") == 84)
            return 84;
        sfSound_setVolume(textbox->speak->sound, scene->opt_info->sound);
        sfSound_play(textbox->speak->sound);
    }
    return 0;
}

void set_textbox(textbox_t *textbox, char *str, sfView *view)
{
    sfVector2f new_pos = sfView_getCenter(view);

    new_pos.x -= 200;
    textbox->textbox->parole->str = str;
    sfText_setString(textbox->textbox->parole->text,
    textbox->textbox->parole->str);
    sfSprite_setPosition(textbox->textbox->picture->sprite, new_pos);
    sfText_setPosition(textbox->textbox->parole->text,
    (sfVector2f) {new_pos.x + 27, new_pos.y + 65});
}

int animate_textbox(textbox_t *textbox, sfView *view, int speed)
{
    int i = 0;
    char *tmp = NULL;
    if (textbox == NULL || textbox->finish == 1)
        return 1;
    manage_clock(textbox->textbox->clock, 0);
    if (textbox->textbox->clock->seconds > calcul_speed_text(speed)) {
        textbox->parser += 1;
        textbox->textbox->clock->seconds = 0;
        restart_clock(textbox->textbox->clock);
        tmp = malloc(sizeof(char) * (textbox->parser + 1));
        for (i = 0; i < textbox->parser && textbox->text[i] != '\0'; i++) {
            tmp[i] = textbox->text[i];
            tmp[i + 1] = '\0';
        }
        if (textbox->text[i] == '\0')
            textbox->finish = 1;
        set_textbox(textbox, tmp, view);
        free(tmp);
    }
    return 0;
}

void display_textbox(sfRenderWindow *window, game_t *game)
{
    if (game->activate_textbox == 1) {
        sfRenderWindow_drawSprite(window, game->textbox->textbox->picture->
        sprite, NULL);
        sfRenderWindow_drawText(window, game->textbox->textbox->parole->
        text, NULL);
    }
}
