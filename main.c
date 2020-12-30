#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "jeu.c"

int main (){
int joueur1 = 1; /* Joueur 1 */
int joueur2 = 2; /* Joueur 2 */
int choixMenu = 0;
int choixPartie = 0;
int choixChargement = 0;
char gameTab[7][7];

printf("\n\n###### BIENVENUE A PUISSANCE 4 ######\n\n");
printf("\t \t Menu \t\t\n\n");

printf(" 1. Nouvelle partie\n 2. Charger Partie \n 3. Info \n 4. Quitter \n ");
do{ 
    scanf("%d",&choixMenu);
    vider_buffer(stdin);
}while(choixMenu < 1 || choixMenu > 4);

switch (choixMenu)
{
case 1: /* Nouvelle partie */
    printf("1.Joueur vs Joueur\n 2.Joueur vs Machine\n");
    /**/
    do{ 
    scanf("%d",&choixPartie);
    vider_buffer(stdin);
    }while(choixPartie < 1 || choixPartie > 2);
    /**/
    switch (choixPartie) 
        {
        case 1: /* Joueur vs Joueur */
            initGame(gameTab);
            partiePvsP(joueur1,joueur2,gameTab);
            break;
        case 2: /* Joueur vs Machine */
            initGame(gameTab);
            partiePvsM(joueur1,gameTab);
        default:
            break;
        }
        break;

case 2 : /* Charger Partie */
    initTable(gameTab);
    loadGame(gameTab);
    printf("Selon quel mode voulez vous jouer  : \n1. Joueur contre joueur ? \n2. Joueur contre Machine ?\n");
    /**/
    do{ 
    scanf("%d",&choixChargement);
    vider_buffer(stdin);
    }while(choixChargement < 1 || choixChargement > 2);
    /**/
    switch (choixChargement)
    {
    case 1: /* Joueur contre Joueur après chargement de partie */
        printPlateau(gameTab);
        partiePvsP(joueur1,joueur2,gameTab);
        break;
    case 2: /* Joueur contre machine après chargement de partie */
        printPlateau(gameTab);
        partiePvsM(joueur1,gameTab);
    default:
        break;
    }
case 3:
    printf("Jeton joueur 1 : O ; Jeton joueur 2 : X \n Un joueur qui aligne 4 fois son jeton sur la ligne, la colonne ou la diagonale gagne.\n");
    printf("\n Le jeu est jouable grace aux chiffres !\n");
    main();
case 4:
    exit(0);
default:
    break;
}
return 0; 
}