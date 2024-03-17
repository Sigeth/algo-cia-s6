#ifndef ALGO_CIA_S6_GFXMENU_H
#define ALGO_CIA_S6_GFXMENU_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "gfxutilitaire.h"
#include "sauvegarde.h"
#include "types.h"
#include "GFXLIB/GfxLib.h"
#include "GFXLIB/BmpLib.h"
#include "GFXLIB/ESLib.h"

typedef enum DISPLAYSTATE {
    MAIN_MENU,
    CHAINAGE_AVANT,
    CHAINAGE_ARRIERE
} DisplayState;

void gestionEvenement(EvenementGfx evenement);
void Buttons();
void miniMenu();


#endif //ALGO_CIA_S6_GFXMENU_H
