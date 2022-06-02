#include <iostream>

void print_arr(int arr[] , int n){

    for(int i=0 ; i<n ; i++)
    std::cout<<arr[i]<<" ";

}

void insertion_sort(int arr[] , int n){

    for(int i=1 ; i<n ; i++){

        int k=i;
        int tmp;
        if(arr[i]<arr[i-1]){

            tmp=arr[i];
            
            while((arr[i]<arr[k-1])&&(k>=0))
            k--;

            for(int j=i ; j>=k ; j--)
            arr[j]=arr[j-1];

            arr[k]=tmp;

        }
    }
}

int main(){

    int n;

    int arr[]={8,7,8,7,7};

    n=sizeof(arr)/sizeof(int);
    
    insertion_sort(arr ,n);
    print_arr(arr , n);

    return 0;
}