#include <iostream>

using namespace std;

float power_divide_et_impera(int x, int y)
{
    if(y==0) return 1;
    if(y==1) return x;

    if(y<0) return 1/power(x, -y);

    float val=x;

    for(int i=1; i<y/2; i++)
    val*=x;

    if(y%2==0) return val*val;
    else return val*val*x;
}

int main()
{
    cout<<power_divide_et_impera(3, 0);

    return 0;
}