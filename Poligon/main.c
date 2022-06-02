#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int M[100][100] , nr , j;
    float p=0 , q=0 , perimetru=0 ;

    do{
        printf("Introduceti nr de puncte:");
        scanf("%d" , &nr);

    }while(nr>10);

    for(int i=0 ; i<nr ; i++){
        for(int j=0 ; j<2 ; j++){
            printf("M[%d][%d]= ", i , j);
            scanf("%d" , &M[i][j]);
        }
    }



    for(int i=0 ; i<nr ; i++){

            j=0;

            if(i==nr-1){
                q=(M[i][j]-M[0][j])*(M[i][j]-M[0][j]);
                p=(M[i][j+1]-M[0][j+1])*(M[i][j+1]-M[0][j+1]);
                perimetru=perimetru+sqrt(p+q);
                //printf("%f" , q);
                //printf("%f" , p);
                //printf("final");
                //printf("\n");

            }else{

           q=(M[i][j]-M[i+1][j])*(M[i][j]-M[i+1][j]);
           p=(M[i][j+1]-M[i+1][j+1])*(M[i][j+1]-M[i+1][j+1]);
           perimetru=perimetru+sqrt(p+q);
           //printf("%f" , q);
            //printf("%f" , p);
            //printf("sex");
            //printf("\n");
            }
            }
            //printf("\n");

        printf("%.2f" , perimetru);




    return 0;
}
