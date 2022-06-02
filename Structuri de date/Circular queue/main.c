#include <stdio.h>
#include <stdlib.h>

struct nod{

    int x;
    struct nod *next;
};

struct coada{

    struct nod *prim;
    struct nod *ultim;
};

typedef struct nod node;
typedef struct coada queue;

void enqueue(queue *coada , int x){

    if(coada->prim==NULL){

        //conditia de prim nod este coada->prim=coada->ultim si pe aceasta o sa o folosim la:
        //la citire ca in cazul in care avem doar un nod sa nu fie infinite loop , deci punem ca conditie coada->prim=coada->ultim si exit(0)
        //la dequeue , in momentul in care ramane un nod , returnam NULL ca la liste simplu inlantuite

        node *nod_nou=malloc(sizeof(node));

        nod_nou->x=x;

        //conditia de prim nod de care ziceam
        coada->prim=nod_nou;

        coada->ultim=nod_nou;

    }else{

        node *nod_nou=malloc(sizeof(node));

        nod_nou->x=x;

        //adaugam la final
        (coada->ultim)->next=nod_nou;

        //mutam ultimul la noul nod
        coada->ultim=(coada->ultim)->next;

        //nextul ultimului il conectam la adresa primului nod coada->prim
        (coada->ultim)->next=coada->prim;
    }

}

void dequeue(queue *coada){

    //conditia de prim nod de care ziceam
    if(coada->prim==coada->ultim){
        exit(0);  //sau return ;
    }

    //retinem capul
    node *tmp=coada->prim;

    //facem legatura cu nodul urmator capului actual
    (coada->ultim)->next=(coada->prim)->next;

    //mutam capul la nodul urmator
    coada->prim=(coada->prim)->next;


    //sau facem legatura ultimului nod la inceput la final , cand am mutat si capul la capul nou
    //(coada->ultim)->next=coada->prim;

    //eliberam din memorie capul vechi pe care l am retinut
    free(tmp);
}

void afisare_lista_circulara(queue *coada){

    node *parcurgere=coada->prim;

    //conditia de prim nod de care ziceam
    if(parcurgere==coada->ultim){
        printf("%d" , parcurgere->x);

        return ; //sau exit(0);
    }

    //facem cu un do while deoarece vrem sa dam skip la verificarea primei iteratii deoarece va fii falsa daca nu dam skip si s ar iesii din start din while ul simplu si
    //din moment ce parcurgere il initiem noi la coada->prim , iar dupa ce s-a efectuat o iteratie
    //do while ul va astepta urmatorul moment cand parcurgere va fii egal cu coada prim
    //(noi primului moment i am dat skip tocmai pt a putea parcurge si a ne putea oprii dupa la urmatorul moment cand parcurgere=prim , adica dupa ce am parcurs toata coada practic)
    do{

        printf("%d " , parcurgere->x);
        parcurgere=parcurgere->next;


    }while(parcurgere!=coada->prim);
}

int main(){

    queue *coada=malloc(sizeof(queue));
    coada->prim=NULL;
    coada->ultim=NULL;

    enqueue(coada , 2);
    enqueue(coada , 2);
    enqueue(coada , 2);
    enqueue(coada , 2);
    enqueue(coada , 2);

    // dequeue(coada);
    // dequeue(coada);
    // dequeue(coada);
    // dequeue(coada);
    // dequeue(coada);
    
    afisare_lista_circulara(coada);

    return 0;
}