#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *front=0;
struct Node *rear=0;

void enqueue(int x){

    struct Node *newnode=(struct Node *) malloc (sizeof(struct Node));
    newnode->data=x;
    newnode->next=NULL;

    if(rear==0 && front==0){
        front=rear=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}

void dequeue(){
    struct Node *temp=front;

    if(front==NULL && rear==NULL){
        printf("Queue is empty\n");
    }
    else if(front==rear){
        front=rear=NULL;
    }
    else{
        front=front->next;
        rear->next=front;
        free(temp);
    }
}

void display(){
    struct Node *temp=front;
    if(front==NULL && rear==NULL){
        printf("Queue is empty\n");
    }
    else{
        while(temp->next!=front){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data); //because it will not print the last element
    }
}

int main(){
    enqueue(5);
    enqueue(11);
    enqueue(17);
    enqueue(23);
    dequeue();
    enqueue(8);
    display();
    return 0;
}