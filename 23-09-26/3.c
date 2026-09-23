#include <stdio.h>

/* Function that returns the number of consecutive 1s starting at index i */
int runLength(int a[], int n, int i) {
    int count = 0;
    while (i < n && a[i] == 1) {
        count++;
        i++;
    }
    return count;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) {
        return 0;
    }

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int violation_session = 0;

    /* Check each position using runLength */
    for (int i = 0; i < n; i++) {
        // When a study streak starts and exceeds k consecutive sessions
        if (runLength(a, n, i) > k) {
            // The violation occurs at the (k + 1)-th consecutive session of this streak
            // (i is 0-indexed, so session number is i + k + 1)
            violation_session = i + k + 1;
            break;
        }
    }

    printf("%d\n", violation_session);

    return 0;
}

