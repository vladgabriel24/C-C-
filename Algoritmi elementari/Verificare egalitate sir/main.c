#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lungime_sir(char *sir){

    int i;

    for(i=0 ; *(sir+i)!='\0' ; i++);
    
    return i;
}

int egalitate_sir(char *sir1 , char *sir2){

    if(lungime_sir(sir1)==lungime_sir(sir2)){

        for(int i=0 ; i<lungime_sir(sir1) ; i++){

            if(*(sir1+i)!=*(sir2+i))
            return 0;
        }
        return 1;

    }else
    return 0;
}

int main(){

    char *sir1=malloc(31*sizeof(char));
    char *sir2=malloc(31*sizeof(char));

    scanf("%s%s" , sir1 , sir2);

    printf("%d" , egalitate_sir(sir1 , sir2));

    return 0;
}