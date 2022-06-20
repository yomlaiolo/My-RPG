/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** dzegsr cvbrre iepv rtion
*/

#include "my.h"

int count_tab_len(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return i - 1;
}

int my_tab_display(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_printf("%s\n", tab[i]);
    }
    return 0;
}

char **my_tabcopy(char **tab)
{
    char **new_tab = NULL;
    int tab_len = count_tab_len(tab);
    int i = 0;
    int j = 0;

    new_tab = malloc(sizeof(char *) * (tab_len + 1));
    for (; i < tab_len; i++) {
        new_tab[i] = malloc(sizeof(char) * (my_strlen(tab[i]) + 1));
        for (j = 0; tab[i][j] != '\0'; j++) {
            new_tab[i][j] = tab[i][j];
        }
        new_tab[i][j] = '\0';
    }
    new_tab[i] = NULL;
    return new_tab;
}
