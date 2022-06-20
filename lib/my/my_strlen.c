/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** count the number of char in a str
*/

int my_putchar(int c);

int my_strlen(char const *str)
{
    int count = 0;
    while (*str != '\0') {
        str += 1;
        count += 1;
    }
    return count;
}
