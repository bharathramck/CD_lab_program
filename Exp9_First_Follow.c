#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_SYMBOLS 10

char productions[MAX_RULES][MAX_SYMBOLS], first[MAX_RULES][MAX_SYMBOLS], follow[MAX_RULES][MAX_SYMBOLS];
int num_productions = 0;

void find_first(char symbol, int rule_index) {
    if (!isupper(symbol)) {
        first[rule_index][strlen(first[rule_index])] = symbol;
        return;
    }

    for (int i = 0; i < num_productions; i++) {
        if (productions[i][0] == symbol) {
            if (productions[i][2] == '$') {
                first[rule_index][strlen(first[rule_index])] = '$';
            } else {
                find_first(productions[i][2], rule_index);
            }
        }
    }
}

void find_follow(char symbol, int rule_index) {
    if (productions[0][0] == symbol) {
        follow[rule_index][strlen(follow[rule_index])] = '$';
    }

    for (int i = 0; i < num_productions; i++) {
        for (int j = 2; productions[i][j] != '\0'; j++) {
            if (productions[i][j] == symbol) {
                if (productions[i][j + 1] != '\0') {
                    find_first(productions[i][j + 1], rule_index);
                }
                if (productions[i][j + 1] == '\0' || strchr(first[rule_index], '$')) {
                    find_follow(productions[i][0], rule_index);
                }
            }
        }
    }
}

int main() {
    printf("Enter the number of productions: ");
    scanf("%d", &num_productions);

    printf("Enter the productions (use '$' for epsilon):\n");
    for (int i = 0; i < num_productions; i++) {
        scanf("%s", productions[i]);
    }

    for (int i = 0; i < num_productions; i++) {
        find_first(productions[i][0], i);
        find_follow(productions[i][0], i);
    }

    printf("\nFIRST and FOLLOW Sets:\n");
    for (int i = 0; i < num_productions; i++) {
        printf("FIRST(%c) = { %s }\n", productions[i][0], first[i]);
        printf("FOLLOW(%c) = { %s }\n", productions[i][0], follow[i]);
    }

    return 0;
}
