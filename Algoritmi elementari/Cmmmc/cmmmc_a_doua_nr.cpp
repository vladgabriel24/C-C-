#include <iostream>

using namespace std;

// metoda f ineficienta si nu merge cu nr mari
int cmmmc(int x , int y){

    if(x==y)
    return 1;

    for(int i=1 ; ;i++){

        if((x*i)%y==0)
        return x*i;
    }
}

/*

    Cel mai practic si eficient este sa ne folosim de proprietatea

    a * b = cmmdc(a,b) * cmmmc(a,b)

    De unde rezulta ca:

    (a * b) / cmmdc(a,b) = cmmmc(a,b)


*/

// Alg lui Euclid , vezi folderul cu cmmdc
int cmmdc(int x , int y){

    if(x%y==0)
    return y;

    return cmmdc(y , x%y);
}

int cmmmc_v2(int x , int y){


    return (x*y)/cmmdc(x,y);
}

int main(){

    int x , y;
    cin>>x>>y;

    cout<<cmmmc(x,y);
    cout<<cmmmc_v2(x,y);


    return 0;
}