#include<stdio.h>
#include<stdlib.h>

// Definition of the doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at the start
struct Node* insertAtStart(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head != NULL) {
        head->prev = newNode;
    }
    newNode->next = head;
    return newNode;
}

// Insert at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Insert at a specific index
struct Node* insertAtIndex(struct Node* head, int data, int index) {
    if (index == 0) {
        return insertAtStart(head, data);
    }
    struct Node* temp = head;
    int i = 0;
    while (i < index - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Index out of bounds\n");
        return head;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

// Delete at the start
struct Node* deleteAtStart(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Delete at the end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
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
    while (i < index && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Index out of bounds\n");
        return head;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}

// Traverse the list
void traversal(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Merge two doubly linked lists
struct Node* merge(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    struct Node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;
    list2->prev = temp;
    return list1;
}

int main() {
    // Testing the doubly linked list operations
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