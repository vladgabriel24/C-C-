#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

bool is_prime(int x){
    
    if(x==0)
        return false;
    
    if(x==1)
        return false;
    
    for(int i=2 ; i<=sqrt(x) ; i++){
        if(x%i==0)
        return false;
    }
    
    return true;
}

void sita_lui_eratostene(int x){
    
//    for(int i=2 ; i<=x ; i++){
//        if(is_prime(i)==true)
//        printf("%d " , i);
//    }
    
    int *v;
    v=calloc(x ,sizeof(int));

    for(int i=2 ; i<=sqrt(x) ; i++){
        // aleg sa merg pana la radical din x , deoarece noi vom parcurge multiplii ai numerelor alese
        // , iar din locurile in care se porneste cu cautatul in spatele (la stanga de rad x) radacinii lui x
        // vor acoperii si numerele din stanga lui radical de x
        // analogie cu verificare nr prim , si faptul ca si acolo mergem pana la radical x (defapt este acelasi principiu)
        // vezi caietul cu notite!!
        if(*(v+i)==0){
            for(int j=2*i ; j<=x ; j=j+i)
                
                // practic alegem sa plecam de la urmatorul multiplu al numarului de plecare ales
                // asta deoarece daca e sa fie marcat ca non prim , se va marca oricum datorita multiplilor numerelor din spate
                // adica daca e sa fie un multiplu de un nr mai mic , acesta va fii patat oricum pt ca de la acel numar mai mic
                // luam toti multiplii
                
                // Adica , pe scurt , plecam de la 2 pana la radical din n , si din numar in numar plecam de la urmatorul multiplu
                // al nr la care suntem (adica de la 2*i) si marcam pana la x , si tot asa pana marcam tot ce trebuie
                *(v+j)=1;
            
                // noi aici de fapt de jucam pe indici , nu pe valorile din vector
                // valorile din vector joaca rolul de fanion in acest caz deoarece ,
                // noi initial alocam dinamic v cu calloc , adica alocam totul cu 0 la casuta
                // acest 0 din casuta ne va spune ca numerul este prim
                // apoi facem parcurgerea de la 2 la radical din x si marcam ce nu e prim , adica punem la casuta 1
                // iar in momentul in care vrem sa afisam sita , vom afisa doar indicii ce au la casuta 0
                // Atentie , noi aici vrem sa afisam indici , deoarece ei sunt "consecutivi" si descriu cel mai bine
                // un sir de nr intregi pozitive

        }
    }

    for(int i=2 ; i<x ; i++){
        // iar la final afisam doar indexul unde ce se afla la el este egal cu 0 , adica nemarcat
        if(*(v+i)==0){
            printf("%d " , i);
        }
    }
}


int main() {
    
    int x=1345672;
    
    clock_t tic=clock();
    
    if(is_prime(x)==true)
        printf("Este prim!\n");
    else if(is_prime(x)==false)
        printf("Nu este prim!\n");
    
    sita_lui_eratostene(x);
    
    clock_t toc=clock();
    
    printf("\nElapsed: %f seconds\n" , (double)(toc-tic)/CLOCKS_PER_SEC);
    
    return 0;
}
