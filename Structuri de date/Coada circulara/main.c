#include <stdio.h>
#include <stdlib.h>

struct coada_circulara{

    int *date;
    int *prim;
    int *ultim;
    int nr_date;


};

typedef struct coada_circulara circular_queue;

void create_tail(circular_queue *coada , int nr){

    (*coada).nr_date=nr;

    (*coada).date=malloc(nr*sizeof(int));
    (*coada).prim=(*coada).date;
    (*coada).ultim=(*coada).date;

}

void enqueue(circular_queue *coada , int x , int *fanion){

    int pos=0;
    int *parcurgere;
    parcurgere=(*coada).prim;

    if((*coada).prim == (*coada).ultim){

        if(*fanion==1){
            *((*coada).date+pos)=x;
            *fanion=0;

            return;
        }

    }

    while(parcurgere!=(*coada).ultim){
        parcurgere++;
        pos++;
        
    }

    pos++;
    pos=pos%(*coada).nr_date;

    *((*coada).date+pos)=x;

    (*coada).ultim=(*coada).date+pos;
}

void dequeue(circular_queue *coada , int *index_stergere){


    (*index_stergere)++;
    //(*index_stergere)=(*index_stergere)%(*coada).nr_date;

    

}

void afisare(circular_queue *coada , int *index_stergere){

    for(int i=(*index_stergere) ; i<(*coada).nr_date ; i++)
    printf("%d " , *((*coada).date+i));


}

int main(){

    circular_queue coada;

    int fanion=1;
    int index_stergere=0;

    create_tail(&coada , 4);

    enqueue(&coada  , 4 , &fanion);
    enqueue(&coada  , 3 , &fanion);
    enqueue(&coada  , 2 , &fanion);
    enqueue(&coada  , 1 , &fanion);
    
    dequeue(&coada ,&index_stergere);
    dequeue(&coada ,&index_stergere);
    dequeue(&coada ,&index_stergere);
    //dequeue(&coada ,&index_stergere);

    afisare(&coada , &index_stergere);
    

    return 0;
}