/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** Swap the content of intergers
*/

int my_putchar(char c);

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
