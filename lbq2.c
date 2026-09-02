#include <stdio.h>

float matdot(float v1[], float v2[], int n) {
    float product = 0.0;
    for (int i = 0; i < n; i++) {
        product += v1[i] * v2[i];
    }
    return product;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    float v1[n], v2[n];

    printf("Enter the values of the first vector: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &v1[i]);
    }

    printf("Enter the values of the second vector: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &v2[i]);
    }

    float dot_product = matdot(v1, v2, n);
    printf("The dot product is %.1f\n", dot_product);

    return 0;
}

