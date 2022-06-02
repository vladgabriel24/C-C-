#include <stdio.h>
#include <stdlib.h>


int lungimesir(char s1[]){

    int l=0;

    for(l ; s1[l]!='\0'; l++);

    return l;
}

int main(){

    char sir[100];
    char ch;

    printf("Introduceti sirul:");scanf("%s" , sir);
    printf("Introduceti litera cautata:");scanf(" %c" , &ch);  //ampersant deoarece vr sa bag val la adresa memoriei
                                                              
    /*
    In momentul in care apas enter de la citirea anterioara , in sirul anterior se pune la final \0 
    si dupa compiler ul genereaza caracterul newline pt urmatorul printf si scanf.
    Acel newline este CONSUMAT de scanf("%c") ceea ce ii baga pe gat automat caracterul newline.
    Din acest motiv inainte de %c am pus un whitespace sau newline pt a CONSUMA acest newline inainte sa il intalneasca scanf ul si sa l manance

    Spre deosebire de %c , %s cand este folosit el sterge automat toate whitespace urile si citeste doar literele sau cifrele.
    Din acest motiv , daca vrem sa citim o propozitie sau cv cu tot cu whitespace folosind %s , vom pune similar ca la %c , un whitespace inainte de %s
    pentru a CONSUMA whitespace ul si prin acest fapt el le ignora si nu le mai sterge
    */

   int l=lungimesir(sir);
   int i;
   int k;

   for(i=0 ; i<l ; i++){
       if(sir[i]==ch)
        k=i;
   }

   printf("Ultima aparitie se afla la indexul cu valoarea: ");
   printf("%d" , k);

    return 0;
}