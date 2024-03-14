#ifndef ALGO_CIA_S6_CHAINAGE_H
#define ALGO_CIA_S6_CHAINAGE_H

#include <stdbool.h>

typedef struct faits {
    char *fait;
    struct faits *suiv;
} FAITS;

typedef struct conditions {
    char *condition;
    struct conditions *suiv;
} CONDITIONS;

typedef struct rules {
    char *conclusion;
    CONDITIONS *ptete_conditions;
    struct rules *suiv;
} RULES;






// Prototypes des fonctions CHAINAGE AVANT
void chainage_avant(RULES *base_de_regles, FAITS *base_de_faits);
bool regle_applicable(RULES *regle, FAITS *base_de_faits);
void ajouter_fait(FAITS *base_de_faits, char *fait);




//Prototypes des fonctions CHAINAGE ARRIERE

bool conclusion_est(RULES *regle, char *but);
bool chainage_arriere(char *but, RULES *base_de_regles, FAITS *base_de_faits);




#endif
