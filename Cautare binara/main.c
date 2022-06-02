#include <stdio.h>
#include <stdlib.h>

void afisare(int v[] , int n){
    

for(int i=0 ; i<n ; i++){
        printf("%d" , v[i]);
    }
}

void citire(int v[] , int n){

    for(int i=0 ; i<n ; i++){
        printf("v[%d]=" , i);
        scanf("%d" , &v[i]);

        if((v[i]<1)||(v[i]>255)){
            printf("Valoarea introdusa nu face parte din multime");
            i--;
        }
        printf("\n");

    }


}

void sortare(int v[] , int n){

    int j=0;
    int temp;
    
    for(int j=0 ; j<n-1 ; j++){
    for(int i=j ; i<n ; i++){       //bubble sort vezi pe wikipedia
        if(v[j]>v[i]){
            temp=v[j];
            v[j]=v[i];
            v[i]=temp;
            
        }
        
            
    }

    }

    

    for(int i=0 ; i<n ; i++){
        printf("%d" , v[i]);
    }
    printf("\n");

    
}


void cautare(int v[] , int n , int m , int x){

    int p,ok=0;
    while(m<=n){

        int mid=(m+n)/2; //(m+n-1)/2



        if(x==v[mid])
            {

                printf("Am gasit numarul %d" , v[mid]);
                ok=1;
                p=mid;
                break;

            }


        if(x>v[mid])

            if((n-mid)%2==0)
                m=mid;
            else
                m=mid+1;



        if(x<v[mid])
            if((mid-m)%2==0)
                n=mid;
            else
                n=mid-1;






    }


    if(ok==1)
        printf("\nNumarul %d a fost gasit pe pozitia %d", x,p);
    else
        printf("\n Numarul nu a fost gasit");


}


int main(){

    int v[100];
    int n;
    int x;

    do{
    printf("Introduceti dimensiunea vectorului:");
    scanf("%d" , &n);
    }while(((n<7)||(n>21))||(n%2==0));    //cand fac cu do while se inverseaza si operatorii logici

    printf("Introduceti elementul cautat:");
    scanf("%d" , &x);     //elementul cautat

    citire(v , n);

    sortare(v , n);  //vectorul a fost sortat

    cautare(v , n , 0 , 78);







    return 0;
}