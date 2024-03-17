#include <unistd.h>
#include "gfxmenu.h"
#define LargeurFenetre 800
#define HauteurFenetre 600

bool saisieActivefait = false;
bool saisieActiveregle = false;
char inputfait[25];
char inputregle[25];
char islecture[25];
char issave[25];

void Buttons(){
    //ombre
    couleurCourante(180, 180, 180);
    rectangle(largeurFenetre()/33, hauteurFenetre()/3, largeurFenetre()/4.5, hauteurFenetre()/5.1);
    rectangle(largeurFenetre()/1.8085, hauteurFenetre()/3, largeurFenetre()/1.35, hauteurFenetre()/5.1);

    rectangle(largeurFenetre()/5.6, hauteurFenetre()/7, largeurFenetre()/2.2, hauteurFenetre()/21.3);
    rectangle(largeurFenetre()/1.91, hauteurFenetre()/7, largeurFenetre()/1.25, hauteurFenetre()/21.3);

    //boutons
    couleurCourante(173, 216, 230);
    //haut
    rectangle(largeurFenetre()/30, hauteurFenetre()/3, largeurFenetre()/4.5, hauteurFenetre()/5);
    couleurCourante(0, 0, 0);
    rectangle(largeurFenetre()/4.5, hauteurFenetre()/3, largeurFenetre()/2, hauteurFenetre()/5.1);
    couleurCourante(255,255,255);
    rectangle(largeurFenetre()/4.45, hauteurFenetre()/3.035, largeurFenetre()/2.01, hauteurFenetre()/4.98);

    couleurCourante(173, 216, 230);
    rectangle(largeurFenetre()/1.8, hauteurFenetre()/3, largeurFenetre()/1.35, hauteurFenetre()/5);
    couleurCourante(0, 0, 0);
    rectangle(largeurFenetre()/1.35, hauteurFenetre()/3, largeurFenetre()/1.0125, hauteurFenetre()/5.1);
    couleurCourante(255,255,255);
    rectangle(largeurFenetre()/1.345, hauteurFenetre()/3.035, largeurFenetre()/1.016, hauteurFenetre()/4.98);

    //bas
    couleurCourante(173, 216, 230);
    rectangle(largeurFenetre()/5.5, hauteurFenetre()/7, largeurFenetre()/2.2, hauteurFenetre()/20);
    rectangle(largeurFenetre()/1.9, hauteurFenetre()/7, largeurFenetre()/1.25, hauteurFenetre()/20);

    couleurCourante(40, 40, 40);
    epaisseurDeTrait(2);

    //Texte
    afficheChaine("Ajouter regle",largeurFenetre()/53.333,largeurFenetre()/15,hauteurFenetre()/4);
    afficheChaine(inputregle,largeurFenetre()/53.333,largeurFenetre()/4.2,hauteurFenetre()/4);
    afficheChaine("Ajouter fait",largeurFenetre()/53.333,largeurFenetre()/1.72,hauteurFenetre()/4);
    afficheChaine(inputfait,largeurFenetre()/53.333,largeurFenetre()/4.2,hauteurFenetre()/4);
    afficheChaine("Chainage avant",largeurFenetre()/44.444,largeurFenetre()/5,hauteurFenetre()/12.5);
    afficheChaine("Chainage arriere",largeurFenetre()/44.444,largeurFenetre()/1.85,hauteurFenetre()/12.5);
}

void miniMenu(){
    afficheChaine("Lecture BDR : L",largeurFenetre()/60,largeurFenetre()/35,hauteurFenetre()/1.05);
    afficheChaine(islecture,largeurFenetre()/60,largeurFenetre()/5,hauteurFenetre()/1.05);
    afficheChaine("Sauvegarde  : S",largeurFenetre()/60,largeurFenetre()/35,hauteurFenetre()/1.10);
    afficheChaine(issave,largeurFenetre()/60,largeurFenetre()/5,hauteurFenetre()/1.05);
    afficheChaine("Reset BDF   : R",largeurFenetre()/60,largeurFenetre()/35,hauteurFenetre()/1.15);
    afficheChaine("Plein ecran : F",largeurFenetre()/60,largeurFenetre()/35,hauteurFenetre()/1.20);
    afficheChaine("Quitter     : Q",largeurFenetre()/60,largeurFenetre()/35,hauteurFenetre()/1.25);
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
            // affichage logo
            if (image != NULL) // Si l'image a pu etre lue
            {
                // On affiche l'image
                ecrisImage((largeurFenetre()-image->largeurImage)/2, (hauteurFenetre()+300-image->hauteurImage)/2, image->largeurImage, image->hauteurImage, image->donneesRGB);
            }
            //affichage mini menu
            miniMenu();
            //affichage bouttons
            Buttons();
            afficheChaine(inputfait,largeurFenetre()/53.333,largeurFenetre()/1.33,hauteurFenetre()/4);
            break;

        case Clavier:
            if(saisieActivefait){
                if (caractereClavier() >= 32 && caractereClavier() <= 126) {
                    if(strlen(inputfait)<24){
                    char temp = caractereClavier();
                    strncat(inputfait,&temp,1);
                    printf("input fait : %s\n",inputfait);}
                }
            }else if(saisieActiveregle){
                if (caractereClavier() >= 32 && caractereClavier() <= 126) {
                    if(strlen(inputregle)<24){
                    char temp = caractereClavier();
                    strncat(inputregle,&temp,1);
                    printf("input regle : %s\n",inputregle);
                    }
                }
            }
            else {
                // Si la saisie n'est pas active, gérer les autres touches spéciales
                switch (caractereClavier()) {
                    case 'S':
                    case 's':
                        //fonction de save
                        strcpy(issave,"Sauvegarde !");
                        break;

                    case 'L':
                    case 'l':
                        //fonction de lecture
                        strcpy(islecture,"Lecture en cours...");
                        break;

                    case 'Q':
                    case 'q':
                        libereDonneesImageRGB(&image);
                        termineBoucleEvenements();
                        break;

                    case 'F':
                    case 'f':
                        pleinEcran = !pleinEcran;
                        if (pleinEcran)
                            modePleinEcran();
                        else
                            redimensionneFenetre(LargeurFenetre, HauteurFenetre);
                        break;

                    case 'R':
                    case 'r':
                        demandeTemporisation(20);
                        break;

                    case 'T':
                    case 't':
                        demandeTemporisation(100);
                        break;

                    case 'U':
                    case 'u':
                        demandeTemporisation(-1);
                        break;
                }
            }
            break;

        case ClavierSpecial:
            printf("ASCII %d\n", toucheClavier());
            break;
//rectangle(largeurFenetre()/1.345, hauteurFenetre()/3.035, largeurFenetre()/1.016, hauteurFenetre()/4.98);
        case BoutonSouris:
            if (etatBoutonSouris() == GaucheAppuye)
            {
                if((abscisseSouris() >= largeurFenetre()/4.45 && abscisseSouris() <= largeurFenetre()/2.01) && (ordonneeSouris() >= hauteurFenetre()/4.98 && ordonneeSouris() <= hauteurFenetre()/3.035)) {
                    saisieActiveregle=true;
                }else{
                    saisieActiveregle=false;
                }
                if((abscisseSouris() >= largeurFenetre()/1.345 && abscisseSouris() <= largeurFenetre()/1.016) && (ordonneeSouris() >= hauteurFenetre()/4.98 && ordonneeSouris() <= hauteurFenetre()/3.035)) {
                    saisieActivefait=true;
                }else{
                    saisieActivefait=false;
                }
                printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
            }
            else if (etatBoutonSouris() == GaucheRelache)
            {
                printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
            }
            break;

        case Souris: // Si la souris est deplacee
            //servira au hover des boutons
            break;

        case Inactivite: // Quand aucun message n'est disponible
            break;

        case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
            printf("Largeur : %d\t", largeurFenetre());
            printf("Hauteur : %d\n", hauteurFenetre());
            break;
    }
}