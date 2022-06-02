#include <stdio.h>
#include <stdlib.h>

struct nod_arbore{

    int x;
    int multiplicitate;
    struct nod_arbore *stanga;
    struct nod_arbore *dreapta;

};

struct hash_table{

    struct nod_arbore *arbore;
    int multiplicitate;
    int indicator; // 0 - good   ,  1 - average  ,  2- bad

};

typedef struct nod_arbore Tree;
typedef struct hash_table Hash;

Tree *creare_nod(int x){

    Tree *nod_nou=malloc(sizeof(Tree));

    nod_nou->x=x;
    nod_nou->multiplicitate=1;

    nod_nou->stanga=NULL;
    nod_nou->dreapta=NULL;

    return nod_nou;

}

Tree *inserare_nod(Tree *arbore , int x){

    if(arbore==NULL)
    return creare_nod(x);

    if( x < arbore-> x)
    arbore->stanga=inserare_nod(arbore->stanga , x);
    else if ( x > arbore->x )
    arbore->dreapta=inserare_nod(arbore->dreapta , x);
    else if( x == arbore->x )
    arbore->multiplicitate=arbore->multiplicitate+1;

    return arbore;
}

Hash *inserare_date(Hash *tabel , int t){

    int n;
    int x;

    for(int i=0 ; i<t ; i++){

        scanf("%d" , &n);
        scanf("%d" , &x);

        (tabel+i)->multiplicitate=x;
        (tabel+i)->arbore=NULL;

        int valoare;
        for(int j=0 ; j<n ; j++){

            scanf("%d" , &valoare);
            (tabel+i)->arbore=inserare_nod((tabel+i)->arbore , valoare);

        }
    }

    return tabel;
}

void parcurgere_arbore(Tree *arbore , int *x){

    if(arbore==NULL)
    return;

    if(arbore->multiplicitate == 1)
    (*x)++;

    parcurgere_arbore(arbore->stanga , x);
    parcurgere_arbore(arbore->dreapta , x);

}

int numere_distincte(Tree *arbore){

    int numere_distincte=0;
    parcurgere_arbore(arbore , &numere_distincte);

    return numere_distincte;

}

Hash *constatare(Hash *tabel , int t){


    for(int i=0 ; i<t ; i++){

        if( numere_distincte((tabel+i)->arbore) == (tabel+i)->multiplicitate )
        (tabel+i)->indicator=0;
        else if( numere_distincte((tabel+i)->arbore) > (tabel+i)->multiplicitate )
        (tabel+i)->indicator=1;
        else if( numere_distincte((tabel+i)->arbore) < (tabel+i)->multiplicitate )
        (tabel+i)->indicator=2;

    }

    return tabel;
}

void interpretare_indicator(Hash *tabel , int t){

    for(int i=0 ; i<t ; i++){

        if((tabel+i)->indicator==0)
        printf("Good");
        else if((tabel+i)->indicator==1)
        printf("Average");
        else if((tabel+i)->indicator==2)
        printf("Bad");

        printf("\n");

    }

}

void afisare_inordine(Tree *arbore){

    if(arbore==NULL)
    return;

    afisare_inordine(arbore->stanga);
    printf("%d " , arbore->x);
    printf("%d\n\n" , arbore->multiplicitate);
    afisare_inordine(arbore->dreapta);

}

int main(){

    Hash *tabel;

    int t , n , x;
    scanf("%d" , &t);

    tabel=(Hash *)malloc(t*sizeof(Hash));

    tabel=inserare_date(tabel ,t);

    tabel=constatare(tabel ,t);

    interpretare_indicator(tabel , t);

    return 0;
}