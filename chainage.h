#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "chainage.h"





//pour vérifier si la conclusion est la meme que le but
//si true on continue les verifs avec chacune des hypotheses   (POUR LE CHAINAGE ARRIERE)

bool conclusion_est(RULES *regle, char *but) {
    return strcmp(regle->conclusion, but) == 0;
}


//fonction chainage arriere
bool chainage_arriere(char *but, RULES *base_de_regles, FAITS *base_de_faits) {
    // si le but est direct dans les faits on s'embete pas et on return direct true
    for (FAITS *fait = base_de_faits; fait != NULL; fait = fait->suiv) {
        if (strcmp(fait->faits, but) == 0) {
            return true;
        }
    }
    
    // sinon on recherche dans les règles
    RULES *regle = base_de_regles;
    while (regle != NULL) {
        if (conclusion_est(regle, but)) {
            CONDITIONS *hypothese = regle->ptete_conditions;
            bool continuee = true;
            while (hypothese != NULL && continuee) {
                // On a repéré notre conclusion, du coup il faut check si toute les hypothèses associées
                // sont vérifiées a leur tour, pour ça qu'on utilise la recursivité ici
                continuee = chainage_arriere(hypothese->conditions, base_de_regles, base_de_faits);
                hypothese = hypothese->suiv;
            }
            if (continuee) {
                return true;
            }
        }
        regle = regle->suiv;
    }
    
    return false;
}

