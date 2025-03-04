#include <stdio.h>
#include <string.h>

int count_ones(char str[]);

int main() {
    char str[50];

    printf("Enter the message stream: ");
    scanf("%s", str);

    int count = count_ones(str);

    if (count % 2 != 0)
        printf("The string has an odd number of ones: %d\n", count);
    else
        printf("The string does not have an odd number of ones.\n");

    return 0;
}

int count_ones(char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '1')
            count++;
    }
    return count;
}
