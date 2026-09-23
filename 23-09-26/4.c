#include <stdio.h>
#include <math.h>

// Function to find the first stable reading
int firstStable(double a[], int n, double tolerance)
{
    // Check the difference between every two successive readings
    for (int i = 0; i < n - 1; i++)
    {
        // Calculate the absolute difference
        double difference = fabs(a[i + 1] - a[i]);

        // Check if the difference is within the tolerance
        if (difference <= tolerance)
        {
            // Return the first index satisfying the condition
            return i;
        }
    }

    // If no such index is found, return -1
    return -1;
}

int main()
{
    int n;
    double tolerance;

    // Read the number of readings
    scanf("%d", &n);

    // Declare the array of sensor readings
    double a[n];

    // Read the sensor readings
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &a[i]);
    }

    // Read the tolerance
    scanf("%lf", &tolerance);

    // Call the function and store the returned index
    int result = firstStable(a, n, tolerance);

    // Print the result
    printf("%d\n", result);

    return 0;
}

For the sample input, the differences are:

- "|9.4 - 10.0| = 0.6"
- "|9.0 - 9.4| = 0.4"
- "|8.8 - 9.0| = 0.2" ← "0.2 <= 0.25"

So the function returns 2, as required.

If you want, I can also give you a very beginner-friendly explanation of every line of this code.
