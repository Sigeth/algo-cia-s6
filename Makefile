main: main.o chainage.o sauvegarde.o gfxmenu.o menu.o types.o gfxutilitaire.o libisentlib.a
	gcc -Wall main.o -o main chainage.o sauvegarde.o gfxmenu.o menu.o types.o gfxutilitaire.o libisentlib.a -lm -lglut -lGL -lX11

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

gfxmenu.o: gfxmenu.c gfxmenu.h
	gcc -Wall -c gfxmenu.c

gfxutilitaire.o: gfxutilitaire.c gfxutilitaire.h
	gcc -Wall -c gfxutilitaire.c

libisentlib.a: BmpLib.o ErreurLib.o ESLib.o GfxLib.o OutilsLib.o SocketLib.o ThreadLib.o TortueLib.o VectorLib.o WavLib.o
	ar r libisentlib.a BmpLib.o ErreurLib.o ESLib.o GfxLib.o OutilsLib.o SocketLib.o ThreadLib.o TortueLib.o VectorLib.o WavLib.o
	ranlib libisentlib.a

BmpLib.o: GFXLIB/BmpLib.c GFXLIB/BmpLib.h GFXLIB/OutilsLib.h
	gcc -Wall -O2 -c GFXLIB/BmpLib.c

ESLib.o: GFXLIB/ESLib.c GFXLIB/ESLib.h GFXLIB/ErreurLib.h
	gcc -Wall -O2 -c GFXLIB/ESLib.c

ErreurLib.o: GFXLIB/ErreurLib.c GFXLIB/ErreurLib.h
	gcc -Wall -O2 -c GFXLIB/ErreurLib.c

GfxLib.o: GFXLIB/GfxLib.c GFXLIB/GfxLib.h GFXLIB/ESLib.h
	gcc -Wall -O2 -c GFXLIB/GfxLib.c -I/usr/include/GL

OutilsLib.o: GFXLIB/OutilsLib.c GFXLIB/OutilsLib.h
	gcc -Wall -O2 -c GFXLIB/OutilsLib.c

SocketLib.o: GFXLIB/SocketLib.c GFXLIB/SocketLib.h
	gcc -Wall -O2 -c GFXLIB/SocketLib.c

ThreadLib.o: GFXLIB/ThreadLib.c GFXLIB/ThreadLib.h
	gcc -Wall -O2 -c GFXLIB/ThreadLib.c

TortueLib.o: GFXLIB/TortueLib.c GFXLIB/TortueLib.h GFXLIB/GfxLib.h
	gcc -Wall -O2 -c GFXLIB/TortueLib.c

VectorLib.o: GFXLIB/VectorLib.c GFXLIB/VectorLib.h
	gcc -Wall -O2 -c GFXLIB/VectorLib.c -msse3

WavLib.o: GFXLIB/WavLib.c GFXLIB/WavLib.h GFXLIB/OutilsLib.h
	gcc -Wall -O2 -c GFXLIB/WavLib.c -Wno-unused-result

clear:
	rm -f *~ *.o