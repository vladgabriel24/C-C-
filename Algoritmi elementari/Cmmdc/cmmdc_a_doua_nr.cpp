#include <iostream>

using namespace std;

// mod iterativ (Algoritmul lui Euclid)
int cmmdc(int x , int y){

    int rest;
    int d=x;
    int i=y;
    
    do{

        rest=d%i;
        d=i;
        i=rest;

        if(d%i==0) { // Atentie la impartirea cu 0
            
            if(rest==1) // Caz : prime intre ele
            return 0; 
            
            return rest;

        }

        /*
            La d%i trebuie sa incheiem prematur functia deoarece
            atunci d%i da 0 pt ca numerele se impart perfect dar,
            dupa aceea i ul devenind restul (conform algoritmului lui Euclid)
            la urm iteratie vom efectua o impartire la 0 (la instructiunea d%i)
            deoarece MOD imparte d la i si ne da 0 si cum noi impartim la 0
            programul se va oprii FARA MESAJ DE EROARE.
        */

    }while(1);
    
}

//mod recursiv
int cmmdc_recursion(int x , int y){

    if(x%y==0){
        
        if(y==1) // Caz : prime intre ele
        return 0;
        
        return y;
    }

    return cmmdc_recursion(y , x%y);
}

int main(){

    int x , y;

    cin>>x>>y;

    cout<<cmmdc(x , y)<<"\n";
    cout<<cmmdc_recursion(x , y);

    return 0;
}