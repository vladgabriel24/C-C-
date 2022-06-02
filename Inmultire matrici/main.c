#include <stdio.h>
#include <stdlib.h>

int main()
{

    int N[10][10], M[10][10] , P[10][10] , n , p , a , b , i , j , k;

    printf("Introduceti dimensiunile matricii 1:");
    printf("\n");
    scanf("%d" , &n);
    scanf("%d" , &p);

    for ( i=0 ; i<n ; i++){
            printf("\n");
        for( j=0 ; j<p ; j++){
            scanf("%d" , &M[i][j]);
        }
    }

    printf("Introduceti dimensiunile matricii 2:");
    printf("\n");
    scanf("%d" , &a);
    scanf("%d" , &b);

    for ( i=0 ; i<a ; i++){
            printf("\n");
        for( j=0 ; j<b ; j++){
            scanf("%d" , &N[i][j]);
        }
    }


    if(p!=a){
        printf("Matricile nu pot fii inmultite");

    }else{




    for ( i=0 ; i<n ; i++){
        for( j=0 ; j<p ; j++){
            P[i][j]=0;
           for(k=0 ; k<a ; k++){

             P[i][j]+=M[i][k]*N[k][j];

           }
        }
    }



    for ( i=0 ; i<n ; i++){
        for( j=0 ; j<p ; j++){
                printf("\n");
            printf("%d" , P[i][j]);
        }
    }


    }


    return 0;
}
