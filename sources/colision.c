/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** colision
*/

#include "rpg.h"

static int get_size(const char *path)
{
    int fd = open(path, O_RDONLY);
    int size = 0;
    char c;

    if (fd == -1)
        return -1;
    while (read(fd, &c, 1) > 0)
        size++;
    close(fd);
    return size;
}

char *get_file(char *path)
{
    char *result;
    int content = 0;
    int size = get_size(path);

    content = open(path, O_RDONLY);
    if (content == -1)
        return NULL;
    result = malloc(sizeof(char) * (size + 1));
    read(content, result, size);
    result[size] = '\0';
    close(content);
    return result;
}

int count_line(char *file)
{
    int i = 0;
    int j = 0;

    while (file[i] != '\0') {
        if (file[i] == '\n')
            j++;
        i++;
    }
    return (j);
}

int verify_coords(int **tab, str_t *str, char **result, coords_t coords)
{
    if (str->count == 0 && result[coords.x][coords.y] == '_') {
        tab[coords.x][0] = my_atoi(str->str1);
        str->count++;
    } else if (str->count == 1 && result[coords.x][coords.y] == '_') {
        tab[coords.x][1] = my_atoi(str->str2);
        str->count++;
    } else if (str->count == 2 && result[coords.x][coords.y] == '_') {
        tab[coords.x][2] = my_atoi(str->str3);
        str->count++;
    }
    if (result[coords.x][coords.y] == '*') {
        if (str->count != 3)
            return 84;
        tab[coords.x][3] = my_atoi(str->str4);
    }
    return 0;
}

void play_colision(scene_t *scene)
{
    if (sfSound_getStatus(scene->game->colision_sound->sound) != sfPlaying &&
    ((scene->game->move[0] == 1 && scene->game->count->count1 >= 1)
    || (scene->game->move[1] == 1 && scene->game->count->count2 >= 1) ||
    (scene->game->move[2] == 1
    && scene->game->count->count3 >= 1) || (scene->game->move[3] == 1 &&
    scene->game->count->count4 >= 1))) {
        sfSound_setVolume(scene->game->colision_sound->sound, (float)
        scene->opt_info->sound);
        sfSound_play(scene->game->colision_sound->sound);
    }
}
