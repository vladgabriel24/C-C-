#include <stdio.h>
#include <stdlib.h>

typedef struct nod{
    
    int x;
    struct nod *next;

}node;

typedef struct coada{
    
    node *first;
    node *last;

}queue;

void enqueue(queue *coada , int x){

    node *nod_nou=malloc(sizeof(node));
    nod_nou->x=x;
    nod_nou->next=NULL;

    if(coada->first==NULL){

        coada->first=nod_nou;
        coada->last=nod_nou;
    }

    coada->last->next=nod_nou;
    coada->last=coada->last->next;
}

void dequeue(queue *coada){

    node *tmp=coada->first;

    coada->first=coada->first->next;

    free(tmp);
}

void afisare(queue *coada){

    node *parcurgere=coada->first;

    while(parcurgere!=NULL){
        
        printf("%d" , parcurgere->x);
        parcurgere=parcurgere->next;
        
    }
}

int main(){

    queue *coada=malloc(sizeof(queue));
    coada->first=NULL;
    coada->last=NULL;
    
    return 0;
}