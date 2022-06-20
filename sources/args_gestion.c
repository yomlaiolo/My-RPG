/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** args_gestion
*/

#include "rpg.h"

int ventilator(game_t *game, args_t *args, int angle)
{
    if (args != NULL && args->ventilator == 1) {
        sfView_rotate(game->view, angle / 100);
        angle++;
        if (angle == 360)
            angle = 0;
    }
    return angle;
}

static void print_h(void)
{
    my_printf("RPG\nUSAGE :\n");
    my_printf("./my_rpg [OPTION]\n");
    my_printf("\t[-h] (open this help menu)\n");
    my_printf("\t[-v] (launch ventilator mod)\n");
}

args_t *init_args(int ac, const char *av[])
{
    args_t *args = malloc(sizeof(args_t));

    args->ventilator = 0;
    args->h = 0;
    for (int i = 0; i < ac; i++) {
        if (my_strcmp(av[i], "-v") == 0)
            args->ventilator = 1;
        if (my_strcmp(av[i], "-h") == 0) {
            print_h();
            args->h = 1;
        }
    }
    return args;
}
