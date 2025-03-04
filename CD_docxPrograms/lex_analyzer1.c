#include <stdio.h>
#include <ctype.h>
#include <string.h>

void check(char s[10]);

FILE *fp, *fp1;

int main() {
    char s[10];

    fp = fopen("i.dat", "r");
    if (fp == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    fp1 = fopen("o.dat", "w");
    if (fp1 == NULL) {
        printf("Error opening output file!\n");
        fclose(fp);
        return 1;
    }

    while (fscanf(fp, "%s", s) != EOF) {
        check(s);
    }

    fclose(fp);
    fclose(fp1);
    return 0;
}

void check(char s[10]) {
    fp1 = fopen("o.dat", "a");

    if (strcmp(s, "read") == 0 || strcmp(s, "write") == 0 ||
        strcmp(s, "while") == 0 || strcmp(s, "for") == 0 ||
        strcmp(s, "if") == 0 || strcmp(s, "else") == 0 ||
        strcmp(s, "endif") == 0 || strcmp(s, "then") == 0) {
        fprintf(fp1, "%s -> keyword\n", s);
    } 
    else if (!isalpha(s[0])) {
        if (strcmp(s, ",") == 0) fprintf(fp1, ", -> comma\n");
        if (strcmp(s, "(") == 0) fprintf(fp1, "( -> open brace\n");
        if (strcmp(s, ")") == 0) fprintf(fp1, ") -> close brace\n");
        if (strcmp(s, ";") == 0) fprintf(fp1, "; -> semicolon\n");
        if (strcmp(s, ">") == 0) fprintf(fp1, "> -> greater than\n");
        if (strcmp(s, "<") == 0) fprintf(fp1, "< -> less than\n");
    } 
    else {
        fprintf(fp1, "%s -> identifier\n", s);
    }

    fclose(fp1);
}
