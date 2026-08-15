#include <stdio.h>

int main()
{
    int n, i;
    int arr[100];
    int *ptr;
    int sum = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    ptr = arr;

    for (i = 0; i < n; i++)
    {
        sum += *ptr;
        ptr++;
    }

    printf("Sum = %d\n", sum);

    return 0;
}