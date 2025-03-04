#include <stdio.h>
#include <string.h>

int count_odd_consecutive_ones(char str[]);

int main() {
    char str[50];

    printf("Enter the message stream: ");
    scanf("%s", str);

    int count = count_odd_consecutive_ones(str);

    if (count > 0)
        printf("The string has an odd number of consecutive ones: %d\n", count);
    else
        printf("The string does not have an odd number of consecutive ones.\n");

    return 0;
}

int count_odd_consecutive_ones(char str[]) {
    int count = 0, temp = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '1') {
            temp++;
            if (str[i + 1] != '1') { // End of consecutive ones
                if (temp % 2 != 0) count += temp;
                temp = 0;
            }
        }
    }

    return count;
}
