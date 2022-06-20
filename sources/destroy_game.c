/*
** EPITECH PROJECT, 2022
** B-MUL-200-TLS-2-1-myrpg-benjamin.bourez
** File description:
** destroy_game
*/

#include "rpg.h"

void destroy_bulle(bulle_t *bulle)
{
    bulle_t *tmp = bulle;
    bulle_t *tmp2 = bulle;

    while (tmp != NULL) {
        tmp = tmp->next;
        destroy_framebuffer(tmp2->framebuffer);
        free(tmp2);
        tmp2 = tmp;
    }
}

void destroy_inv(item_t **inv)
{
    for (int i = 0; i < 6; i++) {
        destroy_text(inv[i]->text);
        destroy_text(inv[i]->quantity_text);
        destroy_sprite(inv[i]->sprite);
        destroy_sprite(inv[i]->sprite2);
        destroy_sprite(inv[i]->use);
        if (inv[i]->clock != NULL)
            destroy_clocck(inv[i]->clock);
        free(inv[i]);
    }
    free(inv);
}

void destroy_player(player_t *player)
{
    destroy_sprite(player->mp_bar);
    destroy_sprite(player->life_bar);
    destroy_sprite(player->life);
    destroy_sprite(player->mp);
    destroy_clocck(player->clock);
    destroy_clocck(player->last_damage);
    free(player->stat);
    free(player);
}

void close_game(game_t *game)
{
    destroy_int_array(game->map_block);
    destroy_int_array(game->stairs);
    destroy_monster(game->monsters);
    destroy_sword_sound(game);
    destroy_bulle(game->bulles);
    destroy_map_render(game->map_render);
    destroy_menu_pause(game->menu_pause);
}

void destroy_game(game_t *game)
{
    destroy_sprite(game->map);
    destroy_entity(game->player);
    destroy_player(game->player_info);
    destroy_sprite(game->inventory_back);
    sfView_destroy(game->view);
    destroy_sound(game->colision_sound);
    destroy_pnj(game->pnj);
    destroy_dialog(game->dialogs);
    destroy_potion_bar(game->potion_bar);
    destroy_zone_sound(game->musics);
    destroy_inv(game->inv);
    destroy_clocck(game->total_clock);
    close_game(game);
    free(game->move);
    free(game->count);
    free(game);
}
