#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char s1[50] , s2[50] , i=0 , j=0 , k=0;

    printf("Introduceti sirul:");   //i
    scanf("%s" , s1);

    printf("Introduceti literele:");  //j
    scanf("%s" , s2);


    for(j=0 ; j<strlen(s2) ; j++){
        for(i=0 ; i<strlen(s1) ; i++){

            if(s2[j]==s1[i]){
                for(k=i ; k<strlen(s1) ; k++){
                    s1[k]=s1[k+1];
                }
                i--;

            }
        }
    }

    printf("%s" , s1);







    return 0;
}
