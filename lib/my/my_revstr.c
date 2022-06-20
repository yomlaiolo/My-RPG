/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** Swap characters of a string
*/

char *my_putstr(char *str);

int my_strlen(char *str);

char *swap(char *str1, char *str2)
{
    char temp;

    temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;

    while (i < j) {
        swap(&str[i], &str[j]);
        j--;
        i++;
    }
    return str;
}
