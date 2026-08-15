#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int *arr;

    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Elements:\n");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);

    return 0;
}