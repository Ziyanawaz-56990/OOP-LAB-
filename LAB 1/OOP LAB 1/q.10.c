#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int rollNumber;
    char name[50];
    float marks;
};

int main()
{
    int n, i, highest = 0;
    struct Student *students;

    scanf("%d", &n);

    students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &students[i].rollNumber);
        scanf(" %[^\n]", students[i].name);
        scanf("%f", &students[i].marks);
    }

    for (i = 1; i < n; i++)
    {
        if (students[i].marks > students[highest].marks)
            highest = i;
    }

    printf("Student with highest marks:\n");
    printf("Roll Number = %d\n", students[highest].rollNumber);
    printf("Name = %s\n", students[highest].name);
    printf("Marks = %.2f\n", students[highest].marks);

    free(students);

    return 0;
}