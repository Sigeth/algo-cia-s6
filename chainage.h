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



// Fonction pour vérifier si une règle a la conclusion donnée
bool conclusion_est(RULES *regle, char *but);

// Fonction récursive pour le chaînage arrière
bool chainage_arriere(char *But, RULES *Base_de_regles, FAITS *Base_de_faits);


#endif
