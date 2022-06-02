//bitii unui double (8 bytes)

#include <stdio.h>
#include <stdlib.h>

union numar
{
    char x[8];
    double nr;

};



int main(){

    /*
    Tipul de date union ocupa memorie egala in valoare cu 
    elementul cu cel mai mare(int bytes)tip de date gasit in el

    De fiecare data cand citim de la tastatura un element din union
    in acel bloc de memorie se va scrie in modul urmator:
    -daca se citeste un element egal in marime cu marimea uniunii,
    pur si simplu se aloca de la prima adresa pana la ultima acea valoare
    (in cod binar spart in nr de bytes care sunt)
    -daca se citeste un element mai mic in marime decat marimea uniunii,
    se va aloca REPETAT acel element in blocul de memorie al uniunii pana se umple
    ex: daca am uniunea de marime double(8 bytes) si citesc un char(1 byte) 't'
    in acele 8 casute se va aloca 't' in mod repetat pana la umplere
    -nu exista ceva mai mare decat uniunea ca ea alege ce i cel mai mare

    De fiecare data cand introducem de la tastatura un element din union , 
    daca mai facem o citire , acea citire va SUPRASCRIE ce am citit initial
    ex: union de marim double(8 bytes) si citesc un char (1 byte) 'c'
    va arata de genu |t||t||t||t||t||t||t||t|
    daca dupa citesc un 'c' va arata |c||c||c||c||c||c||c||c|
    -daca citesc cv mai mic se umple si dupa daca citesc iar cv mic se suprascrie si se umple
    -si daca ct cv mic se umple si ct iar cv egal cu union se suprascrie
    

    */

    union numar nr;
    scanf("%lf" ,&nr.nr); 
    //cu scanf practic: cand zici %(ce vrei sa citesti) practic
    //ii spui cata memorie vrei sa ocupi 
    //si apoi cand introduci de la tastatura practic
    //ii spui si CU CE vrei sa ocupi acea memorie

    for(int i=0 ; i<8 ; i++)
    printf("%i " , nr.x[i]);
    //cu printf practic: cand zici %(ce vrei sa afisezi) practic
    //ii spui cata memorie vrei sa intre in fluxul de afisaj din acel union
    //si ce gaseste acolo afiseaza sub formatul pe care l ai cerut
    //cand alegi ce afisezi , practic alegi ce zona de memorie intra in fluxul de afisaj





    return 0;
}