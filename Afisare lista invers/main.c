#include <stdio.h>
#include <stdlib.h>

typedef struct nod{

    int x;
    struct nod *next;
}nod;

nod *creare_nod(int x){

    nod *nod_nou=malloc(sizeof(nod));

    nod_nou->x=x;

    nod_nou->next=NULL;

    return nod_nou;
}

nod *populare_lista(nod *head , int x){

    if(head==NULL){

        head=creare_nod(x);

        return head;
    }

    nod *parcurgere=head;

    while(parcurgere->next!=NULL)
    parcurgere=parcurgere->next;

    parcurgere->next=creare_nod(x);

    return head;
}

void afisare_lista(nod *head){

    nod *parcurgere=head;

    while(parcurgere!=NULL){

    printf("%d " , parcurgere->x);

    parcurgere=parcurgere->next;
    }
}

void afisare_inversata(nod *head){


    if(head==NULL)

    return ;

    afisare_inversata(head->next);

    printf("%d " , head->x);


}

int main(){

    nod *head=NULL;

    head=populare_lista(head , 2);
    head=populare_lista(head , 3);
    head=populare_lista(head , 4);
    head=populare_lista(head , 5);
    head=populare_lista(head , 6);
    head=populare_lista(head , 7);

    afisare_lista(head);
    printf("\n");
    afisare_inversata(head);

    return 0;
}