#include <stdio.h>
#include <stdlib.h>

struct nod{

    int x;
    struct nod *stanga;
    struct nod *dreapta;
};

typedef struct nod node;

node *creare_nod(int x){

    node *nod_nou=malloc(sizeof(node));

    nod_nou->x=x;

    nod_nou->stanga=NULL;
    nod_nou->dreapta=NULL;

    return nod_nou;
}

node *populare_arbore(node *arbore , int x){

    if(arbore==NULL)
    return creare_nod(x);

    if( x < arbore->x )
    arbore->stanga=populare_arbore(arbore->stanga , x);
    else
    arbore->dreapta=populare_arbore(arbore->dreapta , x);

    return arbore;
}

node *minim(node *arbore ){

   node *min=arbore;
   while(min->stanga!=NULL)
    min=min->stanga;
   
   return min;

}

node *stergere_arbore(node *arbore , int x){

    
    if(arbore->x != x){
        if ( x < arbore->x )
        arbore->stanga=stergere_arbore(arbore->stanga , x);
        else
        arbore->dreapta=stergere_arbore(arbore->dreapta , x);
    }

    if(arbore->x==x){

        if(arbore->dreapta==NULL){

            node *tmp=arbore;

            arbore=arbore->stanga;

            free(tmp);

            return arbore;
        }else if(arbore->stanga==NULL){

            node *tmp=arbore;

            arbore=arbore->dreapta;

            free(tmp);

            return arbore;

        }else if((arbore->stanga==NULL)&&(arbore->dreapta==NULL)){

            free(arbore);

            return NULL;
        }else{

            node *min=minim(arbore->dreapta);
            node *tmp=arbore;
            
            free(tmp);

            return min;

        }
    }

    return arbore;
}

void afisare_inordine(node *arbore){

    if(arbore==NULL)
    return ;

    afisare_inordine(arbore->stanga);
    printf("%d " , arbore->x);
    afisare_inordine(arbore->dreapta);
}

int main(){

    node *arbore=NULL;
    node *min;

    arbore=populare_arbore(arbore , 50);
    arbore=populare_arbore(arbore , 70);
    arbore=populare_arbore(arbore , 40);
    arbore=populare_arbore(arbore , 80);
    arbore=populare_arbore(arbore , 65);
    arbore=populare_arbore(arbore , 44);
    arbore=populare_arbore(arbore , 43);
    arbore=populare_arbore(arbore , 30);
    arbore=populare_arbore(arbore , 20);
    arbore=populare_arbore(arbore , 33);

    arbore=stergere_arbore(arbore , 30);

    afisare_inordine(arbore);
    

    return 0;
}