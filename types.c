#include "types.h"

               // CONDITIONS //
               // init memory leakproof
int init_Conditions(CONDITIONS ** C, int conditions_size){
   *C = (CONDITIONS *)malloc(sizeof(CONDITIONS));
   if (*C == NULL) {
       printf("Erreur d'allocation de la condition\n");
       return 0;
   } else {
       (*C)->conditions = malloc(conditions_size * sizeof(char *));
       if ((*C)->conditions == NULL) {
           printf("Erreur d'allocation des conditions\n");
           free(*C);
           return 0;
       }
       (*C)->suiv = NULL;
       return 1;
   }
}

int isConditionEmpty(CONDITIONS * C){
    return (C == NULL || C->conditions == NULL);
}

int ins_Condition(CONDITIONS **TC, CONDITIONS *C){
    if(C==NULL) {
        printf("rien a ajouter\n");
        return 0;
    }
    C->suiv=*TC;
    *TC=C;
    return 1;
}

int free_ListeConditions(CONDITIONS * TC) {
    if (TC == NULL) {
        printf("La liste de conditions est vide\n");
        return 0;
    }
    free_ListeConditions(TC->suiv);
    free(TC);
    return 1;
}

void affiche_Condition(CONDITIONS * C) {
    if (C == NULL) {
        printf("Condition vide\n");
        return;
    }
    for (int i = 0; C->conditions[i] != NULL; i++) {
        printf("%s ", C->conditions[i]);
    }
    printf("\n");
}

int affiche_ListeConditions(CONDITIONS * TC) {
    int count = 0;
    if (TC != NULL) {
        affiche_ListeConditions(TC);
        count++;
        count += affiche_ListeConditions(TC->suiv);
    }
    return count;
}

                // RULES //

int init_Rule(RULES ** R, int conclusion_size){
    *R = (RULES *)malloc(sizeof(RULES));
    if(*R == NULL){
        printf("Erreur d'allocation de la règle\n");
        free(R);
        return 0;
    }else {
        (*R)->conclusion = malloc((conclusion_size + 1) * sizeof(char));
        if ((*R)->conclusion == NULL) {
            printf("Erreur d'allocation de la conclusion\n");
            free((*R)->conclusion);
            free(R);
            return 0;
        }
        (*R)->suiv = NULL;
        return 1;
    }
}

int isRuleEmpty(RULES * R) {
    return (R == NULL || !strlen(R->conclusion));
}

int ins_Rule(RULES ** TR,RULES * R){
    if (R == NULL){
        printf("rien a ajouter\n");
        return 0;}
    if (*TR == NULL || strcmp((*TR)->conclusion, R->conclusion) >= 0) {
        R->suiv = *TR;
        *TR = R;
        return 1;
    }
    return ins_Rule(&((*TR)->suiv), R);
}

int free_RuleList(RULES *TR){
    if (TR == NULL) {
        printf("Rien a libéré\n");
        return 0;
    }
    free_RuleList(TR->suiv);
    free(TR->conclusion);
    free_ListeConditions(TR->ptete_conditions);
    free(TR);
    return 1;
}

void affiche_Rule(RULES * R){
    if (R == NULL) {
        printf("La règle est vide\n");
        return;
    }
    printf("Conclusion: %s\n", R->conclusion);
    printf("Conditions:\n");
    affiche_ListeConditions(R->ptete_conditions);
}

int affiche_RuleList(RULES * TR){
    int count = 0;
    if (TR == NULL) {
        printf("RuleList vide");
        return 0;
    }
        affiche_Rule(TR);
        count++;
        count += affiche_RuleList(TR->suiv);
    return count;
}

                        // FAITS //

int init_Fait(FAITS ** F, int faits_size){
    *F = (FAITS *)malloc(sizeof(FAITS ));
    if (*F == NULL) {
        printf("Erreur d'allocation de la condition\n");
        return 0;
    } else {
        (*F)->faits = malloc(faits_size * sizeof(char *));
        if ((*F)->faits == NULL) {
            printf("Erreur d'allocation des conditions\n");
            free(*F);
            return 0;
        }
        (*F)->suiv = NULL;
        return 1;
    }
}

int isFaitEmpty(FAITS * F){
    return (F == NULL || F->faits == NULL);
}

int ins_Fait(FAITS ** TF,FAITS * F){
    if(F==NULL) {
        printf("rien a ajouter\n");
        return 0;
    }
    F->suiv=*TF;
    *TF=F;
    return 1;
}

int free_FaitList(FAITS *TF){
    if (TF == NULL) {
        printf("La liste de conditions est vide\n");
        return 0; // Rien à libérer, considéré comme un succès
    }
    for (int i = 0; TF->faits[i] != NULL; i++) {
        free(TF->faits[i]);
    }
    free_ListeConditions(TF->suiv);
    free(TF);
    return 1;
}// Retourne 1 ou 0

void affiche_Fait(FAITS * F){
    if (F == NULL) {
        printf("Fait vide\n");
        return;
    }
    for (int i = 0; F->faits[i] != NULL; i++) {
        printf("%s ", F->faits[i]);
    }
    printf("\n");
}

int affiche_FaitList(FAITS * TF){
    int count = 0;
    if (TF != NULL) {
        affiche_ListeConditions(TF);
        count++;
        count += affiche_ListeConditions(TF->suiv);
    }
    return count;
}
