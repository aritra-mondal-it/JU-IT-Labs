#include <stdio.h>
#include <string.h>
struct Student
{
    char name[50];
    int marks[5];
    int totalMarks;
};
int calculateTotalMarks(int marks[], int numSubjects) {
    int total = 0,i=0;
    for (i = 0; i < numSubjects; ++i) {
        total += marks[i];
    }
    return total;
}
void sortStudents(struct Student students[], int numStudents) {
    struct Student temp;
    int i=0,j=0;
    for (i = 0; i < numStudents - 1; ++i) {
        for (j = 0; j < numStudents - 1 - i; ++j) {
            if (students[j].totalMarks < students[j + 1].totalMarks) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i=0,j=0;
    for (i = 0; i < 5; ++i) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter marks for student %d in 5 subjects: ", i + 1);
        for (j = 0; j < 5; ++j) {
            scanf("%d", &students[i].marks[j]);
        }
        students[i].totalMarks = calculateTotalMarks(students[i].marks, 5);
    }
    sortStudents(students, 5);
    printf("\nStudents in order of merit:\n");
    for (i = 0; i < 5; ++i) {
        printf("%d. Name: %s, Total Marks: %d\n", i + 1, students[i].name, students[i].totalMarks);
    }
    return 0;
}
