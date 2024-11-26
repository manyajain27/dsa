#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

//create new node
struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

//insert node at start
struct Node* insertAtStart(struct Node* head, int data){
    struct Node* newNode=createNode(data);
    newNode->next=head;
    return newNode;
}
//insert node at end
struct Node* insertAtEnd(struct Node* head, int data){
    struct Node* newNode=createNode(data);
    if(head==NULL){
        return newNode;
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

//insert node at index
struct Node* insertAtIndex(struct Node* head, int data, int index){
    struct Node* newNode=createNode(data);
    if(index==0){
        newNode->next=head;
        return newNode;
    }
    struct Node* temp=head;
    int i=0;
    while (i<index-1 && temp!=NULL)
    {
        temp=temp->next;
        i++;
    }

    newNode->next=temp->next;
    temp->next=newNode;
    return head;
}

//delete node at start
struct Node* deleteAtStart(struct Node* head){
    if(head==NULL){
        return NULL;
    }
    struct Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

//delete node at end
struct Node* deleteAtEnd(struct Node* head){
    if(head==NULL){
        return NULL;
    }
    struct Node* temp=head;
    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    struct Node* toDelete=temp->next;
    temp->next=NULL;
    free(toDelete);
    return head;
}

//delete node at index
struct Node* deleteAtIndex(struct Node* head, int index){
    if(head==NULL){
        return NULL;
    }
    struct Node* temp=head;
    int i=0;
    while (i<index-1 && temp!=NULL)
    {
        temp=temp->next;
        i++;
    }

    struct Node* toDelete=temp->next;
    temp->next=toDelete->next;
    free(toDelete);
    return head;
}

//print/traversal linked list

void traversal(struct Node* head){
    struct Node* temp=head;
    while (temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

//search element in linked list
struct Node* search(struct Node* head, int data){
    struct Node* temp=head;
    while (temp!=NULL)
    {
        if(temp->data==data){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

//merge two linked list
struct Node* merge(struct Node* list1, struct Node* list2){
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    struct Node* temp=list1;
    while (temp->next!=NULL)
    {
        temp=temp->next; //this will take it to last node of list1
    }
    temp->next=list2;//continued to add from last node of list1 to list2
    return list1;
}

int main(){
    //create dummy values and perform all operations
    struct Node* head=NULL;
    head=insertAtStart(head, 10);
    head=insertAtStart(head, 20);
    head=insertAtStart(head, 30);
    head=insertAtStart(head, 40);
    head=insertAtStart(head, 50);
    traversal(head);
    printf("\n");
    head=deleteAtStart(head);
    traversal(head);
    printf("\n");

    head=deleteAtEnd(head);
    traversal(head);
    printf("\n");

    head=deleteAtIndex(head, 1);
    traversal(head);
    printf("\n");

    head=insertAtIndex(head,60, 1);
    traversal(head);
    printf("\n");
    head=insertAtEnd(head,45);
    traversal(head);
    printf("\n");
    if(search(head, 30)!=NULL){
        printf("Element found\n");
    }
    
    return 0;
}