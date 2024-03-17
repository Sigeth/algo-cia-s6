#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "chainage.h"
#include "sauvegarde.h"
#include "menu.h"
//GFX
#include "gfxmenu.h"
// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 800
#define HauteurFenetre 600

int main(int argc, char **argv) {
    int choix=0;
    printf("- 1 Interface graphique.\n- 2 Terminale.\n -3 Quitter");
    scanf("%d",&choix);
    do{
        switch(choix){
            case 1:
                initialiseGfx(argc, argv);
                prepareFenetreGraphique("CIA_Expert_System", LargeurFenetre, HauteurFenetre);
                lanceBoucleEvenements();
                break;
            case 2:
                RULES *listRules = NULL;
                menu(listRules);
                break;
            case 3:
                break;
            default:
                printf("Choix invalide\n");
                break;
        }
    }while(choix !=3);
    return 0;
}