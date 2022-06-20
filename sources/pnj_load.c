/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** pnj_load
*/

#include "rpg.h"

int load_statue(pnj_t *pnj)
{
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/statue.png", "Statue1",
    0, 7, (sfVector2f) {982, 800}, 0}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/statue.png", "Statue2",
    0, 8, (sfVector2f) {495, 1670}, 0}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/statue.png", "Statue3",
    0, 9, (sfVector2f) {1122, 4476}, 0}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/statue.png", "Statue4",
    0, 10, (sfVector2f) {2995, 4660}, 0}) == 84)
        return 84;
    return 0;
}

int load_more_chest(pnj_t *pnj)
{
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/chest.png", "Chest1",
    0, 1, (sfVector2f) {857, 3750}, 0}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/chest.png", "Chest4",
    0, 5, (sfVector2f) {1055, 4631}, 0}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/chest.png", "Chest3",
    0, 3, (sfVector2f) {2667, 2202}, 0}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/chest.png", "Chest2",
    0, 2, (sfVector2f) {3190, 3274}, 0}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/chest.png", "Chest2",
    0, 2, (sfVector2f) {4720, 1840}, 0}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/chest.png", "Chest1",
    0, 1, (sfVector2f) {4587, 317}, 0}) == 84)
        return 84;
    return 0;
}

int load_chest(pnj_t *pnj)
{
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/chest.png", "Chest1",
    0, 1, (sfVector2f) {392, 172}, 0}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/chest.png", "Chest2",
    0, 2, (sfVector2f) {645, 2485}, 0}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/chest.png", "Chest3",
    0, 3, (sfVector2f) {321, 606}, 0}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/chest.png", "Chest4",
    0, 5, (sfVector2f) {1200, 2262}, 0}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/chest.png", "Chest1",
    0, 1, (sfVector2f) {2464, 3100}, 0}) == 84)
        return 84;
    if (load_more_chest(pnj) == 84)
        return 84;
    return 0;
}

int load_npc(pnj_t *pnj)
{
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/knight.png", "Trainer",
    0, 0, (sfVector2f) {760, 402}, 1}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/runner.png", "Runner",
    0, 3, (sfVector2f) {880, 215}, 1}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/grandpa.png", "Grandpa",
    0, 0, (sfVector2f) {415, 470}, 1}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/witch.png", "Witch",
    0, 0, (sfVector2f) {2835, 595}, 1}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/voyager1.png",
    "Desertor", 0, 0, (sfVector2f) {645, 2169}, 1}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/voyager2.png",
    "Snowgirl", 0, 0, (sfVector2f) {4720, 332}, 1}) == 84)
        return 84;
    return 0;
}

int load_pnj(pnj_t *pnj)
{
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/endurance_pnj.png",
    "Villager2", 0, 0, (sfVector2f) {653, 1551}, 1}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/endurance_pnj.png",
    "Villager3", 0, 0, (sfVector2f) {1205, 4627}, 1}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/receiver.png",
    "Villager4", 0, 0, (sfVector2f) {3423, 3083}, 1}) == 84)
        return 84;
    if (add_pnj(&(pnj_info_t) {pnj, "./ressources/game/voyager1.png",
    "Villager5", 0, 0, (sfVector2f) {4026, 892}, 1}) == 84)
        return 84;
    if (load_npc(pnj) == 84)
        return 84;
    if (load_chest(pnj) == 84)
        return 84;
    if (load_statue(pnj) == 84)
        return 84;
    return 0;
}
