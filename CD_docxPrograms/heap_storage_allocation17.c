#include <stdio.h>

void allocate_memory(int memory_capacity, int partitions[], int np, int queue[], int nq);

int main() {
    int memory_capacity, np, nq = 5;
    int partitions[10], queue[5];

    printf("Enter memory capacity: ");
    scanf("%d", &memory_capacity);

    printf("Enter the number of partitions: ");
    scanf("%d", &np);

    printf("Enter the partition sizes:\n");
    for (int i = 0; i < np; i++)
        scanf("%d", &partitions[i]);

    printf("Enter the memory request queue:\n");
    for (int i = 0; i < nq; i++)
        scanf("%d", &queue[i]);

    allocate_memory(memory_capacity, partitions, np, queue, nq);

    return 0;
}

void allocate_memory(int memory_capacity, int partitions[], int np, int queue[], int nq) {
    for (int i = 0; i < nq; i++) {
        int min_index = -1, min_size = memory_capacity;

        for (int j = 0; j < np; j++) {
            if (partitions[j] >= queue[i] && partitions[j] < min_size) {
                min_size = partitions[j];
                min_index = j;
            }
        }

        if (min_index != -1) {
            printf("%d KB allocated to partition of size %d KB\n", queue[i], partitions[min_index]);
            partitions[min_index] -= queue[i];  // Reduce partition size
        } else {
            printf("No sufficient memory available for %d KB request.\n", queue[i]);
        }
    }
}

