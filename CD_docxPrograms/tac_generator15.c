#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

char op[MAX][3], arg1[MAX][3], arg2[MAX][3], result[MAX][3];
char stack[MAX][3];
char tempVar[MAX][3] = {"T1", "T2", "T3", "T4", "T5", "T6", "T7", "T8", "T9"};

int top = -1, p = 0;

void push(char str[]) {
    strcpy(stack[++top], str);
}

void generate_TAC(char postfix[]) {
    char t[3];

    for (int i = 0; i < strlen(postfix); i++) {
        t[0] = postfix[i];
        t[1] = '\0';

        if (isalnum(postfix[i])) {
            push(t);
        } else {
            strcpy(op[p], t);
            strcpy(arg2[p], stack[top--]);
            strcpy(arg1[p], stack[top--]);
            strcpy(result[p], tempVar[p]);
            push(result[p]);
            p++;
        }
    }
}

void print_TAC() {
    printf("Generated Three-Address Code:\n");
    for (int i = 0; i < p; i++) {
        printf("%s := %s %s %s\n", result[i], arg1[i], op[i], arg2[i]);
    }
}

int main() {
    char postfix[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    generate_TAC(postfix);
    print_TAC();

    return 0;
}
