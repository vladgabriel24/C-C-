#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char sir[100] ;
    int nr[50];
    int roman=0;
    int k;
    int c;

    scanf("%s" , sir);

    for (int i = 0; i < strlen(sir); i++){

    if(sir[i]=='I'){
        nr[i]=1;
    }
    if(sir[i]=='V'){
        nr[i]=5;
    }
    if(sir[i]=='X'){
        nr[i]=10;
    }
    if(sir[i]=='L'){
        nr[i]=50;
    }
    if(sir[i]=='C'){
        nr[i]=100;
    }
    if(sir[i]=='D'){
        nr[i]=500;
    }
    if(sir[i]=='M'){
        nr[i]=1000;
    }
    }

    for (k=0;k<strlen(sir)-1;k++){
        c=0;
            if(nr[k]<nr[k+1]){
                roman=roman+(nr[k+1]-nr[k]);
                k++;
                c=1;
            }else{
                roman=roman+nr[k];
            }
        
    }

    if((k=strlen(sir)-1)&&(c==0)){
                roman=roman+nr[k];
            }

                printf("%d" , roman);


/*

    for (int j = 0; j < strlen(sir); j++)
    {
        printf("%d" , nr[j]);
    }

*/

    return 0;
}
