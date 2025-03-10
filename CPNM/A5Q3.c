#include <stdio.h>

void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

int main()
{
    char str[1000];
    printf("Enter a string: ");
    fgets(str, 1000, stdin);
    char c;
    printf("Enter a character to remove: ");
    scanf("%c", &c);
    squeeze(str, c);
    printf("String after removing '%c': %s\n", c, str);
    return 0;
}
