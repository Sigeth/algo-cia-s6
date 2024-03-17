#ifndef ALGO_CIA_S6_CHAINAGE_H
#define ALGO_CIA_S6_CHAINAGE_H

#include <stdbool.h>
#include "types.h"




// Prototypes des fonctions CHAINAGE AVANT
FAITS* chainage_avant(RULES *base_de_regles, FAITS *base_de_faits);
bool regle_applicable(RULES *regle, FAITS *base_de_faits);
void ajouter_fait_chainage(FAITS *base_de_faits, char *fait);




//Prototypes des fonctions CHAINAGE ARRIERE

bool conclusion_est(RULES *regle, char *but);
bool chainage_arriere(char *but, RULES *base_de_regles, FAITS *base_de_faits);



#endif
