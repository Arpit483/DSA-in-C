#include <stdio.h>
#include <stdlib.h>

void single();
void multiple();

int main()
{
    single();
    printf("\n");
    multiple();
    return 0;
}

/* Allocate fixed memory for single string */
void single()
{
    char *c;

    // Allocate memory for string
    c = (char *)malloc(50 * sizeof(char));

    if (c == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter a String: ");
    scanf("%s", c);

    printf("Entered String: %s\n", c);

    // Free memory
    free(c);
}

/* Allocate memory based on user input size */
void multiple()
{
    char *c;
    int size;

    printf("Enter Size of String: ");
    scanf("%d", &size);

    // +1 for null terminator
    c = (char *)malloc((size + 1) * sizeof(char));

    if (c == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the String: ");
    scanf("%s", c);

    printf("Entered String: %s\n", c);

    // Free memory
    free(c);
}
