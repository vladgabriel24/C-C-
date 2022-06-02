#include <stdio.h>
#include <stdlib.h>

struct nod{

    int x;
    struct nod *stanga;
    struct nod *dreapta;
};

typedef struct nod nod;

nod *creare_nod(int x){

    nod *nod_nou=malloc(sizeof(nod));

    nod_nou->x=x;

    nod_nou->stanga=NULL;
    nod_nou->dreapta=NULL;

    return nod_nou;
}

nod *inserare_nod(nod *arbore , int x){

    if(arbore==NULL)
    return creare_nod(x);

    if( x < arbore->x )
    arbore->stanga=inserare_nod(arbore->stanga , x);
    else if( x >= arbore->x)
    arbore->dreapta=inserare_nod(arbore->dreapta , x);

    return arbore;
}

void afisare_inordine(nod *arbore){

    if(arbore==NULL)
    return ;

    afisare_inordine(arbore->stanga);
    printf("%d " , arbore->x);
    afisare_inordine(arbore->dreapta);

}

void afisare_postordine(nod *arbore){

    if(arbore==NULL)
    return ;

    afisare_postordine(arbore->stanga);
    afisare_postordine(arbore->dreapta);
    printf("%d " , arbore->x);
}

void afisare_preordine(nod *arbore){

    if(arbore==NULL)
    return ;

    printf("%d " , arbore->x);
    afisare_preordine(arbore->stanga);
    afisare_preordine(arbore->dreapta);
}

int main(){

    nod *arbore=NULL;

    arbore=inserare_nod(arbore , 20);
    arbore=inserare_nod(arbore , 30);
    arbore=inserare_nod(arbore , 40);
    arbore=inserare_nod(arbore , 50);
    arbore=inserare_nod(arbore , 10);
    arbore=inserare_nod(arbore , 15);
    arbore=inserare_nod(arbore , 5);
    arbore=inserare_nod(arbore , 2);

    printf("\nAfisare inordine: ");
    afisare_inordine(arbore);

    printf("\nAfisare preordine: ");
    afisare_preordine(arbore);

    printf("\nAfisare postordine: ");
    afisare_postordine(arbore);


    return 0;
}