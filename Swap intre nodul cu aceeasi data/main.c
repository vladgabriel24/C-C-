#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod{

    char *x;
    struct nod *next;
}nod;

nod *creare_nod(char *x){

    nod *nod_nou=malloc(sizeof(nod));

    nod_nou->x=malloc(6*sizeof(char));
    nod_nou->x=x;

    nod_nou->next=NULL;

    return nod_nou;
}

nod *populare_lista(nod *head , char *x){

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

nod *swap_head(nod *head , char *key){

    nod *parcurgere=head;
    while(parcurgere!=NULL){

        int fanion=0;
        for(int i=0 ; i<strlen(parcurgere->x) ; i++){

            if(*(parcurgere->x+i)!=*(key+i))
            fanion=1;
            
        }

        if(fanion==0){

        nod *parcurgere2=head;
        while(parcurgere2->next!=parcurgere)
        parcurgere2=parcurgere2->next;

        parcurgere2->next=parcurgere->next;
        parcurgere->next=head;
        
        return parcurgere;    
        }
        parcurgere=parcurgere->next;
    }

    return head;
}

void afisare_lista(nod *head){

    nod *parcurgere=head;
    int i=0;

    while(parcurgere!=NULL){

    printf("%s " , parcurgere->x);

    parcurgere=parcurgere->next;
    }
}

int main(){

    nod *head=NULL;

    head=populare_lista(head , "abcde");
    head=populare_lista(head , "lmjgh");
    head=populare_lista(head , "ljyeh");
    head=populare_lista(head , "nnnnn");

    afisare_lista(head);
    printf("\n");
    
    head=swap_head(head , "kkkkk");

    afisare_lista(head);

    return 0;
}