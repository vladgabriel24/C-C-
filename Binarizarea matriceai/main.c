#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//citirematrice
//afisare matrice
//bordare matrice
//submatrice
//binarizare
//transformare

void citirematrice(int N[100][100] , int n , int m ){

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){

            printf("N[%d][%d]=" , i , j);
            scanf("%d" , &N[i][j]);
        }
    }


}

void afisarematrice(int N[100][100] , int n , int m ){

    for(int i=0 ; i<n ; i++){
            printf("\n");
        for(int j=0 ; j<m ; j++){

            printf("%d\t" , N[i][j]);
        }
    }

}

void bordare(int N[100][100], int n , int m , int k){

    int B[100][100];

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
                B[i][j]=N[i][j];
        }
    }

    for(int i=n ; i<k ; i++){
        for(int j=m ; j<k ; j++){
                B[i][j]=0;
        }
    }

    for(int i=0 ; i<n+k ; i++){
            printf("\n");
        for(int j=0 ; j<m+k ; j++){

            printf("%d\t" , B[i][j]);
        }
    }



}

void submatrice(int N[100][100],int k , int l , int c){


    int B[100][100];

    for(int i=l ; i<k ; i++){
        for(int j=c ; j<k ; j++){
            B[i][j]=N[i][j];
        }
    }

    for(int i=l ; i<k ; i++){
            printf("\n");
        for(int j=c ; j<k ; j++){
            printf("%d\t" , B[i][j]);
        }
    }






}

void binarizare(int N[100][100] , int k){

    int B[100][100];
    int m , n;

    if(k>=3){

    m=k/2;

    for(int i=0 ; i<k ; i++){
        for(int j=0 ; j<k ; j++){
            B[i][j]=N[i][j];
        }
    }

    n=B[m][m];

    for(int i=0 ; i<k ; i++){
        for(int j=0 ; j<k ; j++){
            if(B[i][j]>n){
                B[i][j]=1;
            }else{
                B[i][j]=0;
            }
        }
    }

    for(int i=0 ; i<k ; i++){
            printf("\n");
        for(int j=0 ; j<k ; j++){
            printf("%d\t" , B[i][j]);
        }
    }

    printf("\n");
    transformare(B ,3 ,3);

    }else{
    printf("sex");
    }

}

void transformare(int N[100][100] , int m , int n){

    int  nr=0 ,s=1;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
               nr=nr+N[i][j]*pow(2,s);
                s++;

        }
    }

    printf("%d" , nr);


}





int main(){

    float M[100][100];

    citirematrice(M , 5 , 5);
    afisarematrice(M , 5 , 5);
    printf("\n");
    bordare(M , 5 , 5 , 2);
    printf("\n");printf("\n");
    submatrice(M , 3 , 0 , 0);
    printf("\n");printf("\n");
    binarizare(M , 3);
    //transformare(M , 3 , 3);











    return 0;
}
