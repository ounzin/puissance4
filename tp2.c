#include <stdio.h>
#include <stdlib.h>

void vider_buffer(FILE* f){
int c;
while((c=fgetc(f)) != '\n' && c != EOF);
}

/**/

void saisieTab(int t[], int n){
    int i=0;
    do{
        fscanf(stdin,"%d",&t[i]);
        i++;
    }while(i<n);
}

/**/

void afficheTab(int t[], int n){
    int i;
    for(i=0;i<n;i++){
        fprintf(stdout,"%d\t",t[i]);
    }
}
/*
int intTableSize(int* tab){
    return sizeof(tab)/sizeof(int);
}

int charTableSize(char* tab){
    return sizeof(tab)/sizeof(char);
}
*/
int chercherCaractere(char* s, char c){
    int i=0;
    int in; /*the caracter tester 0= in ; other = not in*/

    while(s[i] != '\0'){
        if(s[i] == c){
            in = 0;
            break;
        }else{
            in = 1;
        }
        i += 1;
    }  
    return in;
}

/**/

int multipleDe3(char* s){
    int i=0;
    int is = 1; /* 0 est multiple, 1 n'est pas multiple */
    int sum=0;
    while(s[i] != '\0'){ 
        sum += s[i] - 48; /* Conversion caracater '0' en 0 . En utilisant l'équivalence de la table ASCII*/
        i++;
    }
    if(sum%3 == 0){
        is = 0;
    }
    return is;
}

/**/

int getBit(unsigned int x, int pos){ /* Obtenir le bit à la position pos dans x*/
    int pos_bit = 1 << pos;
    int res = x & pos_bit;
    return res >> pos;
}

/**/

unsigned int setBit(unsigned int x, int pos){ /* Mettre un bit à 1 et afficher le nouveau nombre*/
    int pos_bit = 1 << pos;
    int res = x | pos_bit ;
    return res;
}

/**/

unsigned int clearBit(unsigned int x, int pos){ /*Mettre un bit à zero et afficher le nouveau nombre. on utilse ~ pour inverser le
resultat des décalages */
    int pos_bit_invert = ~(1 << pos);
    int res = x & pos_bit_invert;
    return res;
}

/**/

unsigned int toggleBit(unsigned int x, int pos){ /* Inverser le bit à la position pos et afficher le nouveau nombre. on utilise le ^ 
(ou exclusif) */ 
    int pos_bit = (1<<pos);
    int res = x ^ pos_bit;
    return res; 
}

/**/

unsigned int defineBit(unsigned int x, int pos, int bool){ /* écris dans le bit à la position pos la valeur bool*/
    int pos_bit;
    int res;
    int pos_bit_invert;
    if(bool != 0){
        pos_bit = 1 << pos;
        res = x | pos_bit ;
    }else
    {
        pos_bit_invert = ~(1 << pos);
        res = x & pos_bit_invert;
    }
    return res;
}
/**/

/**/

int longueur(int x){
    int cpt = 0;
    while(x > 0){
        x = x >> 1;
        cpt ++;
    }
    return cpt;
}

void enBinaire(int x){ /* Ecriture sur 4 bits*/
    int i = longueur(x);
    while(i >= 0){
        printf("%d",getBit(x,i));   
        i--;
    }
}

/**/
int multiplication(int a, int b){ /*  */
    int i ;
    int sum = 0;

    for(i=0;i<longueur(a);i++){
        if(getBit(a,i) == 1){
            sum = sum + (b << i);
        }
    }
    return sum;
}
 /**/

void division(int a, int b){
    int i;
    int q = 0;
    int r = a >> (longueur(a) - 1);

    printf("%i\n",longueur(a));
    
    for(i=longueur(a)-1; i>=0; i--){

	    printf("Combien de fois ");
	    enBinaire(b);
	    printf(" tient il dans ");
	    enBinaire(r);
	    printf(" ? ");
		    
	    
	    if(b <= r){
		    printf("1 fois\n");
		    q = (q << 1) + 1;
		    r = r - b;
	    }else{
		    printf("0 fois\n");
		    q = (q << 1) + 0;
	    }

	    printf("Reste : %d , quotient :%d\n", r, q);
	    printf("Je pose %i\n\n",getBit(a,i-1));
	    r = (r << 1) + getBit(a,i-1);
	    

    }

} 

int main(){   
    division(10,2);
    
    return 0;
}
