#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void uniform(char *str, int len)
{
    int i;
    FILE *fp;
    fp = fopen(str, "w");
    for (i = 0; i < len; i++)
    {
        // Generates random integers from 1 to 100
        fprintf(fp, "%d\n", (rand() % 100) + 1);
    }
    fclose(fp);
}

void processVector(int n)
{
    // Generate n random numbers between 1 and 100 into a file
    uniform("vector.dat", n);

    FILE *fp = fopen("vector.dat", "r");
    int arr[n];

    // Read values from the file into the array
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    // Print the initial array
    printf("Initial vector:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    // Use a pointer to find the lowest element in the array
    int *min_ptr = &arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < *min_ptr)
        {
            min_ptr = &arr[i];
        }
    }

    // Set the lowest element to 0 using the pointer
    *min_ptr = 0;

    // Print the updated array
    printf("Updated vector:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");
}

int main(void)
{
    srand(time(NULL));

    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        return 0;
    }

    processVector(n);

    return 0;
}

