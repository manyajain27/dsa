#include<stdio.h>

//merge sort
/*
in merge sort we find mid element and divide the array into two parts
then we further divide the left and right subarrays into two parts and so on
till we get array with individual elements
since array with single element is considered sorted in itself we can merge them
then we merge the sorted subarrays and further merge and merge till we get final sorted array
merging function gives the merged array that is sorted
*/

void merge(int arr[], int low, int mid, int high){
    int n1=mid-low+1; //size of left subarray
    int n2=high-mid; //size of right subarray
    int left[n1], right[n2];
    
    for(int i=0; i<n1; i++){
        left[i]=arr[low+i]; 

    }
    for(int i=0; i<n2; i++){
        right[i]=arr[mid+1+i];

    }
    int i=0, j=0, k=low;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i]; //comparing the elements of left and right subarray and
                            // storing the smaller one in the main array
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;

    }
    while(i<n1){
        arr[k]=left[i]; //if any element is left in left subarray then store it in main array
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=right[j]; //if any element is left in right subarray then store it in main array
        j++;
        k++;
    }

}

void mergeSort(int arr[], int low, int high){
    if(low<high){ //if array has more than one element
        int mid=(low+high)/2;
        mergeSort(arr, low, mid); //sorting left subarray
        mergeSort(arr, mid+1, high); //sorting right subarray
        merge(arr, low, mid, high); //merging the sorted subarrays
    }
    
}

int main(){
      
    #define N 7
    int arr[N]={9,3,5,7,1,2,8};

    printf("Unsorted array: ");
    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }

    mergeSort(arr, 0, N-1);

    printf("\nSorted array: ");
    for(int i=0;i<N;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}

//procedure for merging:
//lets say unsroted arrays to be merged are [3,5,7,9] and [1,2,8]. arrays to be merged must be sorted
//we compare 3 and 1 since 1<3 we store 1 in main array and move to next element in right subarray
//now we compare 3 and 2 since 2<3 we store 2 in main array and move to next element in right subarray
//now we compare 3 and 8 since 3<8 we store 3 in main array and move to next element in left subarray
//now we compare 5 and 8 since 5<8 we store 5 in main array and move to next element in left subarray
//now we compare 7 and 8 since 7<8 we store 7 in main array and move to next element in left subarray
//now we compare 9 and 8 since 9>8 we store 8 in main array and move to next element in right subarray
//right array is exhausted so we just copy the remaining elements of left array to main array
//now we have sorted array [1,2,3,5,7,8,9]