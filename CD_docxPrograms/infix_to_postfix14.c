#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 50

char stack[MAX];
int top = -1;

// Function prototypes
void push(char);
char pop();
int precedence(char);
void infixToPostfix(char[], char[]);

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("The resulting postfix expression is: %s\n", postfix);

    return 0;
}

void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop() {
    return (top >= 0) ? stack[top--] : '\0';
}

int precedence(char c) {
    switch (c) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(')
                postfix[j++] = pop();
            pop(); // Remove '(' from stack
        } else {
            while (top >= 0 && precedence(stack[top]) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top >= 0)
        postfix[j++] = pop();

    postfix[j] = '\0'; // Null-terminate the postfix expression
}
