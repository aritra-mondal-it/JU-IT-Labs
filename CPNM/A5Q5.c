#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r1, c1, r2, c2, i, j, k;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d%d", &r1, &c1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d%d", &r2, &c2);

    if (c1 != r2)
    {
        printf("Multiplication not possible.\n");
        return 0;
    }

    int *a = (int *)calloc(r1 * c1, sizeof(int));
    int *b = (int *)calloc(r2 * c2, sizeof(int));
    int *result = (int *)calloc(r1 * c2, sizeof(int));

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i * c1 + j]);

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i * c2 + j]);

    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            result[i * c2 + j] = 0;

    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            for (k = 0; k < c1; k++)
                result[i * c2 + j] += a[i * c1 + k] * b[k * c2 + j];

    printf("Output Matrix:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
            printf("%d  ", result[i * c2 + j]);
        printf("\n");
    }

    return 0;
}
