#include <stdio.h>
#include <stdlib.h>

struct nod{
  
    int x;
    struct nod *stanga;
    struct nod *dreapta;
};

typedef struct nod Tree;

Tree *creare_nod(int x){

    Tree *nod_nou=malloc(sizeof(Tree));

    nod_nou->x=x;

    nod_nou->stanga=NULL;
    nod_nou->dreapta=NULL;

    return nod_nou;
}

Tree *inserare_nod(Tree *arbore , int x){

    if(arbore==NULL)
    return creare_nod(x);

    if( x < arbore->x )
    arbore->stanga=inserare_nod(arbore->stanga , x);
    else if ( x >= arbore->x )
    arbore->dreapta=inserare_nod(arbore->dreapta , x);

    return arbore;

}

Tree *minim(Tree *arbore){

    Tree *parcurgere=arbore;
    while(parcurgere->stanga!=NULL)
    parcurgere=parcurgere->stanga;

    return parcurgere;

}

Tree *maxim(Tree *arbore){

    Tree *parcurgere=arbore;
    while(parcurgere->dreapta!=NULL)
    parcurgere=parcurgere->dreapta;

    return parcurgere;

}

Tree *stergere_nod(Tree *arbore , int x){

    if(arbore==NULL)
    return NULL;

    Tree *parcurgere=arbore;
    Tree *nod_anterior;

    while(parcurgere->x!=x){

        nod_anterior=parcurgere;

        if( x < parcurgere->x )
        parcurgere=parcurgere->stanga;
        else if ( x > parcurgere->x )
        parcurgere=parcurgere->dreapta;

    }

    if((parcurgere->stanga==NULL)&&(parcurgere->dreapta==NULL)){

        Tree *tmp=parcurgere;

        if(parcurgere->x < nod_anterior->x )
        nod_anterior->stanga=NULL;
        else if (parcurgere->x > nod_anterior->x)
        nod_anterior->dreapta=NULL;

        free(tmp);

        return arbore;

    }else
    if((parcurgere->stanga!=NULL)&&(parcurgere->dreapta==NULL)){

        Tree *tmp=parcurgere;

        if(parcurgere->x < nod_anterior->x )
        nod_anterior->stanga=parcurgere->stanga;
        else if (parcurgere->x > nod_anterior->x)
        nod_anterior->dreapta=parcurgere->stanga;

        free(tmp);

        return arbore;
    }else
    if((parcurgere->stanga==NULL)&&(parcurgere->dreapta!=NULL)){

        Tree *tmp=parcurgere;

        if(parcurgere->x < nod_anterior->x )
        nod_anterior->stanga=parcurgere->dreapta;
        else if (parcurgere->x > nod_anterior->x)
        nod_anterior->dreapta=parcurgere->dreapta;

        free(tmp);

        return arbore;
    }
    else
    if((parcurgere->stanga!=NULL)&&(parcurgere->dreapta!=NULL)){

        Tree *tmp=minim(parcurgere->dreapta);

        parcurgere->x=tmp->x;

        parcurgere->dreapta=stergere_nod(parcurgere->dreapta , tmp->x);

        // free(tmp);  fara free deoarece noi deja stergem ce e la tmp (cand stergem nodul cu reapelarea) 
        // si va da eroare cand vrem sa dam free

        return arbore;
    }

    return arbore;
}

void afisare_inordine(Tree *arbore){

    if(arbore==NULL)
    return;

    afisare_inordine(arbore->stanga);
    printf("%d " , arbore->x);
    afisare_inordine(arbore->dreapta);

}

void afisare_pe_nivele(Tree *arbore , int nivel){

    if(arbore==NULL)
    return;

    if(nivel==1)
    printf("%d " , arbore->x);

    afisare_pe_nivele(arbore->stanga ,nivel-1);
    afisare_pe_nivele(arbore->dreapta , nivel-1);

}

void adancime(Tree *arbore , int *depth , int nivel){

    if(arbore==NULL)
    return;

    if((arbore->stanga==NULL)&&(arbore->dreapta==NULL)){

        if(nivel >= *depth)
        *depth=nivel;


    }

    adancime(arbore->stanga , depth , nivel+1);
    adancime(arbore->dreapta , depth , nivel+1);

}

int inaltime_nod(Tree *arbore , int x ,  int nivel){

    Tree *parcurgere=arbore;
    int drum=1;
    while(parcurgere->x!=x){

        if( x < parcurgere->x){
            drum++;
            parcurgere=parcurgere->stanga;
        }
        else if (x > parcurgere->x){
            drum++;
            parcurgere=parcurgere->dreapta;
        }


    }

    printf("\n%d" , drum);
    int inaltime;
    inaltime=nivel-drum;

    return inaltime;

    // daca se voia adancime dadeam return doar la nivel
}

void afisare_preordine(Tree *arbore){

    if(arbore==NULL)
    return;

    printf("%d " , arbore->x);
    afisare_preordine(arbore->stanga);
    afisare_preordine(arbore->dreapta);

}

void afisare_postordine(Tree *arbore , int *postordine , int *index){

    if(arbore==NULL)
    return;

    afisare_postordine(arbore->stanga , postordine , index);
    afisare_postordine(arbore->dreapta , postordine , index);
    printf("%d " , arbore->x);
    *(postordine+(*index))=arbore->x;
    (*index)++;
}

void afisare_frunze(Tree *arbore){

    if(arbore==NULL)
    return;

    if((arbore->stanga==NULL)&&(arbore->dreapta==NULL))
    printf("%d " , arbore->x);

    afisare_frunze(arbore->stanga);
    afisare_frunze(arbore->dreapta);

}

void nr_noduri(Tree *arbore , int *x){

    if(arbore==NULL)
    return;

    (*x)++;
    nr_noduri(arbore->stanga , x);
    nr_noduri(arbore->dreapta , x);

}

int succesor_postordine(int *postordine , int x){


    int index=0;
    while(*(postordine+index)!=x)
    index++;

    return *(postordine+(index+1)); // si predecesorul este la index-1


}

Tree *inserare_nod_inversat(Tree *arbore , int x){

    if(arbore==NULL)
    return creare_nod(x);

    if( x < arbore->x )
    arbore->dreapta=inserare_nod(arbore->dreapta , x);
    else if ( x >= arbore->x )
    arbore->stanga=inserare_nod(arbore->stanga , x);

    return arbore;
}

void inversare_arbore(Tree *arbore , Tree **arbore_inversat){

    if(arbore==NULL)
    return;

    *arbore_inversat=inserare_nod_inversat(*arbore_inversat , arbore->x);

    inversare_arbore(arbore->stanga , arbore_inversat);
    inversare_arbore(arbore->dreapta , arbore_inversat);

}

int main(){

    Tree *arbore=NULL;
    Tree *min;
    int depth=0;
    int nr=0;
    int index_postordine=0;
    int index_preordine=0;
    int index_inordine=0;

    Tree *arbore_inversat=NULL;


    arbore=inserare_nod(arbore ,50);
    arbore=inserare_nod(arbore ,60);
    arbore=inserare_nod(arbore ,40);
    arbore=inserare_nod(arbore ,30);
    arbore=inserare_nod(arbore ,45);
    arbore=inserare_nod(arbore ,44);
    arbore=inserare_nod(arbore ,33);
    arbore=inserare_nod(arbore ,55);

    nr_noduri(arbore , &nr);

    int *inordine=malloc(nr*sizeof(int));
    int *preordine=malloc(nr*sizeof(int));
    int *postordine=malloc(nr*sizeof(int));

    afisare_inordine(arbore);
    printf("\n");

    afisare_pe_nivele(arbore , 1);

    adancime(arbore , &depth , 1);
    printf("%d" , depth);

    printf("\n%d\n" , inaltime_nod(arbore , 45 , depth));

    nr_noduri(arbore , &nr);

    afisare_postordine(arbore , postordine , &index_postordine);
    printf("\n%d" , succesor_postordine(postordine , 60));

    inversare_arbore(arbore , &arbore_inversat);
    printf("\n");
    afisare_preordine(arbore_inversat);

    return 0;
}