#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_SYMBOLS 2

int nfa[MAX_STATES][MAX_SYMBOLS][MAX_STATES], dfa[MAX_STATES][MAX_SYMBOLS];
int nfa_states, dfa_states = 0, symbols;
int dfa_state_set[MAX_STATES][MAX_STATES], dfa_state_count[MAX_STATES];

int state_exists(int *state_set, int state_count) {
    for (int i = 0; i < dfa_states; i++) {
        if (dfa_state_count[i] == state_count && memcmp(dfa_state_set[i], state_set, state_count * sizeof(int)) == 0)
            return i;
    }
    return -1;
}

void convert_nfa_to_dfa() {
    int queue[MAX_STATES], front = 0, rear = 0;
    queue[rear++] = 0;
    dfa_state_set[0][0] = 0;
    dfa_state_count[0] = 1;
    dfa_states++;

    while (front < rear) {
        int current_dfa_state = queue[front++];
        for (int symbol = 0; symbol < symbols; symbol++) {
            int new_state_set[MAX_STATES], new_state_count = 0;
            for (int i = 0; i < dfa_state_count[current_dfa_state]; i++) {
                int nfa_state = dfa_state_set[current_dfa_state][i];
                for (int j = 0; j < nfa_states; j++) {
                    if (nfa[nfa_state][symbol][j] == 1) {
                        int already_present = 0;
                        for (int k = 0; k < new_state_count; k++) {
                            if (new_state_set[k] == j) {
                                already_present = 1;
                                break;
                            }
                        }
                        if (!already_present) {
                            new_state_set[new_state_count++] = j;
                        }
                    }
                }
            }

            if (new_state_count > 0) {
                int existing_state = state_exists(new_state_set, new_state_count);
                if (existing_state == -1) {
                    memcpy(dfa_state_set[dfa_states], new_state_set, new_state_count * sizeof(int));
                    dfa_state_count[dfa_states] = new_state_count;
                    dfa[current_dfa_state][symbol] = dfa_states;
                    queue[rear++] = dfa_states;
                    dfa_states++;
                } else {
                    dfa[current_dfa_state][symbol] = existing_state;
                }
            }
        }
    }
}

void display_dfa() {
    printf("\nDFA Transition Table:\n");
    printf("State\t0\t1\n");
    for (int i = 0; i < dfa_states; i++) {
        printf("q%d\t", i);
        for (int j = 0; j < symbols; j++) {
            printf("q%d\t", dfa[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of NFA states: ");
    scanf("%d", &nfa_states);

    printf("Enter the number of symbols: ");
    scanf("%d", &symbols);

    printf("Enter the NFA transition table (use 1 for transition, 0 for no transition):\n");
    for (int i = 0; i < nfa_states; i++) {
        for (int j = 0; j < symbols; j++) {
            for (int k = 0; k < nfa_states; k++) {
                scanf("%d", &nfa[i][j][k]);
            }
        }
    }

    convert_nfa_to_dfa();
    display_dfa();
    return 0;
}
