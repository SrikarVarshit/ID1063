#include <stdio.h>
#include <math.h>

/* Function to compute the Root Mean Square (RMS) value */
double rms(double a[], int n) {
    double sum_sq = 0.0;
    for (int i = 0; i < n; i++) {
        sum_sq += a[i] * a[i];
    }
    return sqrt(sum_sq / n);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    double a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    /* Print the RMS value rounded to two decimal places */
    printf("%f\n",rms(a, n));

    return 0;
}

