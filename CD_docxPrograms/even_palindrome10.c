#include <stdio.h>
#include <string.h>

int is_palindrome(char str[]);

int main() {
    char str[100];

    printf("Enter the string: ");
    scanf("%s", str);

    if (is_palindrome(str)) {
        if (strlen(str) % 2 == 0)
            printf("It is an even palindrome.\n");
        else
            printf("It is not an even palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

int is_palindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}
