/*
** EPITECH PROJECT, 2022
** B-MUL-100-TLS-1-1-myrunner-christopher.artigas-fuentes
** File description:
** A function that transfrom an int to a str.
*/

#include <unistd.h>
#include <stdlib.h>

char *my_itoa(int nb)
{
    if (nb == 0)
        return "0";
    int len = 0;
    int temp = nb;
    char *result = NULL;
    while (temp > 0) {
        temp /= 10;
        len++;
    }
    result = malloc(sizeof(*result) * (len + 1));
    result[len] = '\0';
    while (len != 0) {
        len--;
        result[len] = nb % 10 + '0';
        nb /= 10;
    }
    return result;
}
