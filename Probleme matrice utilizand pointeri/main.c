#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int *citirematrice(int *M , int *dim1 , int *dim2){  //i am facut pointeri pe dim1 si dim2 pt a retine adresele dim1 si dim2 alocate in timpul f main

    scanf("%d" , dim1);
    scanf("%d" , dim2);

    M=malloc((*dim1)*(*dim2)*sizeof(int));
    //tre sa fac o functie care returneaza prima locatie a lui M creeata la malloc
    //pt ca dupa ce se termina functia programul nu mai stie unde este
    //deoarece locatia e creeata pe baza unei "variabile copie" creeata de functie
    //si cum ea se sterge nu mai am nicio legatura la locatia aceea de memorie

    for(int i=0 ; i<*dim1 ; i++){
        for(int j=0 ; j<*dim2 ; j++)
        scanf("%d" , M+i*(*dim2)+j);
    }

    return M; 
    //returnez variabila M de tip pointer care a retinut adresa primei val a matricii
    //creeate prin functia malloc in aceasta functie
}

void afisare_diag_principala(int *M , int dim1 , int dim2){  //aici nu tre sa mai scriu pointer la dim-uri ca le am citit deja si daca scriu dim stim care e

    printf("Afisare diagonala principala");
    printf("\n");
    printf("=================================================");
    printf("\n");

    for(int i=0 ; i<dim1 ; i++){
        
        printf("%d " , *(M+i*dim2+i));
    }
    printf("\n");
}

void afisare_diag_secundara(int *M , int dim1 , int dim2){  //aici nu tre sa mai scriu pointer la dim-uri ca le am citit deja si daca scriu dim stim care e

    printf("Afisare diagonala secundara");
    printf("\n");
    printf("=================================================");
    printf("\n");

    for(int i=0 ; i<dim1 ; i++){
        
        printf("%d " , *(M+i*dim2+(dim1-i-1)));
    }
    printf("\n");
}

void afisare_elem_sub_d_principala(int *M , int dim1 , int dim2){

    printf("Afisare elemente de sub diag principala");
    printf("\n");
    printf("=================================================");
    printf("\n");

    for(int i=1 ; i<dim1 ; i++){

        printf("\n");
        for(int j=0 ; j<i ; j++)
        printf("%d " , *(M+i*dim2+j));  
    }
    printf("\n");
}

void afisare_elem_deasupra_d_principala(int *M , int dim1 , int dim2){  //se urmareste pe indicii din matricea "vectorizata"/"colonizata"

    printf("Afisare elemente deasupra diag principala");
    printf("\n");
    printf("=================================================");
    printf("\n");

    for(int i=0 ; i<dim1-1 ; i++){

        printf("\n");
        for(int j=i+1 ; j<dim2 ; j++)
        printf("%d " , *(M+i*dim2+j));  
    }
    printf("\n");
}

void afisare_elem_sub_d_secundara(int *M , int dim1 , int dim2){  //se urmareste pe indicii din matricea "vectorizata"/"colonizata"

    printf("Afisare elemente sub diag secundara");
    printf("\n");
    printf("=================================================");
    printf("\n");

    for(int i=1 ; i<dim1 ; i++){

        printf("\n");
        for(int j=dim2-i ; j<dim2 ; j++)
        printf("%d " , *(M+i*dim2+j));  
    }
    printf("\n");
}

void afisare_elem_deasupra_d_secundara(int *M , int dim1 , int dim2){  //se urmareste pe indicii din matricea "vectorizata"/"colonizata"

    printf("Afisare elemente deasupra diag secundara");
    printf("\n");
    printf("=================================================");
    printf("\n");

    for(int i=0 ; i<dim1-1 ; i++){

        printf("\n");
        for(int j=0 ; j<dim2-1-i ; j++)
        printf("%d " , *(M+i*dim2+j));  
    }
    printf("\n");
}

void afisarematrice_transpusa(int *M , int dim1 , int dim2){

    printf("Afisare matrice transpusa");
    printf("\n");
    printf("=================================================");
    printf("\n");

    for(int j=0 ; j<dim2 ; j++){
        printf("\n");
        for(int i=0 ; i<dim1 ; i++)
        printf("%d " , *(M+i*dim2+j));  
        
    }
    printf("\n");
}

void afisarematrice(int *M , int dim1 , int dim2){

    printf("Afisare matrice");
    printf("\n");
    printf("=================================================");
    printf("\n");

    for(int i=0 ; i<dim1 ; i++){
        printf("\n");
        for(int j=0 ; j<dim2 ; j++)
        printf("%d " , *(M+i*dim2+j));  
        //adun nr de coloane din spate + nr actuale ca practic matricea vectorizata este (colonizata) deoarece are o linie si restu coloane
        //si de aceea tre sa inmul. cu dim2 pt ca reprezinta nr de coloane deja parcurse(practic parcurg cele 3 coloane * cate linii sunt si aflu nr total de coloane a matricii "colonizate")
    }
    printf("\n");
}

int main(){

    int dim1,dim2;
    int *M;

    M=citirematrice(M , &dim1 , &dim2);  //dam adresele lui dim1 si dim2 din main ca f sa lucreze direct la acestea 
    //adica citirea (care are loc in functia citirematr) sa aiba loc la adresele alocate in timpul f main 
    //se executa functia iar M ul din main ia valoarea creeata prin malloc in functia de citire
    //asta pt a stii dupa ce se taie legatura cu functia , unde am pus M ul cat timp am folosit functia
    //(functia creeaza var "copie" si dupa prin malloc am alocat undeva dinamic si legatura cu acea adresa
    //a fost prin variabila copie creeata initial(var M) ,  care a fost stearsa dupa exec functiei
    //deci prin return M , f returneaza acea adresa din mem dinamica pt a putea sa o folosim si in main

    printf("\n");
    afisarematrice(M , dim1 , dim2);
    printf("\n");
    afisare_diag_principala(M , dim1 , dim2);
    printf("\n");
    afisare_diag_secundara(M , dim1 , dim2);
    printf("\n");
    afisare_elem_sub_d_principala(M , dim1 ,dim2);
    printf("\n");
    afisare_elem_deasupra_d_principala(M , dim1, dim2);
    printf("\n");
    afisare_elem_sub_d_secundara(M , dim1 , dim2);
    printf("\n");
    afisare_elem_deasupra_d_secundara(M , dim1 , dim2);
    printf("\n");
    afisarematrice_transpusa(M, dim1 , dim2);


    return 0;
}