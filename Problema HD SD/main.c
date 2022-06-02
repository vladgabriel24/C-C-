#include <stdio.h>
#include <stdlib.h>

void citirematrice(int M[][100] , int n , int m){

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d" , &M[i][j]);
        } 
    }
}

void afisarematrice(int M[][100] , int n , int m){

    for (int i = 0; i < n; i++){
        printf("\n");
        for (int j = 0; j < m; j++){
            printf("%d" , M[i][j]);
            printf(" ");
        } 
    }
}

void extragerematrice(int M[][100] , int N[][100], int k , int x , int y){

    int m=0 , n=0;

    for(int i=x ; i<x+k ; i++){
        for(int j=y ; j<y+k ; j++){
            N[n][m]=M[i][j];
            m++;
        }
        m=0; //resetez m ul pt a nu creste pana in pizda masii
        n++;
    }

    for(int i=0 ; i<k ; i++){
        printf("\n");
        for(int j=0 ; j<k ; j++){
            printf("%d" , N[i][j]);
            printf(" ");
        }
    }
}

int minim_matrice(int M[][100] , int n , int m){

    int min=M[0][0];

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(M[i][j]<min)
            min=M[i][j];
        }
    }
    return min;
}

void suprascriere(int M[][100] , int m , int n ,int k , int x , int y , int val){

    for(int i=x ; i<x+k ; i++){
        for(int j=y ; j<y+k ; j++){
           M[i][j]=val;
        }
    }

    for (int i = 0; i < n; i++){
        printf("\n");
        for (int j = 0; j < m; j++){
            printf("%d" , M[i][j]);
            printf(" ");
        } 
    }


}

void scadere_matrici(int M[][100] ,int N[][100] , int E[][100],  int n , int  m){

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d" , &N[i][j]);
        } 
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            E[i][j]=M[i][j]-N[i][j];
        } 
    }

    for (int i = 0; i < n; i++){
        printf("\n");
        for (int j = 0; j < m; j++){
            printf("%d" , E[i][j]);
            printf(" ");
        } 
    }
}

int main(){

    int test;
    int M[100][100];
    int n , m;
    
    printf("Introduceti dimensiunile matricii:");scanf("%d" , &n);scanf("%d" , &m);
    citirematrice(M , n , m);
    printf("Introduceti valoarea de test: ");scanf("%d" , &test);

    if(test==1)
    afisarematrice(M , n , m);

    if(test==2){

        int k , x , y;
        int N[100][100];

        printf("Introduceti dimensiunea submatricii: ");scanf("%d" , &k);
        printf("Introduceti coordonatele punctului de extragere: ");scanf("%d" , &x);scanf("%d" , &y);
        extragerematrice(M , N , k , x , y);
    }

    if(test==3)
    printf("%d" , minim_matrice(M , n , m));

    if(test==4){
        int k , x , y , val;

        printf("Introduceti dimensiunea submatricii: ");scanf("%d" , &k);
        printf("Introduceti coordonatele punctului de extragere: ");scanf("%d" , &x);scanf("%d" , &y);
        printf("Introduceti valoarea de suprascriere: ");scanf("%d" , &val);

        suprascriere(M , m , n , k , x , y , val);
    }

    if(test==5){

        int E[100][100] , N[100][100];
        scadere_matrici(M , N , E , n , m);
    }

    if(test==6){
        int N[100][100] , P[100][100] , E[100][100];

        for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            N[i][j]=M[i][j];
        } 
        }

        extragerematrice(M , P , 2 , 0 , 0);
        suprascriere(P , 2 , 2 , 2 , 0 , 0 , minim_matrice(P , 2 , 2));

        for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            N[i][j]=P[i][j];
        } 
        }

        extragerematrice(M , P , 2 , 0 , 2);
        suprascriere(P , 2 , 2 , 2 , 0 , 2 , minim_matrice(P , 2 , 2));

        for (int i = 0; i < 2; i++){
        for (int j = 2; j < 4; j++){
            N[i][j]=P[i][j];
        } 
        }

        extragerematrice(M , P , 2 , 2 , 0);
        suprascriere(P , 2 , 2 , 2 , 2 , 0 , minim_matrice(P , 2 , 2));

        for (int i = 2; i < 4; i++){
        for (int j = 0; j < 2; j++){
            N[i][j]=P[i][j];
        } 
        }

        extragerematrice(M , P , 2 , 2 , 2);
        suprascriere(P , 2 , 2 , 2 , 2 , 2 , minim_matrice(P , 2 , 2));

        for (int i = 2; i < 4; i++){
        for (int j = 2; j < 4; j++){
            N[i][j]=P[i][j];
        } 
        }

        // for (int i = 0; i < n; i++){
        //     printf("\n");
        // for (int j = 0; j < m; j++){
        //     printf("%d" , N[i][j]);
        //     printf(" ");
        // } 
        //}

        for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            E[i][j]=M[i][j]-N[i][j];
        } 
    }

        for (int i = 0; i < n; i++){
            printf("\n");
        for (int j = 0; j < m; j++){
            printf("%d" , E[i][j]);
            printf(" ");
        }
    }
    }
    return 0;
}