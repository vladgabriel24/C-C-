#include <stdio.h>
#include <stdlib.h>

int main(){

    int v[50] , n ,i , j , k;

    printf("Introduceti dimensiunea vectorului:");scanf("%d",&n);

    for(i=0 ; i<=n ; i++){

        printf("v[%d]=" , i);
        scanf("%d", &v[i]);    //citirea vectorului
    }

    for(i=0 ; i<=n ; i++){
        for(j=i+1 ; j<=n ; j++){

            if(v[i]==v[j]){

                for(k=i ; k<=n ; k++){

                    v[k]=v[k+1];
                }

                n--;
                j--;  //deoarece atunci cand da de mai mult de 1 duplicat trebuie sa verifice iar de la j ul cu pricina
            }
        }
    }

    for(i=0 ; i<=n ; i++){

        printf("%d" , v[i]);
    }

    return 0;
}
