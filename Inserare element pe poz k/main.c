#include <stdio.h>
#include <stdlib.h>

int main(){

    int v[15] , v1[50] , n , k ,e;

    printf("Introduceti dimensiunea vectorului:");
    scanf("%d" , &n);
    printf("\n");


    printf("Introduceti vectorul:");
    for(int i=1 ; i<=n ; i++){
        scanf("%d" , &v[i]);
    }

    printf("Selectati pozitia unde vreti sa adaugati caracterul:");
    scanf("%d" , &k);

    for(int i=1 ; i<=k ; i++){
        v1[i]=0;
        v1[i]=v[i];
        //printf("%d" , v1[i]);
    }

    printf("\n");

    for(int i=k+1 ; i<=n+1 ; i++){
        v1[i]=0;
        v1[i]=v[i-1];
        //printf("%d" , v1[i]);
    }

    printf("Introduceti elementul dorit sa fie adaugat:");
    scanf("%d" , &e);
    v1[k+1]=e;

    for(int i=1 ; i<=n+1 ; i++){

        printf("%d" , v1[i]);
    }


    return 0;
}
