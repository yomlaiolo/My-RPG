/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** free_tab
*/

#include <stdlib.h>

void free_tab(char **tab)
{
    int i = 0;

    while (tab[i]) {
        free(tab[i]);
        i++;
    }
    free(tab);
}
