/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** reproduce the function print_f from the C lib
*/

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "my.h"
#include "functions.h"

void display_printf(va_list list, char *txt, char i)
{
    void (*function_list[7])(va_list);

    function_list['d'] = &display_int;
    function_list['i'] = &display_int;
    function_list['u'] = &display_int;
    function_list['c'] = &display_char;
    function_list['s'] = &display_str;
    function_list['%'] = &display_porcent;
    function_list['o'] = &display_octale;
    function_list['b'] = &display_binary;
    function_list['p'] = &display_ptr;
    function_list['S'] = &display_str_non_printable;
    function_list['l'] = &display_long;
    function_list['h'] = &display_short;
    (*function_list[txt[i]]) (list);
}

int len_flag(char *txt, char i)
{
    if (txt[i] == 'l' || txt[i] == 'h') {
        if (txt[i + 1] == 'd' || txt[i + 1] == 'i') {
            return 1;
        }
    }
    return 0;
}

void my_printf(char *txt, ...)
{
    int i = 0;

    va_list list;
    va_start(list, txt);
    for (int i = 0; txt[i] != '\0'; i++) {
        if (txt[i] != '%') {
            my_putchar(txt[i]);
        } else {
            i++;
            display_printf(list, txt, i);
            i += len_flag(txt, i);
        }
    }
    va_end(list);
}
