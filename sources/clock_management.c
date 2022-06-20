/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** function for clock management
*/

#include "rpg.h"

void restart_clock(clockk_t *timer)
{
    sfClock_restart(timer->clock);
    timer->diff = 0;
    timer->seconds = 0;
}

void manage_clock(clockk_t *clock, int pause)
{
    if (pause == 0 && clock != NULL && clock->clock != NULL) {
        clock->times = sfClock_getElapsedTime(clock->clock);
        clock->seconds = clock->times.microseconds / 1000000.0 + clock->diff;
    }
    if (pause == 1 && clock->clock != NULL)
        clock->diff = clock->seconds;
    if (pause == 3 && clock->clock != NULL)
        sfClock_restart(clock->clock);
}

void destroy_clocck(clockk_t *clock)
{
    sfClock_destroy(clock->clock);
    free(clock);
    clock = NULL;
}
