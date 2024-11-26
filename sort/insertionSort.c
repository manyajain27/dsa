#include<stdio.h>

//insertion sort
/*
we start from the 2nd element and compare it with the previous element
if the previous element is greater than the current element then we shift the previous element to the right
and insert the current element at the correct position
we repeat this process for all the elements in the array
*/

int main(){
    
    #define N 7
    int arr[N]={9,3,5,7,1,2,8};

    printf("Unsorted array: ");
    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }

    for(int i=1;i<N;i++){
        int current=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>current){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current; // since j becomes -1 when we reach the first element 
    }                       //so we increment j by 1 to get the correct position


    printf("\nSorted array: ");
    //sorted array
    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}