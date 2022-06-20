/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** reproduce the function print_f from the C lib
*/

#include <stdlib.h>
#include "my.h"
#include <stdarg.h>

void display_int(va_list list)
{
    my_put_nbr(va_arg(list, int));
}

void display_char(va_list list)
{
    my_putchar(va_arg(list, int));
}

void display_str(va_list list)
{
    my_putstr(va_arg(list, char *));
}

void display_porcent(va_list list)
{
    my_putchar('%');
}
