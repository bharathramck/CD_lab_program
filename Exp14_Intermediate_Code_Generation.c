#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int tempCount = 1;

void generate_intermediate_code(char expr[]) {
    char operand1, operand2, operator;
    char tempVar[5];

    int len = strlen(expr);
    int i = 0;

    while (i < len) {
        if (isalpha(expr[i]) || isdigit(expr[i])) {
            operand1 = expr[i];
            i++;
        } else {
            operator = expr[i];
            i++;
            if (isalpha(expr[i]) || isdigit(expr[i])) {
                operand2 = expr[i];
                i++;
                snprintf(tempVar, sizeof(tempVar), "T%d", tempCount++);
                printf("%s = %c %c %c\n", tempVar, operand1, operator, operand2);
                operand1 = tempVar[0];
            }
        }
    }
}

int main() {
    char expr[MAX];

    printf("Enter a simple arithmetic expression (e.g., a+b*c): ");
    scanf("%s", expr);

    printf("\nIntermediate Code:\n");
    generate_intermediate_code(expr);

    return 0;
}
