#include <stdlib.h>
#include <stdio.h>


/*
int numarbinar(int sex){

    int binar=0 , c=0 , binar_nou=0;

do{
       binar=(binar*10)+(sex%2);
       c=c+1;
       sex=sex/2;

    }while(sex!=0);

    for(int i=0 ; i<=c ; i++){
        binar_nou=(binar_nou*10)+(binar%10);
    }

}


*/




/*

int main(){

    int nr , binar=0 , c=0;

    printf("Introduceti numarul:");
    scanf("%d" , &nr);

    do{
       binar=(binar*10)+(nr%2);
       c=c+1;
       nr=nr/2;

    }while(nr!=0);

    for(int i=0 ; i<c ; i++){
        printf("%d" , binar%10);
        binar=binar/10;
    }
return 0;
}
  */


  int main(){

  int i , m , n;

  scanf("%d" , &m);
  scanf("%d" , &n);

  for(i=0 ; i<n ; ++i){

        m*=m;
    }

    printf("%d" , m);





  }
