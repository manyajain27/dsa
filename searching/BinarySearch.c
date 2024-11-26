#include<stdio.h>

//binary search
/*
array should be sorted
we have low and high pointers
we find mid and divide the array into two halves
if element is found at mid then return mid
if element is less than mid then search in left half
and the high becomes mid-1
if element is greater than mid then search in right half
and the low becomes mid+1
*/

int main(){
    
    #define N 7
    int arr[N]={2,5,9,23,45,67,89};
    int data, found=0, low=0, high=N-1;
    printf("Enter the element to be searched: ");
    scanf("%d",&data);


    while(low<=high){
        
        int mid=(low+high)/2;

        if(data<arr[mid]){
            high=mid-1;
        }
        else if(data>arr[mid]){
            low=mid+1;
        }
        else if(data==arr[mid]){
            found=1;
            printf("Element found at index %d\n",mid);
            break;
        }
    }
    if(found==0){
        printf("Element not found\n");
    }
    return 0;
}