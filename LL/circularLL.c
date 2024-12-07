#include<stdio.h>
#include<stdlib.h>

// Definition of the circular linked list node
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Points to itself in a circular list
    return newNode;
}

// Insert at the start
struct Node* insertAtStart(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return newNode; // New node becomes the head
}

// Insert at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head; // Head remains unchanged
}

// Insert at a specific index
struct Node* insertAtIndex(struct Node* head, int data, int index) {
    if (index == 0) {
        return insertAtStart(head, data);
    }
    struct Node* temp = head;
    int i = 0;
    while (i < index - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }
    if (temp->next == head && i < index - 1) {
        printf("Index out of bounds\n");
        return head;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Delete at the start
struct Node* deleteAtStart(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == head) { // Single node case
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    struct Node* toDelete = head;
    temp->next = head->next;
    head = head->next;
    free(toDelete);
    return head;
}

// Delete at the end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == head) { // Single node case
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    struct Node* toDelete = temp->next;
    temp->next = head;
    free(toDelete);
    return head;
}

// Delete at a specific index
struct Node* deleteAtIndex(struct Node* head, int index) {
    if (head == NULL || index < 0) {
        return NULL;
    }
    if (index == 0) {
        return deleteAtStart(head);
    }
    struct Node* temp = head;
    int i = 0;
    while (i < index - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }
    if (temp->next == head || temp->next->next == head) {
        printf("Index out of bounds\n");
        return head;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    return head;
}

// Traverse the list
void traversal(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(HEAD)\n");
}

// Merge two circular linked lists
struct Node* merge(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    struct Node* temp1 = list1;
    while (temp1->next != list1) {
        temp1 = temp1->next;
    }
    struct Node* temp2 = list2;
    while (temp2->next != list2) {
        temp2 = temp2->next;
    }
    temp1->next = list2;
    temp2->next = list1;
    return list1;
}

int main() {
    // Testing the circular linked list operations
    struct Node* head = NULL;
    head = insertAtStart(head, 10);
    head = insertAtStart(head, 20);
    head = insertAtStart(head, 30);
    traversal(head);

    head = insertAtEnd(head, 40);
    traversal(head);

    head = deleteAtStart(head);
    traversal(head);

    head = deleteAtEnd(head);
    traversal(head);

    head = insertAtIndex(head, 25, 1);
    traversal(head);

    head = deleteAtIndex(head, 1);
    traversal(head);

    // Merge two lists
    struct Node* list1 = NULL;
    list1 = insertAtEnd(list1, 1);
    list1 = insertAtEnd(list1, 2);
    list1 = insertAtEnd(list1, 3);

    struct Node* list2 = NULL;
    list2 = insertAtEnd(list2, 4);
    list2 = insertAtEnd(list2, 5);
    list2 = insertAtEnd(list2, 6);

    traversal(list1);
    traversal(list2);

    struct Node* mergedList = merge(list1, list2);
    traversal(mergedList);

    return 0;
}
