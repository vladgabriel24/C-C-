#include <stdio.h>
#include <stdlib.h>
#include <assert.H>

struct nod_arbore{
    
    int x;
    struct nod_arbore *stanga;
    struct nod_arbore *dreapta;
};

struct nod_produs_c{
    int x;
    int y;
    struct nod_produs_c *next;

};

typedef struct nod_produs_c Cart;
typedef struct nod_arbore Nod;

Nod *creare_nod(int x){

    Nod *nod_nou;
    nod_nou=malloc(sizeof(Nod));
    assert(nod_nou!=NULL);

    nod_nou->x=x;

    nod_nou->stanga=NULL;
    nod_nou->dreapta=NULL;

    return nod_nou;
}

int is_element(Nod *arbore , int x){  
    // verificarea daca un element x este gasit in arbore : adica o f de cautare cu return 1 daca (x==arbore->x) si daca se iese din while fara return atunci return 0
    // ATENTIE : nu am facut f recursiva ca nu am nevoie , eu doar caut un nod (adica ma duc ca un schior spre locul unde ar putea fii)
    // daca nu il gasesc ies din while (ca nu s-a dat return , adica nu s-a inchis functia) si dau return 0

    Nod *parcurgere=arbore;
    while(parcurgere!=NULL){
       
        if( x< parcurgere -> x)
        parcurgere=parcurgere->stanga;
        else if(x > parcurgere -> x)
        parcurgere=parcurgere->dreapta;
        else if(x == parcurgere -> x)
        return 1;

    }

    if(parcurgere==NULL)
    return 0;
}

Nod *populare_arbore(Nod *arbore , int x){

    int flag;
    flag=is_element(arbore , x);  // conditia de unicitate a elementelor

    if(flag==0){


        if(arbore==NULL)
        return creare_nod(x);

        if( x < arbore->x )
        arbore->stanga=populare_arbore(arbore->stanga , x);
        else if ( x > arbore->x )
        arbore->dreapta=populare_arbore(arbore->dreapta , x);

        return arbore;

    }else
    return arbore;
    
}

Nod *minim(Nod *arbore){

    // Mare ATENTIE la recursivitate cu return de nod de arbore!!!
    // In momentul in care tu vrei sa returnezi un nod specific si pe altele le lasi in pace
    // Adica daca vrei sa returnezi doar intr-un anumit caz si in retul nu si lasi recusivitatea sa si faca de cap cu return uri , va aparea un BUG
    // Instantele de functii dupa return-ul dorit se vor "juca" cu memoria transmisa a arborelui
    // Asadar , cel mai bine e sa evitam recusivitatea la cazuri f f singulare si specifice (min , max , frunze , ..)
    // Folosim recusivitatea doar unde este necesar o parcurgere integrala sau unde am posibilitatea sa returnez si restul de noduri nu doar unul singur
    // sau ceva specific unuia singur

    Nod *parcurgere=arbore;
    while(parcurgere->stanga!=NULL)
    parcurgere=parcurgere->stanga;

    return parcurgere;

}

Nod *maxim(Nod *arbore){

    Nod *parcurgere=arbore;
    while(parcurgere->dreapta!=NULL)
    parcurgere=parcurgere->dreapta;

    return parcurgere;

}


void cardinal(Nod *arbore , int *x){

    
    if(arbore==NULL)
    return;

    (*x)++;
    cardinal(arbore->stanga , x);
    cardinal(arbore->dreapta , x);
    
}

int is_vid(Nod *arbore){

    if(arbore==NULL)
    return 1;
    else
    return 0;

}

Nod *stergere_nod(Nod *arbore , int x){


    if( arbore->x != x){ //fara while , deoarece recursivitatea cicleaza singura!

        if( x < arbore->x )
        arbore->stanga=stergere_nod(arbore->stanga , x);
        else
        arbore->dreapta=stergere_nod(arbore->dreapta , x);
    }
    
    if(arbore->x==x){

        // punem un if aici pt ca in momentul in care ne intoarcem in instantele anterioare de f
        // sa nu se mai intre in procesul de stergere deoarece sunt niste ifuri unde s-ar intra si daca x ul din param nu e egal cu ce e la nod
        // noi vrem sa stergem doar cand am gasit x ul cautat prin deschiderea inlantuita de f
        // cand am gasit se intra in procesul de stergere si dupa recursivitatea merge inapoi
        // din acest moment nu mai vrem sa se execute procesul de stergere deoarece am sters ce am vrut
        // si de asta punem acest if care ne lasa sa intram numai la x ul gasit

        // Ca sumar , cand avem o functie ce nu e void si vrem sa facem recusivitate , 
        // trebuie sa controlam return urile in fiecare instanta de functie , altfel s-ar putea sa apara un BUG

        if((arbore->stanga!=NULL)&&(arbore->dreapta==NULL)){

            Nod *tmp=arbore;
            arbore=arbore->stanga;
            free(tmp);

            return arbore;
        }
        else if((arbore->stanga==NULL)&&(arbore->dreapta!=NULL)){

            Nod *tmp=arbore;
            arbore=arbore->dreapta;
            free(tmp);

            return arbore;

        }
        else if((arbore->stanga==NULL)&&(arbore->dreapta==NULL)){

            Nod *tmp=arbore;
            free(tmp);

            return NULL;
        }
        else if((arbore->stanga!=NULL)&&(arbore->dreapta!=NULL)){

            Nod *min_d=minim(arbore->dreapta);

            arbore->x=min_d->x;

            arbore->dreapta=stergere_nod(arbore->dreapta , min_d->x);

            return arbore;
        }
    }

    return arbore;
}

void afisare_inordine(Nod *arbore){

    if(arbore==NULL)
    return ;

    afisare_inordine(arbore->stanga);
    printf("%d " , arbore->x);
    afisare_inordine(arbore->dreapta);

}

void intersectie(Nod *multime1 , Nod *multime2 , Nod **multime3){  // copiem numai ce este comun intre multime 1 si 2

    if(multime1==NULL)
    return;

    if(is_element(multime2 , multime1->x)==1)
    *multime3=populare_arbore(*multime3 , multime1->x);

    intersectie(multime1->stanga ,multime2 , multime3);
    intersectie(multime1->dreapta ,multime2 , multime3);
}

void copy(Nod *multime1 , Nod **multime2){ // copiere din multime 1 in multime 2

    if(multime1==NULL)
    return;

    *multime2=populare_arbore(*multime2 , multime1->x);

    copy(multime1->stanga , multime2);
    copy(multime1->dreapta , multime2);

}

void reuniune(Nod *multime1 , Nod *multime2 , Nod **multime3){

    copy(multime1 , multime3); // copiem in multime 3  , multime 1
    copy(multime2 , multime3); // copiem in multime 3 si multime 2 dupa (daca din multime 2 se regasesc deja in multime 3 nu se vor copia ca nu avem voie cu elem egale)

}

void stergere_egal(Nod *multime1 , Nod **multime2){  //stergem din multime 2 elementele pe care le gasim in multime 1

    if(multime1==NULL)
    return;

    if(is_element(*multime2 , multime1->x))
    *multime2=stergere_nod(*multime2 , multime1->x);
    
    stergere_egal(multime1->stanga ,multime2);
    stergere_egal(multime1->dreapta ,multime2);

}

void diferenta(Nod *multime1 , Nod *multime2 , Nod **multime3){

    // copiem multime 1 in multime 3
    copy(multime1 , multime3);
    // stergem din multime 3 (adica din ce am copiat din multime1) ce gasim egal cu ce e in multime2
    stergere_egal(multime2 ,multime3);

}

int is_included(Nod *multime1 , Nod *multime2){

    Nod *multime_scadere=NULL;
    diferenta(multime1 , multime2 , &multime_scadere); //daca diferenta dintre submultime si multime este 0 inseamna ca e inclusa altfel nu

    if(multime_scadere==NULL)
    return 1;
    else
    return 0;

}

Cart *creare_nod_lista(int x , int y){


    Cart *nod_nou=malloc(sizeof(Cart));

    nod_nou->x=x;
    nod_nou->y=y;

    nod_nou->next=NULL;

    return nod_nou;

}

Cart *populare_lista(Cart *head , int x , int y){

    if(head==NULL)
    return creare_nod_lista(x , y);

    Cart *parcurgere=head;
    while(parcurgere->next!=NULL)
    parcurgere=parcurgere->next;

    parcurgere->next=creare_nod_lista( x , y);

    return head;
}

/* 

    O functie care ia un x dintr un arbore ce il pastreasa pe tot parcursul recusivitatii
    Si incepe:
    -adauga x ul in lista si y ul conform instantei
    -adauga x ul in lista si y ul conform urmatoarei iteratii

    Deci noi FIXAM un x DAT (dat de alta recusivitate) si cu y ne miscam pe recusivitate si adaugam in lista.

    Deci y ul este variabila prin care adaug in lista (la combinatiile de nr) nodurile din arbore2 (prin recusivitate)
    Si x ul este fixat de noi si pe el(pe acelasi) il adaugam de fiecare data cand adaugam cate un nod din arbore2

    Acest x fixat de noi este dat deoarece eu voi folosii functia asta in alta recusivitate.
 
    Acea recusivitate va parcurge nodurile arborelui 1 si acolo vom schimba x 
    care urmeaza a fi adaugat de fiecare data la fiecare adaugare din nodurile in arbore2(aceasta recursivitate).

    Aceasta recusivitate parcurge nodurile arborelui 2 si aici il schimbam pe y mereu si il adaugam.

 */
void introducere_in_lista(Cart **head , int x , Nod *arbore){

    if(arbore==NULL)
    return;

        *head=populare_lista(*head , x , arbore->x);

    introducere_in_lista(head , x , arbore->stanga);
    introducere_in_lista(head , x , arbore->dreapta);

}

void produs_cart(Nod *multime1 , Nod *multime2 , Cart **multime3){

    if(multime1==NULL)
    return;

    introducere_in_lista(multime3 , multime1->x , multime2);


    produs_cart(multime1->stanga , multime2 , multime3);
    produs_cart(multime1->dreapta , multime2 , multime3);

}

void afisare_lista(Cart *head){

    Cart *parcurgere=head;
    while(parcurgere!=NULL){

        printf("%d,%d " , parcurgere->x , parcurgere->y);

        parcurgere=parcurgere->next;
    }

}

int main(){

    Nod *multime=NULL;
    Nod *multime2=NULL;
    Nod *multime3=NULL;
    Nod *multime4=NULL;
    Nod *multime5=NULL;
    Nod *multime6=NULL;
    Cart *produs_cartezian=NULL;

    multime=populare_arbore(multime , 50);
    multime=populare_arbore(multime , 60);
    multime=populare_arbore(multime , 70);
    multime=populare_arbore(multime , 80);
    multime=populare_arbore(multime , 40);
    multime=populare_arbore(multime , 45);
    multime=populare_arbore(multime , 30);

    multime2=populare_arbore(multime2 , 60);
    multime2=populare_arbore(multime2 , 50);
    multime2=populare_arbore(multime2 , 100);
    multime2=populare_arbore(multime2 , 200);
    multime2=populare_arbore(multime2 , 31);
    multime2=populare_arbore(multime2 , 30);

    multime6=populare_arbore(multime6 , 50);
    multime6=populare_arbore(multime6 , 60);
    multime6=populare_arbore(multime6 , 70);

    afisare_inordine(multime);

    printf("\n");

    afisare_inordine(multime2);

    intersectie(multime , multime2 , &multime3);
    printf("\n");
    afisare_inordine(multime3);

    reuniune(multime ,multime2  , &multime4);
    printf("\n");
    afisare_inordine(multime4);
    
    diferenta(multime , multime2 , &multime5);
    printf("\n");
    afisare_inordine(multime5);

    printf("\n%d" , is_included(multime6 , multime));

    produs_cart(multime , multime2 , &produs_cartezian);
    printf("\n");
    afisare_lista(produs_cartezian);

    return 0;
}