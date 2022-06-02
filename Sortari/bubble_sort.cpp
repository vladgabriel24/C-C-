#include <iostream>

void print_arr(int arr[] , int n){

    for(int i=0 ; i<n ; i++)
    std::cout<<arr[i]<<" ";

}

void bubble_sort(int arr[] , int n){

    print_arr(arr , n);
    std::cout<<"\n";

    int tmp;
    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<n-1-i ; j++){

            //swap
            if(arr[j]>arr[j+1]){

                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }

        }
    }

    print_arr(arr , n);
}

int main(){

    int n;
    
    int arr[]={0,2,2,2,5};

    n=sizeof(arr)/sizeof(int);

    bubble_sort(arr , n);


    return 0;
}