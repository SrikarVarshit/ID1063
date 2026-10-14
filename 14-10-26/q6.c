
#include <stdio.h>

struct Polynomial
{
    int n;
    double a[21];
};

int main()
{
    struct Polynomial poly, deriv;
    double x, value = 0;
    int i;

    printf("Enter degree of polynomial (0-20): ");
    scanf("%d", &poly.n);

    if (poly.n < 0 || poly.n > 20)
    {
        printf("Invalid degree\n");
        return 1;
    }

    printf("Enter coefficients from a0 to an:\n");

    for (i = 0; i <= poly.n; i++)
    {
        printf("a%d = ", i);
        scanf("%lf", &poly.a[i]);
    }

    printf("Enter value of x (a): ");
    scanf("%lf", &x);

    // Compute P(x) using Horner's method
    value = poly.a[poly.n];

    for (i = poly.n - 1; i >= 0; i--)
        value = value * x + poly.a[i];

    printf("P(%.2lf) = %.2lf\n", x, value);

    // Compute derivative polynomial
    deriv.n = (poly.n > 0) ? poly.n - 1 : 0;

    if (poly.n > 0)
    {
        for (i = 1; i <= poly.n; i++)
            deriv.a[i - 1] = i * poly.a[i];
    }
    else
    {
        deriv.a[0] = 0;
    }

    printf("Derivative: ");

    if (poly.n == 0)
    {
        printf("0\n");
    }
    else
    {
        for (i = 0; i <= deriv.n; i++)
        {
            printf("%.2lf", deriv.a[i]);

            if (i > 0)
                printf("x^%d", i);

            if (i < deriv.n)
                printf(" + ");
        }

        printf("\n");
    }

    return 0;
}

