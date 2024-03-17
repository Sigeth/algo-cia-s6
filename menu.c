
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "chainage.h"
#include "sauvegarde.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_GRAY  "\x1b[38m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_BLACK   "\x1b[30m"
#define ANSI_COLOR_BRIGHT_BLACK   "\x1b[90m"




void displayMenu() {
    //system("clear");
    printf(ANSI_COLOR_CYAN "╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ $$$$$$\\  $$$$$$\\  $$$$$$\\     $$$$$$$$\\                                        $$\\        $$$$$$\\                       $$\\                              ║\n");
    printf("║$$  __$$\\ \\_$$  _|$$  __$$\\    $$  _____|                                       $$ |      $$  __$$\\                      $$ |                             ║\n");
    printf("║$$ /  \\__|  $$ |  $$ /  $$ |   $$ |     $$\\   $$\\  $$$$$$\\   $$$$$$\\   $$$$$$\\$$$$$$\\     $$ /  \\__|$$\\   $$\\  $$$$$$$\\$$$$$$\\   $$$$$$\\  $$$$$$\\$$$$\\    ║\n");
    printf("║$$ |        $$ |  $$$$$$$$ |   $$$$$\\   \\$$\\ $$  |$$  __$$\\ $$  __$$\\ $$  __$$\\_$$  _|    \\$$$$$$\\  $$ |  $$ |$$  _____\\_$$  _| $$  __$$\\ $$  _$$  _$$\\   ║\n");
    printf("║$$ |        $$ |  $$  __$$ |   $$  __|   \\$$$$  / $$ /  $$ |$$$$$$$$ |$$ |  \\__|$$ |       \\____$$\\ $$ |  $$ |\\$$$$$$\\   $$ |   $$$$$$$$ |$$ / $$ / $$ |  ║\n");
    printf("║$$ |  $$\\   $$ |  $$ |  $$ |   $$ |      $$  $$<  $$ |  $$ |$$   ____|$$ |      $$ |$$\\     $$\\ $$ |$$ |  $$ | \\____$$\\  $$ |$$\\$$   ____|$$ | $$ | $$ |  ║\n");
    printf("║\\$$$$$$  |$$$$$$\\ $$ |  $$ |   $$$$$$$$\\$$  /\\$$\\ $$$$$$$  |\\$$$$$$$\\ $$ |      \\$$$$  |  \\$$$$$$  |\\$$$$$$$ |$$$$$$$  | \\$$$$  \\$$$$$$$\\ $$ | $$ | $$ |  ║\n");
    printf("║ \\______/ \\______|\\__|  \\__|   \\________\\__/  \\__|$$  ____/  \\_______|\\__|       \\____/   \\______/  \\____$$ |\\_______/   \\____/ \\_______|\\__| \\__| \\__|   ║\n");
    printf("║                                                  $$ |                                             \\$$$$$$  |                                             ║\n");
    printf("║                                                  \\__|                                              \\______/                                              ║\n");
    printf(ANSI_COLOR_CYAN "╠══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║" ANSI_COLOR_BRIGHT_BLACK " 1. " ANSI_COLOR_RESET "Lecture de la base de règles                                                                                                                          " ANSI_COLOR_CYAN "║\n");
    printf("║" ANSI_COLOR_GREEN " 2. " ANSI_COLOR_RESET "Saisie de faits                                                                                                                                       " ANSI_COLOR_CYAN "║\n");
    printf("║" ANSI_COLOR_MAGENTA " 3. " ANSI_COLOR_RESET "Chainage avant                                                                                                                                        " ANSI_COLOR_CYAN "║\n");
    printf("║" ANSI_COLOR_GRAY " 4. " ANSI_COLOR_RESET "Chainage arrière                                                                                                                                      " ANSI_COLOR_CYAN "║\n");
    printf("║" ANSI_COLOR_RED " 5. " ANSI_COLOR_RESET "Quitter                                                                                                                                               " ANSI_COLOR_CYAN "║\n");
    printf(ANSI_COLOR_CYAN "╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf(ANSI_COLOR_RESET "Enter your choice: ");
}

int menu(RULES *listRules) {
    int choice;
    FAITS *listFacts = NULL;
    char but[100];
    do {
        displayMenu();
        scanf("%d", &choice);
        //nettoie le buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
        switch (choice) {
            case 1:
                printf("Lecture de la base de règles\n");
                sleep(1);
                // Lecture de la base de règles
                listRules= readRules();
                printf("Base de règles :\n");
                affiche_ListRules(listRules);
                break;
            case 2:
                printf("Saisie de faits\n");
                sleep(1);
                // Saisie de faits
                listFacts = ask_symptoms(listRules, listFacts);
                break;
            case 3:
                printf("Chainage avant\n");
                sleep(1);
                printf("Que voulez vous démontrer: (laissez vide pour fonctionnement par saturation)\n");
                fgets(but, sizeof(but), stdin);
                but[strcspn(but, "\n")] = 0; // retire le retour chariot
                //chainage avant
                FAITS *listFacts_copie = listFacts;
                chainage_avant(listRules, listFacts_copie);
                affiche_liste_faits(listFacts_copie);
                if(check_if_conclusion_in_faits(listFacts_copie, but)) {
                    printf("\nLe but est atteignable\n");
                } 
                
                else if(strcmp(but, "") == 0){
                	printf("\nAucun but n'a été choisi\n");}
         
                else {
                    printf("\nLe but n'est pas atteignable\n");
                }
                sleep(2);
                break;
            case 4:
                printf("Chainage arrière\n");
                sleep(1);
                //chainage arrière
                printf("Entrez le but à prouver: \n");
                fgets(but, sizeof(but), stdin);
                but[strcspn(but, "\n")] = 0; // retire le retour chariot
                if(chainage_arriere(but, listRules, listFacts)) {
                    printf("Le but est atteignable\n");
                } else {
                    printf("Le but n'est pas atteignable\n");
                }
                sleep(2);

                break;
            case 5:
                printf("Quitter\n");
                sleep(1);
                break;
            default:
                printf("Choix invalide\n");
                sleep(1);
        }
        printf("\n");
    } while (choice != 5);
    free_ListeFaits(listFacts);
    free_RuleList(listRules);
    return 0;
}
