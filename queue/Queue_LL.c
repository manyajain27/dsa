#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *front=NULL;
struct Node *rear=NULL;

void enqueue(int x){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;

    if(front==NULL && rear==NULL){
        front=rear=newNode;
        return;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }
}

void dequeue(){
    struct Node *temp=front;

    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    else if(front==rear){ //one element only
        front=rear=NULL;
    }
    else{
        front=front->next;
    }
    free(temp);
}

void display() {
    struct Node *temp = front;  // Start from the front
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);  // Print the data
        temp = temp->next;  // Move to the next node
    }
    printf("\n");
}

void peek(){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("Front element is %d\n",front->data);
}

int main(){
    enqueue(5);
    enqueue(7);
    enqueue(13);
    enqueue(89);
    dequeue();
    display();
    peek();
    return 0;
}