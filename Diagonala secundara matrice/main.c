#include <stdio.h>
#include <stdlib.h>

void citire_matrice(int M[100][100] , int n , int m){

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){

            scanf("%d" , &M[i][j]);
        }
    }
}

void elemente_diag_secundara(int M[100][100] , int n , int m){

    for(int i=0 ; i<m ; i++){
       
            printf("%d" , M[i][n-1-i]);  //iau numai un for deoarece daca stam si analizam procedeul dupa indicii matricii , parcurgerea diag sec depinde numai de i
    }
}

void elemente_sub_diag_secundara(int M[100][100] , int n , int m){

    for(int i=1 ; i<m ; i++){
        for(int j=n-i ; j<n ; j++){
            printf("%d" , M[i][j]);
        }
    }
}

void elemente_peste_diag_secundara(int M[100][100] , int n , int m){

    for(int i=0 ; i<m-1 ; i++){
        for(int j=0 ; j<n-i-1 ; j++){
            printf("%d" , M[i][j]);
        }
    }
}

int main(){

    int M[100][100];
    int m , n;

    printf("Introduceti dimensiunea matricii:");
    scanf("%d" , &m);
    scanf("%d" , &n);

    citire_matrice(M , m , n);
    elemente_diag_secundara(M , m , n);
    printf("\n");
    elemente_sub_diag_secundara(M , m ,n);
    printf("\n");
    elemente_peste_diag_secundara(M , m , n);

    return 0;
}