/*
** EPITECH PROJECT, 2021
** my_strncpy.c
** File description:
** copiying n caracteres in a string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    for (i = 0; i <= n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
