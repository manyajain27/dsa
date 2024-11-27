#include<stdio.h>

#define N 5
int queue[N]; 
int front = -1, rear = -1;
//  0 1 2 3 4
// [_ _ 1 9 6] (i+1)%size

void enqueue(int x){
    if(front == -1 && rear == -1){
        front=rear=0;
        queue[rear] = x;
    }
    else if((rear+1)%N == front){
        printf("Queue is full\n");
    }
    else{ //queue is not full
        rear = (rear+1)%N;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else if(front==rear){ //only 1 element
        front=rear=-1;
    }
    else{
        front = (front+1)%N;
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else{
        int i=front;
        while(i!=rear){
            printf("%d ",queue[i]);
            i = (i+1)%N;
        }
        printf("%d",queue[rear]);
    }
}

int main(){
    enqueue(5);
    enqueue(11);
    enqueue(17);
    enqueue(23);
    dequeue();
    enqueue(19);
    enqueue(28);
    enqueue(13);
    display();
    return 0;
}