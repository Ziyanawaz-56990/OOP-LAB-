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
    int i;

    for (i = 0; i < 5; i++)
    {
        scanf("%d", &students[i].rollNumber);
        scanf(" %[^\n]", students[i].name);
        scanf("%f", &students[i].marks);
    }

    printf("\nRoll No.\tName\t\tMarks\n");

    for (i = 0; i < 5; i++)
    {
        printf("%d\t\t%s\t\t%.2f\n",
               students[i].rollNumber,
               students[i].name,
               students[i].marks);
    }

    return 0;
}