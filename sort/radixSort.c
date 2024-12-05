#include<stdio.h>

int getMax(int arr[], int n){
    int max = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int exp){
    int count[10]={0};
    int output[n];

    //fill the count array
    for(int i=0; i<n; i++){
        count[(arr[i]/exp)%10]++;
    }
    //update count array to form cumulative count array(which gives pos of element in output array)
    for(int i=1; i<10; i++){
        count[i]=count[i]+count[i-1];
    }
    //fill the output array
    for(int i=n-1; i>=0; i--){
        output[--count[(arr[i]/exp)%10]]=arr[i]; //place element at postion i.e the count in cumulative count array -1 
    }                                            //  and decrement the count
    //copy the output array to original array
    for(int i=0; i<n; i++){
        arr[i]=output[i];
    }

}

void radixSort(int arr[], int n){
    int max = getMax(arr, n);
    for(int exp=1; max/exp>0; exp*=10){
        countingSort(arr, n, exp);

        //this portion of code not needed, just for understanding
        printf("Sorting digit place %d: ", exp);
        for(int i=0; i<n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        //
    }
}

int main(){
    int n;
    printf("enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    radixSort(arr, n);

    printf("Final Sorted array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}