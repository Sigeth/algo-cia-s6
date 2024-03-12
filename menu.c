#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "types.h"
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




void displayMenu() {
    system("clear");
    printf(ANSI_COLOR_CYAN "╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");


    printf("║     $$$$$$\\  $$$$$$\\  $$$$$$\\        $$$$$$$$\\                                           $$\\            $$$$$$\\                        $$\\                                   ║\n");
    printf("║    $$  __$$\\ \\_$$  _|$$  __$$\\       $$  _____|                                          $$ |          $$  __$$\\                       $$ |                                  ║\n");
    printf("║    $$ /  \\__|  $$ |  $$ /  $$ |      $$ |      $$\\   $$\\  $$$$$$\\   $$$$$$\\   $$$$$$\\  $$$$$$\\         $$ /  \\__|$$\\   $$\\  $$$$$$$\\ $$$$$$\\    $$$$$$\\  $$$$$$\\$$$$\\        ║\n");
    printf("║    $$ |        $$ |  $$$$$$$$ |      $$$$$\\    \\$$\\ $$  |$$  __$$\\ $$  __$$\\ $$  __$$\\ \\_$$  _|        \\$$$$$$\\  $$ |  $$ |$$  _____|\\_$$  _|  $$  __$$\\ $$  _$$  _$$\\       ║\n");
    printf("║    $$ |        $$ |  $$  __$$ |      $$  __|    \\$$$$  / $$ /  $$ |$$$$$$$$ |$$ |  \\__|  $$ |           \\____$$\\ $$ |  $$ |\\$$$$$$\\    $$ |    $$$$$$$$ |$$ / $$ / $$ |      ║\n");
    printf("║    $$ |  $$\\   $$ |  $$ |  $$ |      $$ |       $$  $$<  $$ |  $$ |$$   ____|$$ |        $$ |$$\\       $$\\   $$ |$$ |  $$ | \\____$$\\   $$ |$$\\ $$   ____|$$ | $$ | $$ |      ║\n");
    printf("║    \\$$$$$$  |$$$$$$\\ $$ |  $$ |      $$$$$$$$\\ $$  /\\$$\\ $$$$$$$  |\\$$$$$$$\\ $$ |        \\$$$$  |      \\$$$$$$  |\\$$$$$$$ |$$$$$$$  |  \\$$$$  |\\$$$$$$$\\ $$ | $$ | $$ |      ║\n");
    printf("║     \\______/ \\______|\\__|  \\__|      \\________|\\__/  \\__|$$  ____/  \\_______|\\__|         \\____/        \\______/  \\____$$ |\\_______/    \\____/  \\_______|\\__| \\__| \\__|      ║\n");
    printf("║                                                          $$ |                                                    $$\\   $$ |                                                  ║\n");
    printf("║                                                          $$ |                                                    \\$$$$$$  |                                                  ║\n");
    printf("║                                                          \\__|                                                     \\______/                                                   ║\n");

    printf(ANSI_COLOR_CYAN "╠══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║" ANSI_COLOR_YELLOW " 1. " ANSI_COLOR_RESET "Saisie de règles                                                                                                                                                          " ANSI_COLOR_CYAN "║\n");
    printf("║" ANSI_COLOR_GREEN " 2. " ANSI_COLOR_RESET "Saisie de faits                                                                                                                                                           " ANSI_COLOR_CYAN "║\n");
    printf("║" ANSI_COLOR_BLUE " 3. " ANSI_COLOR_RESET "Enregistrement de la base de règles                                                                                                                                       " ANSI_COLOR_CYAN "║\n");
    printf("║" ANSI_COLOR_MAGENTA " 4. " ANSI_COLOR_RESET "Chainage avant                                                                                                                                                            " ANSI_COLOR_CYAN "║\n");
    printf("║" ANSI_COLOR_GRAY " 5. " ANSI_COLOR_RESET "Chainage arrière                                                                                                                                                          " ANSI_COLOR_CYAN "║\n");
    printf("║" ANSI_COLOR_RED " 6. " ANSI_COLOR_RESET "Quitter                                                                                                                                                                   " ANSI_COLOR_CYAN "║\n");
    printf(ANSI_COLOR_CYAN "╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf(ANSI_COLOR_RESET "Enter your choice: ");
}

int menu() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Saisie de règles\n");
                sleep(1);
                // Saisie de règles
                break;
            case 2:
                printf("Saisie de faits\n");
                sleep(1);
                // Saisie de faits
                break;
            case 3:
                printf("Enregistrement de la base de règles\n");
                sleep(1);
                //sauvegarde
                break;
            case 4:
                printf("Chainage avant\n");
                sleep(1);
                //chainage avant
                break;
            case 5:
                printf("Chainage arrière\n");
                sleep(1);
                //chainage arrière
                break;
            case 6:
                printf("Quitter\n");
                sleep(1);
                break;
            default:
                printf("Choix invalide\n");
                sleep(1);
        }
        printf("\n");
    } while (choice != 6);

    return 0;
}