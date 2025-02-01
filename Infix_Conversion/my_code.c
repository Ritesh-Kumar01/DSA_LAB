#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

char postfixStack[MAX];
int postfixTop = -1;

void push(char val) {
    stack[++top] = val;
}

char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

int precedence(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infix_to_postfix(char expression[]) {
    int i;
    char ch;

    for (i = 0; expression[i] != '\0'; i++) {
        ch = expression[i];

        if (isalnum(ch)) {
            postfixStack[++postfixTop] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (stack[top] != '(') {
                postfixStack[++postfixTop] = pop();
            }
            pop();
        } else {
            while (precedence(stack[top]) >= precedence(ch)) {
                postfixStack[++postfixTop] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfixStack[++postfixTop] = pop();
    }

    postfixStack[++postfixTop] = '\0'; 
}

void display(char stack[]) {
    int i;
    for (i = 0; stack[i] != '\0'; i++) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter your infix expression: ");
    scanf("%s", stack);
    printf("Your infix expression is: %s\n", stack);

    infix_to_postfix(stack);

    printf("The postfix expression is: ");
    display(postfixStack);

    return 0;
}
