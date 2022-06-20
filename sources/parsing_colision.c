/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** parsing_colision
*/

#include "rpg.h"

int **parsing_colision3(int **tab, char **result, int i, str_t str)
{
    for (int j = 0; result[i][j]; j++) {
        if (verify_coords(tab, &str, result, (coords_t) {i, j}) == 84)
            return NULL;
        str.str1 = define_str1(&str, result, (coords_t) {i, j});
        str.str2 = define_str2(&str, result, (coords_t) {i, j});
        str.str3 = define_str3(&str, result, (coords_t) {i, j});
        str.str4 = define_str4(&str, result, (coords_t) {i, j});
    }
    return tab;
}

void destroy_str(str_t *str)
{
    free(str->str1);
    free(str->str2);
    free(str->str3);
    free(str->str4);
}

int parsing_colision2(int **tab, char **result, int i)
{
    char *str1 = malloc(sizeof(char) * 20);
    char *str2 = malloc(sizeof(char) * 20);
    char *str3 = malloc(sizeof(char) * 20);
    char *str4 = malloc(sizeof(char) * 20);
    int k = 0;
    int l = 0;
    int m = 0;
    int count = 0;

    str_t str = {str1, str2, str3, str4, count, k, l, m};
    tab[i] = malloc(sizeof(int) * 4);
    if ((tab = parsing_colision3(tab, result, i, str)) == NULL) {
        destroy_str(&str);
        return 84;
    }
    destroy_str(&str);
    return 0;
}

int parsing_colision(game_t *game)
{
    char *file = get_file("game_files/colision.rpg");
    char **result = my_str_to_word_array(file, '\n');

    if (file == NULL)
        return 84;
    game->map_block = malloc(sizeof(int *) * (count_line(file) + 2));
    game->map_block[count_line(file) + 1] = NULL;
    for (int i = 0; result[i]; i++)
        if (parsing_colision2(game->map_block, result, i) == 84)
            return 84;
    free(file);
    free_tab(result);
    return 0;
}
