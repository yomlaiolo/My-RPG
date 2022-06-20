/*
** EPITECH PROJECT, 2021
** my_atoi.c
** File description:
** convert a str to an int, returns 0 if error
*/

int my_atoi(char *str)
{
    int result = 0;
    int sign = 0;
    int i = 0;
    ((str[i] == '-') ? (sign = 1, i++) : (0));
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result *= 10;
            result += str[i] - '0';
        } else
            return (result);
        i++;
    }
    if (sign == 0)
        return result;
    else
        return (-result);
}
