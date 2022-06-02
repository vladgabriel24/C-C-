#include <stdio.h>
#include <stdlib.h>

struct nod{
    int x;
    struct nod *next;
};

struct nod_stiva{
    int x;
    struct nod_stiva *next;
};

typedef struct nod List;
typedef struct nod_stiva Stack;

List *creare_nod(int x){

    List *nod_nou=malloc(sizeof(List));

    nod_nou->x=x;

    nod_nou->next=NULL;

    return nod_nou;

}

Stack *creare_nod_stiva(int x){

    Stack *nod_nou=malloc(sizeof(Stack));

    nod_nou->x=x;

    nod_nou->next=NULL;

    return nod_nou;

}

List *inserare_nod(List *head , int x){

    if(head==NULL)
    return creare_nod(x);

    List *parcurgere=head;
    while(parcurgere->next!=NULL){


        parcurgere=parcurgere->next;
    }

    parcurgere->next=creare_nod(x);

    return head;
}

Stack *inserare_nod_stiva(Stack *head , int x){

    if(head==NULL)
    return creare_nod_stiva(x);

    Stack *parcurgere=head;
    while(parcurgere->next!=NULL){


        parcurgere=parcurgere->next;
    }

    parcurgere->next=creare_nod_stiva(x);

    return head;
}

Stack *pop(Stack *head , List **head_l){

    if(head==NULL)
    return NULL;

    if(head->next==NULL){

        *head_l=inserare_nod(*head_l , head->x);
        return NULL;
    }

    Stack *parcurgere=head;
    while((parcurgere->next)->next!=NULL){


        parcurgere=parcurgere->next;
    }

    *head_l=inserare_nod(*head_l , (parcurgere->next)->x);
    
    Stack *tmp=parcurgere->next;
    parcurgere->next=NULL;

    free(tmp);

    return head;
}

List *inversare(List *head){

    Stack *stiva=NULL;
    List *lista_i=NULL;

    List *parcurgere=head;
    while(parcurgere!=NULL){

        stiva=inserare_nod_stiva(stiva , parcurgere->x);

        parcurgere=parcurgere->next;
    }

    while(stiva!=NULL)
    stiva=pop(stiva , &lista_i);


    return lista_i;

}

void afisare_lista(List *head){


    List *parcurgere=head;
    while(parcurgere!=NULL){
        printf("%d " , parcurgere->x);
        parcurgere=parcurgere->next;
    }
}

List *stergere_la_nod_cerut(List *head , int x){

    if(head==NULL)
    return NULL;

    if(head->next==NULL)
    return NULL;

    if( x == head->x ){

        List *tmp=head;
        head=head->next;
        free(tmp);

        return head;
    }else{

        List *parcurgere=head;
        while((parcurgere->next)->x!=x){
            parcurgere=parcurgere->next;
        }

        List *tmp=parcurgere->next;
        parcurgere->next=(parcurgere->next)->next;
        free(tmp);

        return head;
    }

}

int main(){

    List *lista=NULL;

    lista=inserare_nod(lista , 20);
    lista=inserare_nod(lista , 30);
    lista=inserare_nod(lista , 40);
    lista=inserare_nod(lista , 50);
    lista=inserare_nod(lista , 60);

    lista=inversare(lista);

    afisare_lista(lista);
    printf("\n");

    lista=stergere_la_nod_cerut(lista , 30);
    afisare_lista(lista);

    return 0;
}