#include <stdio.h>
#include <ctype.h>
#include <string.h>

char input[100];
int index = 0;

void E();
void EPrime();
void T();
void TPrime();
void F();

void error() {
    printf("Error in parsing!\n");
    exit(1);
}

void match(char expected) {
    if (input[index] == expected) {
        index++;
    } else {
        error();
    }
}

void E() {
    printf("E -> T E'\n");
    T();
    EPrime();
}

void EPrime() {
    if (input[index] == '+') {
        printf("E' -> + T E'\n");
        match('+');
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
    if (input[index] == '*') {
        printf("T' -> * F T'\n");
        match('*');
        F();
        TPrime();
    } else {
        printf("T' -> ε\n");
    }
}

void F() {
    if (isalpha(input[index])) {
        printf("F -> id\n");
        match(input[index]);
    } else if (input[index] == '(') {
        printf("F -> ( E )\n");
        match('(');
        E();
        match(')');
    } else {
        error();
    }
}

int main() {
    printf("Enter an expression: ");
    scanf("%s", input);

    E();

    if (input[index] == '\0')
        printf("Parsing successful!\n");
    else
        printf("Parsing failed!\n");

    return 0;
}
