#include <iostream>

int *merge(int arr1[] , int arr2[] , int p , int q){

    int *C=(int *)malloc((p+q)*sizeof(int));

    int i=0;
    int j=0;
    int k=0;

    while((i<p)&&(j<q)){

        /*

            Aici am pus un "si logic" deoarece vreau ca while-ul
            sa mearga cat timp ambii vectori nu au fost epuizati.

            Daca la DOAR UNUL DINTRE EI s-a ajuns la final
            in "si - ul logic" va intra un A && F = F deci nu
            se va mai intra in bucla (sau daca ambele au ajuns 
            la final F&&F=F)

        */

        if(arr1[i]<=arr2[j]){

            C[k]=arr1[i];
            i++;
            k++;
        }else if(arr1[i]>arr2[j]){

            C[k]=arr2[j];
            j++;
            k++;
        }
    }

    /*

        Daca doar unul dintre vectori au fost epuizati cu prima bucla
        , verific dupa aceea care dintre ei inca mai pot merge pana la capat
        si cu aceea umplu ce a ramas in rest in ei , in vectorul mare C

    */

    if(i<p){

        while((i<p)&&(k<p+q)){

            C[k]=arr1[i];
            k++;
            i++;
        }
    } 
    
    if(j<q){

        while((j<q)&&(k<p+q)){

            C[k]=arr2[j];
            k++;
            j++;
        }
    }

    return C;
}

int *merge_sort(int arr[] ,int left , int right ,int n){

    if(n==1){

        int *V=(int *)malloc(sizeof(int));
        
        V[0]=arr[left];

        /*
            Aici va fii mereu left , deoarece cand se ajunge la n=1
            (asta pt ca n ul trimis prin valoare la apelul trecut face 1)
            for(int i=left ; i<right ; i++) se va executa doar odata
            si acea data pt arr[left].

        */
      
        return V;
    }

    int mid=left+n/2;

    /*
        Faci desenul unei executii al algoritmului 
        si deduci cum se calculeaza jumatatea si
        cum se desparte vectorul in 2 si ce lungimi au jumatatile

        Atentie!: pt A , se considera ca mid este capatul cu <mid , deci A[mid] nu se va atinge

        pt B: mid de data asta este capatul cu =mid deci se va atinge , dar right nu se va atinge pt ca e <right

        De aceea am putut sa transmit n ul prim mid-left sau right-mid (nu a mai trebuit sa scad 1
        deoarece mid si respectiv right sunt capete deschise , deci valoric cand scad left sau respectiv mid 
        nu mai trebuie sa adun 1 pt ca deja am 1 in plus de la valoarea capatului deschis)

    */

    int *A=merge_sort(arr , left , mid , mid-left);
    int *B=merge_sort(arr , mid , right , right-mid);
    int *C=merge(A , B ,mid-left,right-mid);
    
    return C;

    /*

        Dat fiind ca pt fiecare vector curent , se desparte in 2
        si in cele 2 jumatati se lucreaza iar , relatia de
        recurenta pentru operatiile executate este:

        T(n)=T(n/2)+T(n/2)+c*n=2T(n/2)+c*n
        unde:

        T(n/2) reprezinta operatiile executate la fiecare jumatate in care se imparte vectorul T(n)
        c*n reprezinta operatiile executate te functia merge

        Rezulta conform Master's Theorem: O(nlogn) complexitate

    */
}


int main(){

    int n;
    
    int arr[]={7,2,5,3,7,13,1,12};

    n=sizeof(arr)/sizeof(int);

    int *A;

    A=merge_sort(arr ,0,n, n);

    print_arr(A , 0 , n);

    return 0;
}