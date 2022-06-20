/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-mysokoban-christopher.artigas-fuentes
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

static unsigned int get_word_size(const char *str, char c)
{
    unsigned int size = 0;

    while (str[size] && str[size] != c)
        size++;
    return size;
}

static unsigned int count_words(const char *str, char c)
{
    unsigned int index = 0;
    unsigned int words = 0;
    while (str[index]) {
        if (str[index] == c)
            words++;
        while (str[index] == c)
            index++;
        index++;
    }
    return (words + 1);
}

static char *fill_column(const char *c_str, unsigned int *index_str, char c)
{
    unsigned int index = 0;
    unsigned int size;
    char *column;

    size = get_word_size(c_str + *index_str, c);
    if (!(column = malloc(sizeof(char) * (size + 1))))
        return (NULL);
    while (index < size && c_str[*index_str]) {
        column[index] = c_str[*index_str];
        *index_str += 1;
        index += 1;
    }
    column[index] = '\0';
    *index_str += 1;
    return (column);
}

char **my_str_to_word_array(char *clean_str, char c)
{
    unsigned int index_line;
    unsigned int index_str;
    unsigned int words;
    char **array;

    if (!clean_str)
        return (NULL);
    words = count_words(clean_str, c);
    if (!(array = malloc(sizeof(char *) * (words + 1))))
        return (NULL);
    index_str = 0;
    index_line = 0;
    while (index_line < words) {
        if (!(array[index_line] = fill_column(clean_str, &index_str, c)))
            return (NULL);
        index_line++;
    }
    array[index_line] = NULL;
    return array;
}
