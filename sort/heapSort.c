/*
logic used: 
1. we make sure its a complete binary tree
2. we heapify the tree to make it into a max heap(i.e each parent node is greater than its children)
3. we heapify by:
    i)first we take the last non leaf node and compare with its children and swap with the largest child
    ii)thn we take the second last non leaf node and compare with its children and swap if its lesser than them
    iii)we continue this till we reach the root node and make sure the tree is a max heap
4. once we have a max heap, we replace the root node with the last node of the complete binary tree 
5. we heapify the tree again to make it a max heap and repeat the process till we have deleted all the elements
6. we receive the sorted array in the end
*/

#include<stdio.h>

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    //if left child is larger than root
    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    //if right child is larger than root
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }

    //swap the largest with the root
    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        //recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){

    //we start from last non leaf node
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }

    //delete the root node and replace with last node
    for(int i=n-1; i>0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        //heapify the tree again
        heapify(arr, i, 0);
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

    heapSort(arr, n);

    printf("Sorted array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }


    return 0;
}