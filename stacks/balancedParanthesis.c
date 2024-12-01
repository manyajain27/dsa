#include<stdio.h>

#define N 100
char stack[N];

int top = -1;

int isEmpty() {
    return top == -1;
}


int isFull() {
    return top == N - 1;
}


void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        stack[++top] = value;
        // printf("%d pushed onto the stack.\n", value);
    }
}


int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! No elements to pop.\n");
        return -1;
    } else {
        return stack[top--];
    }
}

void isBalanced(char *exp){ 
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '('){
            push(exp[i]);
        }
        else if(exp[i] == ')'){
            if(isEmpty()){
                printf("Unbalanced\n");
                return;
            }
            pop();
        }
    }
    if(isEmpty()){
        printf("Balanced\n");
    }
    else{
        printf("Unbalanced\n");
    }
}


int main(){

    char exp[] = "())";
    isBalanced(exp);

    return 0;
}