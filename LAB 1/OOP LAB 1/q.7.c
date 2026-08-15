#include <stdio.h>

struct Student
{
    int rollNumber;
    char name[50];
    float marks;
};

int main()
{
    struct Student students[5];
    int i, highest = 0;
    float sum = 0, average;

    for (i = 0; i < 5; i++)
    {
        scanf("%d", &students[i].rollNumber);
        scanf(" %[^\n]", students[i].name);
        scanf("%f", &students[i].marks);

        sum += students[i].marks;

        if (students[i].marks > students[highest].marks)
            highest = i;
    }

    average = sum / 5;

    printf("Student with highest marks:\n");
    printf("Roll Number = %d\n", students[highest].rollNumber);
    printf("Name = %s\n", students[highest].name);
    printf("Marks = %.2f\n", students[highest].marks);

    printf("Average Marks = %.2f\n", average);

    return 0;
}