#include <stdio.h>
#include <stdlib.h>

void citirematrice(int M[][100] , int n , int m){

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            scanf("%d" , &M[i][j]);
        }
    }
}

void afisarematrice(int M[][100] , int n , int m){

    for(int i=0 ; i<n ; i++){
        printf("\n");
        for(int j=0 ; j<m ; j++){
            printf("%d" , M[i][j]);
            printf(" ");
        }
    }
}

void vectorizare(int M[][100] , int v[] , int n , int m){

    int k=0;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m; j++){
            if(k<m*n){
                v[k]=0;
                v[k]=M[i][j];
                k++;
            }
        }
    }

    for(int k=0 ; k<m*n ; k++){
            printf("%d" , v[k]);
            printf(" ");
        }
}

int aparitii_consecutive(int v[] , int n , int index){

    int l=0;

    for(int i=index ; i<n ; i++){
        if(v[i]==v[index]){
            if(v[i]==v[i+1]){
                l++;
            }
        }
    }
    return l-1;
}

void codare(int M[][100] , int v[] , int n , int m){   //v ul este matricea vectorizata pe care o avem deja

    //vectorizare cu afisare

    int k=0;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m; j++){
            if(k<m*n){
                v[k]=0;
                v[k]=M[i][j];
                k++;
            }
        }
    }

    for(int k=0 ; k<m*n ; k++){
            printf("%d" , v[k]);
            printf(" ");
        }

    int consec=v[0];
    int total=1;    
    
    for(int j=1 ; j<n*m ; j++){

    if(v[j]==consec){
        total++;
    }else if(v[j]!=consec){
        printf("\n");
        printf("%d" , consec);
        printf(" ");
        printf("%d" , total);
        printf("\n");
        consec=v[j];
        total=1;
    }

    }

    //deoarece ultimile cifre sunt consec si nu mai apuca sa printeze , printez cand iese din bucla ca val raman aceleasi    
    printf("%d" , consec);
        printf(" ");
        printf("%d" , total);
        printf("\n");

}

int main(){

    int M[100][100];
    int v[100];
    int n , m;
    int test;

    printf("Introduceti dimensiunile matricii: ");scanf("%d" , &n);scanf("%d" , &m);
    citirematrice(M , n , m);

    printf("Introduceti valoarea de test: ");scanf("%d" , &test);

    if(test==1)
    afisarematrice(M , n , m);

    if(test==2)
    vectorizare(M , v , n , m);

    if(test==3){
    int index;
    printf("Introduceti indexul de la care vreti sa cautati:");scanf("%d" , &index);
    printf("%d" , aparitii_consecutive(v , m , index));
    }

    if(test==4){

        codare( M , v , n , m);

    }

    return 0;
}