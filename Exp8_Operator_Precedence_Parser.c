#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

char precedence_table[6][6] = {
    /*  +   -   *   /   i   $  */
    {'>', '>', '<', '<', '<', '>'}, // +
    {'>', '>', '<', '<', '<', '>'}, // -
    {'>', '>', '>', '>', '<', '>'}, // *
    {'>', '>', '>', '>', '<', '>'}, // /
    {'>', '>', '>', '>', '=', 'E'}, // i (operand)
    {'<', '<', '<', '<', '<', 'A'}  // $ (end of input)
};

int get_index(char c) {
    switch (c) {
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case 'i': return 4; // Identifier or operand
        case '$': return 5;
        default: return -1;
    }
}

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return (top >= 0) ? stack[top--] : '\0';
}

void parse(char input[]) {
    int i = 0;
    push('$');

    printf("\nStack\tInput\tAction\n");
    while (1) {
        char stack_top = stack[top];
        char input_symbol = input[i];

        int stack_index = get_index(stack_top);
        int input_index = get_index(input_symbol);

        if (stack_index == -1 || input_index == -1) {
            printf("Invalid symbol encountered!\n");
            return;
        }

        printf("%s\t%s\t", stack, &input[i]);

        char relation = precedence_table[stack_index][input_index];

        if (relation == '<' || relation == '=') {
            push(input_symbol);
            i++;
            printf("Shift\n");
        } else if (relation == '>') {
            pop();
            printf("Reduce\n");
        } else if (relation == 'A') {
            printf("Accepted\n");
            break;
        } else {
            printf("Error\n");
            break;
        }
    }
}

int main() {
    char input[100];

    printf("Enter an arithmetic expression (end with $): ");
    scanf("%s", input);

    parse(input);
    return 0;
}
