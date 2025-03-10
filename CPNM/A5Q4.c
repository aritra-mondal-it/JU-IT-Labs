#include <stdio.h>

int strend(char *s, char *t)
{
    char *s_begin = s;
    char *t_begin = t;

    while (*s)
    {
        s++;
    }

    while (*t)
    {
        t++;
    }

    while (s >= s_begin && t >= t_begin && *s == *t)
    {
        s--;
        t--;
    }

    if (t < t_begin)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char s[1000];
    char t[100];
    printf("Enter string : ");
    fgets(s, 1000, stdin);
    printf("Enter string to be matched: ");
    fgets(t, 100, stdin);
    printf("%d\n", strend(s, t));
    return 0;
}
