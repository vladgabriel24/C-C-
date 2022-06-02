#include <stdio.h>
#include <stdlib.h>

int main(){

    char litera;
    int ascii;

    printf("Introduceti litera:");
    scanf("%c" ,&litera);

    ascii=litera;

    if((ascii>=65)&&(ascii<=90)){
        printf("Ati introdus o litera mare");
    }else{
        printf("Ati introdus o litera mica");
    }

    //printf("%d" , ascii);



    return 0;
}
