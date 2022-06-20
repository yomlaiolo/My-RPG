/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** import all function
*/

#ifndef MY_H
    #define MY_H

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/wait.h>

    int my_compute_power_rec(int nb, int p);

    int my_compute_square_root(int nb);

    int is_prime(int nb);

    int my_find_prime_sup(int nb);

    int my_getnbr(char const *str);

    int my_isneg(int n);

    int my_is_prime(int nb);

    int my_putchar(char c);

    int my_put_nbr(int nb);

    int my_putstr(char const *str);

    int count_lenght_str(char *str);

    void invert_char(char *ptr1, char *ptr2);

    char *my_revstr(char *str);

    int my_showmem(char const *str);

    int my_showstr(char const *str);

    void my_sort_int_array(int *tab, int size);

    char *my_strcapitalize(char *str);

    char *my_strcat(char *dest, char const *src);

    int my_strcmp(char const *s1, char const *s2);

    char *my_strcpy(char *dest, char const *src);

    int my_str_isalpha(char const *str);

    int my_str_islower(char const *str);

    int my_str_isnum(char const *str);

    int my_str_isprintable(char const *str);

    int my_str_isupper(char const *str);

    int my_strlen(char const *str);

    char *my_strlowcase(char *str);

    char *my_strncat(char *dest, char const *src, int n);

    int my_strncmp(char const *s1, char const *s2, int n);

    char *my_strncpy(char *dest, char const *src, int n);

    char *my_strupcase(char *str);

    void my_swap(int *a, int *b);

    void my_put_nbr_octale(int nbr);

    void my_put_nbr_binary(int nbr);

    void my_putptr(long long ptr);

    void my_put_nbr_hexa(long long nbr);

    int count_char(char *str, char c);

    char **my_str_to_word_array(char *str, char c);

    void my_put_long(long nbr);

    void my_put_short(short nbr);

    void my_printf(char *txt, ...);

    char **my_tabcopy(char **tab);

    int my_tab_display(char **tab);

    char *my_itoa(int nb);

    int my_atoi(char *str);

    void free_tab(char **tab);

#endif
