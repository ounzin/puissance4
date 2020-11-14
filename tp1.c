#include <stdio.h>
#include <unistd.h>

void unACent(){ /* Question 1.3*/
    int cpt =1;
    int i;
    int j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%d\t",cpt);
            if(cpt%10==0){
                printf("\n");
            }
            cpt++;       
        }
    }
  
}
void vider_buffer(FILE* f){
int c;
while((c=fgetc(f)) != '\n' && c != EOF);
}

void nombreBorne(int inf, int sup){
    int nbr;  
    do{
    printf("Veuillez saisir un entier \n");
    scanf("%d",&nbr);
    vider_buffer(stdin);
    } while(nbr<inf || nbr >sup);
    if(nbr>inf && nbr<sup){
        printf("%d",nbr);
    }
}

void FtoC(int f){
    printf("celsius = %d", 5*(f-32)/9);
}

void CtoF(double c){
    printf("%.2f \n", 9 * c / 5 + 32);
}

void vitesseKmParH(double distance, double temps){
    printf("Vitesse = %2.f km/h", distance/temps);
}

void pyramide(char c, int nombreLigne){
    int i;
    int j;
    for(i=1;i<=nombreLigne;i++){
        for(j=0;j<i;j++){
            fprintf(stdout,"%c\t",c);
        }
        fprintf(stdout,"\n");
    }
}
int estUnEspace(char c){
    switch (c)
    {
    case ' ': 
        return 0;
        break;

    case '\n': 
        return 0;
        break;   

    case '\t':
        return 0;
        break; 
    
    default: return 1;
        break;
    }
}

void mywc(){
   
  int nbrCarac = 0;
    int nbrMot = 0;
    int nbrLigne = 1;
    char caractereActuel = ' ';
    char caracterePrecedent = ' ';
    /**/
        do{
            caracterePrecedent = caractereActuel;
            caractereActuel = (char) fgetc(stdin);
            if(estUnEspace(caracterePrecedent) && !estUnEspace(caractereActuel)){
                nbrMot += 1;
            }
            if (caractereActuel == '\n')
            {
                nbrLigne += 1;
            }
            
            if(caractereActuel != EOF) {
                printf("%c\n",caractereActuel);
                nbrCarac += 1;}
        
        }while(caractereActuel != EOF); /*End of file*/
    
    fprintf(stdout,"Le nombre de caractere est : %d\n\n",nbrCarac);
    fprintf(stdout,"Le nombre de mots est : %d\n\n",nbrMot);
    fprintf(stdout,"Le nombre de lignes est : %d\n\n",nbrLigne);
}

int estPremier(int nombre){
    int i;
    int a = 0;
   if(nombre >= 1){
       for(i=2;i<nombre;i++){
           if(nombre%i == 0){
               a+=1;
           }
       }
       if(a == 0){
           return 0;
       }else{
          return 1;
       }
   }
}

void afficheKPremier(){
    int i = 1;
    int k;
    int cpt = 0;
    fprintf(stdout,"Veuillez entrer un nombre :\t");
    fscanf(stdin,"%d\n",&k);
    vider_buffer(stdin);
    while(cpt <= k){
        if(estPremier(i)==0) {
            fprintf(stdout,"%d \n",i);
             cpt++;  
            }
        i++;
    }
}

int nombreParfait(int nombre){
    int i;
    int som = 0;
    for(i=1 ; i <nombre ; i++){
        if(nombre%i == 0){
            som += i;
        }
    }

    if(som == nombre){
        return 0; /* nombre parfait */
    }else{
        return 1; /* nombre imparfait */
    }
}

void nombresParfaitsEntreBorne(){
    int inf = 1;
    int sup = 0;
    int i;
    while(inf>sup){
        fprintf(stdout,"Veuillez entrer la borne inferieure :\t");
        fscanf(stdin,"%d",&inf);
        vider_buffer(stdin);
    /**/
        fprintf(stdout,"Veuillez entrer la borne superieure :\t");
        fscanf(stdin,"%d",&sup);
        vider_buffer(stdin);
    }
    /**/
    for(i=inf;i<=sup;i++){
        if(nombreParfait(i) == 0){
            fprintf(stdout,"%d\n",i);
        }
    };
}

int estDoublon(int nombre){
    int i;
    int som = 0;
    int prod = 1;
    for(i=1;i<=nombre;i++){
        if(nombre%i == 0){
            som += i;
            prod *= i;
        }
    }
    if(prod%som == 0){
        return 0; /* est un doublon */
    }else{
        return 1; /* n'est pas un doublon */
    }

}

void doublonEntreBornes(){
    int inf = 1;
    int sup = 0;
    int i;
    while(inf>sup){
        fprintf(stdout,"Veuillez entrer la borne inferieure :\t");
        fscanf(stdin,"%d",&inf);
        vider_buffer(stdin);
    /**/
        fprintf(stdout,"Veuillez entrer la borne superieure :\t");
        fscanf(stdin,"%d",&sup);
        vider_buffer(stdin);
    }
    /**/
    for(i=inf;i<=sup;i++){
        if(estDoublon(i)==0){
            fprintf(stdout,"%d\n",i);
        }
    }
}

int miniProgramme(){
    int choix;
    int sous_choix;
    fprintf(stdout,"Bonjour, veuillez choisir une operation dans le menu grace aux chiffres \t\n\n");
    fprintf(stdout,"1. Calculer k premiers nombres entiers \n");
    fprintf(stdout,"2. Nombres parfaits compris entre deux bornes \n");
    fprintf(stdout,"3. Doublons compris entre deux bornes \n");
    fprintf(stdout,"0. Quitter \n\n");
    fscanf(stdin,"%d",&choix);
    vider_buffer(stdin);

    switch (choix)
    {
    case 1:
        afficheKPremier();
        fprintf(stdout,"\n\n");
        fprintf(stdout,"1. Retour au menu\t");
        fprintf(stdout,"2. Fermer programme\n");
        fscanf(stdin,"%d",&sous_choix);
        vider_buffer(stdin);
        switch (sous_choix)
        {
        case 1:
            main();  
        case 2:
            return 0;
        }

    case 2:
        nombresParfaitsEntreBorne();
        fprintf(stdout,"\n\n");
        fprintf(stdout,"1. Retour au menu\t");
        fprintf(stdout,"2. Fermer programme\n");
        fscanf(stdin,"%d",&sous_choix);
        vider_buffer(stdin);
        switch (sous_choix)
        {
        case 1:
            main();  
        case 2:
             return 0;
        }
    case 3:
        doublonEntreBornes();
        fprintf(stdout,"\n\n");
        fprintf(stdout,"1. Retour au menu\t");
        fprintf(stdout,"2. Fermer programme\n");
        fscanf(stdin,"%d",&sous_choix);
        vider_buffer(stdin);
        switch (sous_choix)
        {
        case 1:
            main();  
        case 2:
             return 0;
        }
    case 0:
        return 0;
    }

}
int main(){
    afficheKPremier();
    return 0;
}