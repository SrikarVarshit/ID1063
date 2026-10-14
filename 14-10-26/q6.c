
#include <stdio.h>

struct Polynomial
{
    int n;
    double a[21];
};

int main()
{
    struct Polynomial poly, deriv;
    struct Polynomial *p = &poly;
    struct Polynomial *d = &deriv;
    double x, value;
    int i;

    printf("Enter degree (0-20): ");
    scanf("%d", &p->n);

    if (p->n < 0 || p->n > 20)
    {
        printf("Invalid degree\n");
        return 1;
    }

    printf("Enter coefficients from a0 to an:\n");

    for (i = 0; i <= p->n; i++)
    {
        printf("a%d = ", i);
        scanf("%lf", p->a + i);
    }

    printf("Enter value of x: ");
    scanf("%lf", &x);

    // Evaluate P(x) using Horner's method
    value = *(p->a + p->n);

    for (i = p->n - 1; i >= 0; i--)
        value = value * x + *(p->a + i);

    printf("P(%.2lf) = %.2lf\n", x, value);

    // Calculate derivative coefficients
    if (p->n == 0)
    {
        d->n = 0;
        *d->a = 0;
    }
    else
    {
        d->n = p->n - 1;

        for (i = 1; i <= p->n; i++)
            *(d->a + i - 1) = i * *(p->a + i);
    }

    printf("Coefficients afte Differentiation:\n");

    for (i = 0; i <= d->n; i++)
        printf("a%d = %.2lf\n", i, *(d->a + i));

    return 0;
}

