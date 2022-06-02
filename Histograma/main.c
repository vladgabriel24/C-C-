#include <stdio.h>
#include <stdlib.h>

void citire_vector(int v[] , int n){

    for(int i=0 ; i<n ; i++){
        
        scanf("%d" , &v[i]);

            if((v[i]>9)||(v[i]<0)){
                i--;
            }
    }

}
void histograma(int v[] , int n , int h[])
{
/*
creeaza un vector de frecventa unde indicii reprezinta numerele din vectorul
pe care il procesam iar la indicii respectivi vom stoca nr de aparitii al acelui nr
*/

  for(int i=0 ; i<=9 ; i++){
      h[i]=0;
      for(int j=0 ; j<n ; j++){

            if(v[j]==i){
              h[i]++;

          }

      }

  }

    /*
    for(int i=0 ; i<=9 ; i++){
      printf("%d" , h[i]);

  }

 */

}

int minim(int v , int n){

    if(v<n)
        return v;
    else
        return n;
    

}

void distanta_histograme(int h1[] , int h2[]){

    int suma=0;

    for(int i=0 ; i<=9 ; i++){

        suma=suma+minim(h1[i],h2[i]);
    }

    printf("%d" , suma);

}

int main(){

    int n;
    int v[100] , m[100];
    int h1[100] , h2[100];

    printf("Introduceti dimensiunile vectorilor:");scanf("%d" , &n);
    citire_vector(v , n);
    citire_vector(m , n);
    histograma(v , n , h1);
    histograma(m , n , h2);
    distanta_histograme(h1 , h2);
    





    return 0;
}