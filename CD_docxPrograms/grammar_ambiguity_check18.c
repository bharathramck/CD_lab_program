#include <stdio.h>
#include <string.h>

int is_ambiguous(char grammar[]);

int main() {
    char grammar[100];

    printf("Enter the grammar (use '|' for multiple productions, e.g., E->E+E|i):\n");
    scanf("%s", grammar);

    if (is_ambiguous(grammar))
        printf("The given grammar is ambiguous.\n");
    else
        printf("The given grammar is unambiguous.\n");

    return 0;
}

int is_ambiguous(char grammar[]) {
    int count = 0;
    char *token = strtok(grammar, "|");

    while (token != NULL) {
        if (strchr(token, '+') || strchr(token, '-') || strchr(token, '*') || strchr(token, '/'))
            count++;
        token = strtok(NULL, "|");
    }

    return count > 1; // If multiple parse tree possibilities exist, it's ambiguous
}
