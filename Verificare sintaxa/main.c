#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Verificare sintaxa:

Trebuie ca paranteza deschisa sa aiba paranteza aferenta care inchide
Deci conteaza ordinea parantezelor: 
Paranteza deschisa se inchide cu prima paranteza inchisa intalnita

Daca deschid mai multe deodata , prima paranteza inchisa va corespunde celei mai "adanci" paranteze , 
urmatoarea va corespunde celei de dinainte si tot asa

Practic , trebuie sa fie un nr egal de paranteze inchise si deschise

Date de intrare:

Sir de caractere de dimensiune arbitrara , cu spatii incluse , totul citit pe o linie

Deci citim pana la EOF 
Citim cu spatii inclusiv

Vom lucra cu liste de tipul "stiva". Principiul LIFO

Abordam problema asa:
Principial , o acolada deschisa isi va astepta acolada inchisa pt a incapsula ceea ce scrie intre ele.
Bineinteles , daca o instructiune are ca prima acolada , una deschisa e clar greseala din start.

Vom ignora complet toate datele de intrare si ne vom baza pe o lista cu toate acoladele din
stringul de intrare puse ordonat , dupa indice.

Adica :      { { { } } 
Cu indice:   1 3 5 9 10

Deci daca ne gandim ca punem acoladele '{' precum un trun de pese lego puse efectiv una peste alta ,
prima acolada '}' pusa pe turn va elimina din turn ultima piesa pusa ('{') si tot asa , 
adica Last in (ultima acolada pusa in turn) First out(este prima care iese in momentul in care se intalneste acolada '}')

Deci o acolada de tip } va da pop la ultima acolada pusa de tip { si tot asa pana cand :
-daca ramane lista goala e corecta sintaxa
-daca dupa o serie de pop-uri raman {{{ nu este corecta si printam toti indicii unde se afla aceste acolade
-daca sunt mai multe pop uri decat push uri(adica am scos toate {{ si vrem sa bagam doar }) 
sau pur si simplu se incepe cu un pop(adica prima acolada introdusa este })
vom printa indicele prima=ei acolade '}' incercate si oprim programul

Eu incercasem cu coada , dar abia acum mi am dat seama de la exemplul 2 ca totul se bazeaza pe LIFO nu LILO

*/

//Implementare stiva:

typedef struct nod{

    char acolada;
    int indice_acolada;
    struct nod *next;
}stack;

stack *push(stack *head , char acolada_primita , int indice){

    if(head==NULL){

        head=malloc(sizeof(stack));
        if(head==NULL){
            printf("Nu se mai pot aloca noduri!");
            exit(0);
        }

        head->acolada=acolada_primita;
        head->indice_acolada=indice;

        head->next=NULL;

        return head;
    }


    stack *nod_nou=malloc(sizeof(stack));
    if(nod_nou==NULL){
        printf("Nu se mai pot aloca noduri!");
        exit(0);
    }

        nod_nou->acolada=acolada_primita;
        nod_nou->indice_acolada=indice;

        nod_nou->next=NULL;

        return nod_nou;
}

stack *pop(stack *head , int i){

    if(head==NULL){
        printf("Incorect!");
        printf("%d" , ++i);
        exit(0);
    }

    if(head->next==NULL)
    return NULL;
    
    stack *parcurgere=head;

    while((parcurgere->next)->next!=NULL){
        printf("%c" , parcurgere->acolada);
        printf("%d" , parcurgere->indice_acolada);

        parcurgere=parcurgere->next;
    }

    parcurgere->next=NULL;

    return head;
}

void afisare_stiva(stack *head){

    if(head==NULL){
        printf("Corect!");
        return ;
    }

    stack *parcurgere=head;

    while(parcurgere!=NULL){

        printf("Incorect!");
        printf("%d" , ++parcurgere->indice_acolada);

        parcurgere=parcurgere->next;
    }
}

//functie citire sir de dimensiune necunoscuta cu tot cu spatii
char * citiresir(){
    
    char *sir;
    int i=0;
    char caracter_introdus;
    char *buffer;
    
    sir=(char *)malloc(sizeof(char));
    if(sir==NULL)
    printf("A esuat alocarea!");
    
    buffer=(char *)malloc(sizeof(char));
    if(buffer==NULL)
    printf("Eroare la alocarea bufferului extern");
    
    scanf("%c" , buffer);
    
    //daca prima citire este un "enter" atunci eliberam buffer-ul altfel bagam litera citia in primul element din stringul de caractere , crestem i ul si apoi mergem mai departe
    if((*buffer=='\n')||(*buffer==EOF)){
    free(buffer);
    }else{
    *sir=*buffer;
    i++;
    }
    
    
    do{
        
        scanf("%c" , &caracter_introdus);
        
        if((caracter_introdus!='\n')&&(caracter_introdus!=EOF)){
            
            *(sir+i)=caracter_introdus;
            i++;
            sir=(char *)realloc(sir , i+sizeof(char));
        }
        
    }while((caracter_introdus!='\n')&&(caracter_introdus!=EOF));
    *(sir+i)='\0';
    
    return sir;
}

int main(){

    stack *stiva=NULL;
    stack *parcurgere=NULL;

    char *sir; //sirul este itrodus corect

    sir=citiresir();

    
        for(int i=0 ; i<strlen(sir) ; i++){
        
            if(*(sir+i)=='{'){
                if(stiva==NULL){
                stiva=push(stiva , *(sir+i) , i);
                parcurgere=stiva;
                }else{

                parcurgere->next=push(stiva , *(sir+i) , i);
                parcurgere=parcurgere->next;
                }
            }else if(*(sir+i)=='}'){
                //cand dam de o paranteza } vom da pop la stiva

                stiva=pop(stiva , i);
            }
        }

    afisare_stiva(stiva);

    return 0;
}