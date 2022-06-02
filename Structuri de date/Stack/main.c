#include <stdio.h>
#include <stdlib.h>

struct nod{

    int x;
    struct nod *next;

};

typedef struct nod node;

node *creare_nod(int x){

    node *nod_nou=malloc(sizeof(node));

    nod_nou->x=x;

    nod_nou->next=NULL;

    return nod_nou;
}

node *push(node *stack , int x){

    node *nod_nou=creare_nod(x);

    if(stack==NULL){

        stack=nod_nou;

        return stack;
    }

    node *parcurgere=stack;
    while(parcurgere->next!=NULL)
    parcurgere=parcurgere->next;

    parcurgere->next=nod_nou;

    return stack;
}

node *pop(node *stack){

    if(stack==NULL)
    exit(0);

    if(stack->next==NULL){

    printf("%d " , stack->x);
    return NULL;
    }

    node *parcurgere=stack;
    while((parcurgere->next)->next!=NULL)
    parcurgere=parcurgere->next;

    printf("%d " , (parcurgere->next)->x);

    node *tmp=parcurgere->next;

    parcurgere->next=NULL;

    free(tmp);

    return stack;

}

void peek(node *stack){

    node *parcurgere=stack;

    while(parcurgere->next!=NULL)
    parcurgere=parcurgere->next;

    printf("%d " , parcurgere->x);

}

void afisare_stiva(node *stack){

    node *parcurgere=stack;
    while(parcurgere!=NULL){

    printf("%d " , parcurgere->x);    
    parcurgere=parcurgere->next;

    }
}

int main(){

    node *stack=NULL;


    stack=push(stack , 2);
    stack=push(stack , 3);
    stack=push(stack , 4);
    stack=push(stack , 5);
    stack=push(stack , 6);

    //stack=pop(stack);

    printf("\n");
    afisare_stiva(stack);
    printf("\n");
    peek(stack);


    return 0;
}