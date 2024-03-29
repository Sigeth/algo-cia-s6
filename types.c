#include "types.h"
#include "chainage.h"

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
        strcpy((*C)->conditions, "Condition initial");
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
    return isValinCondition(&(*TC)->suiv,val);
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
        return 0;
    }
    if (TC->suiv != NULL) {
        free_ListeConditions(TC->suiv);
    }
    free(TC->conditions);
    free(TC);
    return 1;
}

void affiche_Condition(CONDITIONS * C) {
    if (C == NULL) {
        return;
    }
    printf("%s\n \n", C->conditions);
}

int affiche_ListeConditions(CONDITIONS * TC) {
    int count = 0;
    if (TC == NULL) {
        return 0;
    }
    printf("Conditions :\n");
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
        strcpy((*R)->conclusion, "Conclusion initial");
        (*R)->ptete_conditions=NULL;
        (*R)->suiv = NULL;
        return 1;
    }
}

int isRuleEmpty(RULES * R) {
    return (R == NULL || !strlen(R->conclusion));
}

int isValinRules(RULES **TR, char * val){
    if(*TR==NULL){
        return 0;
    }
    if(strcmp((*TR)->conclusion, val) ==0){
        return 1;
    }
    return isValinRules(&(*TR)->suiv,val);
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

RULES * ajouter_rule(RULES *base_de_regles, char *conclusion,char  *conditions) {
    //printf("%s ajouté aux faits établis\n", fait);
    RULES *new_rules = malloc(sizeof(RULES));
    strcpy(new_rules->conclusion,conclusion);
    CONDITIONS *new_conditions = malloc(sizeof(CONDITIONS));
    new_conditions->conditions=conditions;
    new_conditions->suiv=NULL;
    ins_Condition(&new_rules->ptete_conditions,new_conditions);
    new_rules->suiv = NULL;

    if (base_de_regles == NULL) {
        base_de_regles = new_rules;
    }
    else {
        RULES *current = base_de_regles;
        while (current->suiv != NULL) {
            current = current->suiv;
        }
        current->suiv = new_rules;
    }
    //affiche_liste_faits(base_de_faits);
    return base_de_regles;
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
        return 0;
    }
    if (TR->suiv != NULL) {
        free_RuleList(TR->suiv);
    }
    if (TR->conclusion != NULL) {
        free(TR->conclusion);
    }
    if (TR->ptete_conditions != NULL) {
        free_ListeConditions(TR->ptete_conditions);
    }
    free(TR);
    return 1;
}

void affiche_Rule(RULES * R){
    if (R == NULL) {
        return;
    }
    printf("Conclusion: %s\n", R->conclusion);
    affiche_ListeConditions(R->ptete_conditions);
}

int affiche_ListRules(RULES * TR){
    int count = 0;
    if (TR == NULL) {
        return 0;
    }
    printf("Regles :\n \n");
    affiche_Rule(TR);
    count++;
    count += affiche_ListRules(TR->suiv);
    return count;
}

// FAITS //

int init_Fait(FAITS ** F, int faits_size){
    *F = (FAITS *)malloc(sizeof(FAITS));
    if(*F == NULL){
        printf("Erreur d'allocation du noeud de faits\n");
        return 0;
    }else {
        (*F)->faits = malloc((faits_size + 1) * sizeof(char));
        if ((*F)->faits == NULL) {
            printf("Erreur d'allocation des fait\n");
            free((*F)->faits);
            free(*F);
            return 0;
        }
        strcpy((*F)->faits, "Fait initial");
        (*F)->suiv = NULL;
        return 1;
    }
}

int isFaitEmpty(FAITS * F) {
    return (F == NULL || !strlen(F->faits));
}
bool check_if_conclusion_in_faits(FAITS *base_de_faits, char *conclusion) {
    FAITS *fait = base_de_faits;
    while (fait != NULL) {
        if (strcmp(fait->faits, conclusion) == 0) {
            return true;
        }
        fait = fait->suiv;
    }
    return false;
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

int free_ListeFaits(FAITS *TF) {
    if (TF == NULL) {
        return 0;
    }
    if (TF->suiv != NULL) {
        free_ListeFaits(TF->suiv);
    }
    free(TF->faits);
    free(TF);
    return 1;
}


int affiche_liste_faits(FAITS *base_de_faits) {
    int count = 0;
    while (base_de_faits != NULL) {
        printf("%s\n", base_de_faits->faits);
        base_de_faits = base_de_faits->suiv;
        count++;
    }
    return count;
}



FAITS* ajouter_fait(FAITS *base_de_faits, char *fait) {
    //printf("%s ajouté aux faits établis\n", fait);
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
    //affiche_liste_faits(base_de_faits);
    return base_de_faits;
}





FAITS* ask_symptoms(RULES* base_de_regles, FAITS* base_de_faits) {
    char symptom[100];
    printf("Entrer vos symptomes (appuyer sur 'q' pour quitter):\n");
    while (1) {
        fgets(symptom, sizeof(symptom), stdin);
        symptom[strcspn(symptom, "\n")] = 0; // retire le retour chariot
        if (strcmp(symptom, "q") == 0) {
            break;
        }
        if (strlen(symptom) == 0) {
            printf("Merci de renseigner un symptome, veuillez réessayer.\n");
            continue;
        }
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
    }
    return base_de_faits;
}

RULES* ask_rules(RULES* base_de_regles) {
    char conclusion[100];
    //vérfie si la règle n'est pas déjà dans la base de règles
    printf("Entrer la conclusion de la règle:\n");
    fgets(conclusion, sizeof(conclusion), stdin);
    conclusion[strcspn(conclusion, "\n")] = 0; // retire le retour chariot
    if (isValinRules(&base_de_regles, conclusion)) {
        printf("La règle est déjà dans la base de règles\n");
        return base_de_regles;
    }


    // Création d'une nouvelle règle
    RULES* new_rule = malloc(sizeof(RULES));
    new_rule->conclusion = strdup(conclusion);
    new_rule->ptete_conditions = NULL;
    new_rule->suiv = NULL;

    // Demande les conditions
    printf("Entrer les conditions (appuyer sur 'q' pour quitter):\n");
    while (1) {
        char condition[100];
        fgets(condition, sizeof(condition), stdin);
        condition[strcspn(condition, "\n")] = 0; // retire le retour chariot

        if (strcmp(condition, "q") == 0) {
            break;
        }

        // Create a new condition
        CONDITIONS* new_condition = malloc(sizeof(CONDITIONS));
        new_condition->conditions = strdup(condition);
        new_condition->suiv = NULL;

        // Add the condition to the rule
        if (new_rule->ptete_conditions == NULL) {
            new_rule->ptete_conditions = new_condition;
        } else {
            CONDITIONS* current = new_rule->ptete_conditions;
            while (current->suiv != NULL) {
                current = current->suiv;
            }
            current->suiv = new_condition;
        }
    }

    // Ajoute la nouvelle règle à la base de règles
    ins_Rule(&base_de_regles, new_rule);
    return base_de_regles;
}
