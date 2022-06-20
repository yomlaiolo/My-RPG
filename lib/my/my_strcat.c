/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** concatenates tow string
*/

#include "../../include/my.h"

#include <stdlib.h>

char *my_strcat(char *dest , char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)) + 1);
    int x = 0;

    for (int i = 0; i < my_strlen(dest); i++) {
        str[x] = dest[i];
        x++;
    }
    for (int i = 0; i < my_strlen(src); i++) {
        str[x] = src[i];
        x++;
    }
    str[x] = '\0';
    return str;
    free(str);
}
