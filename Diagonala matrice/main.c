#include <stdio.h>
#include <stdlib.h>


int main(){

    int M[100][100];
    int m,n;

    printf("Introduceti dimeniunile matricii:");
    printf("\n");
    scanf("%d" , &m);
    scanf("%d" , &n);
    printf("\n");
    printf("Introduceti elementele matricii:");

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){

            scanf("%d" , &M[i][j]);
        }
    }
        

        if(m!=n){

            printf("elementele de pe diagonala sunt:");
            printf("\n");
            printf("%d" , M[m-1][n-1]);
            printf("%d" , M[0][0]);


        }else{
            printf("elementele de pe diagonala sunt:");

    for (int k = 0; k < m; k++)
    {
        printf("%d" , M[k][k]);
    }
    


}




    return 0;
}