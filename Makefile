main: main.o chainage.o sauvegarde.o menu.o types.o
	gcc -Wall main.o -o main chainage.o sauvegarde.o menu.o types.o

main.o: main.c
	gcc -Wall -c main.c

chainage.o: chainage.c
	gcc -Wall -c chainage.c chainage.h

sauvegarde.o: sauvegarde.c
	gcc -Wall -c sauvegarde.c sauvegarde.h

menu.o: menu.c
	gcc -Wall -c menu.c menu.h

types.o: types.c
	gcc -Wall -c types.c types.h

clear:
	rm *.o