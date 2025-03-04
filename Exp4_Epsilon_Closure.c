#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 100

typedef struct {
    int state_num;
    int transitions[MAX_STATES]; 
} State;

void find_epsilon_closure(State nfa[], int current_state, bool visited[]) {
    if (visited[current_state]) return;
    
    visited[current_state] = true;
    printf("%d ", current_state);

    for (int i = 0; nfa[current_state].transitions[i] != -1; i++) {
        find_epsilon_closure(nfa, nfa[current_state].transitions[i], visited);
    }
}

void find_all_epsilon_closures(State nfa[], int num_states) {
    for (int i = 0; i < num_states; i++) {
        printf("Epsilon closure of state %d: ", i);
        bool visited[MAX_STATES] = {false};
        find_epsilon_closure(nfa, i, visited);
        printf("\n");
    }
}

int main() {
    State nfa[] = {
        {0, {1, 2, -1}}, 
        {1, {3, -1}},    
        {2, {4, -1}},    
        {3, {-1}},       
        {4, {-1}}        
    };

    int num_states = sizeof(nfa) / sizeof(nfa[0]);
    find_all_epsilon_closures(nfa, num_states);

    return 0;
}
