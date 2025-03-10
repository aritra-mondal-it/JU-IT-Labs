#include <stdio.h>
#include <string.h> 
#define MAX_STRINGS 100
#define MAX_LENGTH 100
void bubbleSortStrings(char arr[][MAX_LENGTH], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {   
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char temp[MAX_LENGTH];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}
int main() {
    char strings[MAX_STRINGS][MAX_LENGTH];
    int n = 0;
    printf("Enter strings (press Enter twice to stop):\n");
    while (n < MAX_STRINGS) {
        fgets(strings[n], MAX_LENGTH, stdin);
        strings[n][strcspn(strings[n], "\n")] = '\0';
        if (strlen(strings[n]) == 0) {
            break;
        }
        n++;
    }

    bubbleSortStrings(strings, n);
    printf("\nSorted strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
