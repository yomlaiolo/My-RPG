/*
** EPITECH PROJECT, 2021
** my_putchar.c
** File description:
** put a char
*/

#include "my.h"

void my_put_nbr_hexa(long long nbr)
{
    long long nbr2;

    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * (-1);
    }
    if (nbr >= 16) {
        nbr2 = nbr % 16;
        nbr = nbr / 16;
        my_put_nbr_hexa(nbr);
        if (nbr2 < 10)
            my_putchar(nbr2 + 48);
        else
            my_putchar(nbr2 + 87);
    } else {
        if (nbr < 10)
            my_putchar(nbr + 48);
        else
            my_putchar(nbr + 87);
    }
}
