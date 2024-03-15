#include "sauvegarde.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

RULES* readRules() {
    FILE* rulesFile;
    char ch;

    rulesFile = fopen("regles.kbs", "r");
    if (rulesFile == NULL) {
        printf("File could not be opened\n");
        return NULL;
    }

    char* currWord = malloc(sizeof(char) * 50);
    strcpy(currWord, "");
    int i = 0;

    char* rules[50];
    char* conclusion;

    RULES* listRules = NULL;
    RULES* currRule = NULL;
    do {
        ch = (char) fgetc(rulesFile);

        if (ch != EOF && ch != '\n') {
            if (!strcmp(currWord, "->")) {
                strcpy(currWord, "");
            }

            switch(ch) {
                case ' ':
                    rules[i] = malloc(sizeof(char) * strlen(currWord));
                    strcpy(rules[i], currWord);
                    i++;
                    strcpy(currWord, "");
                    break;
                case ';':
                    conclusion = malloc(sizeof(char) * strlen(currWord));
                    strcpy(conclusion, currWord);
                    strcpy(currWord, "");

                    init_Rule(&currRule, (int) strlen(conclusion));
                    strcpy(currRule->conclusion, conclusion);
                    for(int j=0; j<i; j++) {
                        CONDITIONS* currCondition = NULL;
                        init_Conditions(&currCondition, (int) strlen(rules[j]));
                        printf("%s", rules[j]);
                        strcpy(currCondition->conditions, rules[j]);
                        free(rules[j]);
                        ins_Condition(&currRule->ptete_conditions, currCondition);
                    }
                    ins_Rule(&listRules, currRule);
                    i=0;
                    break;
                default:
                    strncat(currWord, &ch, 1);
                    break;
            }
        }
    } while (ch != EOF);

    free(currWord);
    free(conclusion);

    affiche_ListRules(listRules);
    fclose(rulesFile);
    return listRules;
}
