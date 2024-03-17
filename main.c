#include <stdio.h>
#include "gfxmenu.h"

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 800
#define HauteurFenetre 600

int main(int argc, char **argv) {
    initialiseGfx(argc, argv);

    prepareFenetreGraphique("CIA_Expert_System", LargeurFenetre, HauteurFenetre);

    lanceBoucleEvenements();

    return 0;
}
