/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** display 'P' or 'N' if the interger a parameter
** is positive (or null) or negative
*/

int my_putchar(int c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar(78);
    } else {
        my_putchar(80);
    }
    return 0;
}
