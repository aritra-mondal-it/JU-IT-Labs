#include <stdio.h>
#include <ctype.h>
#include <string.h>
int countWords(char str[]) {
    int wordCount = 0;
    int i = 0;
    int inWord = 0;
    while (str[i] != '\0') {
        if (isspace(str[i])) {
            inWord = 0;
        } else {
            if (!inWord) {
                wordCount++;
                inWord = 1;
            }
        }
        i++;
    }
    return wordCount;
}
int countOccurrences(char str[], char word[]) {
    int count = 0;
    int wordLength = strlen(word);
    char *ptr = strstr(str, word);

    while (ptr != NULL) {
        count++;
        ptr = strstr(ptr + wordLength, word);
    }

    return count;
}
void printReverse(char str[]) {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}
void countVowelsAndConsonants(char str[], int *vowels, int *consonants) {
    *vowels = 0;
    *consonants = 0;
    int i = 0;
    char ch;

    while ((ch = str[i++]) != '\0') {
        if (isalpha(ch)) {
            ch = tolower(ch);
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        }
    }
}
char mostFrequentCharacter(char str[]) {
    int count[256] = {0};
    int maxCount = 0;
    char mostFrequentChar;
    for (int i = 0; str[i] != '\0'; i++) {
        count[(int)str[i]]++;
        if (count[(int)str[i]] > maxCount) {
            maxCount = count[(int)str[i]];
            mostFrequentChar = str[i];
        }
    }
    return mostFrequentChar;
}
int isSubstringPresent(char str[], char substr[]) {
    if (strstr(str, substr) != NULL) {
        return 1;
    } else {
        return 0;
}
int main() {
    char str[100], word[50], substr[50];
    int vowels, consonants;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("Total number of words: %d\n", countWords(str));
    printf("Enter word to search: ");
    scanf("%s", word);
    printf("Occurrences of '%s': %d\n", word, countOccurrences(str, word));
    printf("Characters in reverse order: ");
    printReverse(str);
    countVowelsAndConsonants(str, &vowels, &consonants);
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
    printf("Most frequent character: %c\n", mostFrequentCharacter(str));
    printf("Enter substring to search: ");
    scanf("%s", substr);
    if (isSubstringPresent(str, substr)) {
        printf("'%s' is present in the string.\n", substr);
    } else {
        printf("'%s' is not present in the string.\n", substr);
    }
    return 0;
}
