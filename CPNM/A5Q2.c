#include <stdio.h>

int main()
{
    char str[1000];
    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    char *start = str;
    char *end = str;
    char temp;

    while (*end)
    {
        end++;
        if (*end == '\0')
        {
            char *wordEnd = end - 1;
            while (start < wordEnd)
            {
                temp = *start;
                *start = *wordEnd;
                *wordEnd = temp;
                start++;
                wordEnd--;
            }
        }
        else if (*end == ' ')
        {
            char *wordEnd = end - 1;
            while (start < wordEnd)
            {
                temp = *start;
                *start = *wordEnd;
                *wordEnd = temp;
                start++;
                wordEnd--;
            }
            start = end + 1;
        }
    }

    printf("Reversed string: \n%s", str);

    return 0;
}
