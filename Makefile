main: main.o chainage.o sauvegarde.o gfxmenu.o menu.o types.o GFXLIB/libisentlib.a
	gcc -Wall main.o -o main chainage.o sauvegarde.o gfxmenu.o menu.o types.o GFXLIB/libisentlib.a -lm -lglut -lGL -lX11

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

gfxmenu.o : gfxmenu.c gfxmenu.h GFXLIB/GfxLib.h GFXLIB/BmpLib.h GFXLIB/ESLib.h
	gcc -Wall -c gfxmenu.c

clear:
	rm *.o