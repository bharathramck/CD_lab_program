#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 10
#define MAX_SYMBOLS 2

int dfa[MAX_STATES][MAX_SYMBOLS], num_states, num_symbols;
int final_states[MAX_STATES], num_final_states;
int distinguishable[MAX_STATES][MAX_STATES];

void initialize_table() {
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_states; j++) {
            distinguishable[i][j] = 0;
        }
    }

    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_states; j++) {
            int is_final_i = 0, is_final_j = 0;
            for (int k = 0; k < num_final_states; k++) {
                if (final_states[k] == i) is_final_i = 1;
                if (final_states[k] == j) is_final_j = 1;
            }
            if (is_final_i != is_final_j) {
                distinguishable[i][j] = 1;
            }
        }
    }
}

void minimize_dfa() {
    int changed;
    do {
        changed = 0;
        for (int i = 0; i < num_states; i++) {
            for (int j = 0; j < i; j++) {
                if (distinguishable[i][j] == 0) {
                    for (int s = 0; s < num_symbols; s++) {
                        int next_i = dfa[i][s], next_j = dfa[j][s];
                        if (distinguishable[next_i][next_j] == 1) {
                            distinguishable[i][j] = 1;
                            changed = 1;
                        }
                    }
                }
            }
        }
    } while (changed);

    printf("\nMinimized DFA State Pairs:\n");
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < i; j++) {
            if (distinguishable[i][j] == 0) {
                printf("q%d and q%d are equivalent\n", i, j);
            }
        }
    }
}

int main() {
    printf("Enter the number of DFA states: ");
    scanf("%d", &num_states);

    printf("Enter the number of symbols: ");
    scanf("%d", &num_symbols);

    printf("Enter the DFA transition table:\n");
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_symbols; j++) {
            scanf("%d", &dfa[i][j]);
        }
    }

    printf("Enter the number of final states: ");
    scanf("%d", &num_final_states);

    printf("Enter the final states:\n");
    for (int i = 0; i < num_final_states; i++) {
        scanf("%d", &final_states[i]);
    }

    initialize_table();
    minimize_dfa();

    return 0;
}
