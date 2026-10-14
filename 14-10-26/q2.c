
#include <stdio.h>
#include <stdlib.h>

char *my_strcat(char *dest, const char *src)
{
    char *p = dest;

    while (*p != '\0')
        p++;

    while (*src != '\0')
    {
        *p = *src;
        p++;
        src++;
    }

    *p = '\0';
    return dest;
}

int main()
{
    char *dest = NULL, *src = NULL;
    char *temp;
    int ch, n = 0, m = 0;

    printf("Enter destination string: ");
    dest = malloc(1);
    if (dest == NULL)
        return 1;
    dest[0] = '\0';

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        temp = realloc(dest, n + 2);
        if (temp == NULL)
        {
            free(dest);
            return 1;
        }
        dest = temp;
        dest[n++] = ch;
        dest[n] = '\0';
    }

    printf("Enter source string: ");
    src = malloc(1);
    if (src == NULL)
    {
        free(dest);
        return 1;
    }
    src[0] = '\0';

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        temp = realloc(src, m + 2);
        if (temp == NULL)
        {
            free(dest);
            free(src);
            return 1;
        }
        src = temp;
        src[m++] = ch;
        src[m] = '\0';
    }

    printf("\nBefore concatenation:\n");
    printf("Destination: %s\n", dest);
    printf("Source: %s\n", src);

    temp = realloc(dest, n + m + 1);
    if (temp == NULL)
    {
        free(dest);
        free(src);
        return 1;
    }
    dest = temp;

    my_strcat(dest, src);

    printf("\nAfter concatenation:\n");
    printf("Destination: %s\n", dest);

    free(dest);
    free(src);

    return 0;
}

