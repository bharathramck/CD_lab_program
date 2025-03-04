#include <stdio.h>
#include <ctype.h>
#include <string.h>

void check_token(char str[]);

FILE *fp, *fp1;

int main() {
    char str[20];

    fp = fopen("i.dat", "r");  // Open input file
    if (fp == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    fp1 = fopen("o.dat", "w"); // Open output file
    if (fp1 == NULL) {
        printf("Error opening output file!\n");
        fclose(fp);
        return 1;
    }

    while (fscanf(fp, "%s", str) != EOF) { // Read words from file
        check_token(str);
    }

    fclose(fp);
    fclose(fp1);
    return 0;
}

void check_token(char str[]) {
    fp1 = fopen("o.dat", "a"); // Append output

    // List of keywords
    char *keywords[] = {"read", "write", "while", "for", "if", "else", "endif", "then"};
    int isKeyword = 0;

    for (int i = 0; i < 8; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            fprintf(fp1, "%s -> keyword\n", str);
            isKeyword = 1;
            break;
        }
    }

    if (!isKeyword) {
        if (isalpha(str[0])) { // Identifiers
            fprintf(fp1, "%s -> identifier\n", str);
        } else if (isdigit(str[0])) { // Numbers
            fprintf(fp1, "%s -> number\n", str);
        } else { // Special Symbols
            if (strcmp(str, ",") == 0) fprintf(fp1, ", -> comma\n");
            else if (strcmp(str, "(") == 0) fprintf(fp1, "( -> open brace\n");
            else if (strcmp(str, ")") == 0) fprintf(fp1, ") -> close brace\n");
            else if (strcmp(str, ";") == 0) fprintf(fp1, "; -> semicolon\n");
            else if (strcmp(str, ">") == 0) fprintf(fp1, "> -> greater than\n");
            else if (strcmp(str, "<") == 0) fprintf(fp1, "< -> less than\n");
            else fprintf(fp1, "%s -> special symbol\n", str);
        }
    }

    fclose(fp1);
}
