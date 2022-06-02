#include <stdio.h>
#include <stdlib.h>

int fib1(int x) // O(n^2) timp si O(1) spatiu
{
    if(x==0) return 0;

    if(x==1) return 1;

    return fib1(x-1)+fib1(x-2);
}

int fib2(int x) // O(n) timp si O(n) spatiu
{
    int F[2048];

    F[0]=0;
    F[1]=1;

    for(int i=2; i<=x; i++)
    F[i]=F[i-1]+F[i-2];

    return F[x];
}

int fib3(int x) // O(n) timp si O(1) spatiu
{
    int f1=0;
    int f2=1;

    int tmp;
    for(int i=2; i<=x; i++)
    {
        tmp=f1+f2;
        f1=f2;
        f2=tmp;
    }

    return f2;
}

int main()
{
    int indice=4;

    printf("%d\n", fib1(indice));
    printf("%d\n", fib2(indice));
    printf("%d\n", fib3(indice));

    return 0;
}