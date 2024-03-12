#ifndef ALGO_CIA_S6_CHAINAGE_H
#define ALGO_CIA_S6_CHAINAGE_H

// Structure pour les conditions VA AVEC RULES
typedef struct conditions {
    char **conditions;
    struct conditions *suiv;
} CONDITIONS;

// Structure pour les faits INDEPENDANTS DE RULES
typedef struct faits {
    char **faits;
    struct faits *suiv;
} FAITS;

// Structure pour les regles QUI INTEGRE CONDITIONS
typedef struct rules {
    char *conclusion;
    CONDITIONS *ptete_conditions;
    struct rules *suiv;
} RULES;



bool conclusion_est(RULES *regle, char *but);


bool chainage_arriere(char *but, RULES *base_de_regles, FAITS *base_de_faits);


#endif
