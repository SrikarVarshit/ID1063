#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void binaryMatrix(int n, int m) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int bit = rand() % 2;
            printf("%d ", bit);
        }
        printf("\n");
    }
}

int main(void) {
    int n, m;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter m: ");
    scanf("%d", &m);

    binaryMatrix(n, m);

    return 0;
}

