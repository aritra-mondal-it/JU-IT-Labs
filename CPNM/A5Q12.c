#include <stdio.h>

int main()
{
    FILE *file;
    char filename[100];
    char ch;
    int totalChars = 0, commentChars = 0;
    int inBlockComment = 0, inLineComment = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Cannot open file %s\n", filename);
        return 1;
    }

    while ((ch = fgetc(file)) != EOF)
    {
        totalChars++;

        if (inBlockComment)
        {
            commentChars++;
            if (ch == '*' && (ch = fgetc(file)) == '/')
            {
                inBlockComment = 0;
                commentChars++;
            }
        }
        else if (inLineComment)
        {
            commentChars++;
            if (ch == '\n')
            {
                inLineComment = 0;
            }
        }
        else
        {
            if (ch == '/')
            {
                ch = fgetc(file);
                if (ch == '*')
                {
                    inBlockComment = 1;
                    commentChars += 2;
                }
                else if (ch == '/')
                {
                    inLineComment = 1;
                    commentChars += 2;
                }
                else
                {
                    ungetc(ch, file);
                }
            }
        }
    }

    fclose(file);

    if (totalChars > 0)
    {
        float percentage = (float)commentChars / totalChars * 100;
        printf("Percentage of characters in comments: %f\n", percentage);
    }
    else
    {
        printf("The file is empty.\n");
    }

    return 0;
}
