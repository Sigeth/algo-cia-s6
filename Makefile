main: main.o chainage.o sauvegarde.o gfxmenu.o menu.o types.o GFXLIB/libisentlib.a
	gcc -Wall main.o -o main chainage.o sauvegarde.o gfxmenu.o menu.o types.o GFXLIB/libisentlib.a -lm -lglut -lGL -lX11

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

gfxmenu.o : gfxmenu.c GFXLIB/GfxLib.h GFXLIB/BmpLib.h GFXLIB/ESLib.h
	gcc -Wall -c gfxmenu.c gfxmenu.h

clear:
	rm *.o