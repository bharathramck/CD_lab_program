#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_KEYWORDS 10

char *keywords[MAX_KEYWORDS] = {"int", "float", "if", "else", "while", "for", "return", "char", "void", "double"};

int is_keyword(char *word) {
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void lexical_analyzer(FILE *fp) {
    char c, buffer[50];
    int index = 0;

    while ((c = fgetc(fp)) != EOF) {
        if (isalnum(c) || c == '_') {
            buffer[index++] = c;
        } else {
            if (index != 0) {
                buffer[index] = '\0';
                index = 0;
                if (is_keyword(buffer))
                    printf("%s -> keyword\n", buffer);
                else if (isdigit(buffer[0]))
                    printf("%s -> number\n", buffer);
                else
                    printf("%s -> identifier\n", buffer);
            }

            if (c == ' ' || c == '\t' || c == '\n')
                continue;

            if (strchr("+-*/=><();{},", c))
                printf("%c -> special symbol\n", c);
        }
    }
}

int main() {
    FILE *fp = fopen("input.txt", "r");

    if (!fp) {
        printf("Error: Unable to open file!\n");
        return 1;
    }

    lexical_analyzer(fp);
    fclose(fp);

    return 0;
}
