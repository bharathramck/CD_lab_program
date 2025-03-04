#include <stdio.h>
#include <string.h>

#define MAX 100

struct Symbol {
    char name[50];
    char type[20];
    int size;
} table[MAX];

int count = 0;

void insert(char name[], char type[], int size) {
    strcpy(table[count].name, name);
    strcpy(table[count].type, type);
    table[count].size = size;
    count++;
}

void display() {
    printf("\nSymbol Table:\n");
    printf("---------------------------------\n");
    printf("| Name        | Type      | Size |\n");
    printf("---------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("| %-10s | %-8s | %-4d |\n", table[i].name, table[i].type, table[i].size);
    }

    printf("---------------------------------\n");
}

int main() {
    int choice;
    char name[50], type[20];
    int size;

    while (1) {
        printf("\n1. Insert Symbol\n2. Display Symbol Table\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Identifier Name: ");
                scanf("%s", name);
                printf("Enter Type (int, float, char, etc.): ");
                scanf("%s", type);
                printf("Enter Size: ");
                scanf("%d", &size);
                insert(name, type, size);
                break;

            case 2:
                display();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
