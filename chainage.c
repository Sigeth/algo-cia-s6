
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#include "chainage.h"
#include "types.h"




//PARTIE CHAINAGE AVANT


//fonction pour ajouter, si vous en avez deja une mettez la a la place je vous en prie


FAITS* ajouter_fait(FAITS *base_de_faits, char *fait) {
    printf("%s ajouté aux faits établis\n", fait);
    FAITS *new_fait = malloc(sizeof(FAITS));
    new_fait->faits = strdup(fait);
    new_fait->suiv = NULL;

    if (base_de_faits == NULL) {
        base_de_faits = new_fait;
    }
    else {
        FAITS *current = base_de_faits;
        while (current->suiv != NULL) {
            current = current->suiv;
        }
        current->suiv = new_fait;
    }
    affiche_liste_faits(base_de_faits);
    return base_de_faits;
}


//fonction pour verifier si la regle est bien entiere, genre si 
// les conditions sont toutes réunies dans la base de faits

bool regle_applicable(RULES *regle, FAITS *base_de_faits) {

    CONDITIONS *condition = regle->ptete_conditions;

    //comme je l'ai dit ça check si conditions == faits

    while (condition != NULL) {
        bool trouve = false;
        FAITS *fait = base_de_faits;
        while (fait != NULL) {
            if (strcmp(fait->faits, condition->conditions) == 0) {
                trouve = true;
                break;
            }
            fait = fait->suiv;
        }
        if (!trouve) {
            return false;
        }
        condition = condition->suiv;
    }

    // ici on vérifie si la conclusion est deja dans les faits, pour eviter les boucles infinies
    //si on a deja dans les faits "a b c", et que a b -> c, on va pas rajouter un autre c dans les faits

    FAITS *fait = base_de_faits;
    while (fait != NULL) {
        if (strcmp(fait->faits, regle->conclusion) == 0) {
            return false;
        }
        fait = fait->suiv;
    }
    return true;
}


//fonction principale chainage avant


FAITS* chainage_avant(RULES *base_de_regles, FAITS *base_de_faits) {
    bool regle_appliquee = true;
    while (regle_appliquee) {
        regle_appliquee = false;
        RULES *regle = base_de_regles;
        while (regle != NULL) {
            if (regle_applicable(regle, base_de_faits)) {

                base_de_faits= ajouter_fait(base_de_faits, regle->conclusion);

                regle_appliquee = true;
            }
            regle = regle->suiv;
        }
    }
    return base_de_faits;
}





//PARTIE CHAINAGE ARRIERE




//pour vérifier si la conclusion est la meme que le but
//si true on continue les verifs avec chacune des hypotheses   (POUR LE CHAINAGE ARRIERE)

bool conclusion_est(RULES *regle, char *but) {
    return strcmp(regle->conclusion, but) == 0;
}


//fonction chainage arriere
bool chainage_arriere(char *but, RULES *base_de_regles, FAITS *base_de_faits) {
    // si le but est direct dans les faits on s'embete pas et on return direct true
    for (FAITS *parcours_fait = base_de_faits; parcours_fait != NULL; parcours_fait = parcours_fait->suiv) {
        if (strcmp(parcours_fait->faits, but) == 0) {
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



