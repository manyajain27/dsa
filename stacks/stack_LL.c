#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop(){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = top;
    top = top->next;
    free(temp);
}

void display(){
    struct Node *temp = top;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void peek(){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", top->data);
}



int main(){
    int choice, data;
    while(1){
        printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:

                peek();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}