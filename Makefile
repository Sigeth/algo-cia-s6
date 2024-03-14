main: main.o chainage.o sauvegarde.o menu.o types.o
	gcc -Wall main.o -o main chainage.o sauvegarde.o menu.o types.o

main.o: main.c
	gcc -Wall -c main.c

chainage.o: chainage.c chainage.h
	gcc -Wall -c chainage.c

sauvegarde.o: sauvegarde.c sauvegarde.h
	gcc -Wall -c sauvegarde.c

menu.o: menu.c menu.h
	gcc -Wall -c menu.c

types.o: types.c types.h
	gcc -Wall -c types.c

clear:
	rm *.o