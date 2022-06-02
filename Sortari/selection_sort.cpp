#include <iostream>

using namespace std;

void print_arr(int arr[] , int n){

    for(int i=0 ; i<n ; i++)
    cout<<arr[i]<<" ";

}


void selection_sort(int arr[] , int n){

    int min;
    int index;
    int tmp;
    for(int i=0 ; i<n ; i++){

        min=arr[i];
        //cout<<min;
        index=i;
        for(int j=i ; j<n ; j++){

            if(arr[j]<min){
                min=arr[j];
                index=j;
            }

        }

        //print_arr(arr , n);
        //cout<<"Min:"<<min<<" "<<"i:"<<i<<" "<<"index minim:"<<index<<" "<<"\n";
        //print_arr(arr , n);
        //cout<<" ";

        //swap

        tmp=arr[i];
        arr[i]=arr[index];
        arr[index]=tmp;

        //print_arr(arr , n);
        
        //cout<<"\n";

    }
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0 ; i<n ; i++)
    cin>>arr[i];


    selection_sort(arr , n);
    print_arr(arr , n);

    // Complexitate : O(n^2)

    return 0;
}