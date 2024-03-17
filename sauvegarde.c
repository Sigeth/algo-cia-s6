#include "sauvegarde.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "types.h"


RULES* readRules() {
    FILE* rulesFile;
    char ch;

    rulesFile = fopen("regles.kbs", "r");
    if (rulesFile == NULL) {
        printf("File could not be opened\n");
        return NULL;
    }

    char* currWord = malloc(sizeof(char) * 50);
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
                    if (strcmp(currWord, "") != 0) {
                        rules[i] = malloc(sizeof(char) * strlen(currWord));
                        strcpy(rules[i], currWord);
                        i++;
                        strcpy(currWord, "");
                    }
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
                        strcpy(currCondition->conditions, rules[j]);
                        ins_Condition(&currRule->ptete_conditions, currCondition);
                        free(rules[j]);
                    }
                    ins_Rule(&listRules, currRule);
                    i=0;
                    break;
                default:
                    if (ch == '_') {
                        strcat(currWord, " ");
                    } else {
                        strncat(currWord, &ch, 1);
                    }
                    break;
            }
        }
    } while (ch != EOF);

    free(currWord);
    free(conclusion);

    fclose(rulesFile);
    return listRules;
}

char* replaceChar(char* str, char find, char replace){
    char* current_pos = strchr(str,find);
    while (current_pos) {
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }
    return str;
}

int saveRules(RULES* listRules) {
    if (isRuleEmpty(listRules)) {
        printf("Aucune règle à sauvegarder");
        return 1;
    }
    FILE* fileRules = fopen("regles.kbs", "w");

    RULES* currRule = listRules;
    while (currRule != NULL) {
        CONDITIONS* currCondition = currRule->ptete_conditions;
        while(currCondition != NULL) {
            char* formattedCondition = replaceChar(currCondition->conditions, ' ', '_');
            fprintf(fileRules, "%s ", formattedCondition);
            currCondition = currCondition->suiv;
        }
        char* formattedRule = replaceChar(currRule->conclusion, ' ', '_');
        fprintf(fileRules, "-> %s;\n", formattedRule);
        currRule = currRule->suiv;
    }
    fclose(fileRules);
    return 0;
}
