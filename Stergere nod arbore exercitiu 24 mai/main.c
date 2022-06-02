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

nod *populare_arbore(nod *arbore , int x){

    if(arbore==NULL){

        arbore=creare_nod(x);
        return arbore;
    }

    if(x<arbore->x)
    arbore->stanga=populare_arbore(arbore->stanga , x);
    else if(x>=arbore->x)
    arbore->dreapta=populare_arbore(arbore->dreapta , x);

    return arbore;
}

void afisare_inordine(nod *arbore){

    if(arbore==NULL)
    return ;

    afisare_inordine(arbore->stanga);
    printf("%d " , arbore->x);
    afisare_inordine(arbore->dreapta);
}

void minim_subarbore(nod *arbore , int *min , nod **nod_minim){

    if(arbore==NULL)
    return ;

    minim_subarbore(arbore->stanga ,min , nod_minim);
    minim_subarbore(arbore->dreapta ,min , nod_minim);

    if(*min==0){

        *min=arbore->x;
        *nod_minim=arbore;

    }else

    if(arbore->x < *min){

        *min=arbore->x;
        *nod_minim=arbore;

    }
}

nod *stergere_nod(nod *arbore , int x){

    nod *parcurgere=arbore;
    nod *nod_anterior;

    if(arbore==NULL)
    return NULL;

    while(parcurgere->x!=x){

        nod_anterior=parcurgere;

        if(x<parcurgere->x)
        parcurgere=parcurgere->stanga;
        else
        parcurgere=parcurgere->dreapta;

    }

    // printf("%d " , parcurgere->x);
    // printf("%d \n" , nod_anterior->x);

    if(parcurgere->dreapta==NULL){

        if(parcurgere->x < nod_anterior->x)
        nod_anterior->stanga=parcurgere->stanga;
        else
        nod_anterior->dreapta=parcurgere->stanga;
            
    }else{

        nod *nod_de_schimbat;
        int min=0;

        minim_subarbore(parcurgere->dreapta , &min , &nod_de_schimbat);

        // printf("\nNodul cu care vreau sa il schimb: %d" , nod_de_schimbat->x); //corect
        // printf("\nNodul pe care vreau sa il schimb: %d" , parcurgere->x); //corect
        // printf("\nNodul anterior celui pe care vreau sa il schimb: %d" , nod_anterior->x); //corect

        nod *anterior_sters=arbore;
        while((anterior_sters->stanga!=nod_de_schimbat)&&(anterior_sters->dreapta!=nod_de_schimbat)){

            if(nod_de_schimbat->x < anterior_sters->x)
            anterior_sters=anterior_sters->stanga;
            else
            anterior_sters=anterior_sters->dreapta;

        }

        //printf("\nNodul anterior celui pe care vreau sa il sterg: %d" , anterior_sters->x); //corect

        if(nod_de_schimbat->x < anterior_sters->x)
        anterior_sters->stanga=NULL;
        else
        anterior_sters->dreapta=NULL;

        nod_de_schimbat->stanga=parcurgere->stanga;
        nod_de_schimbat->dreapta=parcurgere->dreapta;

        if(parcurgere->x < nod_anterior->x)
        nod_anterior->stanga=nod_de_schimbat;
        else
        nod_anterior->dreapta=nod_de_schimbat;
            
    }
    
    return arbore;
}

int main(){

    nod *arbore=NULL;
    int min=0;
    nod *nod_minim=NULL;
    nod *minimal;

    arbore=populare_arbore(arbore , 50);
    arbore=populare_arbore(arbore , 60);
    arbore=populare_arbore(arbore , 40);
    arbore=populare_arbore(arbore , 70);
    arbore=populare_arbore(arbore , 55);
    arbore=populare_arbore(arbore , 45);
    arbore=populare_arbore(arbore , 30);
    arbore=populare_arbore(arbore , 44);
    arbore=populare_arbore(arbore , 46);
    arbore=populare_arbore(arbore , 47);
    arbore=populare_arbore(arbore , 71);
    arbore=populare_arbore(arbore , 69);
    arbore=populare_arbore(arbore , 68);
    
    afisare_inordine(arbore);

    arbore=stergere_nod(arbore , 40);
    printf("\n");
    afisare_inordine(arbore);
    
    return 0;
}