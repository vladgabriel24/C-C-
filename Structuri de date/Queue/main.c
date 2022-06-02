#include <stdio.h>
#include <stdlib.h>

struct nod{

    int x;
    struct nod *next;
};

struct queue{

    struct nod *head;
    struct nod *tail;
};

typedef struct nod node;

typedef struct queue queue;

node *creare_nod(int x){

    node *nod_nou=malloc(sizeof(node));

    nod_nou->x=x;

    nod_nou->next=NULL;

    return nod_nou;

}

void enqueue(queue *coada , int x){

    node *nod_nou=creare_nod(x);

    if(coada->head==NULL){

        coada->head=nod_nou;
        coada->tail=nod_nou;
    }else{

        (coada->tail)->next=nod_nou;
        coada->tail=(coada->tail)->next;
    }
}

void dequeue(queue *coada){

    node *tmp=coada->head;

    coada->head=(coada->head)->next;

    free(tmp);
}

void afisare_coada(node *head){

    node *parcurgere=head;
    while(parcurgere!=NULL){

    printf("%d " , parcurgere->x);

    parcurgere=parcurgere->next;

    }
}

int main(){

    queue *coada=malloc(sizeof(queue));
    coada->head=NULL;
    coada->tail=NULL;


    enqueue(coada , 2);
    enqueue(coada , 3);
    enqueue(coada , 4);
    enqueue(coada , 5);
    enqueue(coada , 6);

    dequeue(coada);
    dequeue(coada);
    dequeue(coada);
    dequeue(coada);
    dequeue(coada);
    

    afisare_coada(coada->head);

    return 0;
}