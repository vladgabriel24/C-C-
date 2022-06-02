#include <stdio.h>
#include <stdlib.h>

enum materii{
    fizica,
    mate,
    bio
};

enum facultate{ lab , curs , seminar };


/*

Enumeratia practic este o serie de "#define" uri
de constante(denumiri de constante) in mod ordonat.
Daca nu dai nicio valoare incepe de la 0
Daca la primul dai valoare 1 el enumera 1 2 3 4
Daca la primul dai val 1 si la al doilea 3 o sa fie 1 3 4 5 6
Daca la primul dai val 1 si la al 3 lea dai 7 o sa fie
1 2 7 8 9
etc.

Acest tip de date defineste by default constante intregi de la 0
la cate "denumiri se gasesc acolo".

In doua enum uri nu se pot regasii aceleasi "notatii"/"denumiri"

In memorie nu se aloca nimic pt ca noi doar definim constante.

Va ocupa memorie VARIABILA DECLARATA de acest tip
si atunci va depinde de ce constante anume definim(3.14 , 3 , etc)

Practic frumusete este de ex daca avem o enumeratie enum materr {mate , fizica , bio};
si declaram o variabila de acest tip 
in loc sa scriem var=1 putem scrie var=fizica(adica =1) sau var=++fizica(adica ++1=2) sau var=--bio(--2=1)

Diferenta dintre enum si #define este ca enum ul putem sa il punem intr-o functie
si astfel este cu scop local
pe cand #define ul putem sa il punem numai in locul pt directive de preprocesare
loc unde totul este definit global

*/

int main(){


    enum materii cursuri;

    enum facultate activitati;

    // cursuri=fizica;// adica 0
    // activitati=lab; //adica 0

    
    for(cursuri=fizica ; cursuri<=bio ; cursuri++){ //adica cursuri care ia valori de la 0 la 2 inclusiv
        for(activitati=lab ; activitati<=seminar ; activitati++){ //adica activitati care ia valori de la 0 la 2 inclusiv

        //de ex vr sa adun prezentele
        int prezente=0;
        //adun aici sau fac ce vr yo

        }
    }

    //practic "infrumuseteaza" sau ajuta pt denumirea valorilor pt a le recunoaste mai bn


    return 0;
}