/*
** EPITECH PROJECT, 2021
** my_strncat.c
** File description:
** desvcrer ep tei e on
*/

char *my_putstr(char *str);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    while (dest[i] != '\0') {
        i++;
    }
    return (my_strncpy(dest + i, src, n - 1) - i);
}
