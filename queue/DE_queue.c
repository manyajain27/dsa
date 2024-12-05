//double ended queue
#include<stdio.h>

#define N 5
int queue[N]; 
int front = -1, rear = -1;

void enqueue_front(int x){
    if((rear+1)%N == front){
        printf("Queue is full\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[front] = x;
    }
    else if(front == 0){ 
        front = N-1;
        queue[front] = x;
    }
    else{
        front--;
        queue[front] = x;
    }
}

void enqueue_rear(int x){
    if((rear+1)%N == front){
        printf("Queue is full\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else if(rear == N-1){
        rear = 0;
        queue[rear] = x;
    }
    else{
        rear++;
        queue[rear] = x;
    }
}

void dequeue_front(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else if(front == N-1){
        front = 0;
    }
    else{
        front++;
    }
}

void dequeue_rear(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else if(rear == 0){
        rear = N-1;
    }
    else{
        rear--;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
        int i = front;
        printf("Queue: ");
        while(i != rear){
            printf("%d ", queue[i]);
            i = (i+1)%N;
        }
        printf("%d\n", queue[rear]);
    }
}

int main(){
    //menu driven program
    int choice, x;
    while(1){
        printf("1. Enqueue front\n2. Enqueue rear\n3. Dequeue front\n4. Dequeue rear\n5. Display\n6. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter element to enqueue front: ");
                scanf("%d", &x);
                enqueue_front(x);
                break;
            case 2:
                printf("Enter element to enqueue rear: ");
                scanf("%d", &x);    
                enqueue_rear(x);
                break;
            case 3:
                dequeue_front();
                break;
            case 4:
                dequeue_rear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");

        }
    }

    return 0;
}

