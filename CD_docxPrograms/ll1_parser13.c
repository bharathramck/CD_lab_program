#include <stdio.h>
#include <string.h>

char nt[4] = {'E', 'S', 'A', 'B'};
char t[4] = {'a', 'b', '#', '$'};
char parsing_table[4][4][10] = {
    {"S#", "S#", "", ""}, 
    {"aB", "bA", "", ""},
    {"aS", "bAA", "", ""},
    {"aBB", "bS", "", ""}
};

void display_parsing_table() {
    printf("\n\tLL(1) PARSING TABLE\n\n");
    printf("\t\t a\t b\t #\t $\n");
    for (int i = 0; i < 4; i++) {
        printf(" %c\t", nt[i]);
        for (int j = 0; j < 4; j++) {
            printf("%s\t", parsing_table[i][j][0] ? parsing_table[i][j] : "-");
        }
        printf("\n");
    }
}

int main() {
    display_parsing_table();
    return 0;
}
