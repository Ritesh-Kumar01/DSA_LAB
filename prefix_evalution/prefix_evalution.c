#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX 20 

double compute(char symbol, double op1, double op2){
    switch (symbol){
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return (op2 != 0) ? op1 / op2 : 0; 
    case '$':
        return pow(op1, op2); 
    default:
        return 0;
    }
}

int main()
{
    double stack[MAX], res, op1, op2;
    int top = -1, i;
    char postfix[MAX], symbol;

    printf("Enter the postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    postfix[strcspn(postfix, "\n")] = '\0';

    for (i = 0; i < strlen(postfix); i++){
        symbol = postfix[i];

        if (isdigit(symbol)){
            stack[++top] = symbol - '0';
        }
        else if (symbol == ' '){
            continue; 
        }
        else{
            if (top < 1){
                printf("Error: Invalid postfix expression\n");
                return 1;
            }

            op2 = stack[top--];
            op1 = stack[top--];

            res = compute(symbol, op1, op2);
            stack[++top] = res;
        }
    }

    if (top != 0){
        printf("Error: Invalid postfix expression\n");
    }
    else{
        printf("The result is: %.2f\n", stack[top]);
    }

    return 0;
}