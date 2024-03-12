#ifndef ALGO_CIA_S6_TYPES_H
#define ALGO_CIA_S6_TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Conditions
typedef struct conditions{
    char ** conditions;
    struct conditions * suiv;
} CONDITIONS;

//Règles
typedef struct rules{
    char * conclusion;
    CONDITIONS * ptete_conditions ;
    struct rules * suiv;
} RULES;

//Faits
typedef struct faits{
    char ** faits;
    struct faits * suiv;
}FAITS;


//Les fonctions suivantes retourne 1 ou 0 pour être comprise par un "if" si nécessaire (1 True, 0 False)

                // CONDITIONS //
int init_Conditions(CONDITIONS ** C, int conditions_size);// Retourne 1 ou 0

int isConditionEmpty(CONDITIONS * C);

int ins_Condition(CONDITIONS **TC, CONDITIONS *C);

int free_ListeConditions(CONDITIONS *TC);

void affiche_Condition(CONDITIONS *C);

int affiche_ListeConditions(CONDITIONS *TC);

               // RULES //
int init_Rule(RULES ** R, int conclusion_size);// Retourne 1 ou 0

int isRuleEmpty(RULES * R);// Retourne 1 ou 0

int ins_Rule(RULES ** TR,RULES * R);// Insertion par ordre alphabétique des conclusions. Retourne 1 ou 0

int free_RuleList(RULES *T);// Retourne 1 ou 0

void affiche_Rule(RULES * R);

int affiche_RuleList(RULES * TR); // Retourne le nombre de règles en plus de les afficher

               // FAITS //

int init_Fait(FAITS ** F, int faits_size);// Retourne 1 ou 0

int isFaitEmpty(FAITS * F);// Retourne 1 ou 0

int ins_Fait(FAITS ** TF,FAITS * F);// Insertion par ordre alphabétique des conclusions. Retourne 1 ou 0

int free_FaitList(FAITS *TF);// Retourne 1 ou 0

void affiche_Fait(FAITS * F);

int affiche_FaitList(FAITS * TF); // Retourne le nombre de règles en plus de les afficher
#endif
