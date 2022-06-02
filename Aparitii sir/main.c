#include <stdio.h>
#include <stdlib.h>

int main()
{

    int c=0 ;
    char s1[50] , s2[50];

    printf("Introduceti literele:");
    printf("\n");
    scanf("%s" , s1);

    printf("Introduceti sirul:");
    printf("\n");
    scanf("%s" , s2);

    for(int i=0 ; i<strlen(s1) ; i++){  //s2
        for(int j=0 ; j<strlen(s2) ; j++){ //s1
            if(s1[i]==s2[j]){
                    c++;

        }
        }

    }

    printf("%d" , c/strlen(s1));




    return 0;
}
