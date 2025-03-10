#include <stdio.h>
#include <string.h>
int main()
{
    FILE *sourceFile, *destFile;
    char ch;
    char sourceFileName[1000], destFileName[1000];

    printf("Enter source file name: ");
    fgets(sourceFileName, 1000, stdin);
    sourceFileName[strcspn(sourceFileName, "\n")] = '\0';

    printf("Enter destination file name: ");
    fgets(destFileName, 1000, stdin);
    destFileName[strcspn(destFileName, "\n")] = '\0';

    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL)
    {
        printf("Cannot open source file %s\n", sourceFileName);
        return 1;
    }

    destFile = fopen(destFileName, "w");
    if (destFile == NULL)
    {
        printf("Cannot open destination file %s\n", destFileName);
        fclose(sourceFile);
        return 1;
    }

    while ((ch = fgetc(sourceFile)) != EOF)
    {
        fputc(ch, destFile);
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
