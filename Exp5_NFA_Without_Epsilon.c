#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 20
#define MAX_ALPHABET 10

typedef struct Node {
    int state;
    struct Node *next;
} Node;

void insert_transition(Node *transition[MAX_STATES][MAX_ALPHABET], int from, int symbol, int to) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->state = to;
    newNode->next = transition[from][symbol];
    transition[from][symbol] = newNode;
}

void epsilon_closure(Node *transition[MAX_STATES][MAX_ALPHABET], int state, int closure[MAX_STATES], int visited[MAX_STATES]) {
    if (visited[state]) return;
    visited[state] = 1;
    closure[state] = 1;

    Node *temp = transition[state][MAX_ALPHABET - 1];
    while (temp) {
        epsilon_closure(transition, temp->state, closure, visited);
        temp = temp->next;
    }
}

void convert_nfa(Node *transition[MAX_STATES][MAX_ALPHABET], int num_states, int num_symbols) {
    int closure[MAX_STATES][MAX_STATES] = {0};

    for (int i = 0; i < num_states; i++) {
        int visited[MAX_STATES] = {0};
        epsilon_closure(transition, i, closure[i], visited);
    }

    printf("\nEquivalent NFA without ε-transitions:\n");
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_symbols - 1; j++) {
            int new_set[MAX_STATES] = {0};

            for (int k = 0; k < num_states; k++) {
                if (closure[i][k]) {
                    Node *temp = transition[k][j];
                    while (temp) {
                        new_set[temp->state] = 1;
                        temp = temp->next;
                    }
                }
            }

            printf("q%d -- %c --> {", i, 'a' + j);
            for (int k = 0; k < num_states; k++) {
                if (new_set[k]) printf(" q%d ", k);
            }
            printf("}\n");
        }
    }
}

int main() {
    Node *transition[MAX_STATES][MAX_ALPHABET] = {NULL};
    int num_states = 3, num_symbols = 4;

    insert_transition(transition, 0, 0, 0);
    insert_transition(transition, 0, 3, 1);
    insert_transition(transition, 1, 1, 1);
    insert_transition(transition, 1, 3, 2);
    insert_transition(transition, 2, 2, 2);

    convert_nfa(transition, num_states, num_symbols);
    return 0;
}
