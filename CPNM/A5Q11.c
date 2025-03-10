#include <stdio.h>
#include <string.h>

int main()
{
    FILE *sourceFile, *destFile;
    char ch;
    char sourceFileName[100], destFileName[100];
    int inComment = 0;

    printf("Enter source file name: ");
    fgets(sourceFileName, 100, stdin);

    size_t len = strlen(sourceFileName);
    if (len > 0 && sourceFileName[len - 1] == '\n')
    {
        sourceFileName[len - 1] = '\0';
    }

    printf("Enter destination file name: ");
    fgets(destFileName, 100, stdin);

    len = strlen(destFileName);
    if (len > 0 && destFileName[len - 1] == '\n')
    {
        destFileName[len - 1] = '\0';
    }

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
        if (ch == '/')
        {
            char nextChar = fgetc(sourceFile);
            if (nextChar == '*')
            {
                inComment = 1;
            }
            else
            {
                fputc(ch, destFile);
                if (nextChar != EOF)
                {
                    fputc(nextChar, destFile);
                }
            }
        }
        else if (inComment && ch == '*')
        {
            char nextChar = fgetc(sourceFile);
            if (nextChar == '/')
            {
                inComment = 0;
            }
        }
        else if (!inComment)
        {
            fputc(ch, destFile);
        }
    }

    printf("File copied successfully with comments removed.\n");

    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
