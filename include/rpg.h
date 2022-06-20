/*
** EPITECH PROJECT, 2022
** My_RPG
** File description:
** rpg header
*/

#ifndef RPG_H_
    #define RPG_H_

    #include "my.h"
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Network.h>
    #include <SFML/Window.h>
    #include <SFML/System/Time.h>
    #include <time.h>
    #include <math.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include <string.h>

    typedef struct sprite_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfIntRect rect;
        sfVector2f pos;
        int nb_rect;
        int status;
        int clicked;
    } sprite_t;

    typedef struct coords_s {
        int x;
        int y;
    } coords_t;

    typedef struct text_s {
        sfText *text;
        sfFont *font;
        char *str;
        sfVector2f pos;
    } text_t;

    typedef struct sound_s {
        sfSound *sound;
        sfSoundBuffer *buffer;
        float volume;
    } sound_t;

    typedef struct music_s {
        sfMusic *music;
        float volume;
        int played;
    } music_t;

    typedef struct clockk_s {
        float seconds;
        sfClock *clock;
        sfTime times;
        float diff;
    } clockk_t;

    typedef struct frambuffer_s{
        int width;
        int height;
        sfUint8 *pixels;
        sfUint8 *pixels_save;
        sprite_t *sprite;
        clockk_t *clock;
    } framebuffer_t;

    typedef struct stat_s {
        float hp;
        int hp_max;
        float mp;
        int mp_max;
        int atk;
        int def;
        int endurence;
        int monsters_killed;
    } stat_t;

    typedef struct player_s {
        sprite_t *mp_bar;
        sprite_t *mp;
        sprite_t *life_bar;
        sprite_t *life;
        stat_t *stat;
        int recup;
        clockk_t *clock;
        clockk_t *last_damage;
        int fire;
        int antidote;
        int ice;
        int sword;
    } player_t;

    typedef struct entity_s {
        text_t *parole;
        sprite_t *picture;
        clockk_t *clock;
        framebuffer_t *framebuffer;
    } entity_t;

    typedef struct monster_s {
        entity_t *entity;
        int hp;
        int max_hp;
        int attack;
        int is_moving;
        sfVector2f pos_start;
        int dead;
        int phase;
        sprite_t *life_bar;
        int speed;
        clockk_t *attack_clock;
        clockk_t *poison_clock;
        struct monster_s *next;
        framebuffer_t *framebuffer;
    } monster_t;

    typedef struct textbox_s {
        int next;
        int finish;
        int parser;
        char *text;
        entity_t *textbox;
        sound_t *speak;
    } textbox_t;

    typedef struct item_s {
        int id;
        int quantity;
        text_t *quantity_text;
        sprite_t *sprite;
        sprite_t *sprite2;
        sprite_t *use;
        text_t *text;
        clockk_t *clock;
        int status;
    } item_t;

    typedef struct count_s {
        int count1;
        int count2;
        int count3;
        int count4;
    } count_t;

    typedef struct quest_s {
        int step;
        int count;
    } quest_t;

    typedef struct pnj_s {
        entity_t *entity;
        char *name;
        int nb;
        int drop;
        struct pnj_s *next;
        int anim;
    } pnj_t;

    typedef struct pnj_info_s {
        pnj_t *pnj;
        char *path;
        char *name;
        int nb;
        int drop;
        sfVector2f pos;
        int anim;
    } pnj_info_t;

    typedef struct dialogs_s {
        char **text;
        struct dialogs_s *next;
    } dialogs_t;

    typedef struct option_s {
        sprite_t *display;
        sprite_t *skip;
        sprite_t *text_speed;
        sprite_t *music_volume;
        sprite_t *sound_volume;
        sprite_t *exit;
        sprite_t *font;
        text_t *text;
        sfVector2i mouse_pos;
    } option_t;

    typedef struct intro_s {
        sprite_t *intro;
        sprite_t *play;
        sprite_t *option;
        option_t *option_content;
        sprite_t *help;
        sprite_t *how_to_play;
        int help_open;
        sprite_t *quit;
        music_t *music;
    } intro_t;

    typedef struct pause_s {
        sprite_t *pause;
        sprite_t *resume;
        sprite_t *exit;
        sprite_t *options;
        option_t *option_content;
    } pause_t;

    typedef struct bulle_s {
        framebuffer_t *framebuffer;
        int x;
        int x_limit;
        int y;
        int y_limit;
        int step;
        struct bulle_s *next;
    } bulle_t;

    typedef struct music_zone_s {
        music_t *village;
        music_t *forest;
        music_t *desert;
        music_t *boss;
        music_t *snow;
        clockk_t *fade;
    } music_zone_t;

    typedef struct potion_bar_s {
        entity_t *entity;
        int status;
    } potion_bar_t;

    typedef struct game_s {
        sprite_t *map;
        entity_t *player;
        player_t *player_info;
        monster_t *monsters;
        textbox_t *textbox;
        int activate_textbox;
        int **map_block;
        int **stairs;
        sfView *view;
        item_t **inv;
        int is_inv;
        int pause;
        sprite_t *inventory_back;
        int *move;
        float zoom;
        int speed;
        clockk_t *total_clock;
        float d_time;
        count_t *count;
        pnj_t *pnj;
        dialogs_t *dialogs;
        sound_t *colision_sound;
        sprite_t **map_render;
        int attack;
        int is_menu;
        float scale;
        bulle_t *bulles;
        int speed_text;
        int setting_speed;
        int display_intro;
        pause_t *menu_pause;
        int m_pause;
        int main_quest;
        pnj_t *pnj_tmp;
        monster_t *monster_tmp;
        music_zone_t *musics;
        potion_bar_t **potion_bar;
        sound_t **sword;
        int win;
    } game_t;

    typedef struct lose_s {
        sprite_t *intro;
        sprite_t *quit;
        sprite_t *load;
        sprite_t *menu;
        text_t *text;
    } lose_t;

    typedef struct game_scene_s {
        int scene;
        game_t *game;
    } game_scene_t;

    typedef struct str_s {
        char *str1;
        char *str2;
        char *str3;
        char *str4;
        int count;
        int k;
        int m;
        int l;
    } str_t;

    typedef struct args_s {
        int ventilator;
        int h;
    } args_t;

    typedef struct opt_info_s {
        int display;
        int skip;
        int speed;
        int music;
        int sound;
    } opt_info_t;

    typedef struct scene_s {
        int scene;
        sfRenderWindow *window;
        intro_t *intro;
        game_t *game;
        lose_t *lose;
        int angle;
        args_t *args;
        sprite_t *mouse;
        opt_info_t *opt_info;
        sfVector2f mouse_pos;
        sprite_t *win;
        clockk_t *clock;
        music_t *music;
    } scene_t;

    typedef struct scene_info_s {
        int scene;
        int angle;
        sfRenderWindow *window;
        intro_t *intro;
        lose_t *lose;
        game_t *game;
        args_t *args;
        sprite_t *mouse;
        opt_info_t *opt_info;
        sfVector2f mouse_pos;
    } scene_info_t;

    int load_text_rpg(text_t *text, sfVector2f pos, char *str, int size);

    void set_slider(option_t *option_content, sfRenderWindow *window,
    sfEvent event, int *info_opt);

    void move_pixel(entity_t *entity, game_t *game);

    sprite_t *init_sprite(char *path, sfVector2f pos, sfIntRect rect);

    void display_lose(sfRenderWindow *window, lose_t *lose);

    int load_sprite(sprite_t *s, char *path, sfVector2f pos, sfIntRect rect);

    void load_button(sprite_t *sprite, char *path, int y);

    int load_text(text_t *text, sfVector2f pos, char *str, int size);

    int load_music(music_t *music, char *str, int volume);

    int load_sound(sound_t *sound, char *str);

    entity_t *load_entity(entity_t *entity, char *filename,
    sfVector2f coords, sfIntRect rect);

    framebuffer_t *fill_buffer(framebuffer_t *framebuffer, sfColor color);

    void display_particles(sfRenderWindow *window, framebuffer_t *framebuffer);

    void put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color);

    void update_pixel(framebuffer_t *framebuffer, sfColor old_color,
    sfColor new_color);

    void put_n_pixel(framebuffer_t *framebuffer, int x, sfColor color);

    framebuffer_t *framebuffer_create(int width, int height, sfVector2f pos);

    void step_all_bulle(bulle_t *bulle, int pause);

    void step_bulle(bulle_t *bulle, int pause);

    void restart_clock(clockk_t *timer);

    void init_bulle(bulle_t *bulle);

    bulle_t *make_bulles(void);

    void display_bulles(sfRenderWindow *window, bulle_t *bulle);

    void stay(entity_t *entity, game_t *game);

    game_t *init_game(sfRenderWindow *window, scene_t *scene,
    opt_info_t *info);

    void destroy_lose(lose_t *lose);

    int parsing_colision(game_t *game);

    char *define_str1(str_t *str, char **result, coords_t coords);

    char *define_str2(str_t *str, char **result, coords_t coords);

    char *define_str3(str_t *str, char **result, coords_t coords);

    char *define_str4(str_t *str, char **result, coords_t coords);

    monster_t *generate_monsters(void);

    void inventory(game_t *game, sfRenderWindow *window);

    int load_inventory(game_t *game, sfRenderWindow *window);

    int verify_coords(int **tab, str_t *str, char **result, coords_t coords);

    int count_line(char *file);

    char *get_file(char *path);

    void display_monster(sfRenderWindow *window, monster_t *monster,
    game_t *game);

    void manage_event(scene_t *scene);

    void manage_bars(scene_t *scene);

    textbox_t *init_textbox(char *text, sfView *view, scene_t *scene);

    void init_var_textbox(textbox_t *textbox, char *text);

    int set_volume_textbox(textbox_t *textbox, scene_t *scene);

    void set_textbox(textbox_t *textbox, char *str, sfView *view);

    void display_textbox(sfRenderWindow *window , game_t *game);

    void destroy_textbox(textbox_t *textbox, game_t *game);

    void manage_clock(clockk_t *clock, int pause);

    int animate_textbox(textbox_t *textbox, sfView *view, int speed);

    void manage_event_textbox(scene_t *scene, int type, char *name, int nb);

    void init_clock(clockk_t *timer);

    void move_conds(game_t *game, int i);

    void move_event(game_t *game);

    void released(game_t *game, sfEvent event);

    void pressed(game_t *game, sfEvent event);

    int ventilator(game_t *game, args_t *args, int angle);

    args_t *init_args(int ac, const char *av[]);

    void set_sound(music_t *music, float volume);

    int set_opt(game_t *game, opt_info_t *info);

    int run_game(scene_t *scene, sfRenderWindow *window, int angle,
    args_t *args);

    void display_game(sfRenderWindow *window, game_t *game);

    void display_intro(sfRenderWindow *window, intro_t *intro);

    int run_intro(intro_t *intro, sfRenderWindow *window);

    scene_info_t gestion(scene_t *scene, sfRenderWindow *window);

    intro_t *init_intro(opt_info_t *opt_info);

    void destroy_intro(intro_t *intro);

    void destroy_game(game_t *game);

    sprite_t *over_test(sprite_t *sprite, int move,
    sfRenderWindow *window, sfEvent event);

    void update_time(game_t *game);

    void close_scene(scene_t *scene);

    void colision_event(game_t *game);

    int **parsing_stairs(int **tab, char *path);

    void zoom_stairs(game_t *game, sfRenderWindow *window);

    sprite_t **create_sprite_tab(sprite_t **sprite);

    void attack(entity_t *entity, game_t *game);

    void verify_attack(entity_t *entity, game_t *game);
    dialogs_t *init_dialogs(void);

    sprite_t **create_sprite_tab(sprite_t **sprite);

    void destroy_dialog(dialogs_t *dialog);

    pnj_t *init_pnj(pnj_info_t *infos);

    int add_pnj(pnj_info_t *pnj_info);

    int load_pnj(pnj_t *pnj);

    void display_pnj(sfRenderWindow *window, pnj_t *pnj);

    void destroy_pnj(pnj_t *pnj);

    char *get_dialogs(dialogs_t *dialog, char *name, int nb);

    void move_monster(game_t *game);

    void destroy_sprite(sprite_t *sprite);

    void destroy_text(text_t *text);

    void destroy_music(music_t *music);

    void destroy_sound(sound_t *sound);

    int *monster_separator(entity_t *entity, entity_t *entity2, int *tab);

    int *entity_colision(entity_t *entity, game_t *game);

    void calcul_bar_percent(player_t *player_info);

    void recup_mp(game_t *game);

    void option_gestion(intro_t *intro, sfRenderWindow *window, sfEvent event,
    opt_info_t *info);

    void use_potions(scene_t *scene, int i);

    int manage_pnj_event(scene_t *scene, sfEvent event);

    scene_t *intro_gestion(scene_t *scene);

    scene_t *lose_gestion(scene_t *scene);

    scene_t *game_gestion(scene_t *scene);

    lose_t *init_lose(void);

    void released(game_t *game, sfEvent event);

    void pressed(game_t *game, sfEvent event);

    void final_move(game_t *game, int *tab, int *tab2, monster_t *tmp);

    int manage_pause(game_t *game, sfRenderWindow *window, sfEvent event,
    opt_info_t *info);

    int checker(sfVector2i mouse_pos, sprite_t *sprite, sfEvent event,
    sfRenderWindow *window);

    int slider(sfEvent event, sprite_t *sprite, coords_t border,
option_t *option_content);

    void set_option_values(int *tab, opt_info_t *info, sfRenderWindow *window);

    void timer_potion(scene_t *scene);

    void move_pnj(game_t *game);

    void calcul_monster_life(monster_t *monster);

    void cpy_framebuffer(framebuffer_t *framebuffer);

    void trainer_quest(pnj_t *pnj, scene_t *scene);

    void desertor_quest(pnj_t *pnj, scene_t *scene);

    void snow_quest(pnj_t *pnj, scene_t *scene);

    void use_potion_heal(scene_t *scene, int i);

    void use_potion_atk(scene_t *scene, int i);

    void use_potion_endurance(scene_t *scene, int i);

    void use_potion_fire(scene_t *scene, int i);

    void use_potion_antidote(scene_t *scene, int i);

    void use_potion_ice(scene_t *scene, int i);

    void timer_atk(scene_t *scene);

    void timer_endurance(scene_t *scene);

    void timer_fire(scene_t *scene);

    void timer_antidote(scene_t *scene);

    void timer_ice(scene_t *scene);

    void timer_potion(scene_t *scene);

    void use_potion_heal(scene_t *scene, int i);

    void use_potions(scene_t *scene, int i);

    void set_pos_inv(game_t *g, int i, sfRenderWindow *w);

    void set_var_inv(game_t *g, int i, sfRenderWindow *w);

    int set_inv(game_t *game, int i, int x);

    music_zone_t *init_zone_music(void);

    void gestion_zone_sound(game_t *game, opt_info_t *info, int *tab,
    music_t *music);

    void call_musics(game_t *game, opt_info_t *info);

    potion_bar_t **init_potion_bar(sfView *view);

    void display_potion_bar(sfRenderWindow *window, game_t *game);

    void destroy_potion_bar(potion_bar_t **potion_bar);

    void get_drop(game_t *game, pnj_t *pnj);

    int give_item(game_t *game, pnj_t *pnj);

    int get_pos(monster_t *tmp);

    float get_distance(sfVector2f pos1, sfVector2f pos2);

    void display_pause_options(game_t *g, sfRenderWindow *window);

    void display_pause(game_t *g, sfRenderWindow *window);

    void display_monster_alive(monster_t *tmp, sfRenderWindow *window);

    monster_t *init_monster(int **tab, int i);

    float calcul_speed_text(int speed);

    void restart_monsters(monster_t *monster, game_t *game);

    char *select_monster_texture(int **tab, int i);

    void set_monster_info(monster_t *monster, int **tab, int i);

    option_t *init_option(opt_info_t *info);

    void set_game_info(game_t *game, entity_t *entity, sprite_t *map);

    player_t *set_player_info(void);

    int movement_event(sfEvent event, scene_t *scene);

    void close_event(scene_t *scene, sfEvent event);

    void set_status_inv(scene_t *scene, int i);

    void select_potion(scene_t *scene, sfEvent event);

    scene_t *manage_inventory(scene_t *scene, sfEvent event);

    void play_colision(scene_t *scene);

    int manage_event_close(scene_t *scene, sfEvent event);

    void destroy_sword_sound(game_t *g);

    void destroy_entity(entity_t *entity);

    void destroy_int_array(int **array);

    void display_help(sfRenderWindow *window, intro_t *intro);

    void close_help(intro_t *intro);

    void win_gestion(scene_t *scene);

    void manage_zone(game_t *game);

    void main_quest(pnj_t *pnj, scene_t *scene);

    void destroy_clocck(clockk_t *clock);

    void destroy_framebuffer(framebuffer_t *framebuffer);

    void destroy_monster(monster_t *monster);

    void destroy_map_render(sprite_t **map_render);

    void destroy_menu_pause(pause_t *menu_pause);

    void destroy_zone_sound(music_zone_t *musics);

    int set_sword_sound(game_t *g);

    void monster_quest(monster_t *tmp, game_t *game);

    void init_monster_clock(monster_t *monster);

    int test_file(scene_t *scene, sfRenderWindow *window);

    scene_t *init_scene_save(sfRenderWindow *window, args_t *args,
    scene_t *scene);

#endif
