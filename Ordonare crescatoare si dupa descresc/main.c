#include <stdio.h>
#include <stdlib.h>

int main(){

    int v1[50] , vpar[50] , vimp[50] ,n , i , j=0 , k=0, par=0 , impar=0;

    printf("Introduceti lungimea vectorului:");
    printf("\n");
    scanf("%d" , &n);

    printf("Introduceti sirul:");
    printf("\n");
        for(i=0;i<n;i++){
            scanf("%d" , &v1[i]);

        }

        for(i=0 ; i<n ; i++){
            if(v1[i]%2==0){
                vpar[j]=v1[i];
                j++;
                par++;
            }else{
                vimp[k]=v1[i];
                k++;
                impar++;
            }
        }

        printf("================================================");
        printf("\n");


        for(i=0;i<par;i++){
            printf("%d",vpar[i]);
        }

        for(i=0;i<impar;i++){
            printf("%d",vimp[i]);
        }

        //printf("%d" , par);
        //printf("\n");
       //printf("%d" , impar);
        //printf("\n");

    return 0;
}
