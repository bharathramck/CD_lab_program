#include <stdio.h>
#include <ctype.h>

int is_constant(char str[]);

int main() {
    char str[50];

    printf("Enter a string: ");
    scanf("%s", str);

    if (is_constant(str))
        printf("Given string is a constant.\n");
    else
        printf("Given string is not a constant.\n");

    return 0;
}

int is_constant(char str[]) {
    int i = 0;

    // Allow an optional sign at the beginning
    if (str[i] == '+' || str[i] == '-')
        i++;

    // Check if the rest are digits
    for (; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return 0;
    }

    return (i > 0); // Ensure at least one digit is present
}
