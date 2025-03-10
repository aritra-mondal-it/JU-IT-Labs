#include <stdio.h>
#include <string.h>

typedef struct
{
    int roll_number;
    char name[50];
    char department[50];
    char course[50];
    int year_of_joining;
} Student;

Student students[100];

void print_students_by_year(int year)
{
    int i;
    for (i = 0; i < 100; i++)
    {
        if (students[i].year_of_joining == year)
        {
            printf("%s\n", students[i].name);
        }
    }
}

void print_student_by_roll_number(int roll_number)
{
    int i;
    for (i = 0; i < 100; i++)
    {
        if (students[i].roll_number == roll_number)
        {
            printf("Name: %s\n", students[i].name);
            printf("Department: %s\n", students[i].department);
            printf("Course: %s\n", students[i].course);
            printf("Year of Joining: %d\n", students[i].year_of_joining);
            return;
        }
    }
    printf("No student found with roll number %d\n", roll_number);
}
