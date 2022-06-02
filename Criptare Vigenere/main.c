#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lungimesir(char sir[]);
void extindesir(char sir[] , int n);

int lungimesir(char s1[]){

    int i,l=0;

    for(i=0 ; s1[i]!='\0' ; i++){
        l++;
    }


return l;
}



void extindesir(char s2[] , int k){

    char s1[50];
    int i=0,j , n;

    n=strlen(s2);
    for(j=0 ; j<k ; j++){
        if(i>n-1){
            i=0;                            //cand folosesc void practic zic sa se execute ce am scris in functie
        }
        s1[j]=s2[i];
        i++;
    }

    printf("%s" , s1);

}

int main(){

    char s1[50];
    int k;
    scanf("%d" , &k);
    scanf("%s" , s1);

    printf("%d" , lungimesir(s1));

    extindesir(s1,k);


    return 0;
}
