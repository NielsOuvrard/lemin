##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## un makefile de qualité spécial lem-in
##

SRC = 	src/*.c

BINARY = lem_in

LIB = -I./include/ -L./lib/my/ -lm -lmy

all:
		@cp ./lib/my/my.h include/my.h
		@gcc -c lib/my/*.c
		@ar rc lib/my/libmy.a *.o
		@cp ./lib/my/libmy.a lib/libmy.a
		@gcc -o $(BINARY) -g $(SRC) $(LIB) -g3
		@chmod 777 $(BINARY)
		@make clean

clean:
		rm -f *.o
		rm -f *.gcno
		rm -f *.gcda
		rm -f tests_bin

fclean: clean
		rm lib/my/libmy.a
		rm lib/libmy.a
		rm $(BINARY)

re:	fclean all

auteur:
		@echo $(USER) is the best

push:
		@git add .
		@git status
		@git commit -m "push automatique"
		@git push

mac_del:
		rm -Rf *.dSYM
		rm -Rf .vscode
		rm -f .DS_Store
		rm -f src/.DS_Store

vg_del:
		rm vgcore.*

fm_push:
		make fclean
		make mac_del
		make push

tests_run:
		cp ./lib/my/my.h include/my.h
		gcc -c lib/my/*.c
		ar rc lib/my/libmy.a *.o
		cp ./lib/my/libmy.a lib/libmy.a
		gcc -o tests_bin -g tests/*.c $(SRC) $(LIB) -g3 -lcriterion --coverage
		chmod 777 tests_bin
		./tests_bin < input
		make clean

.PHONY: all clean fclean re push mac_del vg_del fm_push tests_run
