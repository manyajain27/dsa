#include<stdio.h>

//linear search
/*
in linear search we check each element one by one in the array
if the element is found then we return the index of that element
if the element is not found then we return -1
*/

int main(){
    #define N 7
    int arr[N]={9,3,5,7,1,2,8};
    int data, found=0;
    printf("Enter the element to be searched: ");
    scanf("%d",&data);

    for(int i=0;i<N;i++){
        if(arr[i]==data){
            printf("Element found at index %d\n",i);
            found=1;
            break;
        }
    }

    if(found==0){
        printf("Element not found\n");
    }


    return 0;
}