#include <iostream>
#include <fstream>

// {123}x{123}x{123}

using namespace std;

int X[20];
int n;

ifstream fin("permutari.in");
ofstream fout("permutari.out");

int is_valid(int k, int val)
{
    for(int i=0; i<k; i++)
        if(val==X[i]) return 0;

    return 1;
}

void afisare(int k)
{
    for(int i=0; i<k; i++) fout<<X[i]<<" ";
    fout<<endl;
}

void bkt(int k)
{
    for(int i=0; i<n; i++)
    {
        X[k]=i+1;
        if(is_valid(k, X[k])) //is valid
        {
            //verificare final
            if(k==n-1)
            {  
                // daca da: afisare
                afisare(k+1);
            }
            else
            {
                // daca nu: bkt(k+1)
                bkt(k+1);
            }
        }
    }
}

int main()
{

    fin>>n;
    bkt(0);




    return 0;
}