#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    else{
        return root;
    }
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* findMax(struct Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct Node* delete(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = delete(root->left, data);
    } 
    else if (data > root->data) {
        root->right = delete(root->right, data);
    } 
    else { //node found
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        struct Node* temp = findMin(root->right); //The Inorder Successor is the smallest node in the node's right subtree
        root->data = temp->data; //replace the root's data with the inorder successor's data
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void postorder(struct Node* root) { //left-right-vertex
    if (root != NULL) {
        postorder(root->left); //left
        postorder(root->right); //right
        printf("%d ", root->data); //vertex
    }
}

void preorder(struct Node* root) { //vertex-left-right
    if (root != NULL) {
        printf("%d ", root->data); //vertex
        preorder(root->left); //left
        preorder(root->right); //right
    }
}

void inorder(struct Node* root) { //left-vertex-right
    if (root != NULL) {
        inorder(root->left); //left
        printf("%d ", root->data); //vertex
        inorder(root->right); //right
    }
}

int maxHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    else if (data < root->data) {
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
    
}

//mirror image of the tree
void mirror(struct Node* root) {
    if (root == NULL) {
        return;
    }
    else {
        struct Node* temp;
        mirror(root->left); //postorder traversal
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    printf("Height of tree: %d\n", maxHeight(root));

    printf("Deleting 20\n");
    root = delete(root, 20);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Searching for 40: ");
    struct Node* foundNode = search(root, 40);
    if (foundNode != NULL) {
        printf("Found %d\n", foundNode->data);
    } else {
        printf("Not found\n");
    }

    printf("Minimum element: %d\n", findMin(root)->data);
    printf("Maximum element: %d\n", findMax(root)->data);

    printf("Mirroring the tree\n");
    mirror(root);
    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}
