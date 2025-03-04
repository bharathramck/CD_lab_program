#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_identifier(char str[]);

int main() {
    char str[50];

    printf("Enter a string: ");
    scanf("%s", str);

    if (is_identifier(str))
        printf("Given string is an identifier.\n");
    else
        printf("Given string is not an identifier.\n");

    return 0;
}

int is_identifier(char str[]) {
    if (!isalpha(str[0]) && str[0] != '_') // First character must be a letter or underscore
        return 0;

    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_') // Remaining characters must be letters, digits, or underscores
            return 0;
    }
    return 1;
}
