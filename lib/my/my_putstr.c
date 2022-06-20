/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** Display all characters of a srting
*/

int my_putchar(char c);

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str += 1;
    }
    return 0;
}
