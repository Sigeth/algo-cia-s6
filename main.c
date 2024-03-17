#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "gfxmenu.h"

#define LargeurFenetre 800
#define HauteurFenetre 600

int main(int argc, char **argv) {
    int choix=0;
    RULES *listRules = NULL;
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
