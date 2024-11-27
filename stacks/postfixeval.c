#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

// Stack for storing operands
int stack[MAX];
int top = -1;

// Push operation
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = x;
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char *exp) {
    int i;
    
    // Reset stack
    top = -1;

    for (i = 0; exp[i] != '\0'; i++) {
        // If current character is an operand (digit)
        if (isdigit(exp[i])) {
            push(exp[i] - '0');  // Convert char to integer
        }
        // If current character is an operator
        else {
            // Pop two operands
            int op2 = pop();
            int op1 = pop();

            // Perform operation
            switch (exp[i]) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    push(op1 / op2);
                    break;
            }
        }
    }

    // Final result will be at top of stack
    return pop();
}

int main() {
    // Test cases for postfix evaluation
    char exp1[] = "23+4*";    // ((2+3)*4) = 20
    char exp2[] = "524*+9-";  // ((5+2*4)-9) = 8
    
    printf("Postfix Expression: %s\n", exp1);
    printf("Result: %d\n", evaluatePostfix(exp1));
    
    printf("\nPostfix Expression: %s\n", exp2);
    printf("Result: %d\n", evaluatePostfix(exp2));

    return 0;
}