#include <stdio.h>

struct Student
{
    int rollNumber;
    char name[50];
    float marks;
};

int main()
{
    struct Student student;
    struct Student *ptr;

    ptr = &student;

    scanf("%d", &ptr->rollNumber);
    scanf(" %[^\n]", ptr->name);
    scanf("%f", &ptr->marks);

    printf("Roll Number = %d\n", ptr->rollNumber);
    printf("Name = %s\n", ptr->name);
    printf("Marks = %.2f\n", ptr->marks);

    return 0;
}