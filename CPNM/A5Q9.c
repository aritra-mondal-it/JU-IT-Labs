#include <stdio.h>
#include <string.h>

typedef struct
{
    int roll;
    char name[50];
    float marks[6];
    float average;
} Student;

Student students[10];

void sort_students()
{
    int i,j;
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (students[i].average > students[j].average)
            {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main()
{
    int i,j;
    for (i = 0; i < 10; i++)
    {
        printf("Enter roll, name, and marks of 6 subjects for student %d: ", i + 1);
        scanf("%d", &students[i].roll);
        scanf("%s", students[i].name);
        for (j = 0; j < 6; j++)
        {
            scanf("%f", &students[i].marks[j]);
        }

        float sum = 0;
        for (j = 0; j < 6; j++)
        {
            sum += students[i].marks[j];
        }
        students[i].average = sum / 6;
    }

    sort_students();
    for (i = 0; i < 10; i++)
    {
        printf("Roll: %d, Name: %s, Average: %f\n", students[i].roll, students[i].name, students[i].average);
    }

    return 0;
}
