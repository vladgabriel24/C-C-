//   aabbbde
//    abde
//    2 3 1 0



#include <stdio.h>
#include <stdlib.h>

int lungimesir(char s1[]){

    int l=0;

    for(l ; s1[l]!='\0' ; l++);

    return l;
}

int main(){


    char s1[100] , s2[100];

    printf("Introduceti sirul:");scanf("%s" , s1);
    printf("Introduceti literele cautate:");scanf("%s" , s2);

    int l=lungimesir(s1);
    int p=lungimesir(s2);
    int k;

    for(int i=0 ; i<p ; i++){       //abde ->s2
        for(int j=0 ; j<l ; j++){    //aabbbde ->s1

            if(s1[j]==s2[i])
            k++;
        }
        printf("%d" , k);
        k=0;
    }



    return 0;
}