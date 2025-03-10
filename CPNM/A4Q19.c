#include <stdio.h>
#include <stdlib.h>
int compareDates(char date1[], char date2[]) {
    int day1 = atoi(date1);
    int month1 = atoi(date1 + 3);
    int year1 = atoi(date1 + 6);
    int day2 = atoi(date2);
    int month2 = atoi(date2 + 3);
    int year2 = atoi(date2 + 6);
    if (year1 > year2) 
        return 1;
    else if (year1 < year2)
        return -1;
    if (month1 > month2)
        return 1;
    else if (month1 < month2)
        return -1;
    if (day1 > day2)
        return 1;
    else if (day1 < day2)
        return -1;
    return 0;
}
int main() {
    char date1[11], date2[11];
    printf("Enter first date (dd/mm/yyyy): ");
    scanf("%s", date1);
    printf("Enter second date (dd/mm/yyyy): ");
    scanf("%s", date2);
    int result = compareDates(date1, date2);
    if (result == 0) {
        printf("Dates are the same.\n");
    } else if (result == 1) {
        printf("First date is later than the second date.\n");
    } else if (result == -1) {
        printf("First date is earlier than the second date.\n");
    }
    return 0;
}
