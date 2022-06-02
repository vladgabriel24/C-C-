#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void is_palindrom(int x){
     
    int inverse=0;
    int copy=x;
     
    while(copy!=0){
           
        inverse=inverse*10+(copy%10);
        copy=copy/10;
    }
    
    if(inverse==x)
    printf("Numarul este un palindrom!");
    else
    printf("Numarul nu este un palindrom!"); 
}

// O(nr_de_cifre)

int main(){
    
    is_palindrom(12321);
    
    return 0;
}