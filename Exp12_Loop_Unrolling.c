#include <stdio.h>

void loop_unrolling(int n, int unroll_factor) {
    printf("Unrolled loop execution:\n");

    int i;
    for (i = 0; i < n / unroll_factor * unroll_factor; i += unroll_factor) {
        printf("Iteration %d\n", i);
        for (int j = 0; j < unroll_factor; j++) {
            printf("Processing index %d\n", i + j);
        }
    }

    for (; i < n; i++) {
        printf("Processing remaining index %d\n", i);
    }
}

int main() {
    int n, unroll_factor;

    printf("Enter loop iteration count: ");
    scanf("%d", &n);

    printf("Enter unroll factor: ");
    scanf("%d", &unroll_factor);

    loop_unrolling(n, unroll_factor);

    return 0;
}
