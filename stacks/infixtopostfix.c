#include<stdio.h>
#include<ctype.h>

#define MAX 100

int top=-1;
char stack[MAX];

void push(char x){
    if(top==MAX-1){
        printf("Stack Overflow\n");
    }
    else{
        stack[++top]=x;
    }
}

char pop(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        return stack[top--];
    }
}

int priority(char x){
    switch(x){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return 0;
}
void infixtopostfix(char *exp){
    int i;
    char symbol;
    for(i=0;exp[i]!='\0';i++){
        symbol=exp[i];
        if(symbol=='('){
            push(symbol);
        }
        else if(symbol==')'){
            while((stack[top]!='(') && (top!=-1)){
                printf("%c",pop());
            }
            pop();
        }
        else if(!isalnum(symbol)){
            while((top!=-1) && (priority(stack[top])>=priority(symbol))){
                printf("%c",pop());
            }
            push(symbol);
        }
        else{
            printf("%c",symbol); //if it is an operand
        }
    }
    while(top!=-1){
        printf("%c",pop());
    }
}

int main(){
    char exp[MAX]="(a+b*c)/(d-e)";
    infixtopostfix(exp);


    return 0;
}