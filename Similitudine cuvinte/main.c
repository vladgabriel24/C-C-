#include <stdio.h>
#include <stdlib.h>

int lungimesir(char sir[]){

    int l=0 , i=0;

    while(sir[i]!='\0'){
        l++;
        i++;
    }


return l;
}





int main(){

    char sir1[100] , sir2[100];
    int egal;

    printf("Introduceti sirul 1:");
    printf("\n");
    scanf("%s" , sir1);

    printf("Introduceti sirul 2:");
    printf("\n");
    scanf("%s" , sir2);

    //sirurile comparate trebuiesc fie egale , a fi un sir egal => 'vlad'='vlad'

    if(lungimesir(sir1)==lungimesir(sir2)){

    for(int i=0 ; i<lungimesir(sir1);i++){   //sau i<lungimesir(sir2)
        if(sir1[i]==sir2[i]){
            egal=0;    //val 0 inseamna sir e similar
        }else{
            egal=1;   //val 1 inseamna sirul nu e similar
        }

    }
    
    }else{
        egal=0;
    }

    printf("%d" , egal);

    return 0;
}