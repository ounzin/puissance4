/* 
    Auteur : AHMED ADJIBADE 
    ...
    L2I VALROSE 
*/

/*Initialisation du tableau*/

void initTable(char tab[][7]);

/* Affichage du tableau */

void showTable(char tab[][7]);

/* Affichage de la bordure */

void borderGame();

/* Affichage du numero de colonne sur le jeu */ 

void showCol();

/* Affichage du plateau de jeu avec les numeros de colonne et les instructions de bases de jeu */

void printPlateau(char tab[][7]);

/* Initialisation du jeu */ 

void initGame(char tab[][7]);

/* Vérification de caractère dans la table*/

int estVide(char c);

/* Faire tomber jeton placer au sommet d'une colonne */

void gravite(char tab[][7], int colonne, char jeton);

/* Ajout de jeton dans une colonne */

void jouer(int joueur, int colonne, char tab[][7]);

/* Fonction qui vérifie une combinaison gagnante sur une ligne.*/

int verifLigne(char tab[][7]);

/* Fonction qui vérifie une combinaison gagnante sur une colonne */

int verifColonne(char tab[][7]);

/* Fonction qui vérifie une combinaison gagnante sur une colonne */

int verifDiagonale(char tab[][7]);

/* Fonction qui détecte un gagnant */

int isWinner(char tab[][7]);

/* Big Gravite : gravite après avoir tourner le plateau */ 

void bigGravite(char tab[][7]);

/* Tourner plateau à gauche */

void turnLeft(char tab[][7]);

/* Tourner plateau à droite */

void turnRight(char tab[][7]);

/* Retourner le plateau */

void returnPlateau(char tab[][7]);

/* Sauvegarder de partie */

void saveGame(char tab[][7]);

/* Charger une sauvagarde */

void loadGame(char tab[][7]);

/* Partie Joueur vs Joueur */ 

int partiePvsP(int joueur1, int joueur2, char tab[][7]);

/* Partie Joueur vs Machine */

int partiePvsM(int joueur,char tab[][7]);






