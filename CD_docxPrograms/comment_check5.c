#include <stdio.h>
#include <string.h>

int is_comment(char str[]);

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%[^\n]", str); // Read input including spaces

    if (is_comment(str))
        printf("The given string is a comment.\n");
    else
        printf("The given string is not a comment.\n");

    return 0;
}

int is_comment(char str[]) {
    int len = strlen(str);

    // Check for single-line comment (//)
    if (str[0] == '/' && str[1] == '/')
        return 1;

    // Check for multi-line comment (/* ... */)
    if (str[0] == '/' && str[1] == '*' && str[len - 2] == '*' && str[len - 1] == '/')
        return 1;

    return 0;
}
