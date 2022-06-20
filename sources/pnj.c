/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** generate pnj
*/

#include "rpg.h"

pnj_t *init_pnj(pnj_info_t *infos)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));

    pnj->entity = NULL;
    pnj->name = infos->name;
    pnj->nb = 1;
    pnj->drop = infos->drop;
    pnj->anim = infos->anim;
    if ((pnj->entity = load_entity(pnj->entity, infos->path, infos->pos,
    (sfIntRect) {0, 0, 32, 32})) == NULL)
        return (NULL);
    pnj->next = NULL;
    return pnj;
}

int add_pnj(pnj_info_t *pnj_info)
{
    pnj_t *temp = NULL;

    temp = pnj_info->pnj;
    while (temp->next != NULL)
        temp = temp->next;
    if ((temp->next = init_pnj(pnj_info)) == NULL)
        return 84;
    return 0;
}

void display_pnj(sfRenderWindow *window, pnj_t *pnj)
{
    pnj_t *tmp = pnj;

    while (tmp != NULL) {
        sfRenderWindow_drawSprite(window, tmp->entity->picture->sprite, NULL);
        tmp = tmp->next;
    }
}

void destroy_pnj(pnj_t *pnj)
{
    pnj_t *tmp = pnj;
    pnj_t *tmp2 = pnj;

    while (tmp != NULL) {
        tmp = tmp->next;
        destroy_entity(tmp2->entity);
        free(tmp2);
        tmp2 = tmp;
    }
}
