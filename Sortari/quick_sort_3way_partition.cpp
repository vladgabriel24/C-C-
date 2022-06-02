#include <iostream>

void print_arr(int arr[] , int n){

    for(int i=0 ; i<n ; i++)
    std::cout<<arr[i]<<" ";

}

void partition(int arr[] , int left , int right){

    int pivot=arr[left];

    int j=left;
    int tmp;

    for(int i=left+1 ; i<right ; i++){

        if(arr[i]<pivot){

            tmp=arr[j+1];
            arr[j+1]=arr[i];
            arr[i]=tmp;

            j++;
        }
    }

    //swap j ul final cu left(adica cu pivotul)

    tmp=arr[j];
    arr[j]=pivot;
    arr[left]=tmp;

    // O(right) adica O(n)

}

int main(){


    int arr[]={6,4,2,6,6,3,8,9,6,10};
    int n;

    n=sizeof(arr)/sizeof(int);

    partition(arr ,0 ,n);

    print_arr(arr , n);




    return 0;
}