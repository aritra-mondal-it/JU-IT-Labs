#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    FILE *inputFile, *outputFile;
    int *numbers;
    int count = 0, i, temp;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("Cannot open input file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%d", &temp) == 1)
    {
        count++;
    }
    rewind(inputFile);

    numbers = (int *)malloc(count * sizeof(int));
    if (numbers == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(inputFile);
        return 1;
    }

    for (i = 0; i < count; i++)
    {
        fscanf(inputFile, "%d", &numbers[i]);
    }
    fclose(inputFile);

    bubbleSort(numbers, count);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Cannot open output file.\n");
        free(numbers);
        return 1;
    }
    for (i = 0; i < count; i++)
    {
        fprintf(outputFile, "%d\n", numbers[i]);
    }
    fclose(outputFile);

    return 0;
}
