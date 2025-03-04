#include <stdio.h>
#include <string.h>

void optimize_code(const char *input_file, const char *output_file);

int main() {
    optimize_code("i.dat", "o.dat");
    printf("Optimized code saved in o.dat\n");
    return 0;
}

void optimize_code(const char *input_file, const char *output_file) {
    FILE *f1 = fopen(input_file, "r");
    FILE *f2 = fopen(output_file, "w");

    if (!f1 || !f2) {
        printf("Error opening file!\n");
        return;
    }

    char line[50];
    while (fgets(line, sizeof(line), f1)) {
        int len = strlen(line);
        if ((line[len - 2] == '1' && line[len - 3] == '*') ||  // Detect "*1"
            (line[len - 2] == '0' && line[len - 3] == '+')) {  // Detect "+0"
            continue;  // Skip this line (eliminate redundancy)
        }
        fprintf(f2, "%s", line);
    }

    fclose(f1);
    fclose(f2);
}
