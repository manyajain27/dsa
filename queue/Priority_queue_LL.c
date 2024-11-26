/*
each element is associated with a priority,
and elements are enqueued based on their priority rather than just fifo.
and automatically dequeues the highest priority element
*/

//note: in this code priority 0 is considered as highest priority

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;     
    int priority;   
    struct Node* next;
};

struct Node *front = NULL;

//enqueue with priority
void enqueue(int value, int pri){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->priority = pri;
    newNode->next = NULL;
    if(front == NULL || pri < front->priority){ //considering priority 0 as highest
        newNode->next = front;
        front = newNode;
    }
    else{
        struct Node *temp = front;

        while(temp->next != NULL && temp->next->priority <= pri){ //till we find a node with lower priority ie higher number
            temp = temp->next;
        }
        //inserting the node
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//always dequeues the highest priority element as we enueued them with priority
int dequeue(){
    if(front == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        struct Node *temp = front;
        int value = front->data;
        front = front->next;
        free(temp);
        return value;
    }
}

void display(){
    struct Node *temp = front;
    if(front == NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("Priority Queue is: ");
        while(temp != NULL){
            printf("%d[pri:%d] ", temp->data, temp->priority);
            temp = temp->next;
        }
    }
}

int main(){
    
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);
    enqueue(40, 0);
    display();
    printf("\nDequeued: %d\n", dequeue());
    display();

    return 0;
}