#include <stdio.h>

int main()
{
    FILE *file = fopen("hello1.txt", "w");
    fprintf(file, "Hello\n");
    fprintf(file, "This is my first program in file\n");

    fclose(file);

    return 0;
}
