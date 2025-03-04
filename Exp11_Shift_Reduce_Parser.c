#include <stdio.h>
#include <string.h>

#define MAX 20

char stack[MAX];
int top = -1;
char input[MAX];
char grammar[3][3] = {"E+E", "E*E", "(E)"};

void push(char c) {
    stack[++top] = c;
    stack[top + 1] = '\0';
}

void pop() {
    if (top >= 0) {
        stack[top--] = '\0';
    }
}

int reduce() {
    for (int i = 0; i < 3; i++) {
        int len = strlen(grammar[i]);
        if (top >= len - 1 && strncmp(stack + top - len + 1, grammar[i], len) == 0) {
            for (int j = 0; j < len; j++) {
                pop();
            }
            push('E');
            printf("Reduced: %s -> E\n", grammar[i]);
            return 1;
        }
    }
    return 0;
}

void shift_reduce_parsing() {
    int i = 0;
    printf("\nStack\tInput\tAction\n");
    printf("----------------------------\n");

    while (input[i] != '\0') {
        push(input[i++]);
        printf("%s\t%s\tShift\n", stack, input + i);

        while (reduce()) {
            printf("%s\t%s\tReduce\n", stack, input + i);
        }
    }

    if (top == 0 && stack[0] == 'E')
        printf("Accepted\n");
    else
        printf("Rejected\n");
}

int main() {
    printf("Enter an expression: ");
    scanf("%s", input);

    shift_reduce_parsing();
    return 0;
}
