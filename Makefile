##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile for rpg
##

SRC		=		src/*.c \
				src/free/*.c	\
				src/init/*.c	\
				src/scene/*.c	\
				src/btn/*.c \
				src/animator/*.c \
				src/generator/*.c \
				src/menu/*.c \
				src/engine/*.c \
				src/inventory/*.c \
				src/mob/*.c \
				src/world/*.c \
				src/world/cam/*.c \
				src/world/mesh/*.c \

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
	-valgrind --tool=callgrind ./$(NAME) 3 #&> valgrind_log
	-kcachegrind callgrind.*
