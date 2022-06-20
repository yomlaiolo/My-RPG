/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** reproduce the function print_f from the C lib
*/

#include <stdlib.h>
#include "my.h"
#include <stdarg.h>

void display_binary(va_list list)
{
    my_put_nbr_binary(va_arg(list, int));
}

void display_octale(va_list list)
{
    my_put_nbr_octale(va_arg(list, int));
}

void put_zero(char c)
{
    if (c <= 8) {
        my_putchar('0');
        my_putchar('0');
    }
    if (c > 8 && c < 127)
        my_putchar('0');
}

void display_str_non_printable(va_list list)
{
    char *str = va_arg(list, char *);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            put_zero(str[i]);
            my_put_nbr_octale(str[i]);
        } else {
            my_putchar(str[i]);
        }
    }
}

void display_ptr(va_list list)
{
    my_putstr("0x");
    my_putptr(va_arg(list, long long));
}
