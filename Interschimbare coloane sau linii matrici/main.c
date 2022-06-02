#include <stdio.h>
#include <stdlib.h>

void citire_matrice(int M[][100] , int m , int n){

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            scanf("%d" , &M[i][j]);
        }
    }
}

void afisare_matrice(int M[][100] , int m , int n){

    for(int i=0 ; i<m ; i++){
        printf("\n");
        for(int j=0 ; j<n ; j++){
           printf("%d" , M[i][j]);
           printf(" ");
        }
    }
}

int main(){

    int M[100][100];
    int m , n;

    printf("Introduceti dimensiunile matricii:");scanf("%d" , &m);scanf("%d" , &n);

    citire_matrice(M , m , n);

    //interschimbare coloane intre ele
    // int temp;
    // for(int i=0 ; i<m-1 ; i++){
    //     for(int j=0 ; j<n ; j++){
    //        temp=M[i][j];
    //        M[i][j]=M[i+1][j];
    //        M[i+1][j]=temp;
    //     }
    // }

    //afisare_matrice(M , m , n);


    //interschimbare linii intre ele
    // int temp;
    // for(int j=0 ; j<n-1 ; j++){
    //     for(int i=0 ; i<m ; i++){
    //        temp=M[i][j];
    //        M[i][j]=M[i][j+1];
    //        M[i][j+1]=temp;
    //     }
    // }

    //pot adauga si un if pt a interschimba linii/coloane pare sau impare sau depinde de ce vr

    afisare_matrice(M , m , n);

    return 0;
}