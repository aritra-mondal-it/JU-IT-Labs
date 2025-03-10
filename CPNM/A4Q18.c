#include <stdio.h>
int stringLengthRecursive(char str[]) {
    if (str[0] == '\0') {
        return 0;
    } else
        return 1 + stringLengthRecursive(str + 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int length = stringLengthRecursive(str);
    printf("Length of the string: %d\n", length);
    return 0;
}
