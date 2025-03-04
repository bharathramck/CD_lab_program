#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

int stack[MAX], top = -1;
int action(int);
void push(int);
char convert(int);

int grammar_rules[] = {121, 131, 514, 6, 181}; // Example rules

void push(int item) {
    if (top >= MAX - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack[++top] = item;
}

char convert(int item) {
    switch (item) {
        case 1: return 'E';
        case 2: return '*';
        case 3: return '+';
        case 4: return '(';
        case 5: return ')';
        case 6: return 'i';
        case 7: return '$';
        default: return '?';
    }
}

int action(int item) {
    for (int i = 0; i < 5; i++) {
        if (grammar_rules[i] == item)
            return 1;
    }
    return -1;
}

int main() {
    char input[MAX];
    int ip[MAX], i = 0, sum, j, k, cnt, status, m, n;

    printf("Enter the input string (e.g., i+i*i$): ");
    scanf("%s", input);

    // Convert input to numeric representation
    for (i = 0; input[i] != '\0'; i++) {
        switch (input[i]) {
            case 'E': ip[i] = 1; break;
            case '*': ip[i] = 2; break;
            case '+': ip[i] = 3; break;
            case '(': ip[i] = 4; break;
            case ')': ip[i] = 5; break;
            case 'i': ip[i] = 6; break;
            case '$': ip[i] = 7; break;
            default: printf("Invalid character!\n"); return 1;
        }
    }
    ip[i] = -1;

    push(7); // Push '$' onto the stack

    printf("\nStack\tInput\tAction\n");
    printf("----------------------------\n");

    i = 0;
    while (1) {
        printf("\t");
        for (m = 0; m <= top; m++)
            printf("%c", convert(stack[m]));
        printf("\t");

        for (n = i; ip[n] != -1; n++)
            printf("%c", convert(ip[n]));
        printf("\t");

        if (stack[top] == 1 && stack[top - 1] == 7 && ip[i] == 7) {
            printf("Accept\n");
            break;
        }

        sum = 0;
        status = -1;
        for (j = 0; j <= top; j++) {
            sum = sum * 10 + stack[j];
            cnt = j + 1;
            status = action(sum);
            if (status == 1) {
                top = top - cnt;
                push(1);
                printf("Reduce\n");
                break;
            }
        }

        if (status == -1 && ip[i] == 7) {
            printf("Error\n");
            return 1;
        }

        if (ip[i] != 7) {
            push(ip[i]);
            i++;
            printf("Shift\n");
        }

        printf("\n");
    }

    return 0;
}
