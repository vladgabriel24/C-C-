#include <stdio.h>
#include <stdio.h>



int minim(int v , int n){

    if(v<n)
        return v;
    else
        return n;
    

}

int main(){

    int n , m;

    printf("sex");
    scanf("%d" , &m);
    scanf("%d" , &n);

    printf("%d" , minim(m , n));


    return 0;
}


