/*
** EPITECH PROJECT, 2021
** my_put_str.c
** File description:
** Description bhuzvbfghyuez
*/

void my_putchar(char c);

void my_put_nbr_octale(int nbr)
{
    int nbr2;

    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * (-1);
    }
    if (nbr >= 8) {
        nbr2 = nbr % 8;
        nbr = nbr / 8;
        my_put_nbr_octale(nbr);
        my_putchar(nbr2 + 48);
    } else {
        my_putchar(nbr + 48);
    }
}
