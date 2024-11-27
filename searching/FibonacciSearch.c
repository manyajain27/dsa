#include<stdio.h>

//fibonacci search 
/*
in fibonacci search we use fibonacci series to find the position of the element to be searched
array should be sorted. 0 1 1 2 3 5 8 
steps:
1. we generate fibonacci series till the element is greater than or equal to the size of the array
2. If F(k) = 0, then stop and print the message as element not found.
3. we create variable offset=-1, offset marks the range of array that has been searched.
for example is offset is 3 that means we have searched till index 3 and now we will search from index 4 to n.
4. Check index i = min(offset + F(k-2), n-1)
5. If Target Element = A[i],return i and stop the search
6. If Target Element > A[i], then set k = k-1 and offset = i and repeat step 4 & 5
7. if Target Element < A[i], then set k = k-2 and repeat step 4 & 5
*/

int min(int x, int y){
    return x<y?x:y; //returns minimum of x and y
}

int main(){
    
    #define N 7
    int arr[N]={2,5,9,23,45,67,89};
    int data,found=0;
    printf("Enter the element to be searched: ");
    scanf("%d",&data);

    int FibM2 = 0; // (m-2)'th fibonacci number;
    int FibM1 = 1; // (m-1)'th fibonacci number;
    int FibM = FibM2 + FibM1; // m'th fibonacci number

    
    while(FibM < N){ //generates fib series till element is greater than or equal to the size of the array
        FibM2 = FibM1;
        FibM1 = FibM;
        FibM = FibM2 + FibM1;
    }

    int offset = -1; //so we search from index 0
    while(FibM > 1){ 
        int i= min(offset + FibM2, N-1); //index i is the index where we will search
        if(arr[i]==data){
            printf("Element found at index %d",i);
            found = 1;
            return 0;
        }
        else if(arr[i]<data){ 
            FibM = FibM1;
            FibM1 = FibM2;
            FibM2 = FibM - FibM1; //move left in the fibonacci series
            offset = i;

        }
        else if(arr[i]>data){
            FibM = FibM2; //3
            FibM1 = FibM1 - FibM2;//2
            FibM2 = FibM - FibM1; //move two steps left in the fibonacci series //1
        }

    }
    if(found==0){
            printf("Element not found");
        }
    return 0;
}

/*
arr[i] < data
When the element at the current index i is smaller than the target (data):

Logic:
If arr[i] < data, the target must lie in the right subarray (from i+1 to the end of the current range). To search this subarray:

The Fibonacci number FibM decreases to the next lower Fibonacci number in the sequence because we are reducing the size of the search range.
The offset is updated to i, which marks the last index that has been searched.

*/
/*
arr[i] > data
When the element at the current index i is greater than the target (data):

Logic:
If arr[i] > data, the target must lie in the left subarray (from the start of the range to i-1). To search this subarray:

The Fibonacci number FibM decreases by two levels in the Fibonacci sequence because we discard both the current and right subarrays.
The offset remains unchanged since we are still searching to the left of i.
*/