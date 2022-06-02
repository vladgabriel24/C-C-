#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int nr , putere , c=0 , nr_test , zecimal=0 , test=4;

    printf("Introduceti numarul binar=");
    scanf("%d" , &nr);
    nr_test=nr;

    do{
        nr_test=nr_test/10;
        c++;

    }while(nr_test!=0);


    for(int i=0 ; i<=c ; i++){

        if(nr%10==1){
            zecimal=zecimal+pow(2,i);
        }

        nr=nr/10;
    }

    printf("%d" , zecimal);

return 0;
}
