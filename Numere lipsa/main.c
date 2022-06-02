#include <stdio.h>
#include <stdlib.h>

struct nod{

    int x;
    struct nod *next;

};

typedef struct nod Nod;

Nod *creare_nod(int x){

    Nod *nod_nou=malloc(sizeof(Nod));

    nod_nou->x=x;

    nod_nou->next=NULL;

    return nod_nou;

}

int is_element(int x , Nod *multime){

    Nod *parcurgere=multime;
    while(parcurgere!=NULL){

        if( x == parcurgere->x )
        return 1;
        
        parcurgere=parcurgere->next;
    }

    return 0;
}

Nod *populare_lista(Nod *head , int x){

    //  daca ce citim este deja , returnam pur si simplu ce ni s-a dat
    //  asta este benefic deoarece poate nu vrem sa inchidem brusc programul
    //  return NULL este EXCLUS in acest caz

    if(is_element(x , head)==1) 
    return head;

    if(head==NULL)
    return creare_nod(x);

    Nod *parcurgere=head;
    while(parcurgere->next!=NULL)
    parcurgere=parcurgere->next;

    parcurgere->next=creare_nod(x);

    return head;

}

void afisare_lista(Nod *head){

    Nod *parcurgere=head;
    while(parcurgere!=NULL){

        printf("%d " , parcurgere->x);
        parcurgere=parcurgere->next;
    }
}

void introducere_date(Nod **multime1 , Nod **multime2){

    /*

    Mod citire date: Avand in vedere ca avem cifre , %d elimina toate wh dinainte.
    Deci nu este necesara o interventie pe scanf uri si vom efectua
    - un scanf pt n
    - scanf %d pana cand se intalneste EOF (la fiecare citire introducem in lista)

    */

    int n;
    
    int nr;
    char *flag=malloc(sizeof(char));

    //in multimea 1:
    
    // citim un numar si dupa citim si whitespace ul de dupa
    // si daca acel whitespace este chiar '\n' adica enter pe care il apasam cand terminam de introdus
    // iesim din bucla infinita
    // + dupa citire , daca valoarea introdusa nu se incadreaza in interval , se iese din program cu mesaj de atentionare

    scanf("%d" , &n);
    while(1){

        scanf("%d" , &nr);
        if((nr<0)||(nr>10)){
            printf("Ati introdus un numar gresit!");
            exit(0);
        }

        *multime1=populare_lista(*multime1 , nr);

        scanf("%c"  , flag);
        if(*flag=='\n')
        break;

    }

    // si dupa in multimea 2 bagam nr de la 0 pana la n printr un for

    for(int i=0 ; i<=n ; i++)
    *multime2=populare_lista(*multime2 , i);

}

Nod *stergere_nod(Nod *head , int x){

    if(head==NULL)
    return NULL;

    if(head->next==NULL)
    return NULL;

    if( x == head->x ){

        Nod *tmp=head;
        head=head->next;

        free(tmp);

        return head;

    }else{

        Nod *parcurgere=head;
        while((parcurgere->next)->x!=x)
        parcurgere=parcurgere->next;

        Nod *tmp=parcurgere->next;
        parcurgere->next=(parcurgere->next)->next;
        free(tmp);

        return head;

    }
}

Nod *diferenta(Nod *multime1 , Nod *multime2 , int *x){

    Nod *parcurgere1=multime1;
    Nod *multime3=NULL;

    while(parcurgere1!=NULL){

        if(is_element(parcurgere1->x , multime2)==0){
            
            (*x)++;
            multime3=populare_lista(multime3 , parcurgere1->x);
        }

        parcurgere1=parcurgere1->next;
    }

    return multime3;

    /*

        Eu am incercat efectuarea diferentei prin stergere. 
        Adica atunci cand gaseam aceeasi val in ambele multimi , stergeam valoarea respectiva din multimea descazuta.
        DAR
        Eu realizez in functie o parcurgere , iar in momentul in care sterg din multime si tot in ea parcurg ,
        adica sterg si parcurg in acelasi timp , nu se vor lua toate valorile si stergerea va fii defectuoasa.

        Asadar , am optat pentru o varianta de creare a unei noi multimi , 
        iar in momentul in care gasesc o val din multimea descazuta CARE NU ESTE in multimea scazatoare
        adaug acea valoare multimii noi (cu f de adaugare specifica multimilor facuta anterior).

        Si tot asa pana parcurgem toata lista descazuta si comparam si vedem ce nu se regaseste in multimea scazatoare
        si adaug in multimea noua.

        In acest mod parcurg fara sa modific(in acelasi timp) multimea descazuta , deci nu vor aparea erori , 
        iar multimea noua va contine fix ce ne rezulta din diferenta dintre multimile dorite. 

    */
}

int main(){
    
    Nod *multime1=NULL;
    Nod *multime_n=NULL;
    int numere_lipsa=0;
    
    introducere_date(&multime1 , &multime_n);

    printf("\n");
    afisare_lista(multime1);
    printf("\n");
    afisare_lista(multime_n);

    multime_n=diferenta(multime_n , multime1 , &numere_lipsa);
    printf("\n");
    afisare_lista(multime_n);
    printf("\n%d" , numere_lipsa);
    
    return 0;
}