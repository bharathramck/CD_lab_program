#include <stdio.h>
#include <string.h>

int is_relational_operator(char str[]);

int main() {
    char str[5];

    printf("Enter a string: ");
    scanf("%s", str);

    if (is_relational_operator(str))
        printf("It is a relational operator.\n");
    else
        printf("Not a relational operator.\n");

    return 0;
}

int is_relational_operator(char str[]) {
    return (strcmp(str, "<") == 0 || strcmp(str, ">") == 0 ||
            strcmp(str, "<=") == 0 || strcmp(str, ">=") == 0 ||
            strcmp(str, "==") == 0 || strcmp(str, "!=") == 0);
}
