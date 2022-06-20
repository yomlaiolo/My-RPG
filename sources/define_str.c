/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** define_str
*/

#include "rpg.h"

char *define_str1(str_t *str, char **result, coords_t coords)
{
    if (str->count == 0) {
        str->str1[coords.y] = result[coords.x][coords.y];
        str->str1[coords.y + 1] = '\0';
    }
    return str->str1;
}

char *define_str2(str_t *str, char **result, coords_t coords)
{
    if (str->count == 1 && result[coords.x][coords.y] != '_') {
        str->str2[str->k] = result[coords.x][coords.y];
        str->str2[str->k + 1] = '\0';
        str->k++;
    }
    return str->str2;
}

char *define_str3(str_t *str, char **result, coords_t coords)
{
    if (str->count == 2 && result[coords.x][coords.y] != '_') {
        str->str3[str->l] = result[coords.x][coords.y];
        str->str3[str->l + 1] = '\0';
        str->l++;
    }
    return str->str3;
}

char *define_str4(str_t *str, char **result, coords_t coords)
{
    if (str->count == 3 && result[coords.x][coords.y] != '_') {
        str->str4[str->m] = result[coords.x][coords.y];
        str->str4[str->m + 1] = '\0';
        str->m++;
    }
    return str->str4;
}
