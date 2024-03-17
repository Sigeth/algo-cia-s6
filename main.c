#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "chainage.h"
#include "sauvegarde.h"
#include "menu.h"
//GFX
/*#include "gfxmenu.h"
// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 800
#define HauteurFenetre 600

int main(int argc, char **argv) {
    initialiseGfx(argc, argv);

    prepareFenetreGraphique("CIA_Expert_System", LargeurFenetre, HauteurFenetre);

    lanceBoucleEvenements();
    return 0;
}*/

int main() {
    RULES *listRules = NULL;
    menu(listRules);
    return 0;
}
