/*
** EPITECH PROJECT, 2021
** my_compute_square_root.c
** File description:
** calculate the square root of a number
*/

int my_compute_square_root(int nb)
{
    if (nb < 1) {
        return 0;
    } else if (nb == 1) {
        return 1;
    }
    for (int i = 0; i < nb; i++) {
        if (i * i == nb) {
            return i;
        }
    }
    return 0;
}
