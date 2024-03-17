#include <unistd.h>
#include "gfxmenu.h"
#define LargeurFenetre 800
#define HauteurFenetre 600

bool saisieActivefait = false;
bool saisieActiveregle = false;
char inputfait[25];
char inputregle[25];
char faitetat[25];
char regleetat[25];
char islecture[25];
char issave[25];

void Buttons(){
    //boutton ajoute regle
    //ombre
    couleurCourante(180, 180, 180);
    rectangle((float)largeurFenetre()/33, (float)hauteurFenetre()/3,
              (float)largeurFenetre()/4.5f, (float)(hauteurFenetre()/5.1));
    //boutton
    couleurCourante(173, 216, 230);
    rectangle((float)largeurFenetre()/30, (float)hauteurFenetre()/3,
              (float)largeurFenetre()/4.5f, (float)hauteurFenetre()/5);
    //zone texte
    couleurCourante(0, 0, 0);
    rectangle((float)largeurFenetre()/4.5f, (float)hauteurFenetre()/3,
              (float)largeurFenetre()/2, (float)hauteurFenetre()/5.1f);
    couleurCourante(255,255,255);
    rectangle((float)largeurFenetre()/4.45f, (float)hauteurFenetre()/3.035f,
              (float)largeurFenetre()/2.01f, (float)hauteurFenetre()/4.98f);
    //Texte
    couleurCourante(40, 40, 40);
    epaisseurDeTrait(2);
    afficheChaine("Ajouter regle",(float)largeurFenetre()/53.333f,(float)largeurFenetre()/15,(float)hauteurFenetre()/4);
    afficheChaine(inputregle,(float)largeurFenetre()/53.333f,(float)largeurFenetre()/4.2f,(float)hauteurFenetre()/4);
    afficheChaine(regleetat,(float)largeurFenetre()/53.333f,(float)largeurFenetre()/15,(float)hauteurFenetre()/6);

    //bouton ajoute fait
    //ombre
    couleurCourante(180, 180, 180);
    rectangle((float)largeurFenetre()/1.8085f, (float)hauteurFenetre()/3,
              (float)largeurFenetre()/1.35f, (float)hauteurFenetre()/5.1f);
    //boutton
    couleurCourante(173, 216, 230);
    rectangle((float)largeurFenetre()/1.8f, (float)hauteurFenetre()/3,
              (float)largeurFenetre()/1.35f, (float)hauteurFenetre()/5);
    //zone texte
    couleurCourante(0, 0, 0);
    rectangle((float)largeurFenetre()/1.35f, (float)hauteurFenetre()/3,
              (float)largeurFenetre()/1.0125f, (float)hauteurFenetre()/5.1f);
    couleurCourante(255,255,255);
    rectangle((float)largeurFenetre()/1.345f, (float)hauteurFenetre()/3.035f,
              (float)largeurFenetre()/1.016f, (float)hauteurFenetre()/4.98f);
    //texte
    couleurCourante(40, 40, 40);
    epaisseurDeTrait(2);
    afficheChaine("Ajouter fait",(float)largeurFenetre()/53.333f,(float)largeurFenetre()/1.72f,(float)hauteurFenetre()/4);
    afficheChaine(inputfait,(float)largeurFenetre()/53.333f,(float)largeurFenetre()/1.33f,(float)hauteurFenetre()/4);
    afficheChaine(faitetat,(float)largeurFenetre()/53.333f,(float)largeurFenetre()/1.72f,(float)hauteurFenetre()/6);

    //bouton chainage avant
    //ombre
    couleurCourante(180,180,180);
    rectangle((float)largeurFenetre()/5.6f, (float)hauteurFenetre()/7,
              (float)largeurFenetre()/2.2f, (float)hauteurFenetre()/21.3f);
    //boutton
    couleurCourante(173, 216, 230);
    rectangle((float)largeurFenetre()/5.5f, (float)hauteurFenetre()/7,
              (float)largeurFenetre()/2.2f, (float)hauteurFenetre()/20);
    //texte
    couleurCourante(40, 40, 40);
    epaisseurDeTrait(2);
    afficheChaine("Chainage avant",(float)largeurFenetre()/44.444f,(float)largeurFenetre()/5,(float)hauteurFenetre()/12.5f);

    //boutton chainage arriere
    //ombre
    couleurCourante(180,180,180);
    rectangle((float)largeurFenetre()/1.91f, (float)hauteurFenetre()/7,
              (float)largeurFenetre()/1.25f, (float)hauteurFenetre()/21.3f);
    //boutton
    couleurCourante(173, 216, 230);
    rectangle((float)largeurFenetre()/1.9f, (float)hauteurFenetre()/7,
              (float)largeurFenetre()/1.25f, (float)hauteurFenetre()/20);
    //texte
    couleurCourante(40, 40, 40);
    epaisseurDeTrait(2);
    afficheChaine("Chainage arriere",(float)largeurFenetre()/44.444f,(float)largeurFenetre()/1.85f,(float)hauteurFenetre()/12.5f);
}

void miniMenu(){
    afficheChaine("Lecture BDR : L",(float)largeurFenetre()/60,(float)largeurFenetre()/35,(float)hauteurFenetre()/1.05f);
    afficheChaine(islecture,(float)largeurFenetre()/60,(float)largeurFenetre()/5,(float)hauteurFenetre()/1.05f);
    afficheChaine("Sauvegarde  : S",(float)largeurFenetre()/60,(float)largeurFenetre()/35,(float)hauteurFenetre()/1.10f);
    afficheChaine(issave,(float)largeurFenetre()/60,(float)largeurFenetre()/5,(float)hauteurFenetre()/1.10f);
    afficheChaine("Reset BDF  : R",(float)largeurFenetre()/60,(float)largeurFenetre()/35,(float)hauteurFenetre()/1.15f);
    afficheChaine("Plein ecran : F",(float)largeurFenetre()/60,(float)largeurFenetre()/35,(float)hauteurFenetre()/1.20f);
    afficheChaine("Quitter     : Q",(float)largeurFenetre()/60,(float)largeurFenetre()/35,(float)hauteurFenetre()/1.25f);
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
                ecrisImage((largeurFenetre()-image->largeurImage)/2, (hauteurFenetre()+300-image->hauteurImage)/2,
                           image->largeurImage, image->hauteurImage, image->donneesRGB);
            }
            //affichage mini menu
            miniMenu();
            //affichage bouttons
            Buttons();
            break;

        case Clavier:
            printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());
            if(saisieActivefait){
                if (caractereClavier() >= 32 && caractereClavier() <= 126) {
                    if(strlen(inputfait)<24){
                    char temp = caractereClavier();
                    strncat(inputfait,&temp,1);
                    printf("input fait : %s\n",inputfait);}
                }
                if(caractereClavier() == 8) {
                    inputfait[strlen(inputfait) - 1] = '\0';
                }
            }else if(saisieActiveregle){
                if (caractereClavier() >= 32 && caractereClavier() <= 126) {
                    if(strlen(inputregle)<24){
                        char temp = caractereClavier();
                        strncat(inputregle, &temp, 1);
                        printf("input regle : %s\n", inputregle);
                    }
                }
                if(caractereClavier() == 8) {
                    inputregle[strlen(inputregle) - 1] = '\0';
                }
            }
            else {
                switch (caractereClavier()) {
                    case 'S':
                    case 's':
                        //fonction de save
                        strcpy(issave,"Sauvegarde !");
                        //faire en sorte de changer la valeur de issave après une tempo
                        break;

                    case 'L':
                    case 'l':
                        //fonction de lecture
                        strcpy(islecture,"Lecture en cours...");
                        //faire en sorte de changer la valeur de islecture après une tempo
                        break;

                    case 'R':
                    case 'r':
                        //fonction de reset
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

                    case 'V':
                    case 'v':
                        demandeTemporisation(20);
                        break;

                    case 'B':
                    case 'b':
                        demandeTemporisation(100);
                        break;

                    case 'N':
                    case 'n':
                        demandeTemporisation(-1);
                        break;
                }
            }
            break;

        case ClavierSpecial:
            printf("ASCII %d\n", toucheClavier());
            break;
        case BoutonSouris:
            if (etatBoutonSouris() == GaucheAppuye)
            {
                //click sur bouton ajoute regle
                if((abscisseSouris() >= largeurFenetre()/30 && abscisseSouris() <= largeurFenetre()/4.5)
                   && (ordonneeSouris() >= hauteurFenetre()/5 && ordonneeSouris() <= hauteurFenetre()/3)) {
                    //fonction ajoute regle
                    //si succees
                    strcpy(regleetat,"Regle ajoutee");
                    //si echec
                    //strcpy(regleetat,"Erreur d'ajout");
                }
                //click dans zone de texte saisieregle
                if((abscisseSouris() >= largeurFenetre()/4.45 && abscisseSouris() <= largeurFenetre()/2.01)
                   && (ordonneeSouris() >= hauteurFenetre()/4.98 && ordonneeSouris() <= hauteurFenetre()/3.035)) {
                    saisieActiveregle=true;
                    strcpy(regleetat,"");
                }else{
                    saisieActiveregle=false;
                }
                //click sur bouton ajoute fait
                if((abscisseSouris() >= largeurFenetre()/1.8 && abscisseSouris() <= largeurFenetre()/1.35)
                   && (ordonneeSouris() >= hauteurFenetre()/5 && ordonneeSouris() <= hauteurFenetre()/3)) {
                    //fonction ajoute fait
                    //si succees
                    strcpy(faitetat,"Fait ajoutee");
                    strcpy(inputfait,"");
                    //si echec
                    //strcpy(faitetat,"Erreur d'ajout");
                    //strcpy(inputfait,"");
                }
                //click dans zone de texte saisiefait
                if((abscisseSouris() >= largeurFenetre()/1.345 && abscisseSouris() <= largeurFenetre()/1.016)
                && (ordonneeSouris() >= hauteurFenetre()/4.98 && ordonneeSouris() <= hauteurFenetre()/3.035)) {
                    saisieActivefait=true;
                    strcpy(faitetat,"");
                }else{
                    saisieActivefait=false;
                }
                //click chainage avant
                if((abscisseSouris() >= largeurFenetre()/5.5 && abscisseSouris() <= largeurFenetre()/2.2)
                   && (ordonneeSouris() >= hauteurFenetre()/20 && ordonneeSouris() <= hauteurFenetre()/37)) {
                    //fonction chainage avant
                    //resultat dans nouvelle fenetre ?
                }
                //click chainage arriere
                if((abscisseSouris() >= largeurFenetre()/1.9 && abscisseSouris() <= largeurFenetre()/1.25)
                   && (ordonneeSouris() >= hauteurFenetre()/20 && ordonneeSouris() <= hauteurFenetre()/7)) {
                    //fonction chainage arriere
                    //resultat dans nouvelle fenetre ?
                }

                //printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
            }
            else if (etatBoutonSouris() == GaucheRelache)
            {
                //printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
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