#include <stdio.h>
#include <string.h>
#include <ctype.h>

char str[100];
int p = 0, valid = 1;

void E();
void EPrime();
void T();
void TPrime();
void F();

int main() {
    printf("Enter the input string: ");
    scanf("%s", str);

    E(); // Start parsing

    if (p == strlen(str) && valid)
        printf("String is acceptable.\n");
    else
        printf("The given input string is not acceptable.\n");

    return 0;
}

void E() {
    printf("E -> T E'\n");
    T();
    EPrime();
}

void EPrime() {
    if (str[p] == '+') {
        printf("E' -> + T E'\n");
        p++;
        T();
        EPrime();
    } else {
        printf("E' -> ε\n");
    }
}

void T() {
    printf("T -> F T'\n");
    F();
    TPrime();
}

void TPrime() {
    if (str[p] == '*') {
        printf("T' -> * F T'\n");
        p++;
        F();
        TPrime();
    } else {
        printf("T' -> ε\n");
    }
}

void F() {
    if (isalpha(str[p])) {
        printf("F -> id\n");
        p++;
    } else if (str[p] == '(') {
        printf("F -> ( E )\n");
        p++;
        E();
        if (str[p] == ')')
            p++;
        else
            valid = 0; // Invalid if missing closing bracket
    } else {
        valid = 0;
    }
}
