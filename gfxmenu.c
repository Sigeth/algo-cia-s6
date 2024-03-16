#include "gfxmenu.h"
#define LargeurFenetre 1920
#define HauteurFenetre 1080
#define MAX_TEXT_LENGTH 50

char inputText[MAX_TEXT_LENGTH + 1]; // +1 pour \0
//doit être modifié pour être responsive
void Button(int x, int y,int width,int height,char * buttontext){
    //button dimensions
    float buttonWidth = width;
    float buttonHeight = height;
    float buttonX = ((largeurFenetre() - x) - buttonWidth) / 2;
    float buttonY = ((hauteurFenetre() - y) - buttonHeight) / 2;

    //button
    couleurCourante(173, 216, 230);
    rectangle(buttonX, buttonY, buttonX + buttonWidth, buttonY + buttonHeight);

    //button border
    epaisseurDeTrait(2);
    couleurCourante(100, 100, 100);
    ligne(buttonX, buttonY, buttonX + buttonWidth, buttonY);
    ligne(buttonX, buttonY, buttonX, buttonY + buttonHeight);

    couleurCourante(255, 255, 255);
    ligne(buttonX + buttonWidth, buttonY, buttonX + buttonWidth, buttonY + buttonHeight);
    ligne(buttonX, buttonY + buttonHeight, buttonX + buttonWidth, buttonY + buttonHeight);

    //text label
    couleurCourante(0, 0, 0);
    int textWidth = tailleChaine(buttontext, 20);
    int textX = buttonX + (buttonWidth - textWidth) / 2;
    int textY = buttonY + (buttonHeight - 20) / 2;
    afficheChaine(buttontext, 20, textX, textY);
}

void TextInputField(int x,int y) {
    float buttonWidth = 200;
    float buttonHeight = 50;
    float buttonX = ((largeurFenetre() - x) - buttonWidth) / 2;
    float buttonY = ((hauteurFenetre() - y) - buttonHeight) / 2;

    couleurCourante(255, 255, 255);
    epaisseurDeTrait(2);
    couleurCourante(100, 100, 100);
    ligne(buttonX, buttonY, buttonX + buttonWidth, buttonY);
    ligne(buttonX, buttonY, buttonX, buttonY + buttonHeight);
    ligne(buttonX, buttonY+buttonHeight, buttonX+buttonWidth, buttonY + buttonHeight);

    couleurCourante(255, 255, 255);
    rectangle(buttonX, buttonY, buttonX + buttonWidth, buttonY + buttonHeight);

    // Draw input text
    couleurCourante(0, 0, 0);
    epaisseurDeTrait(2);
    afficheChaine(inputText, 20, 60, 80);
}

void gestionEvenement(EvenementGfx evenement)
{
    static bool pleinEcran = false;
    static DonneesImageRGB *image = NULL;

    switch (evenement)
    {
        case Initialisation:
            image = lisBMPRGB("Images/CIAssimo.bmp");
            if(image==NULL){
                printf("img error\n");
            }
            demandeTemporisation(20);
            break;

        case Temporisation:
            rafraichisFenetre();
            break;

        case Affichage:

            effaceFenetre (255, 255, 255);

            Button(840,600,300,50,"Chainage avant");
           /* TextInputField(1230,600);
            Button(-500,600,300,50,"Chainage arriere");
            TextInputField(-900,600);
            Button(400,200,200,50,"Lire la base\nde règles");
            Button(800,200,200,50,"Ajouter une règle");
            Button(1200,200,200,50,"Ajouter un fait");*/

            // Affichage d'une image
            if (image != NULL) // Si l'image a pu etre lue
            {
                // On affiche l'image
                ecrisImage((largeurFenetre()-image->largeurImage)/2, (hauteurFenetre()+400-image->hauteurImage)/2, image->largeurImage, image->hauteurImage, image->donneesRGB);
            }

            break;

        case Clavier:
            printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

            switch (caractereClavier())
            {
                case 'Q': /* Pour sortir quelque peu proprement du programme */
                case 'q':
                    libereDonneesImageRGB(&image); /* On libere la structure image,
					c'est plus propre, meme si on va sortir du programme juste apres */
                    termineBoucleEvenements();
                    break;

                case 'F':
                case 'f':
                    pleinEcran = !pleinEcran; // Changement de mode plein ecran
                    if (pleinEcran)
                        modePleinEcran();
                    else
                        redimensionneFenetre(LargeurFenetre, HauteurFenetre);
                    break;

                case 'R':
                case 'r':
                    // Configure le systeme pour generer un message Temporisation
                    // toutes les 20 millisecondes (rapide)
                    demandeTemporisation(20);
                    break;

                case 'L':
                case 'l':
                    // Configure le systeme pour generer un message Temporisation
                    // toutes les 100 millisecondes (lent)
                    demandeTemporisation(100);
                    break;

                case 'S':
                case 's':
                    // Configure le systeme pour ne plus generer de message Temporisation
                    demandeTemporisation(-1);
                    break;
            }
            break;

        case ClavierSpecial:
            printf("ASCII %d\n", toucheClavier());
            break;

        case BoutonSouris:
            if (etatBoutonSouris() == GaucheAppuye)
            {
                printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
            }
            else if (etatBoutonSouris() == GaucheRelache)
            {
                printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
            }
            break;

        case Souris: // Si la souris est deplacee
            break;

        case Inactivite: // Quand aucun message n'est disponible
            break;

        case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
            printf("Largeur : %d\t", largeurFenetre());
            printf("Hauteur : %d\n", hauteurFenetre());
            break;
    }
}