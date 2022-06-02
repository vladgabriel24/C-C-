#include <stdio.h>
#include <stdlib.h>

struct nod{
    int x;
    struct nod *next;
};

struct nod_produs_cart{

    int x;
    int y;
    struct nod_produs_cart *next;

};

typedef struct nod_produs_cart Cart;
typedef struct nod NOD;

NOD *creare_nod(int x){

    NOD *nod_nou=malloc(sizeof(NOD));

    nod_nou->x=x;

    nod_nou->next=NULL;

    return nod_nou;
}

int is_node(NOD *head , int x){

    if(head==NULL)
    return 0;

    NOD *parcurgere=head;
    while(parcurgere!=NULL){

        if(parcurgere->x==x)
        return 1;

        parcurgere=parcurgere->next;
    }

    return 0;

}

NOD *populare_lista(NOD *head , int x){

    int fanion=is_node(head,x);

    if( fanion==1 )
    return head;

    if(head==NULL)
    return creare_nod(x);

    NOD *parcurgere=head;
    while(parcurgere->next!=NULL)
    parcurgere=parcurgere->next;

    parcurgere->next=creare_nod(x);

    return head;

}

int cardinal(NOD *head){

    int card=0;

    NOD *parcurgere=head;
    while(parcurgere!=NULL){

        card++;
        parcurgere=parcurgere->next;
    }

    return card;
}

int is_vid(NOD *head){

    if(head==NULL)
    return 1;
    else
    return 0;

}

NOD *stergere_nod(NOD *head , int x){

    int fanion=is_node(head,x);

    if( fanion==0 )
    return head;

    if(head==NULL)
    return NULL;

    if(head->next==NULL)
    return NULL;

    if( x == head->x ){

        NOD *tmp=head;
        head=head->next;
        free(tmp);

        return head;
    }else{


        NOD *parcurgere=head;
        while((parcurgere->next)->x!=x)
        parcurgere=parcurgere->next;

        NOD *tmp=parcurgere->next;
        parcurgere->next=parcurgere->next->next;
        free(tmp);

        return head;

    }
}

NOD *intersectie(NOD *head1 , NOD *head2){

    NOD *multime3=NULL;

    NOD *parcurgere1=head1;
    NOD *parcurgere2=head2;

    while(parcurgere1!=NULL){
        
        while(parcurgere2!=NULL){

            if(is_node(parcurgere1 , parcurgere2->x)==1)
            multime3=populare_lista(multime3 , parcurgere2->x);

            parcurgere2=parcurgere2->next;
        }

        parcurgere1=parcurgere1->next;
    }

    return multime3;
}

NOD *reuniune(NOD *head1 , NOD *head2){

    NOD *multime4=NULL;

    NOD *parcurgere=head1;
    while(parcurgere!=NULL){

        multime4=populare_lista(multime4 , parcurgere->x);

        parcurgere=parcurgere->next;
    }

    NOD *parcurgere2=head2;
    while(parcurgere2!=NULL){

        multime4=populare_lista(multime4 , parcurgere2->x);

        parcurgere2=parcurgere2->next;
    }

    return multime4;
}

NOD *diferenta(NOD *head1 , NOD *head2){

    NOD *multime5=NULL;

    NOD *parcurgere=head1;
    while(parcurgere!=NULL){

        
        multime5=populare_lista(multime5 , parcurgere->x);

        parcurgere=parcurgere->next;
    }

    NOD *parcurgere2=head2;
    while(parcurgere2!=NULL){

        if(is_node(multime5 , parcurgere2->x)==1)
        multime5=stergere_nod(multime5 , parcurgere2->x);

        parcurgere2=parcurgere2->next;
    }

    return multime5;
}

int include(NOD *head1 , NOD *head2){


    int includere=1;
    NOD *parcurgere=head1;
    while(parcurgere!=NULL){

        if(is_node(head2 , parcurgere->x)==0)
        includere=0;

        parcurgere=parcurgere->next;
    }

    return includere;
}

void afisare_lista(NOD *head){

    NOD *parcurgere=head;
    while(parcurgere!=NULL){

        printf("%d " , parcurgere->x);
        parcurgere=parcurgere->next;
    }

}

Cart *creare_nod_produs(int x , int y){

    Cart *nod_nou=malloc(sizeof(Cart));

    nod_nou->x=x;
    nod_nou->y=y;

    nod_nou->next=NULL;

    return nod_nou;

}

Cart *populare_lista_produs(Cart *head , int x , int y){

    if(head==NULL)
    return creare_nod_produs(x , y);

    Cart *parcurgere=head;
    while(parcurgere->next!=NULL)
    parcurgere=parcurgere->next;

    parcurgere->next=creare_nod_produs(x , y);

    return head;

}

void produs_cart(NOD *multime1 , NOD *multime2 , Cart **multime_produs){

    NOD *parcurgere1=multime1;
    NOD *parcurgere2=multime2;

    while(parcurgere1!=NULL){

        while(parcurgere2!=NULL){

            *multime_produs=populare_lista_produs(*multime_produs , parcurgere1->x , parcurgere2->x);

            parcurgere2=parcurgere2->next;
        }
        parcurgere2=multime2;

        parcurgere1=parcurgere1->next;
    }

    //return multime_produs;
}

void afisare_lista_produs(Cart *head){

    Cart *parcurgere=head;
    while(parcurgere!=NULL){

        printf("%d,%d " , parcurgere->x , parcurgere->y);
        parcurgere=parcurgere->next;
    }

}

int main(){

    NOD *multime1=NULL;
    NOD *multime2=NULL;
    NOD *multime3=NULL;
    NOD *multime4=NULL;
    NOD *multime5=NULL;
    Cart *multime_produs=NULL;

    multime1=populare_lista(multime1 , 20);
    multime1=populare_lista(multime1 , 30);
    multime1=populare_lista(multime1 , 40);
    multime1=populare_lista(multime1 , 50);
    multime1=populare_lista(multime1 , 60);
    multime1=populare_lista(multime1 , 70);
    multime1=populare_lista(multime1 , 80);
    multime2=populare_lista(multime2 , 20);
    multime2=populare_lista(multime2 , 30);
    multime2=populare_lista(multime2 , 70);
    multime2=populare_lista(multime2 , 80);
    

    afisare_lista(multime1);
    printf("\n");

    afisare_lista(multime2);
    printf("\n");

    multime3=intersectie(multime1 , multime2);
    afisare_lista(multime3);
    printf("\n");

    multime4=reuniune(multime1 , multime2);
    afisare_lista(multime4);
    printf("\n");

    multime5=diferenta(multime1 , multime2);
    afisare_lista(multime5);
    printf("\n");

    printf("%d\n" , include(multime1 , multime2));

    produs_cart(multime1 , multime2 , &multime_produs);
    afisare_lista_produs(multime_produs);
    printf("\n");

    return 0;
}