#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

struct Node* createNode(int c, int p);

struct Node* addPolynomial(struct Node* head1, struct Node* head2) {

    // if any list is empty, then return
    // the other list.
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    
    // If head1.pow is greater, then recursively find
    // its next node, and return head1.
    if (head1->pow > head2->pow) {
        struct Node* nextPtr = 
          addPolynomial(head1->next, head2);
        head1->next = nextPtr;
        return head1;
    }

    // If head2.pow is greater, then recursively find its 
    // next node, and return head2.
    else if (head1->pow < head2->pow) {
        struct Node* nextPtr = 
          addPolynomial(head1, head2->next);
        head2->next = nextPtr;
        return head2;
    }

    // else store the sum of head1.coeff and head2.coeff in
    // head1->coeff, then find its next node and return head1.
    struct Node* nextPtr = 
          addPolynomial(head1->next, head2->next);
    head1->coeff += head2->coeff;
    head1->next = nextPtr;
    return head1;
}


void printList(struct Node* head) {
    struct Node* curr = head;

    while (curr != NULL) {
        printf("%d,%d ", curr->coeff, curr->pow);
        curr = curr->next;

    }

    printf("\n");
}

struct Node* createNode(int c, int p) {
    struct Node* newNode = 
        (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = NULL;
    return newNode;
}


int main() {
    
    // 1st polynomial: 5x^2+4x^1+2x^0
    struct Node* head1 = createNode(5, 2);
    head1->next = createNode(4, 1);
    head1->next->next = createNode(2, 0);

    // 2nd polynomial: -5x^1-5x^0
    struct Node* head2 = createNode(-5, 1);
    head2->next = createNode(-5, 0);

    struct Node* head = addPolynomial(head1, head2);

    printList(head);

    return 0;
}