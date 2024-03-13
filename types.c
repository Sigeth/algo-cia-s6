#include "types.h"

               // CONDITIONS //
               // init memory leakproof normalement
int init_Conditions(CONDITIONS ** C, int conditions_size){
   *C = (CONDITIONS *)malloc(sizeof(CONDITIONS));
   if(*C == NULL){
       printf("Erreur d'allocation du noeud de conditions\n");
       return 0;
   }else {
       (*C)->conditions = malloc((conditions_size + 1) * sizeof(char));
       if ((*C)->conditions == NULL) {
           printf("Erreur d'allocation des conditions\n");
           free((*C)->conditions);
           free(*C);
           return 0;
       }
       (*C)->suiv = NULL;
       return 1;
   }
}

int isConditionEmpty(CONDITIONS * C){
    return (C == NULL || !strlen(C->conditions));
}

int isValinCondition(CONDITIONS **TC, char * val){
    if(*TC==NULL){
        printf("Pas de valeur");
        return 0;
    }
    if(strcmp((*TC)->conditions, val)){
        return 1;
    }
    isValinCondition(&(*TC)->suiv,val);
}

int ins_Condition(CONDITIONS **TC, CONDITIONS *C){
    if (C == NULL){
        printf("rien a ajouter\n");
        return 0;}
    if (*TC == NULL || strcmp((*TC)->conditions, C->conditions) >= 0) {
        C->suiv = *TC;
        *TC = C;
        return 1;
    }
    return ins_Condition(&((*TC)->suiv), C);
}

int free_ListeConditions(CONDITIONS * TC) {
    if (TC == NULL) {
        printf("Rien a libéré\n");
        return 0;
    }
    free_ListeConditions(TC->suiv);
    free(TC->conditions);
    free(TC);
    return 1;
}

void affiche_Condition(CONDITIONS * C) {
    if (C == NULL) {
        printf("Les conditions sont vides\n");
        return;
    }
    printf("Condition(s): %s\n", C->conditions);
}

int affiche_ListeConditions(CONDITIONS * TC) {
    int count = 0;
    if (TC == NULL) {
        printf("La liste de nodes de conditions est vide");
        return 0;
    }
    affiche_Condition(TC);
    count++;
    count += affiche_ListeConditions(TC->suiv);
    return count;
}

                // RULES //

int init_Rule(RULES ** R, int conclusion_size){
    *R = (RULES *)malloc(sizeof(RULES));
    if(*R == NULL){
        printf("Erreur d'allocation de la node de règle\n");
        return 0;
    }else {
        (*R)->conclusion = malloc((conclusion_size + 1) * sizeof(char));
        if ((*R)->conclusion == NULL) {
            printf("Erreur d'allocation de la conclusion\n");
            free((*R)->conclusion);
            free(*R);
            return 0;
        }
        (*R)->suiv = NULL;
        return 1;
    }
}

int isRuleEmpty(RULES * R) {
    return (R == NULL || !strlen(R->conclusion));
}

int isValinRules(RULES **TR, char * val){
    if(*TR==NULL){
        printf("Pas de valeur");
        return 0;
    }
    if(strcmp((*TR)->conclusion, val)){
        return 1;
    }
    isValinRules(&(*TR)->suiv,val);
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

int ins_ConditionToRule(RULES *R,CONDITIONS *teteC){
    if (R == NULL) {
        printf("Rien à ajouter\n");
        return 0;
    }
    R->ptete_conditions = teteC;
    return 1;
}

int ins_ConditionsToRules(RULES ** TR ,RULES *R,CONDITIONS *teteC){
    if (R == NULL) {
        printf("Rien à ajouter\n");
        return 0;
    }
    if (*TR == R) {
        return ins_ConditionToRule((*TR),teteC);
    }
    if ((*TR)->suiv == NULL) {
        printf("La règle spécifiée n'a pas été trouvée dans la liste de règles\n");
        return 0;
    }
    return ins_ConditionsToRules(&((*TR)->suiv), R, teteC);
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

int affiche_ListRules(RULES * TR){
    int count = 0;
    if (TR == NULL) {
        printf("La liste de node de règle est vide");
        return 0;
    }
        affiche_Rule(TR);
        count++;
        count += affiche_ListRules(TR->suiv);
    return count;
}

                        // FAITS //

int init_Fait(FAITS ** F, int faits_size){
    *F = (FAITS *)malloc(sizeof(FAITS));
    if(*F == NULL){
        printf("Erreur d'allocation de la node de faits\n");;
        return 0;
    }else {
        (*F)->faits = malloc((faits_size + 1) * sizeof(char));
        if ((*F)->faits == NULL) {
            printf("Erreur d'allocation des faits\n");
            free((*F)->faits);
            free(*F);
            return 0;
        }
        (*F)->suiv = NULL;
        return 1;
    }
}

int isFaitEmpty(FAITS * F) {
    return (F == NULL || !strlen(F->faits));
}
int isValinFaits(FAITS **TF, char * val){
    if(*TF==NULL){
        printf("Pas de valeur");
        return 0;
    }
    if(strcmp((*TF)->faits, val)){
        return 1;
    }
    isValinFaits(&(*TF)->suiv,val);
}

int ins_Fait(FAITS ** TF,FAITS * F){
    if (F == NULL){
        printf("rien a ajouter\n");
        return 0;}
    if (*TF == NULL || strcmp((*TF)->faits, F->faits) >= 0) {
        F->suiv = *TF;
        *TF = F;
        return 1;
    }
    return ins_Fait(&((*TF)->suiv), F);
}

int free_ListeFaits(FAITS *TF){
    if (TF == NULL) {
        printf("Rien a libéré\n");
        return 0;
    }
    free_ListeFaits(TF->suiv);
    free(TF->faits);
    free(TF);
    return 1;
}

void affiche_Fait(FAITS * F){
    if (F == NULL) {
        printf("Le fait est vide\n");
        return;
    }
    printf("Fait(s): %s\n", F->faits);
}

int affiche_ListFaits(FAITS *TF){
    int count = 0;
    if (TF == NULL) {
        printf("La liste de node de règle est vide");
        return 0;
    }
    affiche_Fait(TF);
    count++;
    count += affiche_ListFaits(TF->suiv);
    return count;
}
