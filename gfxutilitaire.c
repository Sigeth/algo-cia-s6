#include "gfxutilitaire.h"

FAITS* gfxask_symptoms(RULES* base_de_regles, FAITS* base_de_faits, char *symptoms) {
    char *symptom = strtok(symptoms, " ");
    while (symptom != NULL) {
        FAITS* fait = base_de_faits;
        int found_in_faits = 0;
        while (fait != NULL) {
            if (strstr(fait->faits, symptom) != NULL) {
                printf("Symptome %s est deja dans la base_de_faits\n", symptom);
                found_in_faits = 1;
                break;
            }
            fait = fait->suiv;
        }
        if (found_in_faits) {
            symptom = strtok(NULL, " ");
            continue;
        }
        RULES* regle = base_de_regles;
        int found_in_regles = 0;
        while (regle != NULL && !found_in_regles) {
            CONDITIONS* condition = regle->ptete_conditions;
            while (condition != NULL) {
                if (strstr(condition->conditions, symptom) != NULL) {
                    base_de_faits = ajouter_fait(base_de_faits, symptom);
                    printf("Ajout %s a la base_de_faits\n", symptom);
                    found_in_regles = 1;
                    break;
                }
                condition = condition->suiv;
            }
            regle = regle->suiv;
        }
        if (!found_in_regles) {
            printf("Symptome pas dans la base_de_regles\n");
        }
        symptom = strtok(NULL, " ");
    }
    return base_de_faits;
}
