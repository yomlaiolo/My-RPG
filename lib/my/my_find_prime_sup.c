/*
** EPITECH PROJECT, 2021
** my_find_prime_sup.c
** File description:
** find the superior prime number of a number given
*/

int is_prime(int nb)
{
    if (nb < 2) {
        return 0;
    }
    for (int i = 2; i < nb; i += 1) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}

int my_find_prime_sup(int nb)
{
    int i = nb;
    while (is_prime(i) != 1) {
        i += 1;
    }
    return i;
}
