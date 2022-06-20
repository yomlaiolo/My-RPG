/*
** EPITECH PROJECT, 2021
** my_is_prime.c
** File description:
** test if the number is a prime number
*/

int my_is_prime(int nb)
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
