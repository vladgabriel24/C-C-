#include <stdio.h>
#include <stdlib.h>

int main(){


    int v[20];
    int lungime;

    lungime=sizeof(v);///sizeof(int);

    printf("%d" , lungime);

    //operatorul arata cata memorie ocupa vectorul
    //indiferent daca au fost citite valori la toata memoria sau nu

    //ex: v[5]={2 , 3} , sizeof(v)= 5*4bytes=20bytes

    //ex: v[5]={2 , 3 , 4} , sizeof(v)= 5*4bytes=20bytes

    //ex: v[200]={2} , sizeof(v)= 200*4bytes=800bytes

    //practic cat este dimensiunea vectorului (la declaratie) , atata memorie ocupa si sizeof asta ne arata
    //daca este citit ceva la acel bloc inlantuit de memorie asta e partea a 2a
    //ca oricum si daca nu e citit se vor pune by default garbage values deci cat e declarat atat ocupa indiferent de citiri!

    //In concluzie : aceasta metoda de aflare a lungimii este buna daca marimea de memorie a vectorului este aceeasi cu ce citesc in el
    //Deci la alocare dinamica , sau si la static da daca folosescc v[n]




    return 0;
}