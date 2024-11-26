#include<stdio.h>

#define N 5
int queue[N]; 
int front = -1, rear = -1;

void enqueue(int data){
    if(rear == N-1){
        printf("Queue is full\n");
        return;
    }
    else if(front == -1 && rear == -1){ //if queue is empty
        front = rear= 0;
        queue[rear] = data;
    }
    else{ //if queue is not empty
        rear++;
        queue[rear] = data;
    }
    
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
        return;
    }
    else if(front == rear){ //if there is only one element in queue
        front = rear = -1;
    }
    else{
        front++;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
        return;
    }
    else{
        printf("Queue: ");
        for(int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peek(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
        return;
    }
    else{
        printf("Front element: ");
        printf("%d\n", queue[front]);
    }
}

int main(){
    enqueue(5);
    enqueue(8);
    enqueue(12);
    enqueue(78);
    dequeue();
    display();
    peek();
    enqueue(45);
    display();
    return 0;
}