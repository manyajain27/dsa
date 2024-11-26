#include<stdio.h>

//quicksort
/*
in quicksort we take the pivot and put all the elements smaller than pivot 
to its left and all the elements greater than pivot to its right
and then we recursively apply the same process to the left and right subarrays
*/

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i=low, j=high;
    while(i<j){
        
        while(arr[i]<=pivot && i<high){ //will increment i till we find a[i]>pivot
            i++;
        }
        while(arr[j]>pivot){ //will decrement j till we find a[j]<=pivot
            j--;
        }
        if(i<j){
            //swap the elements less than pivot and greater than pivot
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //finally swap the pivot with the element at j which will be the sorted position of pivot
    //and partition the array into left and right which will be sorted recursively
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;

}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int j=partition(arr, low, high);
        quickSort(arr, low, j);
        quickSort(arr, j+1, high);
    }
}

int main(){
    
    #define N 7
    int arr[N]={9,3,5,7,1,2,8};

    printf("Unsorted array: ");
    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }

    quickSort(arr, 0, N-1);

    printf("\nSorted array: ");
    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}

/*
in this example of the given array [9,3,5,7,1,2,8] we dont find any element where arr[i]>pivot so i
increments till it reaches the end of the array i.e i=6 and then we decrement j till we find an element where
arr[j]<=pivot i.e j=6 , since i is not < j we break out of the while loop and then we
swap the pivot with the element at j and thus 9 gets its correct position in the sorted array
and then we sort the left and right subarrays recursively
*/