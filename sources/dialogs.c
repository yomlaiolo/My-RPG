/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** parser for dialog file
*/

#include "rpg.h"

char **dialog_parser(char *path)
{
    char *content = get_file(path);
    char **tab = my_str_to_word_array(content, '$');

    if (content == NULL)
        return NULL;
    free(content);
    return tab;
}

dialogs_t *create_dialog(char *tab)
{
    dialogs_t *dialog = malloc(sizeof(dialogs_t));

    dialog->text = my_str_to_word_array(tab, '&');
    dialog->next = NULL;
    return dialog;
}

char *get_dialogs(dialogs_t *dialog, char *name, int nb)
{
    dialogs_t *tmp = dialog;

    if (tmp == NULL || name == NULL)
        return NULL;
    while (tmp != NULL && my_strncmp(tmp->text[0], name,
    my_strlen(name)) != 0) {
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return NULL;
    return tmp->text[nb];
}

dialogs_t *init_dialogs(void)
{
    dialogs_t *dialog = NULL;
    dialogs_t *temp = NULL;
    dialogs_t *temp2 = NULL;
    char **tab = NULL;
    int i = 0;

    if ((tab = dialog_parser("game_files/dialogs.rpg")) == NULL)
        return NULL;
    dialog = create_dialog(tab[i]);
    temp = dialog;
    temp2 = dialog;
    for (i = 1; tab[i] != NULL; i++) {
        temp = create_dialog(tab[i]);
        temp2->next = temp;
        temp2 = temp;
    }
    temp2->next = NULL;
    free_tab(tab);
    return dialog;
}

void destroy_dialog(dialogs_t *dialog)
{
    dialogs_t *tmp = dialog;

    while (dialog != NULL) {
        dialog = dialog->next;
        free_tab(tmp->text);
        free(tmp);
        tmp = dialog;
    }
    free(tmp);
}
