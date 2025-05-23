#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void add(char num1[], char num2[], char ans[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0, sum, i, j, k;
    k = 0;
    for (i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || carry; i--, j--, k++) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        ans[k] = (sum % 10) + '0';
    }
    ans[k] = '\0';
    int start = 0;
    int end = strlen(ans) - 1;
    char temp;
    while (start < end) {
        temp = ans[start];
        ans[start] = ans[end];
        ans[end] = temp;
        start++;
        end--;
    }    
}
int main() {
    char num1[1000], num2[1000], ans[1001];
    printf("Enter the first number = ");
    scanf("%s", num1);
    printf("Enter the second very long number = ");
    scanf("%s", num2);
    add(num1, num2, ans);
    printf("The sum is: %s\n", ans);
    return 0;
}
