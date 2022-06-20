/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** reproduce the function print_f from the C lib
*/

#include <stdlib.h>
#include "my.h"
#include <stdarg.h>

void display_long(va_list list)
{
    my_put_long(va_arg(list, long));
}

void display_short(va_list list)
{
    my_put_short(va_arg(list, int));
}
