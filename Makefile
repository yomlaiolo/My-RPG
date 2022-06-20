##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

COMPILATION = my_rpg

SRC 	=	sources/main.c\
			sources/entity.c\
			sources/utile_load.c\
			sources/stay.c\
			sources/init_scene.c\
			sources/colision.c\
			sources/define_str.c\
			sources/monsters.c\
			sources/inventory.c\
			sources/parsing_colision.c\
			sources/display.c\
			sources/event.c\
			sources/textbox.c\
			sources/textbox_management.c\
			sources/clock_management.c\
			sources/move.c\
			sources/args_gestion.c\
			sources/music.c\
			sources/scene.c\
			sources/destroy.c\
			sources/manage_event.c\
			sources/stairs.c\
			sources/render_texture.c\
			sources/particles.c\
			sources/utile_particule.c\
			sources/attack.c\
			sources/pnj.c\
			sources/pnj_load.c\
			sources/dialogs.c\
			sources/destroy_scene.c\
			sources/monsters_action.c\
			sources/monsters_colisions.c\
			sources/calcul.c\
			sources/intro.c\
			sources/pnj_management.c\
			sources/gestion.c\
			sources/move_event.c\
			sources/monsters_gestion.c\
			sources/pause.c\
			sources/quest.c\
			sources/quest_repeat.c\
			sources/bulle.c\
			sources/init_bulle.c\
			sources/potion.c\
			sources/potion_use.c\
			sources/potion_timer.c\
			sources/inv.c\
			sources/potion_bar.c\
			sources/pnj_item.c\
			sources/monsters_get.c\
			sources/init_game.c\
			sources/init_option.c\
			sources/set.c\
			sources/help.c\
			sources/win.c\
			sources/destroy_game.c\
			sources/destroy_menu.c\
			sources/init_sound.c\
			sources/slider.c\
			sources/init_main.c\

SRC_TEST	=	$(filter-out main.c,$(SRC))

TEST	=	tests/tests.c

CSFMLFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio\
-lcsfml-window -lm

CFLAGS	=	-Wall -Wextra -pedantic -I./include 

LIB =	-L ./lib/my -lmy

RULE = $(filter-out $@,$(MAKECMDGOALS))

# ------------------------------------------------------------------

OBJ = $(SRC:.c=.o)

%.o:		%.c
	@$(CC) -c -o $@ $< $(CFLAGS)
	@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< |  tr ' ' '.'

all: $(COMPILATION)

$(COMPILATION): $(OBJ)
	@make -sC lib/my
	@$(CC) $(OBJ) -o $(COMPILATION) $(CSFMLFLAGS) $(LIB)
	@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(OBJ) | tr ' ' '.'
	@printf "[\033[1;93mBinary \033[1;32mcreated\033[0m] % 23s\n" \
$(COMPILATION) | tr ' ' '.'

clean:
	@$(RM) -f *~ *.gcno *.gcda *.gcda *.swn *.swo *.c.swp
	@$(RM) -f 'a.out'
	@$(RM) -f vgcore*
	@$(RM) -f 'unit_tests'
	@$(RM) -f lib/my/*.o
	@$(RM) -f lib/my/*.a
	@$(RM) -f lib/*.a
ifneq (,$(wildcard ./$(OBJ)))
	@$(RM) -f $(OBJ)
	@printf "[\033[1;31mDeleted\033[0m] % 32s\n" $(OBJ) | tr ' ' '.'
else
	@printf "[\033[1;36mOBJ \033[1;32malready deleted\033[0m]\n"
endif

fclean : clean
ifneq (,$(wildcard ./$(COMPILATION)))
	@rm -f $(COMPILATION)
	@printf "[\033[1;93mBinary \033[1;31mdeleted\033[0m] % 25s\n" \
$(COMPILATION) | tr ' ' '.'
else
	@printf "[\033[1;93mBinary \033[1;32malready deleted\033[0m]\n"
endif

re: fclean all

debug: CFLAGS += -g3
debug: RULE = re
debug:	re

noice: RULE = re
noice: re
	$(MAKE) clean

tests_run:	fclean
	gcc -o unit_tests $(SRC_TEST) $(TEST) --coverage -lcriterion $(CFLAGS)
	./unit_tests
gcovr:
	gcovr --exclude tests --branch
