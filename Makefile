##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile for bistro-matic
##

SRC		=		src/*.c \
				src/free/*.c	\
				src/init/*.c	\
				src/scene/*.c	\
				src/btn/*.c \
				src/animator/*.c \
				src/generator/*.c \

SRCT 	=		./tests/

NAME	=		my_rpg

FLAGS	=		-L./lib/my -lmy -I./include/ -l m -L./lib/menu -lmenu

CSFLAGS = 		-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
#-fno-diagnostics-show-labels -fno-diagnostics-show-labels fdiagnostics-generate-patch -Wall -Wextra
#fsyntaxe-only
TFLAG 	= 		-lcriterion --coverage -fprofile-arcs

COV 	=		--exclude tests/ -o coverage.html



all:
	make -C ./lib/my build
	make -C ./lib/menu build
	gcc -o $(NAME) $(SRC) $(FLAGS) $(CSFLAGS)

allO4:
	make -C ./lib/my buildO4
	make -C ./lib/menu buildO4
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
	make -C ./lib/menu clean
	rm -f *.html
	rm -f *.gcno
	rm -f *.gcda

fclean:	clean
	#rm -f $(NAME)
	make -C ./lib/my fclean
	make -C ./lib/menu fclean
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.html
	rm -f vgcore.*
	rm -f callgrind.*

re: fclean all

tests_run: fclean
	make -C ./lib/my re
	make -C ./lib/menu re
	gcc -o $(NAME) $(SRC) $(SRCT) $(TFLAG) $(FLAGS) $(CSFLAGS)
	-./$(NAME)
	gcovr --exclude tests/
	gcovr --html $(COV) --html-title $(NAME) --html-details
	rm -f *.gcno
	rm -f *.gcda

valgrind: fclean
	clear
	make -C ./lib/my valgrind
	make -C ./lib/menu valgrind
	gcc -g -o $(NAME) $(SRC) $(FLAGS) $(CSFLAGS)
	valgrind -s --leak-check=full --track-origins=yes  --show-leak-kinds=definite ./$(NAME) #&> valgrind_log

callgrind: fclean
	rm -f callgrind.*
	clear
	make -C ./lib/my valgrind
	make -C ./lib/menu valgrind
	gcc -g -o $(NAME) $(SRC) $(FLAGS) $(CSFLAGS)
	-valgrind --tool=callgrind ./$(NAME) 3 #&> valgrind_log
	-kcachegrind callgrind.*

callgrindO6: fclean
	rm -f callgrind.*
	clear
	make -C ./lib/my buildO6
	make -C ./lib/menu buildO4
	gcc -g -o $(NAME) $(SRC) $(FLAGS) $(CSFLAGS) -O6
	-valgrind --tool=callgrind ./$(NAME) 3 #&> valgrind_log
	-kcachegrind callgrind.*
