#include<stdio.h>

/* selection sort compares each element with all the elements to its right
and swaps the smallest element with that element
*/


int main(){
    #define N 7
    int arr[N]={9,3,5,7,1,2,8};

    /*
    9 & 1 => 1 3 5 7 9 2 8
    3 & 2=> 1 2 5 7 9 3 8
    5 & 3 => 1 2 3 7 9 5 8
    7 & 5 => 1 2 3 5 9 7 8
    9 & 7 => 1 2 3 5 7 9 8
    8 & 9 => 1 2 3 5 7 8 9
    */
    
    printf("Unsorted array: ");
    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }

    for(int i=0;i<N-1;i++){
        int min=i;
        for(int j=i+1;j<N;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }

    printf("\nSorted array: ");

    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }


    return 0;
}