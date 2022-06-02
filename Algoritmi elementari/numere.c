#include <stdio.h>
#include <stdlib.h>

int power(int x, int y)
{

    if(y==1) return x;
    if(y==0) return 1;

    int val=x;

    for(int i=2; i<=y; i++)
    val*=x;

    return val;
}

int main()
{

    int x=12543;

    int V[100];

    int l=0;

    int tmp=x;
    while(tmp)
    {
        tmp/=10;
        l++;
    }

    int k=l;
    int tmp2=x;
    while(tmp2)
    {
        V[--k]=tmp2%10;
        tmp2/=10;
    }

    for(int i=0; i<l; i++)
    printf("%d", V[i]);
    printf("\n");

    int p=l-1;
    while(p!=-1)
    {
        printf("%d ", x/power(10,p--));
    }



    return 0;
}