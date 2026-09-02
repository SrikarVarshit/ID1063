#include <stdio.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[n];
    int count[10] = {0};

    printf("Enter the values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] >= 0 && arr[i] <= 9) {
            count[arr[i]]++;
        }
    }

    for (int i = 0; i <= 9; i++) {
        printf("%d: %d\n", i, count[i]);
    }

    return 0;
}

