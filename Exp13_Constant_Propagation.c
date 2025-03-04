#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

typedef struct {
    char var;
    int value;
    int isConstant;
} Symbol;

Symbol symTable[MAX];
int symCount = 0;

void addSymbol(char var, int value, int isConstant) {
    for (int i = 0; i < symCount; i++) {
        if (symTable[i].var == var) {
            symTable[i].value = value;
            symTable[i].isConstant = isConstant;
            return;
        }
    }
    symTable[symCount].var = var;
    symTable[symCount].value = value;
    symTable[symCount].isConstant = isConstant;
    symCount++;
}

int getConstantValue(char var, int *value) {
    for (int i = 0; i < symCount; i++) {
        if (symTable[i].var == var && symTable[i].isConstant) {
            *value = symTable[i].value;
            return 1;
        }
    }
    return 0;
}

void performConstantPropagation(char expressions[][20], int numExp) {
    printf("\nOptimized Code after Constant Propagation:\n");
    for (int i = 0; i < numExp; i++) {
        char var, op, operand1, operand2;
        int val1, val2;
        if (sscanf(expressions[i], "%c = %c %c %c", &var, &operand1, &op, &operand2) == 4) {
            int isConst1 = getConstantValue(operand1, &val1);
            int isConst2 = getConstantValue(operand2, &val2);
            if (isConst1 && isConst2) {
                int result = (op == '+') ? val1 + val2 : (op == '-') ? val1 - val2 :
                             (op == '*') ? val1 * val2 : (op == '/') ? val1 / val2 : 0;
                printf("%c = %d\n", var, result);
                addSymbol(var, result, 1);
            } else {
                printf("%s\n", expressions[i]);
                addSymbol(var, 0, 0);
            }
        } else if (sscanf(expressions[i], "%c = %d", &var, &val1) == 2) {
            printf("%s\n", expressions[i]);
            addSymbol(var, val1, 1);
        } else {
            printf("%s\n", expressions[i]);
        }
    }
}

int main() {
    int numExp;
    char expressions[MAX][20];

    printf("Enter number of expressions: ");
    scanf("%d", &numExp);
    getchar();

    printf("Enter expressions (e.g., a = b + c or a = 10):\n");
    for (int i = 0; i < numExp; i++) {
        fgets(expressions[i], 20, stdin);
        expressions[i][strcspn(expressions[i], "\n")] = '\0';
    }

    performConstantPropagation(expressions, numExp);
    return 0;
}
