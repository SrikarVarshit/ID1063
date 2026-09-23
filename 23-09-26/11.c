#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Matrix multiplication function: C = A * B
// A is of dimension (r1 x c1), B is of dimension (c1 x c2), result C is (r1 x c2)
void matmul(const double *A, const double *B, double *C, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i * c2 + j] = 0.0;
            for (int k = 0; k < c1; k++) {
                C[i * c2 + j] += A[i * c1 + k] * B[k * c2 + j];
            }
        }
    }
}

// Function to calculate the RMS value using matrix operations
double rms(double a[], int n) {
    // Treat array 'a' as a 1 x n row vector A
    // Construct the transpose vector B (A^T) of size n x 1
    double B[n][1];
    for (int i = 0; i < n; i++) {
        B[i][0] = a[i];
    }

    // Output matrix C will be of size 1 x 1 to hold (A @ A^T)
    double C[1][1];

    // Multiply: (1 x n) * (n x 1) -> (1 x 1)
    matmul(a, (const double *)B, (double *)C, 1, n, 1);

    double sum_sq = C[0][0];
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

    printf("%.2f\n", rms(a, n));

    return 0;
}

