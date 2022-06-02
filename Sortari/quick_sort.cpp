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

    //swap j ul final cu left(adica cu pivotul)

    tmp=arr[j];
    arr[j]=pivot;
    arr[left]=tmp;

    // O(right) adica O(n)

    return j;
}

void quick_sort(int arr[] , int left , int right){

    if(left>=right)
    return;

    // print_arr_recursion(arr ,left ,right);
    // std::cout<<"\n";

    int mid=partition(arr ,left ,right);
    //std::cout<<"Mid este:"<<mid<<"\n";

    // print_arr_recursion(arr ,left ,right);
    // std::cout<<"\n\n";

    quick_sort(arr , left , mid-1);
    quick_sort(arr , mid+1 , right);

    /*
        Din nou , capetele din dreapta sunt capete deschise ,
        deci daca jumatatea din stanga merge de la low la mid-1
        eu voi pune low , mid <=> [low,mid)

        La fel la capatul din dreapta , care merge de la mid+1 la right
        ,voi pune mid+1 , right <==> [mid+1 , right)

    */
}

int main(){

    int arr[]={6,4,2,6,6,3,8,9,6,10};
    int n;

    n=sizeof(arr)/sizeof(int);

    quick_sort(arr , 0 , n-1);

    print_arr(arr , n);

    return 0;
}