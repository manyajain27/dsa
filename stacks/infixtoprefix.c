#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int top = -1;
char stack[MAX];

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    }
    else {
        stack[++top] = x;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    else {
        return stack[top--];
    }
}

int priority(char x) {
    switch(x) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return 0;
}

void reverse(char *exp) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(exp) - 1; i < j; i++, j--) {
        // Swap brackets as well
        if (exp[i] == '('){ 
            exp[i] = ')';
        }
        else if (exp[i] == ')'){
             exp[i] = '(';
        }
        
        if (exp[j] == '('){ 
            exp[j] = ')';
        }
        else if (exp[j] == ')'){ 
            exp[j] = '(';
        }
        
        // Swap characters
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

void infixtoprefix(char exp[]) {
    char result[MAX];
    int i, j = 0;
    char symbol;
    
    // Reverse the expression
    reverse(exp);
    top = -1;  // Reset stack

    for (i = 0; exp[i] != '\0'; i++) {
        symbol = exp[i];

        
        if (symbol == '(') {
            push(symbol);
        }
        else if (symbol == ')') {
            while (top != -1 && stack[top] != '(') {
                result[j++] = pop();
            }
            pop();
        }
        else if (symbol == '+' || symbol == '-' || 
                 symbol == '*' || symbol == '/') {
            while (top != -1 && priority(stack[top]) > priority(symbol)) {
                result[j++] = pop();
            }
            push(symbol);
        }
        else{
            result[j++] = symbol;
        }
        
    }

    // Pop remaining operators
    while (top != -1) {
        result[j++] = pop();
    }

    // Null-terminate the result
    result[j] = '\0';

    // Reverse the result to get prefix
    reverse(result);

    printf("Prefix Expression: %s\n", result);
}

int main() {
    char exp[MAX] = "a*f+b-*nm/+";
    infixtoprefix(exp);
    return 0;
}