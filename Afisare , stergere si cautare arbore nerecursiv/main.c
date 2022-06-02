#include <stdio.h>
#include <stdlib.h>

struct nod_arbore{

    int x;
    struct nod_arbore *stanga;
    struct nod_arbore *dreapta;

};

struct nod_stiva{

    struct nod_arbore *arbore; //o stiva ce stocheaza adrese ale nodurilor din arbore
    struct nod_stiva *next;

};

typedef struct nod_arbore tree;
typedef struct nod_stiva stack;

tree *creare_nod_arbore(int x){

    tree *nod_nou=malloc(sizeof(tree));

    nod_nou->x=x;

    nod_nou->stanga=NULL;
    nod_nou->dreapta=NULL;

    return nod_nou;
}

stack *creare_nod_stiva(tree *arbore){

    stack *nod_nou=malloc(sizeof(stack));

    nod_nou->arbore=arbore;

    nod_nou->next=NULL;

    return nod_nou;

}

tree *inserare_nod(tree *arbore , int x){


    if(arbore==NULL)
    return creare_nod_arbore(x);

    if( x < arbore->x )
    arbore->stanga=inserare_nod(arbore->stanga , x);
    else if ( x >= arbore->x )
    arbore->dreapta=inserare_nod(arbore->dreapta , x);

    return arbore;
}

void afisare_inordine(tree *arbore){

    if(arbore==NULL)
    return ;

    afisare_inordine(arbore->stanga);
    printf("%d " , arbore->x);
    afisare_inordine(arbore->dreapta);

}

stack *push(stack *stiva , tree *arbore , stack **ultim){


    if(stiva==NULL){

        stiva=creare_nod_stiva(arbore);

        *ultim=stiva;

        return stiva;
        
    }

    stack *parcurgere=stiva;

    while(parcurgere->next!=NULL)
    parcurgere=parcurgere->next;

    parcurgere->next=creare_nod_stiva(arbore);
    *ultim=parcurgere->next;

    return stiva;
}

stack *pop(stack *stiva , stack **ultim){

    if(stiva==NULL)
    return NULL;

    if(stiva->next==NULL){

        printf("%d " , (stiva->arbore)->x);
        *ultim=NULL;

        return NULL;
    }

    stack *parcurgere=stiva;

    while((parcurgere->next)->next!=NULL)
    parcurgere=parcurgere->next;

    *ultim=parcurgere;

    printf("%d " , ((parcurgere->next)->arbore)->x );

    stack *tmp=parcurgere->next;
    parcurgere->next=NULL;
    
    free(tmp);

    return stiva;
}

void afisare_stiva(stack *stiva){

    if(stiva==NULL){

        printf("Stiva este goala!");

        return ;
    }

    stack *parcurgere=stiva;
    while(parcurgere!=NULL){

        printf("%d " , (parcurgere->arbore)->x);

        parcurgere=parcurgere->next;

    }

}

void parcurgere_nerecrusiva(tree *arbore , stack *stiva){

    stack *ultim;
    tree *parcurgere=arbore;
    tree *nod_anterior;

    

        
        stiva=push(stiva , parcurgere , &ultim);

        stiva=pop(stiva , &ultim);
            
    

}

int main(){

    tree *arbore=NULL;
    stack *stiva=NULL;
    stack *ultim;

    arbore=inserare_nod(arbore , 50);
    arbore=inserare_nod(arbore , 60);
    arbore=inserare_nod(arbore , 70);
    arbore=inserare_nod(arbore , 40);
    arbore=inserare_nod(arbore , 30);
    arbore=inserare_nod(arbore , 45);
    arbore=inserare_nod(arbore , 55);
    
    // afisare_inordine(arbore);
    // printf("\n");

    // stiva=push(stiva , arbore->stanga , &ultim);
    // stiva=push(stiva , arbore->dreapta , &ultim);
    // afisare_stiva(stiva);

    // stiva=pop(stiva , &ultim);
    // afisare_stiva(stiva);

    parcurgere_nerecrusiva(arbore ,stiva);

    return 0;
}