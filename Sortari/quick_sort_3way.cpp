#include <iostream>
#include <cstdlib>
#include <time.h>

void print_arr(int arr[] , int n){

    for(int i=0 ; i<n ; i++)
    std::cout<<arr[i]<<" ";

}

void print_arr_recursion(int arr[] , int left , int right){

    for(int i=left ; i<right ; i++)
    std::cout<<arr[i]<<" ";

}

int partition(int arr[] , int left , int right){

    int tmp;

    srand(time(NULL));
    int random=left+rand()%(right-left);

    tmp=arr[left];
    arr[left]=arr[random];
    arr[random]=tmp;

    int pivot=arr[left];

    int j=left;
    
    for(int i=left+1 ; i<=right ; i++){

        if(arr[i]<pivot){

            tmp=arr[j+1];
            arr[j+1]=arr[i];
            arr[i]=tmp;

            j++;
        }
    }

    tmp=arr[j];
    arr[j]=pivot;
    arr[left]=tmp;

    return j;
}

void quick_sort(int arr[] , int left , int right){

    if(left>=right)
    return;

    int mid=partition(arr ,left ,right);

    quick_sort(arr , left , mid-1);
    quick_sort(arr , mid+1 , right);
}

int main(){

    
    int n;
    std::cin>>n;

    int arr[n];
    for(int i=0 ; i<n ; i++)
    std::cin>>arr[i];
   
    quick_sort(arr , 0 , n-1);

    print_arr(arr , n);

    return 0;
}