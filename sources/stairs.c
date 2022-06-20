/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** stairs
*/

#include "rpg.h"

void update_zoom(game_t *game, int i)
{
    int count = 0;

    if (game->move[0] == 0 && game->move[1] == 0 &&
    game->move[2] == 0 && game->move[3] == 0)
        count = 1;
    for (int j = 0; j < 4; j++) {
        if (game->move[j] == 1 && game->stairs[i][4] == j) {
            game->zoom -= 0.001;
            game->scale -= 0.0033;
            count++;
        }
    }
    if (count == 0) {
        game->zoom += 0.001;
        game->scale += 0.0033;
    }
}

int get_stair(game_t *game, int i)
{
    if (game->stairs[i][0] < game->player->picture->pos.x &&
        game->stairs[i][1] > game->player->picture->pos.x &&
        game->stairs[i][2] - 20 < game->player->picture->pos.y &&
        game->stairs[i][3] - 25 > game->player->picture->pos.y)
        return (1);
    return (0);
}

void zoom_stairs(game_t *game, sfRenderWindow *window)
{
    if ((game->move[0] == 1 && game->move[3] == 1) ||
    (game->move[1] == 1 && game->move[2] == 1)) {
        sfView_zoom(game->view, game->zoom);
        sfRenderWindow_setView(window, game->view);
        return;
    }
    for (int i = 0; game->stairs[i]; i++)
        if ( get_stair(game, i) == 1 &&
        game->pause == 0)
            update_zoom(game, i);
    if (game->zoom > 0.33) {
        game->zoom = 0.33;
        game->scale = 1;
    }
    if (game->zoom < 0.27) {
        game->zoom = 0.27;
        game->scale = 0.97;
    }
    sfView_zoom(game->view, game->zoom);
    sfRenderWindow_setView(window, game->view);
}

int parsing_stairs2(int *tab, char *line)
{
    int result = 0;
    int i = 0;
    int j = 0;

    while (i < 5 || line[j]) {
        if ((line[j] < '0' || line[j] > '9') && line[j] != '_' &&
        line[j] != '*')
            return 1;
        if (line[j] == '_' || line[j] == '*') {
            tab[i] = result;
            i++;
            result = 0;
        } else
            result = result * 10 + (line[j] - '0');
        j++;
    }
    return 0;
}

int **parsing_stairs(int **tab, char *path)
{
    char *file = get_file(path);
    char **result = my_str_to_word_array(file, '\n');
    int size = 0;

    if (file == NULL)
        return (NULL);
    tab = malloc(sizeof(int *) * (count_line(file) + 2));
    tab[count_line(file) + 1] = NULL;
    while (result[size]) {
        tab[size] = malloc(sizeof(int) * 5);
        if (parsing_stairs2(tab[size], result[size]) == 1)
            return tab;
        size++;
    }
    result[size] = NULL;
    free(file);
    free_tab(result);
    return tab;
}
