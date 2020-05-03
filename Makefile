##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile for rpg
##

SRC		=		src/check.c \
				src/core.c	\
				src/gui.c	\
				src/main.c	\
				src/managers.c	\
				src/player.c	\
				src/animator/animator.c \
				src/animator/init_player_animator.c \
				src/animator/init_pnj_animator.c \
				src/animator/init_skeleton_animator.c \
				src/animator/init_zombie_animator.c \
				src/animator/animator_init.c \
				src/btn/btn_skin.c \
				src/btn/first_skills.c \
				src/btn/goto_dialog.c \
				src/btn/goto.c \
				src/btn/main_funcs.c \
				src/btn/quests.c \
				src/btn/quit_menus.c \
				src/btn/second_skills.c \
				src/engine/arow.c \
				src/engine/engine.c \
				src/engine/entities.c \
				src/engine/items.c \
				src/engine/player.c \
				src/fight/bow.c \
				src/fight/fight.c \
				src/fight/sword.c \
				src/free/free_first.c	\
				src/free/free_second.c	\
				src/generator/breaking.c \
				src/generator/generator.c \
				src/generator/load.c \
				src/generator/map.c \
				src/generator/perlin.c \
				src/generator/save.c \
				src/init/init_buttons.c	\
				src/init/init_utils.c	\
				src/inventory/events.c \
				src/inventory/init_free.c \
				src/inventory/other.c \
				src/inventory/utils.c \
				src/menu/add.c \
				src/menu/buttons.c \
				src/menu/events.c \
				src/menu/init.c \
				src/mob/draw_entity.c \
				src/mob/pnj.c \
				src/mob/spawn.c \
				src/mob/zombie.c \
				src/particle/particle.c \
				src/quests/quests_one.c \
				src/quests/quests_two.c \
				src/scene/dialog.c	\
				src/scene/game.c	\
				src/scene/home.c	\
				src/scene/hud.c	\
				src/scene/inventory.c	\
				src/scene/man.c	\
				src/scene/param.c	\
				src/scene/quest.c	\
				src/scene/skills.c	\
				src/world/cam/calc.c \
				src/world/cam/cam.c \
				src/world/cam/draw.c \
				src/world/cam/init.c \
				src/world/mesh/mesh.c \
				src/world/mesh/meshs.c \
				src/world/main.c

SRCT 	=		./tests/

NAME	=		my_rpg

FLAGS	=		-L./lib/my -lmy -I./include/ -I./src/ -l m

CSFLAGS = 		-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
#-fno-diagnostics-show-labels -fno-diagnostics-show-labels fdiagnostics-generate-patch -Wall -Wextra
#fsyntaxe-only
TFLAG 	= 		-lcriterion --coverage -fprofile-arcs

COV 	=		--exclude tests/ -o coverage.html



all:
	make -C ./lib/my build
	gcc -o $(NAME) $(SRC) $(FLAGS) $(CSFLAGS)

allO4:
	make -C ./lib/my buildO4
	gcc -o $(NAME) $(SRC) $(FLAGS) $(CSFLAGS) -Ofast

run: all
	make fclean
	./$(NAME)

runO4: allO4
	make fclean
	./$(NAME)

clean:
	rm -f $(OBJ)
	make -C ./lib/my clean
	rm -f *.html
	rm -f *.gcno
	rm -f *.gcda

fclean:	clean
	#rm -f $(NAME)
	make -C ./lib/my fclean
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.html
	rm -f vgcore.*
	rm -f callgrind.*

re: fclean all

tests_run: fclean
	make -C ./lib/my re
	gcc -o $(NAME) $(SRC) $(SRCT) $(TFLAG) $(FLAGS) $(CSFLAGS)
	-./$(NAME)
	gcovr --exclude tests/
	gcovr --html $(COV) --html-title $(NAME) --html-details
	rm -f *.gcno
	rm -f *.gcda

valgrind: fclean
	clear
	make -C ./lib/my valgrind
	gcc -g -o $(NAME) $(SRC) $(FLAGS) $(CSFLAGS)
	valgrind -s --leak-check=full --track-origins=yes --show-leak-kinds=definite ./$(NAME) #&> valgrind_log

callgrind: fclean
	rm -f callgrind.*
	clear
	make -C ./lib/my valgrind
	gcc -g -o $(NAME) $(SRC) $(FLAGS) $(CSFLAGS)
	-valgrind --tool=callgrind ./$(NAME) 3 #&> valgrind_log
	-kcachegrind callgrind.*

callgrindO6: fclean
	rm -f callgrind.*
	clear
	make -C ./lib/my buildO6
	gcc -g -o $(NAME) $(SRC) $(FLAGS) $(CSFLAGS) -O6
	-valgrind --tool=callgrind ./$(NAME) 3 &> valgrind_log
	-kcachegrind callgrind.*
