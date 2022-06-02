#include <stdio.h>
#include <stdlib.h>

struct nod{

    int x;
    struct nod *next;
};

typedef struct nod node;

node *creare_nod(){

    node *nod_nou=malloc(sizeof(node));

    scanf("%d" , &nod_nou->x);

    nod_nou->next=NULL;

    return nod_nou;
}

node *populare_lista(node *head){

    if(head==NULL){

        head=creare_nod();

        return head;
    }

    node *nod_nou=creare_nod();
    node *parcurgere=head;

    while(parcurgere->next!=NULL)
    parcurgere=parcurgere->next;

    parcurgere->next=nod_nou;

    return head;
}

void afisare_lista(node *head){

    node *parcurgere=head;

    while(parcurgere!=NULL){

    printf("%d " , parcurgere->x);

    parcurgere=parcurgere->next;

    }
}

node *adaugare_la_inceput(node *head){

    node *nod_nou=creare_nod();

    nod_nou->next=head;

    head=nod_nou;

    return head;
}

void adaugare_la_final(node *head){

    node *nod_nou=creare_nod();
    node *parcurgere=head;

    while(parcurgere->next!=NULL)
    parcurgere=parcurgere->next;

    parcurgere->next=nod_nou;

}

node *adaugare_la_indice(node *head , int indice){

    //node *nod_nou=creare_nod();
    node *parcurgere=head;

    int nr_noduri=0;

    indice--;

    while(parcurgere!=NULL){

    nr_noduri++;

    parcurgere=parcurgere->next;

    }

    if(head==NULL){

        head=creare_nod();

        return head;
    }   

    if(indice==-1){

    head=adaugare_la_inceput(head);

    return head;
    }else if (indice == nr_noduri){

    adaugare_la_final(head);
    return head;    
    }else{

    node *nod_nou=creare_nod();

    parcurgere=head;

    for(int i=0 ; i<indice ; i++)
    parcurgere=parcurgere->next;

    nod_nou->next=parcurgere->next;
    parcurgere->next=nod_nou;

    
    return head;
    }

}

node *stergere_inceput(node *head){

    if(head==NULL)
    exit(0);

    if(head->next==NULL)
    return NULL;

    node *tmp=head;

    head=head->next;

    free(tmp);

    return head;
}

node *stergere_la_final(node *head){

    if(head==NULL)
    exit(0);

    if(head->next==NULL)
    return NULL;

    node *parcurgere=head;

    while((parcurgere->next)->next!=NULL)
    parcurgere=parcurgere->next;

    node *tmp=parcurgere->next;

    parcurgere->next=NULL;

    free(tmp);

    return head;
}

node *stergere_la_index(node *head , int index){

    int nr_noduri=0;

    index--;

    if(head==NULL)
    exit(0);

    if(head->next==NULL)
    return NULL;

    node *parcurgere=head;

    while(parcurgere!=NULL){

    nr_noduri++;

    parcurgere=parcurgere->next;

    }

    if(index==0){
        
        head=stergere_inceput(head);

        return head;
    //}else if(index==nr_noduri){

        //head=stergere_la_final(head);

        //return head;

    }else{

        parcurgere=head;

        for(int i=0 ; i<index-1 ; i++)
        parcurgere=parcurgere->next;

        node *tmp=parcurgere->next;
        parcurgere->next=(parcurgere->next)->next;
        
        free(tmp);

        return head;
    }

}

node *stergere_lista(node *head){

    node *tmp=head;

    while(tmp!=NULL){

        head=head->next;

        free(tmp);

        tmp=head;
    }

    return NULL;
}



int main(){

    node *head=NULL;

    head=populare_lista(head);
    head=populare_lista(head);
    head=populare_lista(head);
    head=populare_lista(head);
    head=populare_lista(head);

    //head=adaugare_la_inceput(head);

    //adaugare_la_final(head);

    

    // afisare_lista(head);
    // printf("\n");

    // head=stergere_inceput(head);
    // head=stergere_la_final(head);

    head=stergere_la_index(head , 2);

    //head=adaugare_la_indice(head , 5);

    //head=stergere_lista(head);
    afisare_lista(head);

    return 0;
}