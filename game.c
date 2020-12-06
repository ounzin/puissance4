#include <stdio.h>
#include <stdlib.h>

/* Vider buffer */

void vider_buffer(FILE* f){
int c;
while((c=fgetc(f)) != '\n' && c != EOF);
}

/*Initialisation du tableau*/

void initTable(char tab[][7]){
int i;
int j;
for(i=0;i<7;i++){
for(j=0;j<7;j++){
tab[i][j] = ' ';
}
}
}

/* Affichage du tableau */

void showTable(char tab[][7]){
int i;
int j;
for(i=0;i<7;i++){
for(j=0;j<7;j++){
    printf("|%c",tab[i][j]);
}
printf("|\n");
}
}

/* Affichage de la bordure */

void borderGame(){
int i;
for(i=1;i<=15;i++){
printf("_");
}
printf("\n\n");
}

/* Affichage du numero de colonne sur le jeu */ 

void showCol(){
int i;
int cpt = 0;
for(i=1;i<16;i++){
if(i%2 == 0){
cpt++;
printf("%d",cpt);
}else{
printf(" ");
}

}
}

/* Affichage du plateau de jeu avec les numeros de colonne et les instructions de bases de jeu */

void printPlateau(char tab[][7]){ /* Affiche l'état actuel du plateau */
borderGame();
showTable(tab);
borderGame();
showCol();
}

/* Initialisation du jeu */ 

void initGame(char tab[][7]){
initTable(tab);
printPlateau(tab); 
printf("\n");
}

/* Vérification de caractère dans la table*/

int estVide(char c){
if(c == ' '){
return 1;
}else {
return 0;
}
}

/* Faire tomber jeton placer au sommet d'une colonne */

void gravite(char tab[][7], int colonne, char jeton){
int i;
for(i=0; i<7;i++){
if(estVide(tab[i][colonne-1]) == 1){
if(i == 6){ /* toute la colonne est vide */
    tab[i][colonne-1] = jeton;
    break;
}
}else{
tab[i-1][colonne-1] = jeton;
break;
}
}

}

/* Ajout de jeton dans une colonne */

void jouer(int joueur, int colonne, char tab[][7]){ 
switch (joueur)
{
case 1 :
gravite(tab,colonne,'O');
break;
case 2 :
gravite(tab,colonne,'X');    
default:
break;
}
}

/* Fonction qui vérifie une combinaison gagnante sur une ligne.*/

int verifLigne(char tab[][7]){
int i;
int j;
int endPlayer1 = 0;
int endPlayer2 = 0;
int sumO = 0;
int sumX = 0;

for(i=0;i<7;i++){
for(j=0;j<7;j++){
if(estVide(tab[i][j]) == 0){
    if(j>0){
    if(tab[i][j] == 'O' && tab[i][j-1] == 'O'){
        sumO += 1;
        if(sumO == 3){
            endPlayer1 += 1;
            break;
        }
    }else{
        sumO = 0;
    }
    if(tab[i][j] == 'X' && tab[i][j-1] == 'X'){
        sumX += 1;
        if(sumX == 3){
            endPlayer2 += 1;
            break;
        }
    }else{
        sumX = 0;
    } 
}
}
}
}

if(endPlayer1 != 0){
return 1; /* Jouer 1 gagne */
}

if(endPlayer2 != 0){
return 2; /* Joeur 2 gagne */
}

return 0;
}

/* Fonction qui vérifie une combinaison gagnante sur une colonne */

int verifColonne(char tab[][7]){
int i;
int j;
int sumO = 0;
int sumX = 0;
int endPlayer1 = 0;
int endPlayer2 = 0;

for(i=0;i<7;i++){
for(j=0;j<7;j++){
if(estVide(tab[j][i]) == 0){
    
    if(j>0){
    if(tab[j][i] == 'O' && tab[j-1][i] == 'O'){
        sumO += 1;
        if(sumO == 3){
            endPlayer1 += 1;
            break;
        }
    }else{
        sumO = 0;
    }
    if(tab[j][i] == 'X' && tab[j-1][i] == 'X'){
        sumX += 1;
        if(sumX == 3){
            endPlayer2 += 1;
            break;
        }
    }else{
        sumX = 0;
    } 
}
}
}
}

if(endPlayer1 != 0){
return 1; /* Jouer 1 gagne */
}

if(endPlayer2 != 0){
return 2; /* Joeur 2 gagne */
}
return 0;
}

/* Fonction qui vérifie une combinaison gagnante sur une colonne (not yet) */

int verifDiagonale(char tab[][7]){
return 0;
}

/* Fonction qui détecte un gagnant */

int isWinner(char tab[][7]){
int i;
int j;
int full = 0;
/* Verification sur ligne */

if(verifLigne(tab) == 1){
printf("\n Jouer 1 gagne\n");
return 0;
exit(0);
}
if(verifLigne(tab) == 2){
printf("\n Joueur 2 gagne\n");
return 0;
exit(0);
}   

/* Verification sur colonne */

if(verifColonne(tab) == 1){
printf("\n Jouer 1 gagne\n");
return 0;
exit(0);
}
if(verifColonne(tab) == 2){
printf("\n Joueur 2 gagne\n");
return 0;
exit(0);
} 

/* Partie nulle */

for(i=0;i<7;i++){
for(j=0;j<7;j++){
if(estVide(tab[i][j] = 0)){
    full += 1;
}
}
}

if(full == 49){
printf("Partie nulle ! \n");
return 0;
exit(0);
}
return 1;
}

/* Big Gravite : gravite après avoir tourner le plateau */ 

void bigGravite(char tab[][7]){
int t;
int i;
int j;
char temp = ' '; 
for (t=0;t<7;t++){
for(i=1; i<7; i++){
    for(j=0; j<7; j++){
    if(estVide(tab[i][j]) == 1){
    if(estVide(tab[0][j] == 0)){
        break;
    }
    tab[i][j] = temp;
    tab[i][j] = tab[i-1][j];
    tab[i-1][j] = temp;
}
}
}
}
}


/* Tourner plateau à gauche */

void turnLeft(char tab[][7]){
int i;
int j;
char temp[7][7];
char copie[7][7];
initTable(temp);
initTable(copie);

/* rotation */

for(i=0;i<7;i++){
for(j=0;j<7;j++){
    copie[j][i] = tab[i][6-j];
}
}
/* copie dans tab et gravité */

for(i=0;i<7;i++){
for(j=0;j<7;j++){
    tab[i][j] = copie[i][j];
}
}
bigGravite(tab);
printPlateau(tab);
}

/* Tourner plateau à droite */

void turnRight(char tab[][7]){
int i;
int j;
char temp[7][7];
char copie[7][7];
initTable(temp);
initTable(copie);

/* rotation */

for(i=0;i<7;i++){
    for(j=0;j<7;j++){
        copie[i][j] = tab[6-j][i];
    }
}
/* copie dans tab et gravité */

for(i=0;i<7;i++){
    for(j=0;j<7;j++){
        tab[i][j] = copie[i][j];
    }
}
bigGravite(tab);
printPlateau(tab);
}

/* Retourner le plateau */

void returnPlateau(char tab[][7]){
int i;
int j;
char temp[7][7];
char copie[7][7];
initTable(temp);
initTable(copie);

/* rotation */

for(i=0;i<7;i++){
    for(j=0;j<7;j++){
        copie[i][j] = tab[6-i][j];
    }
}
/* copie dans tab et gravité */

for(i=0;i<7;i++){
    for(j=0;j<7;j++){
        tab[i][j] = copie[i][j];
    }
}
bigGravite(tab);
printPlateau(tab);
}

/* Création d'une nouvelle partie */ 

int partie(int joueur1, int joueur2, char tab[][7]){
int end = 1;
int choix1;
int choix2;
int colonne1;
int colonne2;
while(end){

/* Joueur 1 */
if(isWinner(tab) == 0){
    end++;
    break;
}
printf(" Joueur %d, veuillez choisir une action (numero) : \n 0.Jouer \t 1.Rotation gauche \t 2. Rotation droite \t 3. Retourner plateau \t 4.Quitter \n", joueur1);
scanf("%d",&choix1);

if(choix1 == 0){
    printf("\n Jouer %d joue dans la colonne : ", joueur1);
    scanf("%d",&colonne1);
    gravite(tab,colonne1,'O');
    printPlateau(tab);
}

/*switch (choix1)
{
    case 0 :
        printf("\n Jouer %d joue dans la colonne : ", joueur1);
        scanf("%d",&colonne1);
        gravite(tab,colonne1,'O');
        printPlateau(tab);
        break;
    case 1:
        turnLeft(tab);
        break;
    case 2:
        turnRight(tab);
        break;
    case 3:
        returnPlateau(tab);
        break;
    case 4:
        printf("Joueur %d gagne par forfait !\n",joueur2);
        exit(0);
        break;
    default:
    break;
}*/

/* Joueur 2 */
if(isWinner(tab) == 0){
end++;
break;
}
printf(" Joueur %d, veuillez choisir une action (numero) : \n 0.Jouer \t 1.Rotation gauche \t 2. Rotation droite \t 3. Retourner plateau \t 4.Quitter \n", joueur2);
scanf("%d",&choix2);
switch (choix2)
{
case 0 :
printf("\n Jouer %d joue dans la colonne : ", joueur2);
scanf("%d",&colonne2); 
vider_buffer(stdin);
jouer(joueur2,colonne2,tab);
printPlateau(tab);
break;
case 1:
turnLeft(tab);
break;
case 2:
turnRight(tab);
break;
case 3:
returnPlateau(tab);
break;
case 4:
printf("Joueur %d gagne par forfait !\n",joueur1);
exit(0);
break;
default:
break;
}
}
return 0;
}



int main (){
int joueur1 = 1; /* Joueur 1 */
int joueur2 = 2; /* Joueur 2 */
char gameTab[7][7];
initGame(gameTab);
partie(joueur1,joueur2,gameTab);
return 0;
}